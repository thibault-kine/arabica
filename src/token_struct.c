#include "token_struct.h"
#include <stdlib.h>

char *type_to_string(TokenType type)
{
    switch (type)
    {
    case KWD:
        return "KWD";
    case LIT:
        return "LIT";
    case BRK:
        return "BRK";
    default:
        return "UNKNOWN";
    }
}

const char **get_token_table()
{
    // char** table = malloc(sizeof(char*) * 28);

    // table[0] = "LOAD_VAL";
    // table[1] = "READ_VAR";
    // table[2] = "STORE_VAR";
    // table[3] = "ADD";
    // table[4] = "SUB";
    // table[5] = "MUL";
    // table[6] = "DIV";
    // table[7] = "MOD";
    // table[8] = "JMP";
    // table[9] = "JMP_IF_ZERO";
    // table[10] = "JMP_IF_TRUE";
    // table[11] = "EQ";
    // table[12] = "NEQ";
    // table[13] = "GT";
    // table[14] = "LT";
    // table[15] = "GTE";
    // table[16] = "LTE";
    // table[17] = "PRINT_VAL";
    // table[18] = "INPUT_VAL";
    // table[19] = "HALT";
    // table[20] = "LOAD_STR";
    // table[21] = "PRINT_STR";
    // table[22] = "INPUT_STR";
    // table[23] = "STR_LEN";
    // table[24] = "CONCAT";
    // table[25] = "GET_CHAR";
    // table[26] = "SET_CHAR";
    // table[27] = "STR_CMP";
    static const char *table[] = {
        "LOAD_VAL",
        "READ_VAR",
        "STORE_VAR",
        "ADD", "SUB", "MUL", "DIV", "MOD",
        "JMP", "JMP_IF_ZERO", "JMP_IF_TRUE",
        "EQ", "NEQ",
        "GT", "LT", "GTE", "LTE",
        "PRINT_VAL",
        "INPUT_VAL",
        "HALT",
        "LOAD_STR",
        "PRINT_STR", "INPUT_STR", "STR_LEN",
        "CONCAT",
        "GET_CHAR",
        "SET_CHAR",
        "STR_CMP"};
    return table;
}