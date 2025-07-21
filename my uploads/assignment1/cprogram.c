#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <gmp.h>
#include <time.h>
int dataType;
int opcode;
double readTime, computeTime, writeTime;
void dataType1(FILE *input, FILE *output)
{
    clock_t start, end;

    start = clock();
    int rowsA, colsA;
    if (fscanf(input, "%d %d", &rowsA, &colsA) != 2)
    {
        printf("Error reading rowsA and colsA from input file.\n");
        return;
    }
    printf("rowsA: %d, colsA: %d\n", rowsA, colsA);
    int **matrixA = (int **)malloc(rowsA * sizeof(int *));
    for (int i = 0; i < rowsA; i++)
    {
        matrixA[i] = (int *)malloc(colsA * sizeof(int));
        for (int j = 0; j < colsA; j++)
        {
            if (fscanf(input, "%d", &matrixA[i][j]) != 1)
            {
                printf("Error reading matrixA[%d][%d] from input file.\n", i, j);
                return;
            }
        }
    }

    int rowsB, colsB;
    if (fscanf(input, "%d %d", &rowsB, &colsB) != 2)
    {
        printf("Error reading rowsB and colsB from input file.\n");
        return;
    }
    printf("rowsB: %d, colsB: %d\n", rowsB, colsB);
    int **matrixB = (int **)malloc(rowsB * sizeof(int *));
    for (int i = 0; i < rowsB; i++)
    {
        matrixB[i] = (int *)malloc(colsB * sizeof(int));
        for (int j = 0; j < colsB; j++)
        {
            if (fscanf(input, "%d", &matrixB[i][j]) != 1)
            {
                printf("Error reading matrixB[%d][%d] from input file.\n", i, j);
                return;
            }
        }
    }

    end = clock();
    readTime = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("readTime: %lf\n", readTime);

    start = clock();

    mpz_t **result = (mpz_t **)malloc(rowsA * sizeof(mpz_t *));
    for (int i = 0; i < rowsA; i++)
    {
        result[i] = (mpz_t *)malloc(colsB * sizeof(mpz_t));
        for (int j = 0; j < colsB; j++)
        {
            mpz_init(result[i][j]);
        }
    }

    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            mpz_t sum;
            mpz_init(sum);
            mpz_set_ui(result[i][j], 0);
            for (int k = 0; k < colsA; k++)
            {
                mpz_t temp;
                mpz_init(temp);
                mpz_set_si(temp, matrixA[i][k]);
                mpz_mul_ui(temp, temp, matrixB[k][j]);
                mpz_add(sum, sum, temp);
                mpz_clear(temp);
            }
            mpz_set(result[i][j], sum);
            mpz_clear(sum);
        }
        printf("%d\n", i);
    }

    end = clock();

    computeTime = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("computeTime: %lf\n", computeTime);

    start = clock();

    fprintf(output, "%d %d\n", rowsA, colsB);

    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            gmp_fprintf(output, "%Zd ", result[i][j]);
        }
        gmp_fprintf(output, "\n");
    }

    end = clock();
    writeTime = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("writeTime: %lf\n", writeTime);

    for (int i = 0; i < rowsA; i++)
    {
        free(matrixA[i]);
    }
    free(matrixA);
    for (int i = 0; i < rowsB; i++)
    {
        free(matrixB[i]);
    }
    free(matrixB);

    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            mpz_clear(result[i][j]);
        }
        free(result[i]);
    }
    free(result);
}
void dataType2(FILE *input, FILE *output)
{
    clock_t start, end;
    start = clock();
    int rowsA, colsA;
    if (fscanf(input, "%d %d", &rowsA, &colsA) != 2)
    {
        printf("Error reading rowsA and colsA from input file.\n");
        return;
    }
    printf("rowsA: %d, colsA: %d\n", rowsA, colsA);
    float **matrixA = (float **)malloc(rowsA * sizeof(float *));
    for (int i = 0; i < rowsA; i++)
    {
        matrixA[i] = (float *)malloc(colsA * sizeof(float));
        for (int j = 0; j < colsA; j++)
        {
            if (fscanf(input, "%f", &matrixA[i][j]) != 1)
            {
                printf("Error reading matrixA[%d][%d] from input file.\n", i, j);
                return;
            }
        }
    }

    int rowsB, colsB;
    if (fscanf(input, "%d %d", &rowsB, &colsB) != 2)
    {
        printf("Error reading rowsB and colsB from input file.\n");
        return;
    }
    printf("rowsB: %d, colsB: %d\n", rowsB, colsB);
    float **matrixB = (float **)malloc(rowsB * sizeof(float *));
    for (int i = 0; i < rowsB; i++)
    {
        matrixB[i] = (float *)malloc(colsB * sizeof(float));
        for (int j = 0; j < colsB; j++)
        {
            if (fscanf(input, "%f", &matrixB[i][j]) != 1)
            {
                printf("Error reading matrixB[%d][%d] from input file.\n", i, j);
                return;
            }
        }
    }

    end = clock();
    readTime = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("readTime: %lf\n", readTime);

    start = clock();

    float **result = (float **)malloc(rowsA * sizeof(float *));
    for (int i = 0; i < rowsA; i++)
    {
        result[i] = (float *)malloc(colsB * sizeof(float));
        for (int j = 0; j < colsB; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++)
            {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
        printf("%d\n", i);
    }

    end = clock();
    computeTime = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("computeTime: %lf\n", computeTime);

    start = clock();
    fprintf(output, "%d %d\n", rowsA, colsA);
    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            fprintf(output, "%f ", result[i][j]);
        }
        fprintf(output, "\n");
    }

    end = clock();
    writeTime = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("writeTime: %lf\n", writeTime);

    for (int i = 0; i < rowsA; i++)
    {
        free(matrixA[i]);
    }
    free(matrixA);

    for (int i = 0; i < rowsB; i++)
    {
        free(matrixB[i]);
    }
    free(matrixB);

    for (int i = 0; i < rowsB; i++)
    {
        free(result[i]);
    }
    free(result);
}
void dataType3(FILE *input, FILE *output)
{
    clock_t start, end;
    start = clock();
    int rowsA, colsA;
    if (fscanf(input, "%d %d", &rowsA, &colsA) != 2)
    {
        printf("Error reading rowsA and colsA from input file.\n");
        return;
    }
    printf("rowsA: %d, colsA: %d\n", rowsA, colsA);
    long **matrixA = (long **)malloc(rowsA * sizeof(long *));
    for (int i = 0; i < rowsA; i++)
    {
        matrixA[i] = (long *)malloc(colsA * sizeof(long));
        for (int j = 0; j < colsA; j++)
        {
            if (fscanf(input, "%ld", &matrixA[i][j]) != 1)
            {
                printf("Error reading matrixA[%d][%d] from input file.\n", i, j);
                return;
            }
        }
    }

    int rowsB, colsB;
    if (fscanf(input, "%d %d", &rowsB, &colsB) != 2)
    {
        printf("Error reading rowsB and colsB from input file.\n");
        return;
    }
    printf("rowsB: %d, colsB: %d\n", rowsB, colsB);
    long **matrixB = (long **)malloc(rowsB * sizeof(long *));
    for (int i = 0; i < rowsB; i++)
    {
        matrixB[i] = (long *)malloc(colsB * sizeof(long));
        for (int j = 0; j < colsB; j++)
        {
            if (fscanf(input, "%ld", &matrixB[i][j]) != 1)
            {
                printf("Error reading matrixB[%d][%d] from input file.\n", i, j);
                return;
            }
        }
    }

    end = clock();
    readTime = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("readTime: %lf\n", readTime);

    start = clock();

    mpz_t **result = (mpz_t **)malloc(rowsA * sizeof(mpz_t *));
    for (int i = 0; i < rowsA; i++)
    {
        result[i] = (mpz_t *)malloc(colsB * sizeof(mpz_t));
        for (int j = 0; j < colsB; j++)
        {
            mpz_init(result[i][j]);
        }
    }

    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            mpz_t sum;
            mpz_init(sum);
            mpz_set_ui(result[i][j], 0);
            for (int k = 0; k < colsA; k++)
            {
                mpz_t temp;
                mpz_init(temp);
                mpz_set_si(temp, matrixA[i][k]);
                mpz_mul_ui(temp, temp, matrixB[k][j]);
                mpz_add(sum, sum, temp);
                mpz_clear(temp);
            }
            mpz_set(result[i][j], sum);
            mpz_clear(sum);
        }
        printf("%d\n", i);
    }

    end = clock();
    computeTime = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("computeTime: %lf\n", computeTime);

    start = clock();

    fprintf(output, "%d %d\n", rowsA, colsB);

    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            gmp_fprintf(output, "%Zd ", result[i][j]);
        }
        gmp_fprintf(output, "\n");
    }

    end = clock();
    writeTime = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("writeTime: %lf\n", writeTime);

    for (int i = 0; i < rowsA; i++)
    {
        free(matrixA[i]);
    }
    free(matrixA);

    for (int i = 0; i < rowsB; i++)
    {
        free(matrixB[i]);
    }
    free(matrixB);

    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            mpz_clear(result[i][j]);
        }
        free(result[i]);
    }
    free(result);
}
void dataType4(FILE *input, FILE *output)
{
    clock_t start, end;

    start = clock();
    int rowsA, colsA;
    if (fscanf(input, "%d %d", &rowsA, &colsA) != 2)
    {
        printf("Error reading rowsA and colsA from input file.\n");
        return;
    }
    printf("rowsA: %d, colsA: %d\n", rowsA, colsA);
    double **matrixA = (double **)malloc(rowsA * sizeof(double *));
    for (int i = 0; i < rowsA; i++)
    {
        matrixA[i] = (double *)malloc(colsA * sizeof(double));
        for (int j = 0; j < colsA; j++)
        {
            if (fscanf(input, "%lf", &matrixA[i][j]) != 1)
            {
                printf("Error reading matrixA[%d][%d] from input file.\n", i, j);
                return;
            }
        }
    }

    int rowsB, colsB;
    if (fscanf(input, "%d %d", &rowsB, &colsB) != 2)
    {
        printf("Error reading rowsB and colsB from input file.\n");
        return;
    }
    printf("rowsB: %d, colsB: %d\n", rowsB, colsB);
    double **matrixB = (double **)malloc(rowsB * sizeof(double *));
    for (int i = 0; i < rowsB; i++)
    {
        matrixB[i] = (double *)malloc(colsB * sizeof(double));
        for (int j = 0; j < colsB; j++)
        {
            if (fscanf(input, "%lf", &matrixB[i][j]) != 1)
            {
                printf("Error reading matrixB[%d][%d] from input file.\n", i, j);
                return;
            }
        }
    }

    end = clock();
    readTime = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("readTime: %lf\n", readTime);

    start = clock();

    double **result = (double **)malloc(rowsA * sizeof(double *));
    for (int i = 0; i < rowsA; i++)
    {
        result[i] = (double *)malloc(colsB * sizeof(double));
        for (int j = 0; j < colsB; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++)
            {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
        printf("%d\n", i);
    }

    end = clock();
    computeTime = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("computeTime: %lf\n", computeTime);

    start = clock();

    fprintf(output, "%d %d\n", rowsA, colsA);
    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            fprintf(output, "%lf ", result[i][j]);
        }
        fprintf(output, "\n");
    }

    end = clock();
    writeTime = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("writeTime: %lf\n", writeTime);

    for (int i = 0; i < rowsA; i++)
    {
        free(matrixA[i]);
    }
    free(matrixA);

    for (int i = 0; i < rowsB; i++)
    {
        free(matrixB[i]);
    }
    free(matrixB);

    for (int i = 0; i < rowsB; i++)
    {
        free(result[i]);
    }
    free(result);
}

