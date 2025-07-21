#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <gmp.h>
#include <time.h>
#include <sys/time.h>
#include <pthread.h>
int dataType;
int opcode;
double readTime, computeTime, writeTime;

typedef struct
{
    int startRow;
    int endRow;
    int colsA;
    int colsB;
    int **matrixA;
    int **matrixB;
    mpz_t **result;
} thread_data_int32;

typedef struct
{
    int startRow;
    int endRow;
    int colsA;
    int colsB;
    float **matrixA;
    float **matrixB;
    float **result;
} thread_data_float;

typedef struct
{
    int startRow;
    int endRow;
    int colsA;
    int colsB;
    long **matrixA;
    long **matrixB;
    mpz_t **result;
} thread_data_int64;

typedef struct
{
    int startRow;
    int endRow;
    int colsA;
    int colsB;
    double **matrixA;
    double **matrixB;
    double **result;
} thread_data_double;

void *thread_multiply_int32(void *arg)
{
    thread_data_int32 *data = (thread_data_int32 *)arg;
    for (int i = data->startRow; i < data->endRow; i++)
    {
        for (int j = 0; j < data->colsB; j++)
        {
            mpz_t sum;
            mpz_init(sum);
            mpz_set_ui(data->result[i][j], 0);
            for (int k = 0; k < data->colsA; k++)
            {
                mpz_t temp;
                mpz_init(temp);
                mpz_set_si(temp, data->matrixA[i][k]);
                mpz_mul_ui(temp, temp, data->matrixB[k][j]);
                mpz_add(sum, sum, temp);
                mpz_clear(temp);
            }
            mpz_set(data->result[i][j], sum);
            mpz_clear(sum);
        }
        printf("%d\n", i);
    }
    pthread_exit(NULL);
}

void *thread_multiply_float(void *arg)
{
    thread_data_float *data = (thread_data_float *)arg;
    for (int i = data->startRow; i < data->endRow; i++)
    {
        for (int j = 0; j < data->colsB; j++)
        {
            data->result[i][j] = 0;
            for (int k = 0; k < data->colsA; k++)
            {
                data->result[i][j] += data->matrixA[i][k] * data->matrixB[k][j];
            }
        }
        printf("%d\n", i);
    }
    pthread_exit(NULL);
}

void *thread_multiply_int64(void *arg)
{
    thread_data_int64 *data = (thread_data_int64 *)arg;
    for (int i = data->startRow; i < data->endRow; i++)
    {
        for (int j = 0; j < data->colsB; j++)
        {
            mpz_t sum;
            mpz_init(sum);
            mpz_set_ui(data->result[i][j], 0);
            for (int k = 0; k < data->colsA; k++)
            {
                mpz_t temp;
                mpz_init(temp);
                mpz_set_si(temp, data->matrixA[i][k]);
                mpz_mul_ui(temp, temp, data->matrixB[k][j]);
                mpz_add(sum, sum, temp);
                mpz_clear(temp);
            }
            mpz_set(data->result[i][j], sum);
            mpz_clear(sum);
        }
        printf("%d\n", i);
    }
    pthread_exit(NULL);
}

void *thread_multiply_double(void *arg)
{
    thread_data_double *data = (thread_data_double *)arg;
    for (int i = data->startRow; i < data->endRow; i++)
    {
        for (int j = 0; j < data->colsB; j++)
        {
            data->result[i][j] = 0;
            for (int k = 0; k < data->colsA; k++)
            {
                data->result[i][j] += data->matrixA[i][k] * data->matrixB[k][j];
            }
        }
        printf("%d\n", i);
    }
    pthread_exit(NULL);
}

