#include "../include/token_struct.h"

const char *TOKEN_TABLE[28] = {
    "LOAD_VAL",
    "READ_VAR",
    "STORE_VAR",
    "ADD", "SUB", "MUL", "DIV", "MOD",
    "JMP", "JMP_IF_ZERO", "JMP_IF_TRUE",
    "EQ", "NEQ",
    "GT", "LT", "GTE", "LTE",
    "PRINT_VAL",
    "INPUT_VAL",
    "HALT",
    "LOAD_STR",
    "PRINT_STR", "INPUT_STR", "STR_LEN",
    "CONCAT",
    "GET_CHAR",
    "SET_CHAR",
    "STR_CMP"
};
