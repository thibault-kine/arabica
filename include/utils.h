#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>
#include <stdio.h>

/**
 * Splits the string content of a file into an array of strings.
 * This method splits the whitespaces but keeps the line breaks.
 * @param file the file to read and split the content of
*/
char** split_file_content(FILE* file);

#endif