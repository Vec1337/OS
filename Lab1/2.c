#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Krivi broj argumenata!");
        return 1;
    }

    int source = open(argv[1], O_RDONLY);
    if (source == -1) {
        printf("Pogreska prilikom otvaranja izvorisne datoteke!");
        return 1;
    }

    int destination = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (destination == -1) {
        printf("Pogreska prilikom kreiranja odredisne dateteke!");
        close(source);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    int bytesRead;

    while ((bytesRead = read(source, buffer, sizeof(buffer)) > 0)) {
        write(destination, buffer, bytesRead);
    }

    close(source);
    close(destination);

    printf("File copied successfully!\n");

    return 0;
}