#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../include/token_struct.h"
#include "../include/token_analysis.h"
#include "../include/read_arabica.h"

void read_arabica(char* path){

    if (strstr(path, ".abc"))
    {
        FILE* file_arabe = fopen(path, "r");
        if (file_arabe == NULL)
        {
            printf("Arabica is missing !");
            exit(0);
        }
            fseek(file_arabe, 0, SEEK_END);
            long file_size = ftell(file_arabe);
            fseek(file_arabe, 0, SEEK_SET);
            char* file_content = malloc(sizeof(char) * file_size);
            fputs(file_content, file_arabe);
            char c;
            int i = 0;
            while ((c = fgetc(file_arabe)) != EOF)
            {
                file_content[i] = c;
                i++;
            }
            printf(file_content);
            printf("tedt");
    }
    else
    {
        printf("File is not Arabica !");
        exit(0);
    }
    
    
}
