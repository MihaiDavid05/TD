#include<stdint.h>
#include<stdbool.h>
#define MAX_LINE 500
#define STR_SIZE 50
#ifndef AUTOMAT_H
#define AUTOMAT_H
typedef struct {
	bool ok;
	uint32_t line_count;
	uint8_t str[MAX_LINE][STR_SIZE + 1];
}AT_DATA;
#endif // !AUTOMAT_H

