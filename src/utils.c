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

// Pour activer les messages de debug, décommentez la ligne suivante:
// #define DEBUG
// ou compiler avec la commande suivante:
// gcc -DDEBUG split.c

int is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
	// Si c'est un espace, une tabulation,
	// un saut de page, un retour chariot ou un retour à la ligne
		return (1);
	return (0);
}

int count_letters(char *str, int i)
 // i est la position du premier caractere d'un mot dans la chaine
{
	int count;

	count = 0;										// Compteur de caractères
	while (str[i] != '\0' && is_space(str[i]) == 0) // Tant qu'on est pas à la fin de la chaîne et qu'on est pas sur un espace
	{
		count++; // On incrémente le compteur de caractères
		i++;
	}
    
	return (count);
}

int count_words(char *str)
{
	int i;
	int count;

	i = 0;				   // Compteur de caractères
	count = 0;			   // Compteur de mots
	while (str[i] != '\0') // Tant qu'on est pas à la fin de la chaîne
	{
		if (is_space(str[i]) == 0) // Si on est pas sur un espace
		{
			count++;										// On incrémente le compteur de mots
			while (str[i] != '\0' && is_space(str[i]) == 0) // Tant qu'on est pas à la fin de la chaîne
															// et qu'on est pas sur un espace
				i++;										// On incrémente le compteur de caractères
		}
		else
			i++; // On passe au caractère suivant
	}

	return (count);
}

char **split(char *str) {

	char **tab;
	int i;
	int j;
	int k;

	i = 0;															// i parcourt la chaîne de caractères
	j = 0;															// j parcourt le tableau de pointeurs
	k = 0;															// k parcourt la chaîne de caractères de destination
	tab = (char **)malloc(sizeof(char *) * (count_words(str) + 1)); // Allocation du tableau de pointeurs, +1 pour le NULL

	while (str[i] != '\0') // Tant qu'on est pas à la fin de la chaîne
	{
		if (is_space(str[i]) == 0) // Si on est pas sur un espace
		{
			tab[j] = (char *)malloc(sizeof(char) * (count_letters(str, i) + 1)); // Allocation de la chaîne de caractères, +1 pour le '\0'

			while (str[i] != '\0' && is_space(str[i]) == 0) // Tant qu'on est pas à la fin de la chaîne et qu'on est pas sur un espace
				tab[j][k++] = str[i++];						// On copie le caractère et on incrémente i et k
			tab[j][k] = '\0';								// On termine la chaîne de caractères

			j++;   // On incrémente j pour passer à la chaîne suivante
			k = 0; // On remet k à 0 pour la chaîne suivante
		}
		else
			i++; // On incrémente i pour passer au caractère suivant
	}
	tab[j] = NULL; // On termine le tableau de pointeurs
	return (tab);  // On retourne le tableau de pointeurs
}