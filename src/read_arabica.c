#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <endian.h>

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
    // printf("%d", token_list[1][0]);
    while (token_list[i] != NULL)
    {
      // printf("%s\n", token_list[i]);
      token[i].value = token_list[i];
      token[i].type = get_token_type(token[i].value);
      token[i].index = get_token_index(token[i].value);

      printf("id: %02X | value: %s\n", token[i].index, token[i].value);
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

    for (int i = 0; token_list[i] != NULL; i++)
    {
      free(token_list[i]);
    }
    free(token_list);

    return result;
  }
  else
  {
    printf("File is not Arabica !");
    exit(0);
  }
}

uint32_t reverse_endianness(uint32_t value)
{
  uint32_t byte0 = (value & 0x000000FF) << 24;
  uint32_t byte1 = (value & 0x0000FF00) << 8;
  uint32_t byte2 = (value & 0x00FF0000) >> 8;
  uint32_t byte3 = (value & 0xFF000000) >> 24;
  return (byte0 | byte1 | byte2 | byte3);
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
    int bit_to_write = 0;

    token[i].value = tokens[i];
    token[i].type = get_token_type(token[i].value);

    if (token[i].type == LIT)
    {
      if (token[i].value[0] == 34)
      {
        int j = 1;
        while (token[i].value[j] != 34)
        {
          bit_to_write = token[i].value[j];
          fwrite(&bit_to_write, sizeof(char), 1, out);
          j++;
        }
      }
      else
      {
        token[i].index = get_token_index(token[i].value);
        bit_to_write = reverse_endianness(token[i].index);

        fwrite(&bit_to_write, sizeof(int), 1, out);
      }
    }
    else
    {
      token[i].index = get_token_index(token[i].value);
      bit_to_write = token[i].index;

      fwrite(&bit_to_write, sizeof(char), 1, out);
    }

    free(tokens[i]);
    i++;
  }

  int size = get_file_size(out);
  write_header(out, size);
  
  fclose(out);
}

void write_header(FILE *f, int size)
{
  fseek(f, 0, SEEK_SET);

  char *code_header = "CODE";
  for (int i = 0; code_header[i] != '\0'; i++)
  {
    if (fwrite(&code_header[i], sizeof(char), 1, f) != 1)
    {
      perror("Error while writing header");
      exit(1);
    }
  }

  int _size = reverse_endianness(size);

  if (fwrite(&_size, sizeof(int), 1, f) != 1)
  {
    perror("Error while writing size in header");
    exit(1);
  }
}

int get_file_size(FILE *f)
{
  fseek(f, 0, SEEK_END);
  int size = ftell(f);
  fseek(f, 0, SEEK_SET);

  return size;
}