// MInesweeper project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "matrix.h"
#include "matrix2.h"

int matrix[8][8];
int matrix2[16][16];
int visitedMatrix[8][8];
int visitedMatrix2[16][16];

const char bomb = 'X';
int noFlags; // no = number of
char choice = 'y';
int win;

int row;
int column;
char action;

void initialize_matrix_shell();
void initialize_matrix2_shell();
void visitedMatrix_equal_zero();
void visitedMatrix2_equal_zero();
void generate_matrix();
void ask_for_input();
void ask_for_input_v2();
void pause_loop();
void print_matrix_shell();
void print_matrix2_shell();
void level_easy();
void level_medium();
void print_you_lose();
void print_you_win();
void reveal_empty_space(int row, int column);
void reveal_empty_space_v2(int row, int column);
void reveal_neighbors(int i, int j);
void reveal_neighbors_v2(int i, int j);
void print_instructions();

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//														E A S Y      L E V E L																   //
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void menu()
{
	char x;

	label:
	printf("Bine ati venit !");
	printf("\nAlegeti nivelul de dificultate .");
	printf("\n\n1) Easy");
	printf("\n2) Medium");
	printf("\n3) How to play");

	cout << "\n\n";
	cin >> x;

	if (x == '1')
	{
		system("cls");
	}

	switch (x)
	{
	case '1':
	repeat:
		noFlags = 0;
		win = 64;
		while (choice == 'y')
		{
			initialize_matrix_shell();
			visitedMatrix_equal_zero();
			level_easy();

			printf("\nRestart level ? (y / n)");
			cin >> choice;
			if (choice == 'y')
			{
				goto repeat;
			}

		}
		break;

	case '2':
	repeat2:
		noFlags = 0;
		win = 256;
		while (choice == 'y')
		{
			initialize_matrix2_shell();
			visitedMatrix2_equal_zero();
			level_medium();

			printf("\nRestart level ? (y / n)");
			cin >> choice;
			if (choice == 'y')
			{
				goto repeat2;
			}
		}
		break;

	case '3' :
		system("cls");
		print_instructions();
		printf("\n\nPress any key to continue . . .");
		_getch();
		system("cls");
		goto label;
		break;

	default: printf("\nWrong number . Please wait . . .");
		pause_loop();
		system("cls");
		goto label;
		break;
	}
}

void initialize_matrix_shell()
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			matrix_shell[i * 3 + 2][j * 4 + 4] = square;
		}
	}
}

void generate_mine(unsigned short &i, unsigned short &j)
{
	i = rand() % 8;
	j = rand() % 8;
}

void generate_matrix()
{
	srand(time(NULL));
	unsigned short i, j, nr, index;
	int  noMines;
	int checkMine[10];
	bool ok;

	//initialized with 0
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			matrix[i][j] = 0;
		}
	}
	//intialize checkMine
	for (i = 0; i < 10; i++)
	{
		checkMine[i] = -1;
	}
	//generate mines
	noMines = 0;
	while (noMines != 10)
	{
		ok = true;
		generate_mine(i, j);
		nr = i * 10 + j;
		for (index = 0; index < 10; index++)
		{
			if (nr == checkMine[index])
			{
				ok = false;
			}
		}
		if (ok == true)
		{
			checkMine[noMines] = nr;
			matrix[i][j] = 9;
			++noMines;
		}
	}

	nr = 0;
	//starting from here it generates the matrix
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			nr = 0;
			if (matrix[i][j] != 9)
			{
				if (i == 0 && j == 0)
				{
					if (matrix[i][j + 1] == 9)
					{
						++nr;
					}
					if (matrix[i + 1][j + 1] == 9)
					{
						++nr;
					}
					if (matrix[i + 1][j] == 9)
					{
						++nr;
					}
				}
				else if (i == 0 && j == 7)
				{
					if (matrix[i][j - 1] == 9)
					{
						++nr;
					}
					if (matrix[i + 1][j - 1] == 9)
					{
						++nr;
					}
					if (matrix[i + 1][j] == 9)
					{
						++nr;
					}
				}
				else if (i == 7 && j == 0)
				{
					if (matrix[i - 1][j] == 9)
					{
						++nr;
					}
					if (matrix[i - 1][j + 1] == 9)
					{
						++nr;
					}
					if (matrix[i][j + 1] == 9)
					{
						++nr;
					}
				}
				else if (i == 7 && j == 7)
				{
					if (matrix[i][j - 1] == 9)
					{
						++nr;
					}
					if (matrix[i - 1][j - 1] == 9)
					{
						++nr;
					}
					if (matrix[i - 1][j] == 9)
					{
						++nr;
					}
				}
				else if (i == 0 && (j >= 1 && j <= 6))
				{
					if (matrix[i][j - 1] == 9)
					{
						++nr;
					}
					if (matrix[i + 1][j - 1] == 9)
					{
						++nr;
					}
					if (matrix[i + 1][j] == 9)
					{
						++nr;
					}
					if (matrix[i + 1][j + 1] == 9)
					{
						++nr;
					}
					if (matrix[i][j + 1] == 9)
					{
						++nr;
					}
				}
				else if (i == 7 && (j >= 1 && j <= 6))
				{
					if (matrix[i][j - 1] == 9)
					{
						++nr;
					}
					if (matrix[i - 1][j - 1] == 9)
					{
						++nr;
					}
					if (matrix[i - 1][j] == 9)
					{
						++nr;
					}
					if (matrix[i - 1][j + 1] == 9)
					{
						++nr;
					}
					if (matrix[i][j + 1] == 9)
					{
						++nr;
					}
				}
				else if (j == 0 && (i >= 1 && i <= 6))
				{
					if (matrix[i - 1][j] == 9)
					{
						++nr;
					}
					if (matrix[i - 1][j + 1] == 9)
					{
						++nr;
					}
					if (matrix[i][j + 1] == 9)
					{
						++nr;
					}
					if (matrix[i + 1][j + 1] == 9)
					{
						++nr;
					}
					if (matrix[i + 1][j] == 9)
					{
						++nr;
					}
				}
				else if (j == 7 && (i >= 1 && i <= 6))
				{
					if (matrix[i - 1][j] == 9)
					{
						++nr;
					}
					if (matrix[i - 1][j - 1] == 9)
					{
						++nr;
					}
					if (matrix[i][j - 1] == 9)
					{
						++nr;
					}
					if (matrix[i + 1][j - 1] == 9)
					{
						++nr;
					}
					if (matrix[i + 1][j] == 9)
					{
						++nr;
					}
				}
				else
				{
					if (matrix[i - 1][j - 1] == 9)
					{
						++nr;
					}
					if (matrix[i - 1][j] == 9)
					{
						++nr;
					}
					if (matrix[i - 1][j + 1] == 9)
					{
						++nr;
					}
					if (matrix[i][j + 1] == 9)
					{
						++nr;
					}
					if (matrix[i + 1][j + 1] == 9)
					{
						++nr;
					}
					if (matrix[i + 1][j] == 9)
					{
						++nr;
					}
					if (matrix[i + 1][j - 1] == 9)
					{
						++nr;
					}
					if (matrix[i][j - 1] == 9)
					{
						++nr;
					}
				}

				matrix[i][j] = nr;
			}
		}

	}
}

