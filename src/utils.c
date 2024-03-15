#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "utils.h"

char** split_file_content(FILE *file) {
    char c;
    char word[32];
    char** words = malloc(sizeof(char*) * 100);
    int word_count = 0;
    int word_index = 0;
    int inside_quotes = 0; // bool

    while ((c = fgetc(file)) != EOF)
    {
        // if(c == '\n') {
        //     word[word_index] = '\0';
        //     words[word_count] = strdup(word);
        //     word_count++;
        //     word_index = 0;
        // } 
        if (c == '"') {
            inside_quotes = !inside_quotes;
        }

        if ((c == ' ' || c == '\t' || c == '\n') && !inside_quotes) {
            if (word_index > 0)
            {
                word[word_index] = '\0';
                words[word_count] = strdup(word);
                word_count++;
                word_index = 0;
            }
            if(c == '\n') {
                words[word_count] = strdup("\n");
                word_count++;
            }
        } else {
            word[word_index] = c;
            word_index++;
            if (word_index > 100)
            {
                fprintf(stderr, "Word too long\n");
                exit(0);
            }
        }
    }

    if (word_index > 0)
    {
        word[word_index] = '\0';
        words[word_count] = strdup(word);
        word_count++;
    }

    for (int i = 0; i < word_count; i++)
    {
        free(words[i]);
    }

    return words;
}