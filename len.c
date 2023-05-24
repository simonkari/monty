#include "monty.h"

/**
 * _size_line - Calculates the size of a line.
 * @line: line to read
 * Return: The size of the line.
 */
#include "monty.h"

int _size_line(char *line)
{
    int size = 0;
    char *ptr = line;

    while (*ptr++)
        size++;

    return size;
}