void ask_for_input()
{
	do {
		printf("\nEnter the row : ");
		cin >> row;
	} while (row < 1 || row >8);

	do {
		printf("Enter the column : ");
		cin >> column;
	} while (column < 1 || column > 8);

	printf("Enter the action (\"o\",\"f\") : ");
	cin >> action;

	if (action != 'o' && action != 'f')
	{
		do {
			printf("\nInvalid action . Avaible actions -> o - open , f -> flag\nPlease ,enter the action : ");
			cin >> action;
		} while (action != 'o' && action != 'f');
	}
}

void pause_loop()
{
	int i;
	for (i = 0; i < 2000000000; i++)
	{
		// nothing here , go away
	}
}

//lines = 25		columns = 35
void print_matrix_shell()
{
	int i, j;
	for (i = 0; i < 25; i++)
	{
		for (j = 0; j < 35; j++)
		{
			if (matrix_shell[i][j] == 'F')
			{
				SetConsoleTextAttribute(console, 13);
				cout << matrix_shell[i][j];
				SetConsoleTextAttribute(console, 15);
			}
			else if (matrix_shell[i][j] == '1' && i > 1 && j > 1)
			{
				SetConsoleTextAttribute(console, 11);
				cout << matrix_shell[i][j];
				SetConsoleTextAttribute(console, 15);
			}
			else if (matrix_shell[i][j] == '2' && i > 1 && j > 1)
			{
				SetConsoleTextAttribute(console, 10);
				cout << matrix_shell[i][j];
				SetConsoleTextAttribute(console, 15);
			}
			else if (matrix_shell[i][j] == '3' && i > 1 && j > 1)
			{
				SetConsoleTextAttribute(console, 12);
				cout << matrix_shell[i][j];
				SetConsoleTextAttribute(console, 15);
			}
			else if (matrix_shell[i][j] == '4' && i > 1 && j > 1)
			{
				SetConsoleTextAttribute(console, 12);
				cout << matrix_shell[i][j];
				SetConsoleTextAttribute(console, 15);
			}
			else if (matrix_shell[i][j] == '5' && i > 1 && j > 1)
			{
				SetConsoleTextAttribute(console, 12);
				cout << matrix_shell[i][j];
				SetConsoleTextAttribute(console, 15);
			}
			else
			{
				cout << matrix_shell[i][j];
			}
		}
		cout << endl;
	}
}

void show_the_entire_matrix()
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (matrix[i][j] == 0)
			{
				matrix_shell[i * 3 + 2][j * 4 + 4] = ' ';
			}
			else if (matrix[i][j] == 1)
			{
				matrix_shell[i * 3 + 2][j * 4 + 4] = '1';
			}
			else if (matrix[i][j] == 2)
			{
				matrix_shell[i * 3 + 2][j * 4 + 4] = '2';
			}
			else if (matrix[i][j] == 3)
			{
				matrix_shell[i * 3 + 2][j * 4 + 4] = '3';
			}
			else if (matrix[i][j] == 4)
			{
				matrix_shell[i * 3 + 2][j * 4 + 4] = '4';
			}
			else if (matrix[i][j] == 5)
			{
				matrix_shell[i * 3 + 2][j * 4 + 4] = '5';
			}
			else if (matrix[i][j] == 6)
			{
				matrix_shell[i * 3 + 2][j * 4 + 4] = '6';
			}
			else if (matrix[i][j] == 7)
			{
				matrix_shell[i * 3 + 2][j * 4 + 4] = '7';
			}
			else if (matrix[i][j] == 9)
			{
				matrix_shell[i * 3 + 2][j * 4 + 4] = bomb;
			}
		}
	}

	printf("\n\n");
	for (i = 0; i < 25; i++)
	{
		for (j = 0; j < 35; j++)
		{
			if (matrix_shell[i][j] == 'F')
			{
				SetConsoleTextAttribute(console, 13);
				cout << matrix_shell[i][j];
				SetConsoleTextAttribute(console, 15);
			}
			else if (matrix_shell[i][j] == '1' && i > 1 && j > 1)
			{
				SetConsoleTextAttribute(console, 11);
				cout << matrix_shell[i][j];
				SetConsoleTextAttribute(console, 15);
			}
			else if (matrix_shell[i][j] == '2' && i > 1 && j > 1)
			{
				SetConsoleTextAttribute(console, 10);
				cout << matrix_shell[i][j];
				SetConsoleTextAttribute(console, 15);
			}
			else if (matrix_shell[i][j] == '3' && i > 1 && j > 1)
			{
				SetConsoleTextAttribute(console, 12);
				cout << matrix_shell[i][j];
				SetConsoleTextAttribute(console, 15);
			}
			else if (matrix_shell[i][j] == '4' && i > 1 && j > 1)
			{
				SetConsoleTextAttribute(console, 12);
				cout << matrix_shell[i][j];
				SetConsoleTextAttribute(console, 15);
			}
			else if (matrix_shell[i][j] == '5' && i > 1 && j > 1)
			{
				SetConsoleTextAttribute(console, 12);
				cout << matrix_shell[i][j];
				SetConsoleTextAttribute(console, 15);
			}
			else
			{
				cout << matrix_shell[i][j];
			}
		}
		cout << endl;
	}
}

