#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "token_struct.h"
#include "token_analysis.h"
#include "utils.h"

TokenType get_token_type(char *token)
{
  if (token[0] >= 'A' && token[0] <= 'Z')
  {
    return KWD;
  }
  else if (token[0] == '\"' || (token[0] >= '0' && token[0] <= '9'))
  {
    return LIT;
  }
  else if (token[0] == '\n')
  {
    return BRK;
  }
  else
  {
    printf("Cannot detect token type: %s\n", token);
    exit(0);
  }
}

long int get_token_index(char *token)
{

  if (get_token_type(token) == BRK)
  {
    return 13;
  }
  if (get_token_type(token) == KWD)
  {
    int i = 0;
    while (get_token_table()[i] != NULL)
    {
      // Si c'est un token Arabica, on renvoie son index (relatif à la table de tokens)
      if (strcmp(token, get_token_table()[i]) == 0)
      {
        return i + 1;
      }

      // Todo: Si c'est un litteral ou un \n, on devra renvoyer une liste d'int (un pour chaque char)
      i++;
    }
  }
  if (get_token_type(token) == LIT)
  {
  }

  return -1;
}