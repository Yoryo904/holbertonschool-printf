#include "printf_header.h"

/**
 * _strlen - Counts the length of a string.
 * @s: The string.
 *
 * Return: The length of the string, or 0 if the string is NULL.
 */
int _strlen(const char *s)  /* Usar const para indicar que no se modifica*/
{
  int i = 0;

  if (s == NULL)  
    return 0;

  while (s[i])
    i++;
  return i;
}
