#include <stdio.h>

#include "headers/token_struct.h"

int main(void) {
    Token myToken;
    myToken.type = LIT;
    myToken.value = "HELLO";

    printf("%s\n", myToken.value);
}