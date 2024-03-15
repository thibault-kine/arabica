#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "token_struct.h"
#include "token_analysis.h"
#include "read_arabica.h"
#include "utils.h"

Token* read_arabica(char* path){

    // si la string contient bien une extension ".abc"
    if (strstr(path, ".abc"))
    {
        FILE* file_arabe = fopen(path, "r");
        if (file_arabe == NULL)
        {
            printf("%s is missing !", path);
            exit(0);
        }

        Token* result = malloc(sizeof(Token) * 100);
        char** token_list = split_file_content(file_arabe);
        int i = 0;
        // Boucle à travers la liste vide de tokens et la
        while(token_list[i] != NULL) {
            result[i].value = token_list[i];
            result[i].type = get_token_type(result[i].value);
            result[i].index = i + 1;

            printf(
                "Token:\nid = %x\ntype: %s\nvalue: %s\n\n", 
                result[i].index, 
                type_to_string(result[i].type),
                result[i].value
            );
            i++;
        }

        fclose(file_arabe);

        return result;
    }
    else
    {
        printf("File is not Arabica !");
        exit(0);
    }
}