int main(int argc, char **argv)
{
    char *inputFile = argv[1];
    char *outFile = argv[2];

    FILE *input = fopen(inputFile, "r");
    FILE *output = fopen(outFile, "w");

    if (input == NULL)
    {
        perror("Error opening input file");
        return 1;
    }
    if (fscanf(input, "%d", &opcode) != 1)
    {
        printf("Error reading opcode from input file.\n");
        fclose(input);
        return 1;
    }
    printf("opcode: %d\n", opcode);
    if (fscanf(input, "%d", &dataType) != 1)
    {
        printf("Error reading data type from input file.\n");
        fclose(input);
        return 1;
    }
    printf("dataType: %d\n", dataType);

    if (dataType == 1)
    {
        dataType1(input, output);
    }
    else if (dataType == 2)
    {
        dataType2(input, output);
    }
    else if (dataType == 3)
    {
        dataType3(input, output);
    }
    else if (dataType == 4)
    {
        dataType4(input, output);
    }
    else
    {
        printf("Invalid data type\n");
        fclose(input);
        return 1;
    }

    FILE *graph = fopen("graph.txt", "a");
    fprintf(graph, "%d %d %lf %lf %lf\n", opcode, dataType, readTime, computeTime, writeTime);

    fclose(input);
    fclose(output);
    fclose(graph);
}