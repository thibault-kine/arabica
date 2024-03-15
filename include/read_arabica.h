#ifndef READ_ARABICA_H
#define READ_ARABICA_H

#include "token_struct.h"

/**
 * Reads the content of an Arabica file and returns the list of tokens found in it
 * @param path the file path
*/
Token* read_arabica(char* path);

#endif