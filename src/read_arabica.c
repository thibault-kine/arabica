#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../include/token_struct.h"
#include "../include/token_analysis.h"

Token* read_arabica(char* path){

    if (strstr(path, ".abc"))
    {
        FILE* file_arabe = fopen(path, "r");
        if (file_arabe == NULL)
        {
            printf("Arabica is missing !");
            exit(0);
        }
        
    }
    else
    {
        printf("File is not Arabica !");
        exit(0);
    }
    
    
}
