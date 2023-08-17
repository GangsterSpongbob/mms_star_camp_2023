#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#define NUM_READ_BUFFER 10000

void print_sum_of_nums_in_file(char *);

int main(int argc, char *argv[])
{
    for (size_t i = 0; i < argc - 1; i++)
    {
        print_sum_of_nums_in_file(argv[i + 1]);
    }

    return 0;
}

void print_sum_of_nums_in_file(char *filename)
{
    printf("%s - ", filename);

    int sum_of_nums = 0;
    uint64_t num_buffer;

    int fd = open(filename, O_CREAT | O_RDONLY, 0666);
    printf("\n%d\n", fd);

    ssize_t bytes_read;
    do
    {
        bytes_read = read(fd, &num_buffer, 8);
        if (bytes_read == -1)
        {
            perror("Encountered an error while reading the file\n");
            close(fd);
            return;
        }
        else if (bytes_read == 0)
        {
            break;
        }

        sum_of_nums += num_buffer;
    } while (bytes_read > 0);

    printf("%i\n", sum_of_nums);

    close(fd);
}