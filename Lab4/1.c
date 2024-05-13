#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int zbroj = 0;

void child_process() {
    zbroj += 1;
    printf("Child Process - Zbroj = %d\n", zbroj);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Neispravan broj argumenata!\n");
        return 1;
    }

    int broj_procesa = atoi(argv[1]);

    for (int i = 0; i < broj_procesa; ++i) {
        pid_t pid = fork();

        if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            child_process();
            exit(EXIT_SUCCESS);
        }
    }

    for (int i = 0; i < broj_procesa; ++i) {
        wait(NULL);
    }

    printf("\nParent Process - Konacni rezultat zbroj = %d\n", zbroj);

    return 0;
}
