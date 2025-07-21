#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <fully_qualified_path_to_an_input_file> <fully_qualified_path_to_output_file>\n", argv[0]);
        return 1;
    }

    char *input_filename = argv[1];
    char *output_filename = argv[2];

    FILE *input_file = fopen(input_filename, "r");
    if (input_file == NULL)
    {
        perror("Error opening input file");
        return 1;
    }

    int opcode;
    // Read opcode from input file
    if (fscanf(input_file, "%d", &opcode) != 1)
    {
        printf("Error reading opcode from input file.\n");
        fclose(input_file);
        return 1;
    }

    fclose(input_file);

    char *program_name;
    char command[256];
    int ret;
    switch (opcode)
    {
    case 1:
        program_name = "python.py";
        snprintf(command, sizeof(command), "python3 %s %s %s", program_name, input_filename, output_filename);
        ret = system(command);
        if (ret != 0)
        {
            printf("Error executing command: %s\n", command);
            return 1;
        }
        break;
    case 2:
        program_name = "MatrixMultiplier.java";
        snprintf(command, sizeof(command), "javac %s", program_name);
        ret = system(command);
        if (ret != 0)
        {
            printf("Error executing command: %s\n", command);
            return 1;
        }
        program_name = "MatrixMultiplier";
        snprintf(command, sizeof(command), "java %s %s %s", program_name, input_filename, output_filename);
        ret = system(command);
        if (ret != 0)
        {
            printf("Error executing command: %s\n", command);
            return 1;
        }
        break;
    case 3:
        program_name = "cprogram.c";
        snprintf(command, sizeof(command), "gcc %s -o cprogram -lgmp", program_name);
        ret = system(command);
        if (ret != 0)
        {
            printf("Error executing command: %s\n", command);
            return 1;
        }
        program_name = "cprogram";
        snprintf(command, sizeof(command), "./%s %s %s", program_name, input_filename, output_filename);
        ret = system(command);
        if (ret != 0)
        {
            printf("Error executing command: %s\n", command);
            return 1;
        }
        break;
    case 5:
        program_name = "cThread.c";
        snprintf(command, sizeof(command), "gcc %s -o cThread -lpthread -lgmp", program_name);
        ret = system(command);
        if (ret != 0)
        {
            printf("Error executing command: %s\n", command);
            return 1;
        }
        program_name = "cThread";
        snprintf(command, sizeof(command), "./%s %s %s", program_name, input_filename, output_filename);
        ret = system(command);
        if (ret != 0)
        {
            printf("Error executing command: %s\n", command);
            return 1;
        }
        break;
    default:
        printf("Invalid opcode.\n");
        return 1;
    }

    program_name = "graph.py";
    snprintf(command, sizeof(command), "python3 %s", program_name);
    ret = system(command);
    if (ret != 0)
    {
        printf("Error executing command: %s\n", command);
        return 1;
    }

    return 0;
}
