#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include"Automat.c"
#include"Automat.c"
int main(int argc, char *argv[]) {
	FILE *f;
	if (argc != 2) {
		printf("Trebuie sa dati file path ca si argument !");
	}
	else {
		f = fopen(argv[1], "rb");

		char ch;
		int stare = 3;
		while (!feof(f)) {
			ch = fgetc(f);
			stare = parse(ch);
			if (stare <= 0) {
				printf("Eroare la starea %d", abs(stare));
				break;
			}
		}
		close(f);
		
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
		else {
			printf("Mai este nevoie de caractere !");
		}
	}

}