#include <stdio.h>
#include <string.h>

#include "headers/token_struct.h"

int main(void) {
    char* token_str = "STR_CMP";
    int i = 0;
    while(TOKENS_STRS[i] != NULL) {
        if(strcmp(token_str, TOKENS_STRS[i]) == 0) {
            Token myToken;
            myToken.index = i + 1;
            myToken.value = token_str;
            myToken.type = KWD;

            printf("%x : %s\n", myToken.index, myToken.value);
        }
        i++;
    }
}