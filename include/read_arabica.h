#ifndef READ_ARABICA_H
#define READ_ARABICA_H

#include "token_struct.h"

#include <stdint.h>

/**
 * Reads the content of an Arabica file and returns the list of tokens found in it
 * @param path the file path
*/
Token* read_arabica(char* path);

/**
 * Writes the binary file
 * @param tokens the token list
*/
void write_file(char** tokens);

uint32_t reverse_endianness(uint32_t value);

void write_header(FILE* f, int size);

int get_file_size(FILE* f);

#endif