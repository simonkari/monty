#include "monty.h"

/**
 * _size_line - Calculates the size of a line.
 * @line: line to read
 * Return: The size of the line.
 */
int _size_line(char *line)
{
unsigned int con = 0;

while (line[con])
{
con++;
}
return (con);
}
