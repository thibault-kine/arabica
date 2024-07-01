#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "token_struct.h"
#include "token_analysis.h"
#include "read_arabica.h"
#include "utils.h"

Token *read_arabica(char *path)
{

  // si la string contient bien une extension ".abc"
  if (strstr(path, ".abc"))
  {
    FILE *file_arabe = fopen(path, "r");
    if (file_arabe == NULL)
    {
      printf("%s is missing !", path);
      exit(0);
    }

    Token *token = malloc(sizeof(Token) * 100);
    char **token_list = split_file_content(file_arabe);
    int i = 0;
    // Boucle à travers la liste vide de tokens et la remplit
    while (token_list[i] != NULL)
    {
      token[i].value = token_list[i];
      token[i].type = get_token_type(token[i].value);
      token[i].index = get_token_index(token[i].value);

      printf(
          "id: %02X\n",
          token[i].index);
      i++;
    }

    write_file(token_list);

    // Libère l'espace alloué pour les calculs
    Token *result = token;
    for (int j = 0; j < i; j++)
    {
      free(&token[j]);
    }
    free(token);
    fclose(file_arabe);

    return result;
  }
  else
  {
    printf("File is not Arabica !");
    exit(0);
  }
}

void write_file(char **tokens)
{
  FILE *out = fopen("output", "wb");
  if (out == NULL)
  {
    printf("Error: Output file could not be created");
    exit(0);
  }

  Token *token = malloc(sizeof(Token) * 100);
  int i = 0;
  while (tokens[i] != NULL)
  {
    token[i].value = tokens[i];
    token[i].type = get_token_type(token[i].value);
    token[i].index = get_token_index(token[i].value);

    fwrite(itoa(token[i].index), sizeof(char*), 1, out);

    i++;
  }

  fclose(out);
}