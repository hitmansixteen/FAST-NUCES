#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

int isVowel(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        return 1;
    else
        return 0;
}

int isAlphabet(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    else
        return 0;
}
void reverse(char *string)
{
    printf("%s", string);
    int start, end;
    int i = 0;
    while (string[i] != '\0')
    {
        while (!isAlphabet(string[i]) && string[i] != '\0')
            i++;
        start = i;
        while (isAlphabet(string[i]))
            i++;
        end = i - 1;
        while (start < end)
        {
            while (isVowel(string[start]) || !isAlphabet(string[start]))
                start++;
            while (isVowel(string[end]) || !isAlphabet(string[end]))
                end--;

            swap(&string[start], &string[end]);

            // char temp = string[start];
            // string[start] = string[end];
            // string[end] = temp;

            start++;
            end--;
        }
        i++;
    }
    printf("%s", string);
}

int main(int argc, char **argv)
{
    FILE *file = fopen(argv[1], "r");

    if (!file)
        printf("Can't open file\n");
    else
    {
        fseek(file, 0, SEEK_END);
        int size = ftell(file);
        fseek(file, 0, SEEK_SET);

        char *string = (char *)malloc(size * sizeof(char));

        fread(string, sizeof(char), size, file);

        // printf("%s", string);
        reverse(string);

        fclose(file);

        free(string);
    }

    return 0;
}
