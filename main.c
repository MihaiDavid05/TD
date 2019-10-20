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

		while (!feof(f)) {
			ch = fgetc(f);
			parse(ch);
		}
	}

}