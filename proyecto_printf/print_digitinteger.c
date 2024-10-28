#include <stdio.h>
#include <stdlib.h>
#include "printf_header.h"
#include <stdarg.h>

/**
 * print_digitinteger - Extracts an integer from the argument list
 *                      and stores it as a string in the provided buffer.
 * @arguments: The list of arguments containing the integer.
 * @arrayBuffer: The buffer where the integer string will be stored.
 * @arrayBuff_len: A pointer to the length of the buffer.
 *
 * Return: void
 */

void print_digitinteger(va_list arguments, char *arrayBuffer, int *arrayBuff_len) {
  int num = va_arg(arguments, int);
  char temp[12];  /* Suficiente para el rango de un int*/
  int i = 0;
  int j = 0;

  /* Manejo del numero negativo*/
  if (num < 0)
    {
    if (*arrayBuff_len < BUFFER_SIZE - 1) {  /* Comprobar el buffer*/
      arrayBuffer[(*arrayBuff_len)++] = '-';
    }
    num = -num;
  } else if (num == 0) {
    /* Si el numero es 0,simplemente lo agrego al buffer*/
    if (*arrayBuff_len < BUFFER_SIZE - 1) {
      arrayBuffer[(*arrayBuff_len)++] = '0';
    }
    return;  /* Salir ya que no hay mas digitos*/
  }

    /* Convertir el numero a string en reversa*/
    do {
      temp[i++] = (num % 10) + '0';
      num /= 10;
    } while (num > 0);

    /* Agregar los digitos al buffer en el orden correcto*/
    for (j = i - 1; j >= 0; j--) {
      if (*arrayBuff_len < BUFFER_SIZE - 1) {  /* Comprobar el buffer*/
	arrayBuffer[(*arrayBuff_len)++] = temp[j];
      }
    }
    /* Asegurarse de que el buffer este terminado en nulo*/
    arrayBuffer[*arrayBuff_len] = '\0'; 
}
