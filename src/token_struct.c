#include "token_struct.h"
#include <stdlib.h>

char *type_to_string(TokenType type)
{
  switch (type)
  {
  case KWD:
    return "KWD";
  case LIT:
    return "LIT";
  case BRK:
    return "BRK";
  default:
    return "UNKNOWN";
  }
}

const char **get_token_table()
{
  static const char *table[] = {
      "LOAD_VAL",
      "READ_VAR",
      "STORE_VAR",
      "ADD",
      "SUB",
      "MUL",
      "DIV",
      "MOD",
      "JMP",
      "JMP_IF_ZERO",
      "JMP_IF_TRUE",
      "EQ",
      "NEQ",
      "GT",
      "LT",
      "GTE",
      "LTE",
      "PRINT_VAL",
      "INPUT_VAL",
      "HALT",
      "LOAD_STR",
      "PRINT_STR",
      "INPUT_STR",
      "STR_LEN",
      "CONCAT",
      "GET_CHAR",
      "SET_CHAR",
      "STR_CMP",
      NULL};
  return table;
}