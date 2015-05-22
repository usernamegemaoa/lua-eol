#! /usr/bin/env lua
--
-- gc-library-before-varfunc.lua
-- Copyright (C) 2015 Adrian Perez <aperez@igalia.com>
--
-- Distributed under terms of the MIT license.
--

local libtest = require("eris").load("libtest")
assert.Not.Nil(libtest)

local variable = libtest.intvar

-- Force early collection of the library
libtest = nil
collectgarbage()

-- This should work and not crash.
assert.Equal(42, variable:get())
variable = nil
collectgarbage()