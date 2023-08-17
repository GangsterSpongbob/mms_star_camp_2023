#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#include <stdio.h> //

int main(int argc, char *argv[])
{
    srand(time(NULL));

    int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
    for (size_t i = 0; i < atoi(argv[2]); i++)
    {
        uint64_t new_num = rand() % 10000;
        printf("%lu\n", new_num);
        write(fd, &new_num, 8);
    }

    close(fd);

    return 0;
}