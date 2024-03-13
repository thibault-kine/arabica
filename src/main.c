#include <stdio.h>
#include <string.h>

#include "../include/token_struct.h"
#include "../include/token_analysis.h"

int main(void) {
    char* token_str = "STR_CMP";
    int i = 0;
    while(TOKEN_TABLE[i] != NULL) {
        if(strcmp(token_str, TOKEN_TABLE[i]) == 0) {
            Token myToken;
            myToken.index = i + 1;
            myToken.value = token_str;
            myToken.type = get_token_type(myToken.value);

            printf("Token:\nid = %x\ntype: %d\nvalue: %s\n", myToken.index, myToken.type, myToken.value);
        }
        i++;
    }
}