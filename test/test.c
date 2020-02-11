#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include <stdio.h>
#include <sys/errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>


void error(lua_State *L, const char *fmt, ...) {
	va_list argp;
	va_start(argp, fmt);
	vfprintf(stderr, fmt, argp);
	va_end(argp);
	lua_close(L);
	lua_close(L);
	exit(EXIT_FAILURE);
}


static void stackDump(lua_State *L) {
	int top = lua_gettop(L);
	for (int i = 1; i <= top; i++) {
		int t = lua_type(L, i);
		switch (t) {
			case LUA_TSTRING: {
				printf("'%s'", lua_tostring(L, i));
				break;
			}
			case LUA_TBOOLEAN: {
				printf(lua_toboolean(L, i) ? "true" : "false");
				break;
			}
			case LUA_TNUMBER: {
				printf("%g", lua_tonumber(L, i));
				break;
			}
			default:
				printf("%s", lua_typename(L, t));
				break;
		}
		printf(" ");
	}
	printf("\n");
}

int main(int argc, char *argv[]) {

	char *file = NULL;
	if (argc == 1) {
		file = "my.lua";
	} else {
		file = argv[1];
	}

	lua_State *L = lua_open();
	luaL_openlibs(L);
	int result = luaL_dofile(L, file);
	if (result != 0) {
		fprintf(stderr, "load file fail %d\n", result);
		printf("%s\n", strerror(errno));
		char name[128];
		getcwd(name, sizeof(name));
		printf("current dir:%s\n", name);
	}
	return 0;
}
