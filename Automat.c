#include<stdio.h>
#include "Automat.h"
#include<stdint.h>
AT_DATA at;
uint8_t parser(uint8_t ch)
{
	static uint8_t state=0;
	static uint32_t line_index, string_index;
	switch (state)
	{
	case 0:

		if (ch == 0x0D)
		{
			state = 1;
		}
		break;

	case 1:
		if (ch == 0x0A)
		{
			state = 2;
		}
		else return -state;
		break;
	case 2:
		if (ch == 'E')
		{
			state = 3;
			at.str[line_index++][string_index++] = ch;
		}
		else {
			if (ch == 'O')
			{
				state = 8;
				at.str[line_index++][string_index++] = ch;
			}
			else {
				if (ch == '+')
				{
					state = 11;
					at.str[line_index++][string_index++] = ch;
				}
				else return -state;
			}
		}
		break;
	case 3:
		if (ch == 'R')
		{
			state = 4;
			at.str[line_index++][string_index++] = ch;
		}
		else return -state;
		break;
	case 4:
		if (ch == 'R')
		{
			state = 5;
			at.str[line_index++][string_index++] = ch;
		}
		else return -state;
		break;
	case 5:
		if (ch == 'O')
		{
			state = 6;
			at.str[line_index++][string_index++] = ch;
		}
		else return -state;
		break;
	case 6:
		if (ch == 'R')
		{
			state = 7;
			at.str[line_index++][string_index++] = ch;
		}
		else return -state;
		break;
	case 7:
		if (ch == 0x0D)
		{
			state = 8;
		}
		else return -state;
		break;
	case 8:
		if (ch == 0x0A)
		{
			state = 9;
		}
		else return -state;
		break;
	case 9:
	{
		at.ok = true;
		return 1;
	}
	case 10:
		if (ch == 'K')
		{
			state = 7;
			at.str[line_index++][string_index++] = ch;
		}
		else return -state;
		break;
	case 11:
		if (ch != 0x0D)
		{
			state = 11;
			at.str[line_index++][string_index++] = ch;
		}
		else
		{
			if (ch == 0x0D)
			{
				state = 12;
			}
			else return -state;
		}
		break;
	case 12:
		if (ch == 0x0A)
		{
			state = 13;
		}
		else return -state;
	case 13:
		if (ch == '+')
		{
			state = 11;
		}
		else
		{
			if (ch == 0x0D)
			{
				state = 14;
			}
			else return -state;
		}
		break;
	case 14:
		if (ch == 0x0A)
		{
			state = 15;
		}
		break;
	case 15:
		if (ch == 'O')
		{
			state = 16;
			at.str[line_index++][string_index++] = ch;
		}
		else {
			if (ch == 'E')
			{
				state = 17;
				at.str[line_index++][string_index++] = ch;
			}
			else return -state;
		}
		break;
	case 16:
		if (ch == 'K')
		{
			state = 7;
			at.str[line_index++][string_index++] = ch;
		}
		else return -state;
		break;
	case 17:
		if (ch == 'R')
		{
			state = 18;
			at.str[line_index++][string_index++] = ch;
		}
		else return -state;
		break;
	case 18:
		if (ch == 'R')
		{
			state = 19;
			at.str[line_index++][string_index++] = ch;
		}
		else return -state;
		break;
	case 19:
		if (ch == 'O')
		{
			state = 20;
			at.str[line_index++][string_index++] = ch;
		}
		else return -state;
		break;
	case 20:
		if (ch == 'R')
		{
			state = 7;
			at.str[line_index++][string_index++] = ch;
		}
		else return -state;
	}
	return 2;
}