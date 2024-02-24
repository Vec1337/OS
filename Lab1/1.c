#include <stdio.h>
#include <stdlib.h>


#define BUFFER_SIZE 512

int main(int argc, char* argv[]) {
	
	if(argc != 3) {
		printf("Krivi broj argumenata!");
		return 1;
	}

	FILE* source = fopen(argv[1], "rb");
	if(source == NULL) {
		printf("Pogreska prilikom otvaranja izvorisne datoteke!");
		return 1;
	}

	FILE* destination = fopen(argv[2] , "wb");
	if(destination == NULL) {
		printf("Pogreska prilikom kreiranja odredisne datoteke!");
		return 1;
	}

	char buffer[BUFFER_SIZE];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        fwrite(buffer, 1, bytesRead, destination);
    }


	fclose(source);
	fclose(destination);

	printf("File coped successfully!\n");

	return 0;
}
