#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int zbroj = 0;


void *child_thread(void *arg) {

    zbroj += 1;
    printf("Child Thread - Zbroj =  %d\n", zbroj);

    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Neispravan broj argumenata\n");
        return 1;
    }

    int num_threads = atoi(argv[1]);

    pthread_t threads[num_threads];

    for (int i = 0; i < num_threads; ++i) {
        if (pthread_create(&threads[i], NULL, child_thread, NULL) != 0) {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < num_threads; ++i) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join");
            exit(EXIT_FAILURE);
        }
    }

    printf("\nParent Thread - Zbroj = %d\n", zbroj);

    return 0;
}
