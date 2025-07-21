#include <stdio.h>

int main(int argc, char **argv)
{
    // to open the file ./q1 is argv[0] and q1.txt is argv[1]
    FILE *file = fopen(argv[1], "r");
    // ch while store input from file character wise.
    char ch;
    // count will store the count of digits.
    int count = 0;

    // this
    if (!file)
        printf("Can't open file.\n");
    else
    {
        while ((ch = getc(file)) != EOF)
        {
            if (ch >= '0' && ch <= '9')
                count++;
        }
        printf("The number of digits in the file are: %d\n", count);
        fclose(file);
    }

    return 0;
}