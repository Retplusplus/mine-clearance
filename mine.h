#ifndef _MINE_H_
#define _MINE_H_



#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

#define ROWS 12
#define COLS 12
#define DEFAULT_MINES 20

#pragma warning(disable:4996)

void SetMines(char mine[][COLS], int _rows, int _cols);
void showBoard(char show[][COLS], int _rows, int _cols);
void PlayGame(char mine[][COLS], char show[][COLS], int _rows, int _cols);
int GetIndexMines(char mine[][COLS], int _x, int _y);
void game();


#endif