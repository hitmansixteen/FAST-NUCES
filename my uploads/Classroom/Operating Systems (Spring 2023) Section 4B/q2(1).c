#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    char name[50];
    char rollNo[50];
    char email[50];
};

void addStudent(struct Student s, char *filename)
{
    FILE *file = fopen(filename, "a");
    if (!file)
        printf("Can't open file!\n");
    else
    {
        fprintf(file, "Name: %s", s.name);
        fprintf(file, "Roll No. %s", s.rollNo);
        fprintf(file, "Email: %s", s.email);
        fclose(file);
        printf("Record added successfully!!\n");
    }
}

void deleteStudent(int n, char *filename)
{
    if (n < 0)
    {
        printf("Invalid Number!!\n");
        return;
    }
    FILE *file = fopen(filename, "r");

    if (!file)
    {
        printf("Can't open file\n");
        return;
    }
    char str[50];
    int i = 0;
    while (fgets(str, 50, file))
        i++;
    i /= 3;
    if (i <= n)
    {
        printf("Invalid Number!!\n");
        return;
    }
    struct Student *s = (struct Student *)malloc(i * sizeof(struct Student));
    fclose(file);

    file = fopen(filename, "r");
    for (int j = 0; j < i; j++)
    {
        fgets(s[j].name, 50, file);
        fgets(s[j].rollNo, 50, file);
        fgets(s[j].email, 50, file);
    }
    fclose(file);
    file = fopen(filename, "w");
    for (int j = 0; j < i; j++)
    {
        if (j != n)
        {
            fprintf(file, "%s", s[j].name);
            fprintf(file, "%s", s[j].rollNo);
            fprintf(file, "%s", s[j].email);
        }
    }
    fclose(file);
    free(s);
    printf("Student deleted successfully!!\n");
}

void readStudent(int n, char *filename)
{
    if (n < 0)
    {
        printf("Invalid Number!!\n");
        return;
    }
    n *= 3;
    FILE *file = fopen(filename, "r");

    if (!file)
        printf("Can't open file\n");
    else
    {
        char str[50];
        int i = 0;
        while (i != n && fgets(str, 50, file))
            i++;
        if (!fgets(str, 50, file))
            printf("Invalid Number!!\n");
        else
        {
            printf("%s", str);
            printf("%s", fgets(str, 50, file));
            printf("%s", fgets(str, 50, file));
        }
    }
}

int main(int argc, char **argv)
{
    int option = 1;
    while (option)
    {
        printf("==========\n");
        printf("1. Add Student\n");
        printf("2. Read Student\n");
        printf("3. Delete Student\n");
        printf("0. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
        {
            struct Student s;
            scanf("%*c");
            printf("Enter student name: ");
            fgets(s.name, 50, stdin);
            printf("Enter student roll number: ");
            fgets(s.rollNo, 50, stdin);
            printf("Enter student email: ");
            fgets(s.email, 50, stdin);

            addStudent(s, argv[1]);
            break;
        }
        case 2:
        {
            int n;
            printf("Enter Student Number: ");
            scanf("%d", &n);
            printf("==========\n");
            readStudent(n, argv[1]);
            break;
        }
        case 3:
        {
            int n;
            printf("Enter Student Number: ");
            scanf("%d", &n);
            printf("==========\n");
            deleteStudent(n, argv[1]);
            break;
        }
        case 0:
            break;
        default:
            printf("Invalid option!!\n");
        }
    }
    return 0;
}
