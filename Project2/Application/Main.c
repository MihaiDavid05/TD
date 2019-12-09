#define _CRT_SECURE_NO_DEPRECATE
#include "Header.h"
#include<stdio.h>


int main(int argc, char *argv[]) {
	FILE *f;
	if (argc != 2) {
		printf("Trebuie sa dati file path ca si argument !");
	}
	else {
		f = fopen(argv[1], "rb");

		char ch;

		int stare = 3;
		bool special = true;

		while (!feof(f)) {
			ch = fgetc(f);
			printf(" %c ", ch);
			stare = parser(ch,special);
			printf("\n%d", stare);
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
					if (special) {
						printf("%s\r\n", at.str[i]);
					}
					else {
						printf("+%s\r\n", at.str[i]);
					}
				}
				printf("\r\n");
				printf("OK");
			}
			printf("\r\n");
		}
		else if (stare == 2) {
			printf("Mai este nevoie de caractere !");
		}
	}

}