void level_easy()
{
	system("cls");
	printf("\n --- Welcome to MINESWEEPER ---\n --- This is the easy mode ---\n --- Good luck ---\n\n     Loading . . .   \n\n~~~~~PLEASE WAIT~~~~~\n");
	pause_loop();
	
	clock_t start;
	double duration;
	start = clock();

	system("cls");
	print_matrix_shell();
	generate_matrix();
	ask_for_input();

	while (true)
	{	//action = flag
		if (action == 'f')
		{
			if (matrix_shell[(row - 1) * 3 + 2][(column - 1) * 4 + 4] == 'F')
			{
				matrix_shell[(row - 1) * 3 + 2][(column - 1) * 4 + 4] = square;
				--noFlags;
			}
			else if (noFlags == 10)
			{
				printf("\nToo many flags . . .  ");
				for (int i = 0; i < 900000000; i++)
				{
					//just a little pause to read
				}
			}
			else if (matrix_shell[(row - 1) * 3 + 2][(column - 1) * 4 + 4] == square)
			{
				matrix_shell[(row - 1) * 3 + 2][(column - 1) * 4 + 4] = 'F';
				++noFlags;
			}
			else
			{
				printf("\nYou cannot put the flag there . . .");
				for (int i = 0; i < 900000000; i++)
				{
					//just a little pause to read
				}
			}
		}
		//action = open
		else
		{
			if (matrix[row - 1][column - 1] == 0)
			{
				reveal_empty_space(row - 1, column - 1);
			}
			else if (matrix[row - 1][column - 1] == 1)
			{
				if (matrix_shell[(row - 1) * 3 + 2][(column - 1) * 4 + 4] == 'F')
				{
					--noFlags;
				}
				matrix_shell[(row - 1) * 3 + 2][(column - 1) * 4 + 4] = '1';

				if (visitedMatrix[row - 1][column - 1] != 1)
				{
					--win;
				}
				visitedMatrix[row - 1][column - 1] = 1;


			}
			else if (matrix[row - 1][column - 1] == 2)
			{
				if (matrix_shell[(row - 1) * 3 + 2][(column - 1) * 4 + 4] == 'F')
				{
					--noFlags;
				}
				matrix_shell[(row - 1) * 3 + 2][(column - 1) * 4 + 4] = '2';

				if (visitedMatrix[row - 1][column - 1] != 1)
				{
					--win;
				}
				visitedMatrix[row - 1][column - 1] = 1;

			}
			else if (matrix[row - 1][column - 1] == 3)
			{
				if (matrix_shell[(row - 1) * 3 + 2][(column - 1) * 4 + 4] == 'F')
				{
					--noFlags;
				}
				matrix_shell[(row - 1) * 3 + 2][(column - 1) * 4 + 4] = '3';

				if (visitedMatrix[row - 1][column - 1] != 1)
				{
					--win;
				}
				visitedMatrix[row - 1][column - 1] = 1;

			}
			else if (matrix[row - 1][column - 1] == 4)
			{
				if (matrix_shell[(row - 1) * 3 + 2][(column - 1) * 4 + 4] == 'F')
				{
					--noFlags;
				}
				matrix_shell[(row - 1) * 3 + 2][(column - 1) * 4 + 4] = '4';

				if (visitedMatrix[row - 1][column - 1] != 1)
				{
					--win;
				}
				visitedMatrix[row - 1][column - 1] = 1;

			}
			else if (matrix[row - 1][column - 1] == 5)
			{
				if (matrix_shell[(row - 1) * 3 + 2][(column - 1) * 4 + 4] == 'F')
				{
					--noFlags;
				}
				matrix_shell[(row - 1) * 3 + 2][(column - 1) * 4 + 4] = '5';

				if (visitedMatrix[row - 1][column - 1] != 1)
				{
					--win;
				}
				visitedMatrix[row - 1][column - 1] = 1;

			}
			else if (matrix[row - 1][column - 1] == 6)
			{
				if (matrix_shell[(row - 1) * 3 + 2][(column - 1) * 4 + 4] == 'F')
				{
					--noFlags;
				}
				matrix_shell[(row - 1) * 3 + 2][(column - 1) * 4 + 4] = '6';

				if (visitedMatrix[row - 1][column - 1] != 1)
				{
					--win;
				}
				visitedMatrix[row - 1][column - 1] = 1;

			}
			else if (matrix[row - 1][column - 1] == 7)
			{
				if (matrix_shell[(row - 1) * 3 + 2][(column - 1) * 4 + 4] == 'F')
				{
					--noFlags;
				}
				matrix_shell[(row - 1) * 3 + 2][(column - 1) * 4 + 4] = '7';

				if (visitedMatrix[row - 1][column - 1] != 1)
				{
					--win;
				}
				visitedMatrix[row - 1][column - 1] = 1;

			}
		}
		if (win == 10)
		{
			system("cls");
			print_you_win();
			break;
		}
		if (matrix[row - 1][column - 1] == 9 && action == 'o')
		{
			system("cls");
			print_you_lose();
			show_the_entire_matrix();
			break;
		}
		system("cls");
		print_matrix_shell();
		ask_for_input();

	}

	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	printf("\nYour time : %1.1f seconds\n", duration);
}

void print_you_lose()
{
	system("cls");
	printf("\n\n-------BOOOOOOOM !!!!! -------");
	printf("\n---------YOU LOSE ----------\n");
}

void print_you_win()
{
	system("cls");
	printf("\n\n-------Congratulations !!!!! -------");
	printf("\n---------YOU WIN ----------\n");
}

