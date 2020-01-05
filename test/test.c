#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include <stdio.h>
#include <sys/errno.h>
#include <string.h>
#include <unistd.h>

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
