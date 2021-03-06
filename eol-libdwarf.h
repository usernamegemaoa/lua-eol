/*
 * eol-libdwarf.h
 * Copyright (C) 2015 Adrian Perez <aperez@igalia.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef EOL_LIBDWARF_H
#define EOL_LIBDWARF_H

#ifdef EOL_WORKAROUND_DWARF_PUBTYPE_DIE_OFFSET
# if EOL_WORKAROUND_DWARF_PUBTYPE_DIE_OFFSET
#  define dwarf_pubtype_die_offset dwarf_pubtype_type_die_offset
# endif
#endif /* EOL_WORKAROUND_DWARF_PUBTYPE_DIE_OFFSET */

#if defined(EOL_LIBDWARF_BUNDLED) && EOL_LIBDWARF_BUNDLED
# include "libdwarf.h"
# include "dwarf.h"
#else
# if defined(EOL_LIBDWARF_LIBDWARF_H) && EOL_LIBDWARF_LIBDWARF_H
#  include <libdwarf/libdwarf.h>
#  include <libdwarf/dwarf.h>
# else
#  include <libdwarf.h>
#  include <dwarf.h>
# endif /* EOL_LIBDWARF_LIBDWARF_H */
#endif /* EOL_LIBDWARF_BUNDLED */

#include "eol-util.h"


#define DW_TYPE_TAG_NAMES(F) \
    F (base_type)            \
    F (typedef)              \
    F (const_type)           \
    F (array_type)           \
    F (pointer_type)         \
    F (union_type)           \
    F (enumeration_type)     \
    F (structure_type)

#define DW_DEALLOC_TYPES(F)                    \
    F (string, char*,           DW_DLA_STRING) \
    F (die,    Dwarf_Die,       DW_DLA_DIE)    \
    F (error,  Dwarf_Error,     DW_DLA_ERROR)  \
    F (attr,   Dwarf_Attribute, DW_DLA_ATTR)


#define DW_DECLARE_DW_DATA_T(name, ctype, _) \
    typedef struct {                         \
        Dwarf_Debug debug;                   \
        ctype name;                          \
    } dw_ ## name ## _t;
DW_DEALLOC_TYPES (DW_DECLARE_DW_DATA_T)
#undef DW_DECLARE_DW_DATA_T


#define DW_DECLARE_DEALLOC_CALLBACK(name, _, __) \
    extern void dw_dealloc_ ## name (void*);
DW_DEALLOC_TYPES (DW_DECLARE_DEALLOC_CALLBACK)
#undef DW_DECLARE_DEALLOC_CALLBACK

/* Ugh. Those have to be defined one by one. */
#define dw_ldie_t    LAUTO (dw_dealloc_die)    dw_die_t
#define dw_lstring_t LAUTO (dw_dealloc_string) dw_string_t
#define dw_lerror_t  LAUTO (dw_dealloc_die)    dw_error_t
#define dw_lattr_t   LAUTO (dw_dealloc_attr)   dw_attr_t


static inline unsigned
dw_die_offset (Dwarf_Die die, Dwarf_Error *e)
{
    CHECK_NOT_NULL (die);
    Dwarf_Off offset;
    return dwarf_dieoffset (die, &offset, e) == DW_DLV_OK
         ? (unsigned) offset : (unsigned) DW_DLV_BADOFFSET;
}


static inline unsigned
dw_die_offset_ (Dwarf_Die die)
{
    CHECK_NOT_NULL (die);
    return dw_die_offset (die, NULL);
}


extern char* dw_die_repr (Dwarf_Debug dbg, Dwarf_Die die);
static inline char* dw_die_reprb (const dw_die_t dd)
{ return dw_die_repr (dd.debug, dd.die); }


extern char* dw_die_get_string_attr (Dwarf_Debug  dbg,
                                     Dwarf_Die    die,
                                     Dwarf_Half   tag,
                                     Dwarf_Error *e);
static inline char*
dw_die_get_string_attrb (const dw_die_t dd,
                         Dwarf_Half     tag,
                         Dwarf_Error   *e)
{ return dw_die_get_string_attr (dd.debug, dd.die, tag, e); }


extern bool dw_die_get_uint_attr (Dwarf_Debug     dbg,
                                  Dwarf_Die       die,
                                  Dwarf_Half      tag,
                                  Dwarf_Unsigned *out,
                                  Dwarf_Error    *e);
static inline bool
dw_die_get_uint_attrb (const dw_die_t  dd,
                       Dwarf_Half      tag,
                       Dwarf_Unsigned *out,
                       Dwarf_Error    *e)
{ return dw_die_get_uint_attr (dd.debug, dd.die, tag, out, e); }


extern bool dw_die_get_sint_attr (Dwarf_Debug   dbg,
                                  Dwarf_Die     die,
                                  Dwarf_Half    tag,
                                  Dwarf_Signed *out,
                                  Dwarf_Error  *e);
static inline bool
dw_die_get_sint_attrb (const dw_die_t dd,
                       Dwarf_Half     tag,
                       Dwarf_Signed  *out,
                       Dwarf_Error   *e)
{ return dw_die_get_sint_attr (dd.debug, dd.die, tag, out, e); }


extern bool
dw_tue_array_get_n_items (Dwarf_Debug     dbg,
                          Dwarf_Die       tue,
                          Dwarf_Unsigned *out,
                          Dwarf_Error    *e);


static inline char*
dw_die_name (Dwarf_Die    die,
             Dwarf_Error *e)
{
    CHECK_NOT_NULL (die);

    char *name;
    if (dwarf_diename (die, &name, e) != DW_DLV_OK)
        name = NULL;
    return name;
}


static inline const char*
dw_errmsg (Dwarf_Error e)
{
    return e ? dwarf_errmsg (e) : "no libdwarf error";
}


#if EOL_TRACE
# define DW_TRACE_DIE(fmt, dbg, die, ...)                 \
    do {                                                  \
        LMEM char *die_repr = dw_die_repr ((dbg), (die)); \
        TRACE (BROWN "%s" NORMAL " " fmt,                 \
               die_repr, ##__VA_ARGS__);                  \
    } while (0)
# define DW_TRACE_DIE_ERROR(fmt, dbg, die, err, ...)      \
    do {                                                  \
        LMEM char *die_repr = dw_die_repr ((dbg), (die)); \
        TRACE (BROWN "%s " NORMAL "{" RED "%s" NORMAL     \
               "} " fmt, die_repr, dw_errmsg (err),       \
               ##__VA_ARGS__);                            \
    } while (0);
#else
# define DW_TRACE_DIE(...)       ((void) 0)
# define DW_TRACE_DIE_ERROR(...) ((void) 0)
#endif

#endif /* !EOL_LIBDWARF_H */
