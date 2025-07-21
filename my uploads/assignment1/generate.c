#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdint.h>
int n;
void generateInputFile(int opcode, int dataType, const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Error: Unable to create input file.\n");
        exit(1);
    }

    // Write opcode and matrix data type to file
    fprintf(file, "%d\n%d\n", opcode, dataType);

    // Write dimensions of the first matrix (nxn)
    fprintf(file, "%d %d\n", n, n);

    // Write first matrix data based on data type
    switch (dataType)
    {
    case 1: // 32 bit integers

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int32_t x = rand();
                fprintf(file, "%d ", x); // Generate random integer data (modify as needed)
            }
            fprintf(file, "\n");
        }
        break;
    case 2: // 32 bit floats
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                float x = (float)rand() / RAND_MAX;
                fprintf(file, "%f ", x); // Generate random float data (modify as needed)
            }
            fprintf(file, "\n");
        }
        break;
    case 3: // 64 bit integers
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int64_t x = ((int64_t)rand() << 32) | rand();
                fprintf(file, "%ld ", x); // Generate random long integer data (modify as needed)
            }
            fprintf(file, "\n");
        }
        break;
    case 4: // 64 bit doubles
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                double x = (double)rand() / RAND_MAX;
                fprintf(file, "%lf ", x); // Generate random double data (modify as needed)
            }
            fprintf(file, "\n");
        }
        break;
    default:
        printf("Error: Invalid data type.\n");
        fclose(file);
        exit(1);
    }

    // Write dimensions of the second matrix (nxn)
    fprintf(file, "%d %d\n", n, n);

    // Write second matrix data based on data type (same as first matrix for simplicity)
    switch (dataType)
    {
    case 1: // 32 bit integers
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int32_t x = rand();
                fprintf(file, "%d ", x); // Generate random integer data (modify as needed)
            }
            fprintf(file, "\n");
        }
        break;
    case 2: // 32 bit floats
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                float x = (float)rand() / RAND_MAX;
                fprintf(file, "%f ", x); // Generate random float data (modify as needed)
            }
            fprintf(file, "\n");
        }
        break;
    case 3: // 64 bit integers
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int64_t x = ((int64_t)rand() << 32) | rand();
                fprintf(file, "%ld ", x); // Generate random long integer data (modify as needed)
            }
            fprintf(file, "\n");
        }
        break;
    case 4: // 64 bit doubles
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                double x = (double)rand() / RAND_MAX;
                fprintf(file, "%lf ", x); // Generate random double data (modify as needed)
            }
            fprintf(file, "\n");
        }
        break;
    default:
        printf("Error: Invalid data type.\n");
        fclose(file);
        exit(1);
    }

    fclose(file);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <size>\n", argv[0]);
        return 1;
    }

    n = atoi(argv[1]);

    // // Generate input file for python
    // generateInputFile(1, 1, "input1.txt");
    // generateInputFile(1, 2, "input2.txt");
    // generateInputFile(1, 3, "input3.txt");
    // generateInputFile(1, 4, "input4.txt");

    // // Generate input file for Java
    // generateInputFile(2, 1, "input5.txt");
    // generateInputFile(2, 2, "input6.txt");
    // generateInputFile(2, 3, "input7.txt");
    // generateInputFile(2, 4, "input8.txt");

    // // Generate input file for C
    // generateInputFile(3, 1, "input9.txt");
    // generateInputFile(3, 2, "input10.txt");
    // generateInputFile(3, 3, "input11.txt");
    // generateInputFile(3, 4, "input12.txt");

    // // Generate input file for C pthreads
    // generateInputFile(5, 1, "input17.txt");
    // generateInputFile(5, 2, "input18.txt");
    // generateInputFile(5, 3, "input19.txt");
    // generateInputFile(5, 4, "input20.txt");

    printf("Input file generated successfully.\n");

    return 0;
}