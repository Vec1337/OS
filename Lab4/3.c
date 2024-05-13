#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

#define BROJ_SJEDALA 100

int sjedala[BROJ_SJEDALA] = {0};

void kašnjenje(int min_sekundi, int max_sekundi) {
    int sekunde = rand() % (max_sekundi - min_sekundi + 1) + min_sekundi;
    sleep(sekunde);
}


void zauzmiSjedalo(int sjedalo) {
    kašnjenje(1, 2);

    sjedala[sjedalo] = 1;
}

void *checkInKorisnika(void *arg) {
    int brojKorisnika = *((int *)arg);

    printf("Korisnik %d pokreće check-in...\n", brojKorisnika);

    kašnjenje(1, 5);

    int sjedalo;
    do {
        
        kašnjenje(1, 3);
        sjedalo = rand() % BROJ_SJEDALA;

        printf("Korisnik %d odabrao je sjedalo %d. ", brojKorisnika, sjedalo);

        kašnjenje(1, 3);

        if (rand() % 2 == 0) {
            printf("Korisnik %d odbio je sjedalo.\n", brojKorisnika);
        } else {
            printf("Korisnik %d prihvatio je sjedalo.\n", brojKorisnika);

            zauzmiSjedalo(sjedalo);
        }

    } while (sjedala[sjedalo] == 0); 

    printf("Korisnik %d završio je check-in.\n", brojKorisnika);

    pthread_exit(NULL);
}

int main() {
    srand((unsigned int)time(NULL));

    pthread_t dretve[100];
    int brojeviKorisnika[100];

    for (int i = 0; i < 100; ++i) {
    
        kašnjenje(1, 5);

        brojeviKorisnika[i] = i + 1;

        if (pthread_create(&dretve[i], NULL, checkInKorisnika, &brojeviKorisnika[i]) != 0) {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < 100; ++i) {
        if (pthread_join(dretve[i], NULL) != 0) {
            perror("pthread_join");
            exit(EXIT_FAILURE);
        }
    }

    int zauzetaSjedala = 0;
    for (int i = 0; i < BROJ_SJEDALA; ++i) {
        if (sjedala[i] == 1) {
            zauzetaSjedala++;
        }
    }

    printf("\nKonačan broj zauzetih sjedala: %d\n", zauzetaSjedala);
    printf("Konačan broj slobodnih sjedala: %d\n", BROJ_SJEDALA - zauzetaSjedala);

    return 0;
}
