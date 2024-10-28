#include "printf_header.h"

/**
 * print_string - Concatenates and saves a variadic list to a buffer
 * and receives the length of the buffer.
 * @arguments: The variadic list.
 * @arrayBuffer: The buffer.
 * @arrayBuff_len: The buffer's length.
 *
 */
void print_string(va_list arguments, char *arrayBuffer, int *arrayBuff_len)
{
  int i = 0;
  char *argument = va_arg(arguments, char *); 

  /* Verificar si el argumento es NULL*/
  if (argument == NULL)
    {
      char *null_str = "(null)";
      while (null_str[i])
	{
	  if (*arrayBuff_len < BUFFER_SIZE - 1)  /* comprobar buffer*/
	    {
	      arrayBuffer[*arrayBuff_len] = null_str[i];
	      (*arrayBuff_len)++;
	    }
	  i++;
	}
      return;
    }

  /* Copiar la cadena al buffer*/
  for (i = 0; argument[i]; i++)
    {
      if (*arrayBuff_len < BUFFER_SIZE - 1) 
	{
	  arrayBuffer[*arrayBuff_len] = argument[i];
	  (*arrayBuff_len)++;
	}
    }
  arrayBuffer[*arrayBuff_len] = '\0'; 
}
