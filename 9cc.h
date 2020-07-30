#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
// tokenize.c
//

// Token
typedef enum {
  TK_RESERVED,
  TK_NUM,
  TK_EOF,
} TokenKind;

// Token type
typedef struct Token Token;
struct Token {
  TokenKind kind; // トークンの型
  Token *next;    // 次の入力トークン
  int val;        // kindがTK_NUMの場合、その数値
  char *str;      // トークン文字列
  int len;        // トークンの長さ
};

extern char *user_input;
extern Token *token;

Token *tokenize(void);

//
// parse.c
//

// AST node
typedef enum {
  ND_ADD, // +
  ND_SUB, // -
  ND_MUL, // *
  ND_DIV, // /
  ND_EQ,  // ==
  ND_NE,  // !=
  ND_LT,  // <
  ND_LE,  // <=
  ND_NUM, // 整数
} NodeKind;

// ?~J?象?~K?~V~G?~\??~A??~C~N?~C??~C~I?~A??~^
typedef struct Node Node;
struct Node {
  NodeKind kind; // ?~C~N?~C??~C~I?~A??~^~K
  Node *lhs;     // 左辺
  Node *rhs;     // ?~O?辺
  int val;       //kind?~A~LND_NUM?~A??| ??~P~H?~A??~A?使?~A~F
};

Node *expr();

// codegen.c
void gen(Node *node);

// utility
void error(char *fmt, ...);
