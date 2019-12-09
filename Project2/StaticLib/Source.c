#include "Header.h"
#include<stdio.h>

AT_DATA at;

int parser(char ch,bool special)
{
	static uint8_t state = 0;
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
		else {
			line_index = 0;
			string_index = 0;
			return -state;
		}
		break;
	case 2:
		if (special) {
			if (ch != 0x0D && ch != '+') {
				at.str[line_index][string_index++] = ch;
				state = 11;
			}
			else {
				line_index = 0;
				string_index = 0;
				return -state;
			}
		}
		else{
			if (ch == 'E')
			{
				state = 3;
			}
			else {
				if (ch == 'O')
				{
					state = 10;
				}
				else {
					if (ch == '+')
					{
						state = 11;
					}
					else {
						line_index = 0;
						string_index = 0;
						return -state;
					}
				}
			}
		}
		break;
	case 3:
		if (ch == 'R')
		{
			state = 4;
		}
		else {
			line_index = 0;
			string_index = 0;
			return -state;
		}
		break;
	case 4:
		if (ch == 'R')
		{
			state = 5;
		}
		else {
			line_index = 0;
			string_index = 0;
			return -state;
		}
		break;
	case 5:
		if (ch == 'O')
		{
			state = 6;
		}
		else {
			line_index = 0;
			string_index = 0;
			return -state;
		}
		break;
	case 6:
		if (ch == 'R')
		{
			state = 7;
			at.ok = false;
		}
		else {
			line_index = 0;
			string_index = 0;
			return -state;
		}
		break;
	case 7:
		if (ch == 0x0D)
		{
			state = 8;
		}
		else {
			line_index = 0;
			string_index = 0;
			return -state;
		}
		break;
	case 8:
		if (ch == 0x0A)
		{
			state = 9;
		}
		else {
			line_index = 0;
			string_index = 0;
			return -state;
		}
		break;
	case 9:
	{
		if (at.ok == false) {
			return 1;
		}
		else {
			return 1;
		}
	}
	case 10:
		if (ch == 'K')
		{
			state = 7;
			at.ok = true;
		}
		else {
			line_index = 0;
			string_index = 0;
			return -state;
		}
		break;
	case 11:
		if (ch != 0x0D)
		{
			if (string_index < STR_SIZE) {
				state = 11;
				at.str[line_index][string_index++] = ch;
			}
			else {
				state = 11;
			}
		}
		else
		{
			if (ch == 0x0D)
			{
				if (line_index < MAX_LINE) {
					at.str[line_index++][string_index] = '\0';
					string_index = 0;
					at.line_count++;
					state = 12;
				}
				else {
					state = 12;
				}
			}
			else {
				line_index = 0;
				string_index = 0;
				return -state;
			}
		}
		break;
	case 12:
		if (ch == 0x0A)
		{
			state = 13;
		}
		else {
			line_index = 0;
			string_index = 0;
			return -state;
		}
		break;
	case 13:
		if (special) {
			if (ch == 0x0D)
			{
				state = 14;
			}
			else {
				line_index = 0;
				string_index = 0;
				return -state;
			}
		}
		else{
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
				else {
					line_index = 0;
					string_index = 0;
					return -state;
				}
			}
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
		}
		else {
			if (ch == 'E')
			{
				state = 17;
			}
			else {
				line_index = 0;
				string_index = 0;
				return -state;
			}
		}
		break;
	case 16:
		if (ch == 'K')
		{
			state = 7;
			at.ok = true;
		}
		else {
			line_index = 0;
			string_index = 0;
			return -state;
		}
		break;
	case 17:
		if (ch == 'R')
		{
			state = 18;
		}
		else {
			line_index = 0;
			string_index = 0;
			return -state;
		}
		break;
	case 18:
		if (ch == 'R')
		{
			state = 19;
		}
		else {
			line_index = 0;
			string_index = 0;
			return -state;
		}
		break;
	case 19:
		if (ch == 'O')
		{
			state = 20;
		}
		else {
			line_index = 0;
			string_index = 0;
			return -state;
		}
		break;
	case 20:
		if (ch == 'R')
		{
			state = 7;
			at.ok = false;
		}
		else {
			line_index = 0;
			string_index = 0;
			return -state;
		}
		break;
	}
	return 2;
}