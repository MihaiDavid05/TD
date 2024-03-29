#pragma once
#ifndef AUTOMAT_H
#define AUTOMAT_H
#include<stdint.h>
#include<stdbool.h>
#define MAX_LINE 1000
#define STR_SIZE 150
typedef struct {
	bool ok;
	uint32_t line_count;
	uint8_t str[MAX_LINE][STR_SIZE + 1];
}AT_DATA;

extern AT_DATA at;
int parser(char ch, bool special);
#endif // !AUTOMAT_H