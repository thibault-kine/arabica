#include <stdio.h>
#include <string.h>

#include "../include/token_struct.h"
#include "../include/token_analysis.h"

TokenType get_token_type(char* token){
    if (token[0] >= 65 && token[0] <= 90)
    {
        return KWD;
    }
    else if (token[0] == '\"' || (token[0] >= 48 && token[0] <= 57))
    {
        return LIT;
    }
    else if (token[0] == '\n')
    {
        return BRK;
    }
    else
    {
        printf("Cannot detect tokentype");
        return -1;
    }    
}