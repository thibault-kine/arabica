#ifndef TOKEN_ANALYSIS_H
#define TOKEN_ANALYSIS_H

#include "token_struct.h"

/**
 * Returns a TokenType according to the token's first character
 * @param token the token string
*/
TokenType get_token_type(char* token);

/**
 * Returns an int corresponding to the token's index
 * @param token the token string
*/
long int get_token_index(char* token);

#endif