#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * string_nconcat - allocates memory then concatenates the content of
 * two parameter strings in it takes only n characters of the second string
 * @s1: string one
 * @s2: string two
 * @n: number of characters of s2 we add to s1 in our resulting string
 *
 * Return: Returns a pointer to the created string
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *str;
	char *concat;
	unsigned int i;
	unsigned int s1len;
	unsigned int s2len;

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}
	s1len = _strlen(s1);
	s2len = _strlen(s2);
	concat = str_concat(s1, s2);
	if (n < s2len)
	{
		str = malloc((s1len + n + 1) * sizeof(char));
		for (i = 0; i <= s1len + n; i++)
		{
			if (i == s1len + n)
			{
				str[i] = '\0';
			}
			str[i] = concat[i];
		}
		free(concat);
		return (str);
	}
	return (concat);
}

/**
 * _strlen - counts the elements of a string
 * @s: a string we want to count the elements of
 *
 * Return: Returns strilen the value
 * containing the counted string elements
 */
int _strlen(char *s)
{
	int i;
	int strilen = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		strilen++;
	}
	return (strilen);
}

/**
 * str_concat - takes two strings allocates memory to contain both
 * and creates a string containing both entries
 * @s1: String 1
 * @s2: String 2
 *
 * Return: Returns a pointer to the new string containing bith entries
 * or NULL if malloc fails
 */
char *str_concat(char *s1, char *s2)
{
	unsigned int s1len;
	unsigned int s2len;
	unsigned int i;
	unsigned int j = 0;
	char *ar;

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}
	s1len = _strlen(s1);
	s2len = _strlen(s2) + 1;
	ar = malloc((s1len + s2len) * sizeof(char));
	if (ar == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < s1len; i++)
	{
		ar[i] = s1[i];
	}
	for (i = s1len; i < (s1len + s2len); i++)
	{
		ar[i] = s2[j];
		j++;
	}
	return (ar);
}
