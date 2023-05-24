#include "monty.h"

/**
 * func - Takes arguments and returns a function pointer.
 * @tokens: arguments
 * Return: A function pointer.
 */

void (*func(char *tokens))(stack_t **stack, unsigned int num_line)
{
    static const struct {
        const char *opcode;
        void (*func)(stack_t **stack, unsigned int num_line);
    } ops[] = {
        {"push", _push},
        {"pall", _pall},
        {"pint", _pint},
        {"pop", _pop},
        {"swap", _swap},
        {"add", _add},
        {"nop", _nop},
        {"sub", _sub},
        {"div", _div},
        {"mul", _mul},
        {"mod", _mod},
        {"pchar", _pchar},
        {"pstr", _pstr},
        {"rotl", _rotl},
        {"rotr", _rotr},
        {"stack", _stack},
        {"queue", _queue},
        {"err", _error},
        {"#", _nop},
        {NULL, NULL}
    };

    for (int i = 0; ops[i].opcode != NULL; i++)
    {
        if (strcmp(ops[i].opcode, tokens) == 0)
            return ops[i].func;
    }

    return ops[17].func;
}
