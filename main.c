#include "monty.h"
globals_t global;
/**
 * main - The main entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 * Return: An integer representing the exit status of the program.
 */
#include "monty.h"
globals_t global;

/**
 * main - main function
 * @argc: number of the arguments
 * @argv: argument
 * Return: Always 0
 */
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fputs("USAGE: monty file\n", stderr);
        return EXIT_FAILURE;
    }

    global.fil = fopen(argv[1], "r");
    if (global.fil == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    global.line = NULL;
    size_t numbytes = 0;
    ssize_t bytesr;
    unsigned int con = 1;
    stack_t *stack = NULL;

    while ((bytesr = getline(&global.line, &numbytes, global.fil)) != -1)
    {
        delete_jump(global.line);

        if (global.line[0] != '#')
        {
            global.token = strtok(global.line, " \t\n");
            global.opco = global.token;

            if (global.opco != NULL)
            {
                global.token = strtok(NULL, " \t\n");
                void (*op_func)(stack_t **, unsigned int) = func(global.opco);
                if (op_func != NULL)
                    op_func(&stack, con);
                else
                {
                    fprintf(stderr, "L%u: unknown instruction %s\n", con, global.opco);
                    free(global.line);
                    fclose(global.fil);
                    free_l(&stack);
                    return EXIT_FAILURE;
                }
            }
            con++;
        }
    }

    free_l(&stack);
    free(global.line);
    fclose(global.fil);

    return EXIT_SUCCESS;
}