void dataType1(FILE *input, FILE *output)
{
    struct timeval start, end;

    gettimeofday(&start, NULL);
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

    gettimeofday(&end, NULL);
    readTime = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;

    printf("readTime: %lf\n", readTime);

    gettimeofday(&start, NULL);

    mpz_t **result = (mpz_t **)malloc(rowsA * sizeof(mpz_t *));
    for (int i = 0; i < rowsA; i++)
    {
        result[i] = (mpz_t *)malloc(colsB * sizeof(mpz_t));
        for (int j = 0; j < colsB; j++)
        {
            mpz_init(result[i][j]);
        }
    }

    int numThreads = 4;
    pthread_t threads[numThreads];
    thread_data_int32 threadData[numThreads];
    int rowsPerThread = rowsA / numThreads;
    int remainingRows = rowsA % numThreads;
    int rowIndex = 0;

    for (int i = 0; i < numThreads; i++)
    {
        threadData[i].startRow = rowIndex;
        threadData[i].endRow = rowIndex + rowsPerThread;
        threadData[i].colsA = colsA;
        threadData[i].colsB = colsB;
        threadData[i].matrixA = matrixA;
        threadData[i].matrixB = matrixB;
        threadData[i].result = result;
        rowIndex += rowsPerThread;

        if (i == numThreads - 1)
        {
            threadData[i].endRow += remainingRows;
        }

        printf("startRow: %d, endRow: %d\n", threadData[i].startRow, threadData[i].endRow);
        pthread_create(&threads[i], NULL, thread_multiply_int32, (void *)&threadData[i]);
    }

    for (int i = 0; i < numThreads; i++)
    {
        pthread_join(threads[i], NULL);
    }

    gettimeofday(&end, NULL);
    computeTime = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;

    printf("computeTime: %lf\n", computeTime);

    gettimeofday(&start, NULL);

    fprintf(output, "%d %d\n", rowsA, colsB);

    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            gmp_fprintf(output, "%Zd ", result[i][j]);
        }
        gmp_fprintf(output, "\n");
    }

    gettimeofday(&end, NULL);
    writeTime = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;

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
    struct timeval start, end;
    gettimeofday(&start, NULL);
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

    gettimeofday(&end, NULL);
    readTime = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    printf("readTime: %lf\n", readTime);

    gettimeofday(&start, NULL);

    float **result = (float **)malloc(rowsA * sizeof(float *));
    for (int i = 0; i < rowsA; i++)
    {
        result[i] = (float *)malloc(colsB * sizeof(float));
    }

    int numThreads = 4;
    pthread_t threads[numThreads];
    thread_data_float threadData[numThreads];
    int rowsPerThread = rowsA / numThreads;
    int remainingRows = rowsA % numThreads;
    int rowIndex = 0;

    for (int i = 0; i < numThreads; i++)
    {
        threadData[i].startRow = rowIndex;
        threadData[i].endRow = rowIndex + rowsPerThread;
        threadData[i].colsA = colsA;
        threadData[i].colsB = colsB;
        threadData[i].matrixA = matrixA;
        threadData[i].matrixB = matrixB;
        threadData[i].result = result;
        rowIndex += rowsPerThread;

        if (i == numThreads - 1)
        {
            threadData[i].endRow += remainingRows;
        }

        printf("startRow: %d, endRow: %d\n", threadData[i].startRow, threadData[i].endRow);
        pthread_create(&threads[i], NULL, thread_multiply_float, (void *)&threadData[i]);
    }

    for (int i = 0; i < numThreads; i++)
    {
        pthread_join(threads[i], NULL);
    }

    gettimeofday(&end, NULL);
    computeTime = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    printf("computeTime: %lf\n", computeTime);

    gettimeofday(&start, NULL);
    fprintf(output, "%d %d\n", rowsA, colsA);
    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            fprintf(output, "%f ", result[i][j]);
        }
        fprintf(output, "\n");
    }

    gettimeofday(&end, NULL);
    writeTime = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
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
    struct timeval start, end;
    gettimeofday(&start, NULL);
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

    gettimeofday(&end, NULL);
    readTime = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    printf("readTime: %lf\n", readTime);

    gettimeofday(&start, NULL);

    mpz_t **result = (mpz_t **)malloc(rowsA * sizeof(mpz_t *));
    for (int i = 0; i < rowsA; i++)
    {
        result[i] = (mpz_t *)malloc(colsB * sizeof(mpz_t));
        for (int j = 0; j < colsB; j++)
        {
            mpz_init(result[i][j]);
        }
    }

    int numThreads = 4;
    pthread_t threads[numThreads];
    thread_data_int64 threadData[numThreads];
    int rowsPerThread = rowsA / numThreads;
    int remainingRows = rowsA % numThreads;
    int rowIndex = 0;

    for (int i = 0; i < numThreads; i++)
    {
        threadData[i].startRow = rowIndex;
        threadData[i].endRow = rowIndex + rowsPerThread;
        threadData[i].colsA = colsA;
        threadData[i].colsB = colsB;
        threadData[i].matrixA = matrixA;
        threadData[i].matrixB = matrixB;
        threadData[i].result = result;
        rowIndex += rowsPerThread;

        if (i == numThreads - 1)
        {
            threadData[i].endRow += remainingRows;
        }

        printf("startRow: %d, endRow: %d\n", threadData[i].startRow, threadData[i].endRow);
        pthread_create(&threads[i], NULL, thread_multiply_int64, (void *)&threadData[i]);
    }

    for (int i = 0; i < numThreads; i++)
    {
        pthread_join(threads[i], NULL);
    }

    gettimeofday(&end, NULL);
    computeTime = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    printf("computeTime: %lf\n", computeTime);

    gettimeofday(&start, NULL);

    fprintf(output, "%d %d\n", rowsA, colsB);

    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            gmp_fprintf(output, "%Zd ", result[i][j]);
        }
        gmp_fprintf(output, "\n");
    }

    gettimeofday(&end, NULL);
    writeTime = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
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
    struct timeval start, end;

    gettimeofday(&start, NULL);
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

    gettimeofday(&end, NULL);
    readTime = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    printf("readTime: %lf\n", readTime);

    gettimeofday(&start, NULL);

    double **result = (double **)malloc(rowsA * sizeof(double *));
    for (int i = 0; i < rowsA; i++)
    {
        result[i] = (double *)malloc(colsB * sizeof(double));
    }

    int numThreads = 4;
    pthread_t threads[numThreads];
    thread_data_double threadData[numThreads];
    int rowsPerThread = rowsA / numThreads;
    int remainingRows = rowsA % numThreads;
    int rowIndex = 0;

    for (int i = 0; i < numThreads; i++)
    {
        threadData[i].startRow = rowIndex;
        threadData[i].endRow = rowIndex + rowsPerThread;
        threadData[i].colsA = colsA;
        threadData[i].colsB = colsB;
        threadData[i].matrixA = matrixA;
        threadData[i].matrixB = matrixB;
        threadData[i].result = result;
        rowIndex += rowsPerThread;

        if (i == numThreads - 1)
        {
            threadData[i].endRow += remainingRows;
        }

        printf("startRow: %d, endRow: %d\n", threadData[i].startRow, threadData[i].endRow);
        pthread_create(&threads[i], NULL, thread_multiply_double, (void *)&threadData[i]);
    }

    for (int i = 0; i < numThreads; i++)
    {
        pthread_join(threads[i], NULL);
    }

    gettimeofday(&end, NULL);
    computeTime = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    printf("computeTime: %lf\n", computeTime);

    gettimeofday(&start, NULL);

    fprintf(output, "%d %d\n", rowsA, colsA);
    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            fprintf(output, "%lf ", result[i][j]);
        }
        fprintf(output, "\n");
    }

    gettimeofday(&end, NULL);
    writeTime = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
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