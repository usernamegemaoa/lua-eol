/* ANSI-C code produced by gperf version 3.0.4 */
/* Command-line: gperf --output=specials.inc specials.gperf  */
/* Computed positions: -k'3' */

#if !((' ' == 32) && ('!' == 33) && ('"' == 34) && ('#' == 35) \
      && ('%' == 37) && ('&' == 38) && ('\'' == 39) && ('(' == 40) \
      && (')' == 41) && ('*' == 42) && ('+' == 43) && (',' == 44) \
      && ('-' == 45) && ('.' == 46) && ('/' == 47) && ('0' == 48) \
      && ('1' == 49) && ('2' == 50) && ('3' == 51) && ('4' == 52) \
      && ('5' == 53) && ('6' == 54) && ('7' == 55) && ('8' == 56) \
      && ('9' == 57) && (':' == 58) && (';' == 59) && ('<' == 60) \
      && ('=' == 61) && ('>' == 62) && ('?' == 63) && ('A' == 65) \
      && ('B' == 66) && ('C' == 67) && ('D' == 68) && ('E' == 69) \
      && ('F' == 70) && ('G' == 71) && ('H' == 72) && ('I' == 73) \
      && ('J' == 74) && ('K' == 75) && ('L' == 76) && ('M' == 77) \
      && ('N' == 78) && ('O' == 79) && ('P' == 80) && ('Q' == 81) \
      && ('R' == 82) && ('S' == 83) && ('T' == 84) && ('U' == 85) \
      && ('V' == 86) && ('W' == 87) && ('X' == 88) && ('Y' == 89) \
      && ('Z' == 90) && ('[' == 91) && ('\\' == 92) && (']' == 93) \
      && ('^' == 94) && ('_' == 95) && ('a' == 97) && ('b' == 98) \
      && ('c' == 99) && ('d' == 100) && ('e' == 101) && ('f' == 102) \
      && ('g' == 103) && ('h' == 104) && ('i' == 105) && ('j' == 106) \
      && ('k' == 107) && ('l' == 108) && ('m' == 109) && ('n' == 110) \
      && ('o' == 111) && ('p' == 112) && ('q' == 113) && ('r' == 114) \
      && ('s' == 115) && ('t' == 116) && ('u' == 117) && ('v' == 118) \
      && ('w' == 119) && ('x' == 120) && ('y' == 121) && ('z' == 122) \
      && ('{' == 123) && ('|' == 124) && ('}' == 125) && ('~' == 126))
/* The character set is not based on ISO-646.  */
#error "gperf generated tables don't work with this execution character set. Please report a bug to <bug-gnu-gperf@gnu.org>."
#endif

#line 9 "specials.gperf"
struct ErisSpecial {
	const char *name;
	ErisSpecialCode code;
};
#include <string.h>
/* maximum key range = 6, duplicates = 0 */

#ifdef __GNUC__
__inline
#else
#ifdef __cplusplus
inline
#endif
#endif
static unsigned int
eris_special_hash (register const char *str, register unsigned int len)
{
  static const unsigned char asso_values[] =
    {
      12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
      12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
      12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
      12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
      12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
      12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
      12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
      12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
      12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
      12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
      12, 12, 12, 12, 12, 12, 12, 12,  0, 12,
       5, 12, 12, 12, 12, 12,  0, 12,  0, 12,
      12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
      12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
      12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
      12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
      12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
      12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
      12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
      12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
      12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
      12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
      12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
      12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
      12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
      12, 12, 12, 12, 12, 12
    };
  return len + asso_values[(unsigned char)str[2]];
}

#ifdef __GNUC__
__inline
#if defined __GNUC_STDC_INLINE__ || defined __GNUC_GNU_INLINE__
__attribute__ ((__gnu_inline__))
#endif
#endif
const struct ErisSpecial *
eris_special_lookup (register const char *str, register unsigned int len)
{
  enum
    {
      TOTAL_KEYWORDS = 4,
      MIN_WORD_LENGTH = 6,
      MAX_WORD_LENGTH = 9,
      MIN_HASH_VALUE = 6,
      MAX_HASH_VALUE = 11
    };

  static const struct ErisSpecial wordlist[] =
    {
      {""}, {""}, {""}, {""}, {""}, {""},
#line 15 "specials.gperf"
      {"__type", ERIS_SPECIAL_TYPE},
#line 16 "specials.gperf"
      {"__value", ERIS_SPECIAL_VALUE},
      {""},
#line 17 "specials.gperf"
      {"__library", ERIS_SPECIAL_LIBRARY},
      {""},
#line 14 "specials.gperf"
      {"__name", ERIS_SPECIAL_NAME}
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      register int key = eris_special_hash (str, len);

      if (key <= MAX_HASH_VALUE && key >= 0)
        {
          register const char *s = wordlist[key].name;

          if (*str == *s && !strncmp (str + 1, s + 1, len - 1) && s[len] == '\0')
            return &wordlist[key];
        }
    }
  return 0;
}