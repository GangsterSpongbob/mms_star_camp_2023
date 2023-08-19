#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 256

int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        FILE *file_in = fopen(argv[i], "r");
        if (file_in == NULL)
        {
            perror("Error opening file\n");
            exit(-1);
        }

        char buffer[BUFFER_SIZE];
        unsigned int index = 0;
        while (fscanf(file_in, "%s", buffer + index) == 1)
        {
            index++;
        }

        for (size_t i = 0; i < index; i++)
        {
            printf("%s ", buffer + i);
        }
        printf("\n");
        fclose(file_in);
    }

    return 0;
}