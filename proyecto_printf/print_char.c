#include "printf_header.h"

/**
 * print_char - Extracts a character from the argument list and
 *               stores it in the provided buffer.
 * @arguments: The list of arguments containing the character.
 * @arrayBuffer: The buffer where the character will be stored.
 * @arrayBuff_len: A pointer to the length of the buffer.
 *
 * Return: void
 */

void print_char(va_list arguments, char *arrayBuffer, int *arrayBuff_len)
{
  char c = (char)va_arg(arguments, int);  /* Extraer el caracter como un int*/
  if (*arrayBuff_len < BUFFER_SIZE - 1)  /* Asegurarse de que no exceda el tamano del buffer*/
    {
      arrayBuffer[*arrayBuff_len] = c;  /* Almacenar el caracter*/
      (*arrayBuff_len)++;
    }
  arrayBuffer[*arrayBuff_len] = '\0';  /* Terminar la cadena*/
}
