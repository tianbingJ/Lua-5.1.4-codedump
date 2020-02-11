/*
** $Id: llex.h,v 1.58.1.1 2007/12/27 13:02:25 roberto Exp $
** Lexical Analyzer
** See Copyright Notice in lua.h
*/

#ifndef llex_h
#define llex_h

#include "lobject.h"
#include "lzio.h"

// 256个字符
#define FIRST_RESERVED    257

/* maximum length of a reserved word */
#define TOKEN_LEN    (sizeof("function")/sizeof(char))


/*
* WARNING: if you change the order of this enumeration,
* grep "ORDER RESERVED"
*/
enum RESERVED {
	/* terminal symbols denoted by reserved words */
			TK_AND = FIRST_RESERVED, //and
			TK_BREAK, //break
			TK_DO,  //do
			TK_ELSE, //else
			TK_ELSEIF, //elseif
			TK_END,    //end
			TK_FALSE,  //false
			TK_FOR,   //for
			TK_FUNCTION, //function
			TK_IF,       //if
			TK_IN,      //in
			TK_LOCAL,   //local
			TK_NIL,     //nil
			TK_NOT,     //not
			TK_OR,      //or
			TK_REPEAT,  //repeat
			TK_RETURN,  //return
			TK_THEN,    //then
			TK_TRUE,    //true
			TK_UNTIL,   //until
			TK_WHILE,  //while
	/* other terminal symbols */
			TK_CONCAT,  //..
			TK_DOTS,    //...
			TK_EQ,      // "=="
			TK_GE,     //">="
			TK_LE,     //<=
			TK_NE,     //~=
			TK_NUMBER, //number
			TK_NAME,   //name
			TK_STRING, //string
			TK_EOS    //eof
};

/* number of reserved words */
#define NUM_RESERVED    (cast(int, TK_WHILE-FIRST_RESERVED+1))


/* array with token `names' */
LUAI_DATA const char *const luaX_tokens[];

// 存放数据信息：字符串或者数字
typedef union {
	lua_Number r;
	TString *ts;
} SemInfo;  /* semantics information */


typedef struct Token {
	int token;
	SemInfo seminfo;
} Token;

// 保存词法分析状态的数据结构
typedef struct LexState {
	int current;  /* current character (charint) */
	int linenumber;  /* input line counter */
	int lastline;  /* line of last token `consumed' */
	Token t;  /* current token */
	Token lookahead;  /* look ahead token */
	struct FuncState *fs;  /* `FuncState' is private to the parser */
	struct lua_State *L;
	ZIO *z;  /* input stream */
	Mbuffer *buff;  /* buffer for tokens */
	TString *source;  /* current source name */
	char decpoint;  /* locale decimal point */
} LexState;


LUAI_FUNC void luaX_init(lua_State *L);

LUAI_FUNC void luaX_setinput(lua_State *L, LexState *ls, ZIO *z,
							 TString *source);

LUAI_FUNC TString *luaX_newstring(LexState *ls, const char *str, size_t l);

LUAI_FUNC void luaX_next(LexState *ls);

LUAI_FUNC void luaX_lookahead(LexState *ls);

LUAI_FUNC void luaX_lexerror(LexState *ls, const char *msg, int token);

LUAI_FUNC void luaX_syntaxerror(LexState *ls, const char *s);

LUAI_FUNC const char *luaX_token2str(LexState *ls, int token);


#endif
