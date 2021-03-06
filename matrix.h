#pragma once

const char square = 219;
char matrix_shell[100][100] = {
	{ ' ',' ',' ',' ','1',' ',' ',' ' ,'2',' ',' ',' ' ,'3',' ',' ',' ','4',' ',' ',' ','5',' ',' ',' ','6',' ',' ',' ','7',' ',' ',' ','8',' ',' ' },
	{ ' ',' ','_','_','_','_','_','_','_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', },
	{ '1',' ','|',' ',square,' ','|',' ',square,' ','|', ' ',square,' ','|', ' ',square,' ','|', ' ',square,' ','|', ' ',square,' ','|', ' ',square,' ','|', ' ',square,' ','|' },
	{ ' ',' ','|','_','_','_','|','_','_','_','|', '_','_','_','|', '_','_','_','|', '_','_','_','|', '_','_','_','|', '_','_','_','|', '_','_','_','|', },
	{ ' ',' ','|',' ',' ',' ','|',' ',' ',' ','|', ' ',' ',' ','|', ' ',' ',' ','|', ' ',' ',' ','|', ' ',' ',' ','|', ' ',' ',' ','|', ' ',' ',' ','|', },
	{ '2',' ','|',' ',square,' ','|',' ',square,' ','|', ' ',square,' ','|', ' ',square,' ','|', ' ',square,' ','|', ' ',square,' ','|', ' ',square,' ','|', ' ',square,' ','|' },
	{ ' ',' ','|','_','_','_','|','_','_','_','|', '_','_','_','|', '_','_','_','|', '_','_','_','|', '_','_','_','|', '_','_','_','|', '_','_','_','|', },
	{ ' ',' ','|',' ',' ',' ','|',' ',' ',' ','|', ' ',' ',' ','|', ' ',' ',' ','|', ' ',' ',' ','|', ' ',' ',' ','|', ' ',' ',' ','|', ' ',' ',' ','|', },
	{ '3',' ','|',' ',square,' ','|',' ',square,' ','|', ' ',square,' ','|', ' ',square,' ','|', ' ',square,' ','|', ' ',square,' ','|', ' ',square,' ','|', ' ',square,' ','|' },
	{ ' ',' ','|','_','_','_','|','_','_','_','|', '_','_','_','|', '_','_','_','|', '_','_','_','|', '_','_','_','|', '_','_','_','|', '_','_','_','|', },
	{ ' ',' ','|',' ',' ',' ','|',' ',' ',' ','|', ' ',' ',' ','|', ' ',' ',' ','|', ' ',' ',' ','|', ' ',' ',' ','|', ' ',' ',' ','|', ' ',' ',' ','|', },
	{ '4',' ','|',' ',square,' ','|',' ',square,' ','|', ' ',square,' ','|', ' ',square,' ','|', ' ',square,' ','|', ' ',square,' ','|', ' ',square,' ','|', ' ',square,' ','|' },
	{ ' ',' ','|','_','_','_','|','_','_','_','|', '_','_','_','|', '_','_','_','|', '_','_','_','|', '_','_','_','|', '_','_','_','|', '_','_','_','|', },
	{ ' ',' ','|',' ',' ',' ','|',' ',' ',' ','|', ' ',' ',' ','|', ' ',' ',' ','|', ' ',' ',' ','|', ' ',' ',' ','|', ' ',' ',' ','|', ' ',' ',' ','|', },
	{ '5',' ','|',' ',square,' ','|',' ',square,' ','|', ' ',square,' ','|', ' ',square,' ','|', ' ',square,' ','|', ' ',square,' ','|', ' ',square,' ','|', ' ',square,' ','|' },
	{ ' ',' ','|','_','_','_','|','_','_','_','|', '_','_','_','|', '_','_','_','|', '_','_','_','|', '_','_','_','|', '_','_','_','|', '_','_','_','|', },
	{ ' ',' ','|',' ',' ',' ','|',' ',' ',' ','|', ' ',' ',' ','|', ' ',' ',' ','|', ' ',' ',' ','|', ' ',' ',' ','|', ' ',' ',' ','|', ' ',' ',' ','|', },
	{ '6',' ','|',' ',square,' ','|',' ',square,' ','|', ' ',square,' ','|', ' ',square,' ','|', ' ',square,' ','|', ' ',square,' ','|', ' ',square,' ','|', ' ',square,' ','|' },
	{ ' ',' ','|','_','_','_','|','_','_','_','|', '_','_','_','|', '_','_','_','|', '_','_','_','|', '_','_','_','|', '_','_','_','|', '_','_','_','|', },
	{ ' ',' ','|',' ',' ',' ','|',' ',' ',' ','|', ' ',' ',' ','|', ' ',' ',' ','|', ' ',' ',' ','|', ' ',' ',' ','|', ' ',' ',' ','|', ' ',' ',' ','|', },
	{ '7',' ','|',' ',square,' ','|',' ',square,' ','|', ' ',square,' ','|', ' ',square,' ','|', ' ',square,' ','|', ' ',square,' ','|', ' ',square,' ','|', ' ',square,' ','|' },
	{ ' ',' ','|','_','_','_','|','_','_','_','|', '_','_','_','|', '_','_','_','|', '_','_','_','|', '_','_','_','|', '_','_','_','|', '_','_','_','|', },
	{ ' ',' ','|',' ',' ',' ','|',' ',' ',' ','|', ' ',' ',' ','|', ' ',' ',' ','|', ' ',' ',' ','|', ' ',' ',' ','|', ' ',' ',' ','|', ' ',' ',' ','|', },
	{ '8',' ','|',' ',square,' ','|',' ',square,' ','|', ' ',square,' ','|', ' ',square,' ','|', ' ',square,' ','|', ' ',square,' ','|', ' ',square,' ','|', ' ',square,' ','|' },
	{ ' ',' ','|','_','_','_','|','_','_','_','|', '_','_','_','|', '_','_','_','|', '_','_','_','|', '_','_','_','|', '_','_','_','|', '_','_','_','|', },
};


HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);