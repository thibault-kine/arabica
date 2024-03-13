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

const char* TOKEN_TABLE[28];

#endif