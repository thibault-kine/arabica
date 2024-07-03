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
  else if (token[0] == 34 || (token[0] >= '0' && token[0] <= '9'))
  {
    return LIT;
  }
  else if (token[0] == '\n')
  {
    return BRK;
  }
  else
  {
    perror("Erreur lors de l'analyse du type");
    return -1;
  }
}

long int get_token_index(char *token)
{
  // printf("truc %s", token);

  if (get_token_type(token) == BRK)
  {
    return 13;
  }
  else if (get_token_type(token) == KWD)
  {
    int i = 0;
    const char **table = get_token_table();
    while (table[i] != NULL)
    {
      printf("%02X %s\n", i, table[i]);
      // Si les 2 string sont identiques
      if (strcmp(token, table[i]) == 0)
      {
        return i + 1;
      }
      i++;
    }
    return -1;
  }
  else if (get_token_type(token) == LIT)
  {
    // si c'est un entier
    if (token[0] >= '0' && token[0] <= '9')
    {
      return atoi(token);
    }
  }

  return -1;
}
