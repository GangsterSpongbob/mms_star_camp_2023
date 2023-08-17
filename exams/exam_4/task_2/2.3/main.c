#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <pthread.h>

#define NUM_READ_BUFFER 10000

void *print_sum_of_nums_in_file(void *);

int main(int argc, char *argv[])
{
    for (size_t i = 0; i < argc - 1; i++)
    {
        pthread_t thread_1;
        if (pthread_create(&thread_1, NULL, print_sum_of_nums_in_file, argv[i + 1]) == -1)
        {
            perror("Could not create thread: ");
            exit(-1);
        }

        pthread_create(&thread_1, NULL, print_sum_of_nums_in_file, argv[i + 1]);
        int *res_sum;
        pthread_join(thread_1, (void **)&res_sum);

        printf("%s%s%s%d\n", "Result of ", argv[i + 1], " is: ", *res_sum);
        free(res_sum);
        // print_sum_of_nums_in_file(argv[i + 1]);
    }

    return 0;
}

void *print_sum_of_nums_in_file(void *filename)
{
    int *sum_of_nums = malloc(sizeof(int));
    *sum_of_nums = 0;

    uint64_t num_buffer;

    int fd = open(filename, O_CREAT | O_RDONLY, 0666);

    ssize_t bytes_read;
    do
    {
        bytes_read = read(fd, &num_buffer, 8);
        if (bytes_read == -1)
        {
            perror("Encountered an error while reading the file\n");
            free(sum_of_nums);
            close(fd);
            return NULL;
        }
        else if (bytes_read == 0)
        {
            break;
        }

        *sum_of_nums += num_buffer;
    } while (bytes_read > 0);

    close(fd);

    return sum_of_nums;
}