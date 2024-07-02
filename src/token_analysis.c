#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "token_struct.h"
#include "token_analysis.h"
#include "utils.h"

TokenType get_token_type(char *token)
{
  if (token == NULL)
  {
    fprintf(stderr, "Erreur : le pointeur de token est nul.\n");
    exit(EXIT_FAILURE);
  }

  if (token[0] >= 'A' && token[0] <= 'Z')
  {
    return KWD;
  }
  else if (token[0] == '"' || (token[0] >= '0' && token[0] <= '9'))
  {
    return LIT;
  }
  else if (token[0] == '\n')
  {
    return BRK;
  }
  else
  {
    fprintf(stderr, "Impossible de détecter le type de token : %s\n", token);
    exit(EXIT_FAILURE);
  }
}

long int get_token_index(char *token)
{
  // printf("%s", token);
  
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

      i++;
    }
  }
  if (get_token_type(token) == LIT)
  {
    // si c'est un entier
    if (token[0] >= '0' && token[0] <= '9') {
      return atoi(token);
    }

    // si c'est une string
  }

  return -1;
}