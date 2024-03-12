#ifndef TOKEN_STRUCT_H
#define TOKEN_STRUCT_H

/**
 * @param KWD Keyword (ex: PRINT_STR, LOAD_VAL, ...)
 * @param LIT Litteral (ex: "Hello world", 42, true, ...)
 * @param BRK Line break (\\n)
*/
typedef enum t_token_type {
    KWD,    
    LIT,    
    BRK,    
} TokenType;

/**
 * @param index The index according to the documentation
 * @param type Type from the TokenType enum
 * @param value Token value as a string
*/
typedef struct t_token {
    int index;
    TokenType type; 
    char* value;
} Token;

const char* TOKENS_STRS[] = {
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

#endif