void reveal_empty_space(int i,int j)
{
	if (matrix[i][j] == 0)
	{
		if (matrix_shell[i * 3 + 2][j * 4 + 4] == 'F')
		{
			--noFlags;
		}
		matrix_shell[i * 3 + 2][j * 4 + 4] = ' ';
		if (visitedMatrix[i][j] != 1)
		{
			--win;
		}
		visitedMatrix[i][j] = 1;
		reveal_neighbors(i, j);


	}
	if (j - 1 >= 0 && (matrix[i][j - 1] == 0) && visitedMatrix[i][j - 1] == 0)
	{
		reveal_empty_space(i, j - 1);
	}
	if (j + 1 <= 7 && (matrix[i][j + 1] == 0) && visitedMatrix[i][j + 1] == 0)
	{
		reveal_empty_space(i, j + 1);
	}
	if (i - 1 >= 0 && (matrix[i - 1][j] == 0) && visitedMatrix[i - 1][j] == 0)
	{
		reveal_empty_space(i - 1, j);
	}
	if (i + 1 <= 7 && (matrix[i + 1][j] == 0) && visitedMatrix[i + 1][j] == 0)
	{
		reveal_empty_space(i + 1, j);
	}
	if (i - 1  >= 0 && j - 1 >= 0 && (matrix[i - 1][j - 1] == 0) && visitedMatrix[i - 1][j - 1] == 0)
	{
		reveal_empty_space(i - 1, j - 1);
	}
	if (i - 1 >= 0 && j + 1 <= 7 && (matrix[i - 1][j + 1] == 0) && visitedMatrix[i - 1][j + 1] == 0)
	{
		reveal_empty_space(i - 1, j + 1);
	}
	if (i + 1 <= 7 && j + 1 <= 7 && (matrix[i + 1][j + 1] == 0) && visitedMatrix[i + 1][j + 1] == 0)
	{
		reveal_empty_space(i + 1, j + 1);
	}
	if (i + 1 <= 7 && j - 1 >= 0 && (matrix[i + 1][j - 1] == 0) && visitedMatrix[i + 1][j -1] == 0)
	{
		reveal_empty_space(i + 1, j - 1);
	}
}

void visitedMatrix_equal_zero()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			visitedMatrix[i][j] = 0;
		}
	}
}

void reveal_neighbors(int i, int j)
{
	if (j - 1 >= 0)
	{
		matrix_shell[i * 3 + 2][(j - 1) * 4 + 4] = char(matrix[i][j - 1] + 48);
		if (matrix[i][j - 1] == 0)
		{
			matrix_shell[i * 3 + 2][(j - 1) * 4 + 4] = ' ';
		}
		if (matrix[i][j - 1] != 0 && visitedMatrix[i][j - 1] != 1)
		{
			--win;
			visitedMatrix[i][j - 1] = 1;

		}
	}
	if (j - 1 >= 0 && i - 1 >= 0)
	{
		matrix_shell[(i - 1) * 3 + 2][(j - 1) * 4 + 4] = char(matrix[i - 1][j - 1] + 48);
		if (matrix[i - 1][j - 1] == 0)
		{
			matrix_shell[(i - 1) * 3 + 2][(j - 1) * 4 + 4] = ' ';
		}
		if (matrix[i - 1][j - 1] != 0 && visitedMatrix[i - 1][j - 1] != 1)
		{
			--win;
			visitedMatrix[i - 1][j - 1] = 1;

		}
	}
	if (i - 1 >= 0)
	{
		matrix_shell[(i - 1) * 3 + 2][j * 4 + 4] = char(matrix[i - 1][j] + 48);
		if (matrix[i - 1][j] == 0)
		{
			matrix_shell[(i - 1) * 3 + 2][j * 4 + 4] = ' ';
		}
		if (matrix[i - 1][j] != 0 && visitedMatrix[i - 1][j] != 1)
		{
			--win;
			visitedMatrix[i - 1][j] = 1;

		}
	}
	if (i - 1 >= 0 && j + 1 <= 7)
	{
		matrix_shell[(i - 1) * 3 + 2][(j + 1) * 4 + 4] = char(matrix[i - 1][j + 1] + 48);
		if (matrix[i - 1][j + 1] == 0)
		{
			matrix_shell[(i - 1) * 3 + 2][(j + 1) * 4 + 4] = ' ';
		}
		if (matrix[i - 1][j + 1] != 0 && visitedMatrix[i - 1][j + 1] != 1)
		{
			--win;
			visitedMatrix[i - 1][j + 1] = 1;

		}
	}
	if (j + 1 <= 7)
	{
		matrix_shell[i * 3 + 2][(j + 1) * 4 + 4] = char(matrix[i][j + 1] + 48);
		if (matrix[i][j + 1] == 0)
		{
			matrix_shell[i * 3 + 2][(j + 1) * 4 + 4] = ' ';
		}
		if (matrix[i][j + 1] != 0 && visitedMatrix[i][j + 1] != 1)
		{
			--win;
			visitedMatrix[i][j + 1] = 1;

		}
	}
	if (i + 1 <= 7 && j + 1 <= 7)
	{
		matrix_shell[(i + 1) * 3 + 2][(j + 1) * 4 + 4] = char(matrix[i + 1][j + 1] + 48);
		if (matrix[i + 1][j + 1] == 0)
		{
			matrix_shell[(i + 1) * 3 + 2][(j + 1) * 4 + 4] = ' ';
		}
		if (matrix[i + 1][j + 1] != 0 && visitedMatrix[i + 1][j + 1] != 1)
		{
			--win;
			visitedMatrix[i + 1][j + 1] = 1;

		}
	}
	if (i + 1 <= 7)
	{
		matrix_shell[(i + 1) * 3 + 2][j * 4 + 4] = char(matrix[i + 1][j] + 48);
		if (matrix[i + 1][j] == 0)
		{
			matrix_shell[(i + 1) * 3 + 2][j * 4 + 4] = ' ';
		}
		if (matrix[i + 1][j] != 0 && visitedMatrix[i + 1][j] != 1)
		{
			--win;
			visitedMatrix[i + 1][j] = 1;

		}
	}
	if (i + 1 <= 7 && j - 1 >= 0)
	{
		matrix_shell[(i + 1) * 3 + 2][(j - 1) * 4 + 4] = char(matrix[i + 1][j - 1] + 48);
		if (matrix[i + 1][j - 1] == 0)
		{
			matrix_shell[(i + 1) * 3 + 2][(j - 1) * 4 + 4] = ' ';
		}
		if (matrix[i + 1][j - 1] != 0 && visitedMatrix[i + 1][j - 1] != 1)
		{
			--win;
			visitedMatrix[i + 1][j - 1] = 1;

		}
	}
}

