cmake_minimum_required(VERSION 3.15)
project(Lua_5_1_4_codedump)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -Wall -Wextra")
set(CMAKE_BUILD_TYPE Debug)


include_directories(etc)
include_directories(src)
file(COPY test/my.lua DESTINATION ${CMAKE_BINARY_DIR})

add_executable(Lua_5_1_4_codedump
#        etc/all.c
#        etc/lua.hpp
#        etc/min.c
#        etc/noparser.c
        src/lapi.c
        src/lapi.h
        src/lauxlib.c
        src/lauxlib.h
        src/lbaselib.c
        src/lcode.c
        src/lcode.h
        src/ldblib.c
        src/ldebug.c
        src/ldebug.h
        src/ldo.c
        src/ldo.h
        src/ldump.c
        src/lfunc.c
        src/lfunc.h
        src/lgc.c
        src/lgc.h
        src/linit.c
        src/liolib.c
        src/llex.c
        src/llex.h
        src/llimits.h
        src/lmathlib.c
        src/lmem.c
        src/lmem.h
        src/loadlib.c
        src/lobject.c
        src/lobject.h
        src/lopcodes.c
        src/lopcodes.h
        src/loslib.c
        src/lparser.c
        src/lparser.h
        src/lstate.c
        src/lstate.h
        src/lstring.c
        src/lstring.h
        src/lstrlib.c
        src/ltable.c
        src/ltable.h
        src/ltablib.c
        src/ltm.c
        src/ltm.h
#        src/lua.c
        src/lua.h
#        src/luac.c
        src/luaconf.h
        src/lualib.h
        src/lundump.c
        src/lundump.h
        src/lvm.c
        src/lvm.h
        src/lzio.c
        src/lzio.h
        src/print.c
        test/test.c
#        test/testusrdata.c
        )

