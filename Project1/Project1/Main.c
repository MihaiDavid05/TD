#include"Header.h"
int main(int argc, char *argv[]) {
	FILE *f;
	if (argc != 2) {
		printf("\nTrebuie sa dati file path ca si argument !");
	}
	else {
		f = fopen(argv[1], "rb");

		char ch;
		int stare = 3;
		while (!feof(f)) {
			ch = fgetc(f);
			printf(" %c ", ch);
			stare = parser(ch);
			printf("\n%d",stare);
			if (stare <= 0) {
				printf("\nEroare la starea %d , text gresit !", abs(stare));
				break;
			}
		}
		fclose(f);

		if (stare == 1) {
			printf("\r\n");
			if (at.ok == false) {
				printf("ERROR");
			}
			else {
				int i;
				for (i = 0; i < at.line_count; i++) {
					printf("+%s\r\n", at.str[i]);
				}
				printf("\r\n");
				printf("OK");
			}
			printf("\r\n");
		}
		else if (stare == 2) {
			printf("\nMai este nevoie de caractere !");
		}
	}

}