void print_instructions()
{
	printf("You are presented with a board of squares.Some squares contain mines(bombs), others don't.\n If you act on a square containing a bomb, you lose.\n If you manage to act all the squares (without acting on any bombs) you win.");
	printf("\nActing a square which doesn't have a bomb reveals the number of neighbouring squares containing bombs.\nUse this information plus some guess work to avoid the bombs.");
	printf("\nTo open a square, point at the square and act on it.\nTo mark a square you think is a bomb, point and act is \"f\" action .");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                             M E D I U M        L E V E L																	   //
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void initialize_matrix2_shell()
{
	int i, j;
	for (i = 0; i < 16; i++)
	{
		for (j = 0; j < 16; j++)
		{
			matrix2_shell[i * 3 + 2][j * 4 + 4] = square;
		}
	}
}

void visitedMatrix2_equal_zero()
{
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			visitedMatrix2[i][j] = 0;
		}
	}
}

void print_matrix2_shell()
{
	int i, j;
	for (i = 0; i < 49; i++)
	{
		for (j = 0; j < 67; j++)
		{
			if (matrix2_shell[i][j] == 'F')
			{
				SetConsoleTextAttribute(console, 13);
				cout << matrix2_shell[i][j];
				SetConsoleTextAttribute(console, 15);
			}
			else if (matrix2_shell[i][j] == '1' && i > 1 && j > 1)
			{
				SetConsoleTextAttribute(console, 11);
				cout << matrix2_shell[i][j];
				SetConsoleTextAttribute(console, 15);
			}
			else if (matrix2_shell[i][j] == '2' && i > 1 && j > 1)
			{
				SetConsoleTextAttribute(console, 10);
				cout << matrix2_shell[i][j];
				SetConsoleTextAttribute(console, 15);
			}
			else if (matrix2_shell[i][j] == '3' && i > 1 && j > 1)
			{
				SetConsoleTextAttribute(console, 12);
				cout << matrix2_shell[i][j];
				SetConsoleTextAttribute(console, 15);
			}
			else if (matrix2_shell[i][j] == '4' && i > 1 && j > 1)
			{
				SetConsoleTextAttribute(console, 12);
				cout << matrix2_shell[i][j];
				SetConsoleTextAttribute(console, 15);
			}
			else if (matrix2_shell[i][j] == '5' && i > 1 && j > 1)
			{
				SetConsoleTextAttribute(console, 12);
				cout << matrix2_shell[i][j];
				SetConsoleTextAttribute(console, 15);
			}
			else
			{
				cout << matrix2_shell[i][j];
			}
		}
		cout << endl;
	}
}

void ask_for_input_v2()
{
	do {
		printf("\nEnter the row : ");
		cin >> row;
	} while (row < 1 || row > 16);

	do {
		printf("Enter the column : ");
		cin >> column;
	} while (column < 1 || column > 16);

	printf("Enter the action (\"o\",\"f\") : ");
	cin >> action;

	if (action != 'o' && action != 'f')
	{
		do {
			printf("\nInvalid action . Avaible actions -> o - open , f -> flag\nPlease ,enter the action : ");
			cin >> action;
		} while (action != 'o' && action != 'f');
	}
}

void generate_mine_v2(unsigned short &i, unsigned short &j)
{
	i = rand() % 16;
	j = rand() % 16;
}

