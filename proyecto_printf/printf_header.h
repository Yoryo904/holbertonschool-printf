#ifndef _PRINTF_HEADER_H_
#define _PRINTF_HEADER_H_
/*Libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define BUFFER_SIZE 1024  /* Definir un tamano de buffer adecuado*/
/*Structs*/

/**
 * 
 * struct char_function_struct - recives a character and a pointer to function
 * @char: the character that identifies the type of data to print.
 * @function: the pointer to function that handles the printing
 *
 * Description: char_function_struct - This struct associates a character
 * with a corresponding function that takes a variadic list, a string, 
 * and a pointer to an integer for output.
 */
typedef struct char_function_struct
{
  char character;
  void (*function)(va_list arguments, char *arrayBuffer, int *arrayBuff_len);
} char_function_struct_t;
/*Prototypes*/

int _strlen(const char *s);
int _printf(const char *format,...);
void print_string(va_list arguments, char *arrayBuffer, int *arrayBuff_len);
void print_char(va_list arguments, char *arrayBuffer, int *arrayBuff_len);
void print_digitinteger(va_list arguments, char *arrayBuffer, int *arrayBuff_len);

#endif
