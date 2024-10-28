#include "printf_header.h"
#include <unistd.h>  /* Para la funcinnn write*/

#define BUFFER_SIZE 1024  /* Define un tamano de buffer adecuado*/

/**
 * _printf - Receives a format string and prints it with
 * desired modifications based on the variadic arguments.
 * '%s' to print a string, '%c' to print a character, '%d' 
 * to print a digit, and '%i' to print an integer.
 * @format: The format string to be modified.
 *
 * Return: The length of the formatted output string.
 */
int _printf(const char *format, ...)
{
  int i = 0, j = 0;
  char arrayBuffer[BUFFER_SIZE];
  int arrayBuff_len = 0;
  int format_len = 0;

  char_function_struct_t pointer_strct[] = {
    {'c', print_char},
    {'s', print_string},
    {'d', print_digitinteger},
    {'i', print_digitinteger},
    {'\0', NULL}
  };

  va_list arguments;

  if (format == NULL)
    return (0);

  va_start(arguments, format);
  format_len = _strlen(format);

  for (i = 0; i < format_len; i++)
    {
      if (format[i] == '%')
	{
	  i++;  /* Mover al siguiente caracter*/
	  for (j = 0; pointer_strct[j].character; j++)
	  {
	    if (format[i] == pointer_strct[j].character)
	      {
		pointer_strct[j].function(arguments, arrayBuffer, &arrayBuff_len);
		break;
	      }
	  }
	}
      else
	{
	  arrayBuffer[arrayBuff_len++] = format[i];  /* Copiar el caracter al buffer*/
        }
    }

    va_end(arguments);

    write(1, arrayBuffer, arrayBuff_len);  /* Escribe el buffer en la salida estandar*/
    return (arrayBuff_len);  
}
