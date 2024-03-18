#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<unistd.h>

char polje[100000];


int main() {
    
    srand(time(NULL));

    
    for (int i = 0; i < sizeof(polje); i++) {
        polje[i] = (rand() % 2 == 0) ? -1 : 1;
    }

    for (int i = 0; i < sizeof(polje); ++i) {
        printf("%d ", polje[i]);
    }
    printf("\n");

    sleep(15);

    return 0;
}