void generate_matrix2()
{
	srand(time(NULL));
	unsigned short i, j, nr, index;
	int  noMines;
	int checkMine[20];
	bool ok;

	//initialized with 0
	for (i = 0; i < 16; i++)
	{
		for (j = 0; j < 16; j++)
		{
			matrix2[i][j] = 0;
		}
	}
	//intialize checkMine
	for (i = 0; i < 20; i++)
	{
		checkMine[i] = -1;
	}
	//generate mines
	noMines = 0;
	while (noMines != 20)
	{
		ok = true;
		generate_mine_v2(i, j);
		nr = i * 10 + j;
		for (index = 0; index < 20; index++)
		{
			if (nr == checkMine[index])
			{
				ok = false;
			}
		}
		if (ok == true)
		{
			checkMine[noMines] = nr;
			matrix2[i][j] = 9;
			++noMines;
		}
	}

	nr = 0;
	//starting from here it generates the matrix
	for (i = 0; i < 16; i++)
	{
		for (j = 0; j < 16; j++)
		{
			nr = 0;
			if (matrix2[i][j] != 9)
			{
				if (i == 0 && j == 0)
				{
					if (matrix2[i][j + 1] == 9)
					{
						++nr;
					}
					if (matrix2[i + 1][j + 1] == 9)
					{
						++nr;
					}
					if (matrix2[i + 1][j] == 9)
					{
						++nr;
					}
				}
				else if (i == 0 && j == 15)
				{
					if (matrix2[i][j - 1] == 9)
					{
						++nr;
					}
					if (matrix2[i + 1][j - 1] == 9)
					{
						++nr;
					}
					if (matrix2[i + 1][j] == 9)
					{
						++nr;
					}
				}
				else if (i == 15 && j == 0)
				{
					if (matrix2[i - 1][j] == 9)
					{
						++nr;
					}
					if (matrix2[i - 1][j + 1] == 9)
					{
						++nr;
					}
					if (matrix2[i][j + 1] == 9)
					{
						++nr;
					}
				}
				else if (i == 15 && j == 15)
				{
					if (matrix2[i][j - 1] == 9)
					{
						++nr;
					}
					if (matrix2[i - 1][j - 1] == 9)
					{
						++nr;
					}
					if (matrix2[i - 1][j] == 9)
					{
						++nr;
					}
				}
				else if (i == 0 && (j >= 1 && j <= 14))
				{
					if (matrix2[i][j - 1] == 9)
					{
						++nr;
					}
					if (matrix2[i + 1][j - 1] == 9)
					{
						++nr;
					}
					if (matrix2[i + 1][j] == 9)
					{
						++nr;
					}
					if (matrix2[i + 1][j + 1] == 9)
					{
						++nr;
					}
					if (matrix2[i][j + 1] == 9)
					{
						++nr;
					}
				}
				else if (i == 15 && (j >= 1 && j <= 14))
				{
					if (matrix2[i][j - 1] == 9)
					{
						++nr;
					}
					if (matrix2[i - 1][j - 1] == 9)
					{
						++nr;
					}
					if (matrix2[i - 1][j] == 9)
					{
						++nr;
					}
					if (matrix2[i - 1][j + 1] == 9)
					{
						++nr;
					}
					if (matrix2[i][j + 1] == 9)
					{
						++nr;
					}
				}
				else if (j == 0 && (i >= 1 && i <= 14))
				{
					if (matrix2[i - 1][j] == 9)
					{
						++nr;
					}
					if (matrix2[i - 1][j + 1] == 9)
					{
						++nr;
					}
					if (matrix2[i][j + 1] == 9)
					{
						++nr;
					}
					if (matrix2[i + 1][j + 1] == 9)
					{
						++nr;
					}
					if (matrix2[i + 1][j] == 9)
					{
						++nr;
					}
				}
				else if (j == 15 && (i >= 1 && i <= 14))
				{
					if (matrix2[i - 1][j] == 9)
					{
						++nr;
					}
					if (matrix2[i - 1][j - 1] == 9)
					{
						++nr;
					}
					if (matrix2[i][j - 1] == 9)
					{
						++nr;
					}
					if (matrix2[i + 1][j - 1] == 9)
					{
						++nr;
					}
					if (matrix2[i + 1][j] == 9)
					{
						++nr;
					}
				}
				else
				{
					if (matrix2[i - 1][j - 1] == 9)
					{
						++nr;
					}
					if (matrix2[i - 1][j] == 9)
					{
						++nr;
					}
					if (matrix2[i - 1][j + 1] == 9)
					{
						++nr;
					}
					if (matrix2[i][j + 1] == 9)
					{
						++nr;
					}
					if (matrix2[i + 1][j + 1] == 9)
					{
						++nr;
					}
					if (matrix2[i + 1][j] == 9)
					{
						++nr;
					}
					if (matrix2[i + 1][j - 1] == 9)
					{
						++nr;
					}
					if (matrix2[i][j - 1] == 9)
					{
						++nr;
					}
				}

				matrix2[i][j] = nr;
			}
		}

	}
}

void show_the_entire_matrix2()
{
	int i, j;
	for (i = 0; i < 16; i++)
	{
		for (j = 0; j < 16; j++)
		{
			if (matrix2[i][j] == 0)
			{
				matrix2_shell[i * 3 + 2][j * 4 + 4] = ' ';
			}
			else if (matrix2[i][j] == 1)
			{
				matrix2_shell[i * 3 + 2][j * 4 + 4] = '1';
			}
			else if (matrix2[i][j] == 2)
			{
				matrix2_shell[i * 3 + 2][j * 4 + 4] = '2';
			}
			else if (matrix2[i][j] == 3)
			{
				matrix2_shell[i * 3 + 2][j * 4 + 4] = '3';
			}
			else if (matrix2[i][j] == 4)
			{
				matrix2_shell[i * 3 + 2][j * 4 + 4] = '4';
			}
			else if (matrix2[i][j] == 5)
			{
				matrix2_shell[i * 3 + 2][j * 4 + 4] = '5';
			}
			else if (matrix2[i][j] == 6)
			{
				matrix2_shell[i * 3 + 2][j * 4 + 4] = '6';
			}
			else if (matrix2[i][j] == 7)
			{
				matrix2_shell[i * 3 + 2][j * 4 + 4] = '7';
			}
			else if (matrix2[i][j] == 9)
			{
				matrix2_shell[i * 3 + 2][j * 4 + 4] = bomb;
			}
		}
	}

	printf("\n\n");
	for (i = 0; i < 49; i++)
	{
		for (j = 0; j < 67; j++)
		{
			if (matrix2_shell[i][j] == 'F')
			{
				SetConsoleTextAttribute(console, 13);
				cout << matrix2_shell[i][j];
				SetConsoleTextAttribute(console, 15);
			}
			else if (matrix2_shell[i][j] == '1' && i > 1 && j > 1)
			{
				SetConsoleTextAttribute(console, 11);
				cout << matrix2_shell[i][j];
				SetConsoleTextAttribute(console, 15);
			}
			else if (matrix2_shell[i][j] == '2' && i > 1 && j > 1)
			{
				SetConsoleTextAttribute(console, 10);
				cout << matrix2_shell[i][j];
				SetConsoleTextAttribute(console, 15);
			}
			else if (matrix2_shell[i][j] == '3' && i > 1 && j > 1)
			{
				SetConsoleTextAttribute(console, 12);
				cout << matrix2_shell[i][j];
				SetConsoleTextAttribute(console, 15);
			}
			else if (matrix2_shell[i][j] == '4' && i > 1 && j > 1)
			{
				SetConsoleTextAttribute(console, 12);
				cout << matrix2_shell[i][j];
				SetConsoleTextAttribute(console, 15);
			}
			else if (matrix2_shell[i][j] == '5' && i > 1 && j > 1)
			{
				SetConsoleTextAttribute(console, 12);
				cout << matrix2_shell[i][j];
				SetConsoleTextAttribute(console, 15);
			}
			else
			{
				cout << matrix2_shell[i][j];
			}
		}
		cout << endl;
	}
}

