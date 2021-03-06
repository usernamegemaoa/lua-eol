#! /usr/bin/env lua
--
-- libtest-lookup-function.lua
-- Copyright (C) 2015 Adrian Perez <aperez@igalia.com>
--
-- Distributed under terms of the MIT license.
--

local libtest = require("eol").load("libtest")
assert(libtest, "could not load libtest.so")

local add = libtest.add
assert.Not.Nil(add)
assert.Userdata(add, "org.perezdecastro.eol.Function")
assert.Callable(add)
assert.Equal(libtest, add.__library)
