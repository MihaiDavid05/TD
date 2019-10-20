#include"Automat.h"
int main(int argc, char *argv[]) {
	FILE *f;
	if (argc != 2) {
		printf("Trebuie sa dati file path ca si argument !"); //trebuie sa dau de la propreties
	}
	else {
		f = fopen(argv[1], "rb");

		char ch;
		int stare = 3;
		while (!feof(f)) {
			ch = fgetc(f);
			stare = parser(ch);
			if (stare <= 0) {
				printf("Eroare la starea %d", abs(stare));
				break;
			}
		}
		fclose(f);

		if (stare == 1) {
			printf("\r\n");
			if (at.line_count == 1) {
				printf("%s\r\n", at.str[0]);
			}
			else {
				int i;
				for (i = 0; i < at.line_count; i++) {
					printf("+%s\r\n", at.str[i]);
				}
				printf("\r\n");
			}
			printf("\r\n");
		}
		else if (stare == 2) {
			printf("Mai este nevoie de caractere !");
		}
	}

}