void reveal_empty_space_v2(int i, int j)
{
	if (matrix2[i][j] == 0)
	{
		if (matrix2_shell[i * 3 + 2][j * 4 + 4] == 'F')
		{
			--noFlags;
		}
		matrix2_shell[i * 3 + 2][j * 4 + 4] = ' ';
		if (visitedMatrix2[i][j] != 1)
		{
			--win;
		}
		visitedMatrix2[i][j] = 1;
		reveal_neighbors_v2(i, j);


	}
	if (j - 1 >= 0 && (matrix2[i][j - 1] == 0) && visitedMatrix2[i][j - 1] == 0)
	{
		reveal_empty_space_v2(i, j - 1);
	}
	if (j + 1 <= 15 && (matrix2[i][j + 1] == 0) && visitedMatrix2[i][j + 1] == 0)
	{
		reveal_empty_space_v2(i, j + 1);
	}
	if (i - 1 >= 0 && (matrix2[i - 1][j] == 0) && visitedMatrix2[i - 1][j] == 0)
	{
		reveal_empty_space_v2(i - 1, j);
	}
	if (i + 1 <= 15 && (matrix[i + 1][j] == 0) && visitedMatrix2[i + 1][j] == 0)
	{
		reveal_empty_space_v2(i + 1, j);
	}
	if (i - 1 >= 0 && j - 1 >= 0 && (matrix2[i - 1][j - 1] == 0) && visitedMatrix2[i - 1][j - 1] == 0)
	{
		reveal_empty_space_v2(i - 1, j - 1);
	}
	if (i - 1 >= 0 && j + 1 <= 15 && (matrix2[i - 1][j + 1] == 0) && visitedMatrix2[i - 1][j + 1] == 0)
	{
		reveal_empty_space_v2(i - 1, j + 1);
	}
	if (i + 1 <= 15 && j + 1 <= 15 && (matrix2[i + 1][j + 1] == 0) && visitedMatrix2[i + 1][j + 1] == 0)
	{
		reveal_empty_space_v2(i + 1, j + 1);
	}
	if (i + 1 <= 15 && j - 1 >= 0 && (matrix2[i + 1][j - 1] == 0) && visitedMatrix2[i + 1][j - 1] == 0)
	{
		reveal_empty_space_v2(i + 1, j - 1);
	}
}

void reveal_neighbors_v2(int i, int j)
{
	if (j - 1 >= 0)
	{
		matrix2_shell[i * 3 + 2][(j - 1) * 4 + 4] = char(matrix2[i][j - 1] + 48);
		if (matrix2[i][j - 1] == 0)
		{
			matrix2_shell[i * 3 + 2][(j - 1) * 4 + 4] = ' ';
		}
		if (matrix2[i][j - 1] != 0 && visitedMatrix2[i][j - 1] != 1)
		{
			--win;
			visitedMatrix2[i][j - 1] = 1;

		}
	}
	if (j - 1 >= 0 && i - 1 >= 0)
	{
		matrix2_shell[(i - 1) * 3 + 2][(j - 1) * 4 + 4] = char(matrix2[i - 1][j - 1] + 48);
		if (matrix2[i - 1][j - 1] == 0)
		{
			matrix2_shell[(i - 1) * 3 + 2][(j - 1) * 4 + 4] = ' ';
		}
		if (matrix2[i - 1][j - 1] != 0 && visitedMatrix2[i - 1][j - 1] != 1)
		{
			--win;
			visitedMatrix2[i - 1][j - 1] = 1;

		}
	}
	if (i - 1 >= 0)
	{
		matrix2_shell[(i - 1) * 3 + 2][j * 4 + 4] = char(matrix2[i - 1][j] + 48);
		if (matrix2[i - 1][j] == 0)
		{
			matrix2_shell[(i - 1) * 3 + 2][j * 4 + 4] = ' ';
		}
		if (matrix2[i - 1][j] != 0 && visitedMatrix2[i - 1][j] != 1)
		{
			--win;
			visitedMatrix2[i - 1][j] = 1;

		}
	}
	if (i - 1 >= 0 && j + 1 <= 15)
	{
		matrix2_shell[(i - 1) * 3 + 2][(j + 1) * 4 + 4] = char(matrix2[i - 1][j + 1] + 48);
		if (matrix2[i - 1][j + 1] == 0)
		{
			matrix2_shell[(i - 1) * 3 + 2][(j + 1) * 4 + 4] = ' ';
		}
		if (matrix2[i - 1][j + 1] != 0 && visitedMatrix2[i - 1][j + 1] != 1)
		{
			--win;
			visitedMatrix2[i - 1][j + 1] = 1;

		}
	}
	if (j + 1 <= 15)
	{
		matrix2_shell[i * 3 + 2][(j + 1) * 4 + 4] = char(matrix2[i][j + 1] + 48);
		if (matrix2[i][j + 1] == 0)
		{
			matrix2_shell[i * 3 + 2][(j + 1) * 4 + 4] = ' ';
		}
		if (matrix2[i][j + 1] != 0 && visitedMatrix2[i][j + 1] != 1)
		{
			--win;
			visitedMatrix2[i][j + 1] = 1;

		}
	}
	if (i + 1 <= 15 && j + 1 <= 15)
	{
		matrix2_shell[(i + 1) * 3 + 2][(j + 1) * 4 + 4] = char(matrix2[i + 1][j + 1] + 48);
		if (matrix2[i + 1][j + 1] == 0)
		{
			matrix2_shell[(i + 1) * 3 + 2][(j + 1) * 4 + 4] = ' ';
		}
		if (matrix2[i + 1][j + 1] != 0 && visitedMatrix2[i + 1][j + 1] != 1)
		{
			--win;
			visitedMatrix2[i + 1][j + 1] = 1;

		}
	}
	if (i + 1 <= 15)
	{
		matrix2_shell[(i + 1) * 3 + 2][j * 4 + 4] = char(matrix2[i + 1][j] + 48);
		if (matrix2[i + 1][j] == 0)
		{
			matrix2_shell[(i + 1) * 3 + 2][j * 4 + 4] = ' ';
		}
		if (matrix2[i + 1][j] != 0 && visitedMatrix2[i + 1][j] != 1)
		{
			--win;
			visitedMatrix2[i + 1][j] = 1;

		}
	}
	if (i + 1 <= 15 && j - 1 >= 0)
	{
		matrix2_shell[(i + 1) * 3 + 2][(j - 1) * 4 + 4] = char(matrix2[i + 1][j - 1] + 48);
		if (matrix2[i + 1][j - 1] == 0)
		{
			matrix2_shell[(i + 1) * 3 + 2][(j - 1) * 4 + 4] = ' ';
		}
		if (matrix2[i + 1][j - 1] != 0 && visitedMatrix2[i + 1][j - 1] != 1)
		{
			--win;
			visitedMatrix2[i + 1][j - 1] = 1;

		}
	}
}

