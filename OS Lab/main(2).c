#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
    int fd = open("file.txt", O_RDONLY);

    char buff[1];
    int nRead, offset = 0;

    while (nRead = read(fd, buff, 1) > 0)
    {
        if (offset % 2 == 0)
            write(1, buff, 1);

        offset = lseek(fd, 1, SEEK_CUR);
    }
    printf("\n");

    close(fd);
}