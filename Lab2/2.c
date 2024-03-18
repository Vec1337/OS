#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Neispravan broj argumenata!\n");
        return 1;
    }

    setbuf(stdout, NULL);  

    int brojDjece = atoi(argv[1]);

    for (int i = 1; i <= brojDjece; ++i) {
        pid_t child_pid = fork();

        switch (child_pid) {
            case -1:
                printf("fork\n");
                exit(EXIT_FAILURE);
                break;

            case 0:
                
                printf("Child #%d\n", i);
                exit(EXIT_SUCCESS);
                break;

            default:
                
                printf("Parent #%d\n", i);

                wait(NULL);
        }
    }

    return 0;
}
