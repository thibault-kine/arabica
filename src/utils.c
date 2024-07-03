#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "utils.h"

char **split_file_content(FILE *file)
{
  char c;
  char word[32];
  char **words = malloc(sizeof(char *) * 100);
  int word_count = 0;
  int word_index = 0;
  int inside_quotes = 0; // bool

  if (words == NULL)
  {
    fprintf(stderr, "Erreur d'allocation mémoire.\n");
    exit(EXIT_FAILURE);
  }

  while ((c = fgetc(file)) != EOF)
  {
    if (c == '"')
    {
      inside_quotes = !inside_quotes;
    }

    if ((c == ' ' || c == '\t' || c == '\n') && !inside_quotes)
    {
      if (word_index > 0)
      {
        word[word_index] = '\0';
        words[word_count] = strdup(word);
        if (words[word_count] == NULL)
        {
          fprintf(stderr, "Erreur d'allocation mémoire.\n");
          exit(EXIT_FAILURE);
        }
        word_count++;
        word_index = 0;
      }
      if (c == '\n')
      {
        words[word_count] = strdup("\n");
        if (words[word_count] == NULL)
        {
          fprintf(stderr, "Erreur d'allocation mémoire.\n");
          exit(EXIT_FAILURE);
        }
        word_count++;
      }
    }
    else
    {
      word[word_index] = c;
      word_index++;
      if (word_index >= 32)
      {
        fprintf(stderr, "Mot trop long\n");
        exit(EXIT_FAILURE);
      }
    }
  }

  if (word_index > 0)
  {
    word[word_index] = '\0';
    words[word_count] = strdup(word);
    if (words[word_count] == NULL)
    {
      fprintf(stderr, "Erreur d'allocation mémoire.\n");
      exit(EXIT_FAILURE);
    }
    word_count++;
  }

  // Libérez toutes les mémoires allouées avant de retourner
  for (int i = 0; i < word_count; i++)
  {
    free(words[i]);
  }
  free(words); // Libérer le tableau des mots

  return words;
}

char *concat_int(int *integers, int size)
{
  char *res = (char *)malloc((size * 12 + 1) * sizeof(char));
  res[0] = '\0';

  for (int i = 0; i < size; i++)
  {
    char temp[12];
    sprintf(temp, "%d", integers[i]);
    strcat(res, temp);
  }

  return res;
}

char *itoa(int n)
{
  char *str = malloc(sizeof(char) * 12);
  int i = 0;

  if (n == 0)
  {
    str[i++] = '0';
  }
  else
  {
    int is_negative = 0;
    if (n < 0)
    {
      is_negative = 1;
      n = -n;
    }

    while (n != 0)
    {
      int digit = n % 10;
      str[i++] = digit + '0';
      n /= 10;
    }

    if (is_negative)
    {
      str[i++] = '-';
    }
  }

  str[i] = '\0';

  // Inverser la chaîne
  for (int j = 0; j < i / 2; j++)
  {
    char temp = str[j];
    str[j] = str[i - j - 1];
    str[i - j - 1] = temp;
  }

  return str;
}

int ft_in_seperator(char c, char *charset)
{
  int i;

  i = 0;
  while (*(charset + i))
  {
    if (*(charset + i) == c)
      return (1);
    i++;
  }
  return (0);
}

int count_words(char *str, char *charset)
{
  int count;

  count = 0;
  while (*str)
  {
    while (*str && ft_in_seperator(*str, charset))
      str++;
    if (*str && !ft_in_seperator(*str, charset))
    {
      count++;
      while (*str && !ft_in_seperator(*str, charset))
        str++;
    }
  }
  return (count);
}

char *alloc_word(char *str, char *charset)
{
  char *word;
  int i;

  i = 0;
  while (*(str + i) && !ft_in_seperator(*(str + i), charset))
    i++;
  if (!(word = (char *)malloc(sizeof(char) * (i + 1))))
    return (NULL);
  i = 0;
  while (*(str + i) && !ft_in_seperator(*(str + i), charset))
  {
    *(word + i) = *(str + i);
    i++;
  }
  *(word + i) = '\0';
  return (word);
}

char **split(char *str, char *charset)
{
  char **words;
  int count;
  int size;
  int j;

  size = count_words(str, charset);
  if (!(words = (char **)malloc(sizeof(char *) * (size + 1))))
    return (NULL);
  count = 0;
  j = 0;
  while (*(str + j))
  {
    while (*(str + j) && ft_in_seperator(*(str + j), charset))
      j++;
    if (*(str + j) && !ft_in_seperator(*(str + j), charset))
    {
      if (!(words[count] = alloc_word((str + j), charset)))
        return (NULL);
      count++;
      while (*(str + j) && !ft_in_seperator(*(str + j), charset))
        str++;
    }
  }
  words[count] = NULL;
  return (words);
}