void level_medium()
{
	system("cls");
	printf("\n --- Welcome to MINESWEEPER ---\n --- This is the MEDIUM mode ---\n --- Good luck ---\n\n     Loading . . .   \n\n~~~~~PLEASE WAIT~~~~~\n");
	pause_loop();

	clock_t start;
	double duration;
	start = clock();

	system("cls");
	print_matrix2_shell();
	generate_matrix2();
	wrong:
	ask_for_input_v2();

	while (true)
	{	//action = flag
		if (action == 'f')
		{
			if (matrix2_shell[(row - 1) * 3 + 2][(column - 1) * 4 + 4] == 'F')
			{
				matrix2_shell[(row - 1) * 3 + 2][(column - 1) * 4 + 4] = square;
				--noFlags;
			}
			else if (noFlags == 20)
			{
				printf("\nToo many flags . . .  ");
				for (int i = 0; i < 900000000; i++)
				{
					//just a little pause to read
				}
			}
			else if (matrix2_shell[(row - 1) * 3 + 2][(column - 1) * 4 + 4] == square)
			{
				matrix2_shell[(row - 1) * 3 + 2][(column - 1) * 4 + 4] = 'F';
				++noFlags;
			}
			else
			{
				printf("\nYou cannot put the flag there . . .");
				for (int i = 0; i < 900000000; i++)
				{
					//just a little pause to read
				}
			}
		}
		//action = open
		else
		{
			if (matrix2[row - 1][column - 1] == 0)
			{
				reveal_empty_space_v2(row - 1, column - 1);
			}
			else if (matrix2[row - 1][column - 1] == 1)
			{
				if (matrix2_shell[(row - 1) * 3 + 2][(column - 1) * 4 + 4] == 'F')
				{
					--noFlags;
				}
				matrix2_shell[(row - 1) * 3 + 2][(column - 1) * 4 + 4] = '1';

				if (visitedMatrix2[row - 1][column - 1] != 1)
				{
					--win;
				}
				visitedMatrix2[row - 1][column - 1] = 1;


			}
			else if (matrix2[row - 1][column - 1] == 2)
			{
				if (matrix2_shell[(row - 1) * 3 + 2][(column - 1) * 4 + 4] == 'F')
				{
					--noFlags;
				}
				matrix2_shell[(row - 1) * 3 + 2][(column - 1) * 4 + 4] = '2';

				if (visitedMatrix2[row - 1][column - 1] != 1)
				{
					--win;
				}
				visitedMatrix2[row - 1][column - 1] = 1;

			}
			else if (matrix2[row - 1][column - 1] == 3)
			{
				if (matrix2_shell[(row - 1) * 3 + 2][(column - 1) * 4 + 4] == 'F')
				{
					--noFlags;
				}
				matrix2_shell[(row - 1) * 3 + 2][(column - 1) * 4 + 4] = '3';

				if (visitedMatrix2[row - 1][column - 1] != 1)
				{
					--win;
				}
				visitedMatrix2[row - 1][column - 1] = 1;

			}
			else if (matrix2[row - 1][column - 1] == 4)
			{
				if (matrix2_shell[(row - 1) * 3 + 2][(column - 1) * 4 + 4] == 'F')
				{
					--noFlags;
				}
				matrix2_shell[(row - 1) * 3 + 2][(column - 1) * 4 + 4] = '4';

				if (visitedMatrix2[row - 1][column - 1] != 1)
				{
					--win;
				}
				visitedMatrix2[row - 1][column - 1] = 1;

			}
			else if (matrix2[row - 1][column - 1] == 5)
			{
				if (matrix2_shell[(row - 1) * 3 + 2][(column - 1) * 4 + 4] == 'F')
				{
					--noFlags;
				}
				matrix2_shell[(row - 1) * 3 + 2][(column - 1) * 4 + 4] = '5';

				if (visitedMatrix2[row - 1][column - 1] != 1)
				{
					--win;
				}
				visitedMatrix2[row - 1][column - 1] = 1;

			}
			else if (matrix2[row - 1][column - 1] == 6)
			{
				if (matrix2_shell[(row - 1) * 3 + 2][(column - 1) * 4 + 4] == 'F')
				{
					--noFlags;
				}
				matrix2_shell[(row - 1) * 3 + 2][(column - 1) * 4 + 4] = '6';

				if (visitedMatrix2[row - 1][column - 1] != 1)
				{
					--win;
				}
				visitedMatrix2[row - 1][column - 1] = 1;

			}
			else if (matrix2[row - 1][column - 1] == 7)
			{
				if (matrix2_shell[(row - 1) * 3 + 2][(column - 1) * 4 + 4] == 'F')
				{
					--noFlags;
				}
				matrix2_shell[(row - 1) * 3 + 2][(column - 1) * 4 + 4] = '7';

				if (visitedMatrix2[row - 1][column - 1] != 1)
				{
					--win;
				}
				visitedMatrix2[row - 1][column - 1] = 1;

			}
		}
		if (win == 20)
		{
			system("cls");
			print_you_win();
			break;
		}
		if (matrix2[row - 1][column - 1] == 9 && action == 'o')
		{
			system("cls");
			print_you_lose();
			show_the_entire_matrix2();
			break;
		}
		system("cls");
		print_matrix2_shell();
		ask_for_input_v2();

	}

	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	printf("\nYour time : %1.1f seconds\n", duration);
}




int main()
{
	menu();
	

	

	//printf("\n\n\n\n");

	//printf("\n\nPress any key to leave . . . ");
	//_getch();
    return 0;
}

