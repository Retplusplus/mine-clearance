#include"mine.h"

static int GetRandomIndex(int start, int end)
{
	return rand() % (end - start + 1) + start; 
}



void SetMines(char mine[][COLS], int _rows, int _cols)
{
	int count = DEFAULT_MINES;
	srand((unsigned long)time(NULL));
	while (count)
	{
		int x = GetRandomIndex(1, _rows - 2);
		int y = GetRandomIndex(1, _cols - 2);
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

void     showBoard(char show[][COLS], int _rows, int _cols)
{
	printf("   ");
	int i = 1;
	for (; i <=_cols-2 ; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	printf("---");
	for (i=1; i <= _cols - 2; i++)
	{
		printf("--");
	}
	printf("\n");
	for (i =1 ; i <= _rows - 2; i++)
	{
		printf("%2d|", i);
		for (int j = 1; j <= _cols-2; j++)
		{
			printf("%c ", show[i][j]);
		}
		printf("\n");
	}

}

int GetIndexMines(char mine[][COLS], int x, int y)
{
	return mine[x - 1][y - 1] + mine[x-1][y] + mine[x - 1][y + 1] + \
		mine[x][y-1] + mine[x][y + 1] + \
		mine[x+1][y] + mine[x + 1][y - 1] + mine[x+1][y+1]-8*'0';

}

void Expand(char mine[][COLS], char show[][COLS], int _rows, int _cols)//À©´ó
{
	if ((_rows > 1) && (_cols > 1) && (ROWS-2> _rows)&&(COLS-2>_cols))
	{
		if (show[_rows][_cols]=='0')
		{
			show[_rows][_cols] = ' ';
			if (mine[_rows - 1][_cols - 1] == '0')
			{
				show[_rows - 1][_cols - 1] = GetIndexMines(mine, _rows - 1, _cols - 1) + '0';
			}
			if (mine[_rows - 1][_cols] == '0')
			{
				show[_rows - 1][_cols] = GetIndexMines(mine, _rows - 1, _cols) + '0';
			}
			if (mine[_rows - 1][_cols + 1]=='0')
			{
			show[_rows - 1][_cols + 1] = GetIndexMines(mine, _rows-1, _cols+1) + '0';
			}
			if (mine[_rows][_cols - 1]=='0')
			{
			show[_rows][_cols - 1] = GetIndexMines(mine, _rows, _cols-1) + '0';
			}
			//if()
			show[_rows][_cols + 1] = GetIndexMines(mine, _rows, _cols+1) + '0';

			show[_rows + 1][_cols - 1] = GetIndexMines(mine, _rows+1, _cols-1) + '0';
	
			show[_rows + 1][_cols ] = GetIndexMines(mine, _rows+1, _cols) + '0';

			show[_rows + 1][_cols + 1] = GetIndexMines(mine, _rows+1, _cols+1) + '0';
	
		}
	}
}

void PlayGame(char mine[][COLS],char show[][COLS],int _rows,int _cols)
{
	
	int x, y;
	int is_win = 0;	
	showBoard(show, ROWS, COLS);
	showBoard(mine, ROWS, COLS);

	while (1)
	{
		printf("please enter<rows,cols>:>");
		scanf("%d%d", &x, &y);
		if ((x >= 1 && x <= _rows - 2) && (y >= 1 && y <= _cols - 2))
		{
			if (mine[x][y] == '0')
			{				
				int num = GetIndexMines(mine, x, y);
				show[x][y] = num + '0';
				is_win++;
				Expand(mine, show,x,y);
				showBoard(show, ROWS, COLS);
				if ((_rows - 2)*(_cols - 2) - is_win == DEFAULT_MINES)
				{
					printf("you win\n");
					break;
				}
			}
			else if (is_win == 0)
			{
				for (int i = 1; i <= 10; i++)
				{
					for (int j = 1; j <= 10; j++)
					{
						int tmp = mine[i][j];
						mine[i][j] = mine[x][y];
						mine[x][y] = tmp;
						if (mine[x][y] == '0')
						{
							i += 10;
							j += 10;
						}
						
					}
				}
				int num = GetIndexMines(mine, x, y);
				show[x][y] = num + '0';
				is_win++;
				showBoard(show, ROWS, COLS);
				showBoard(mine, ROWS, COLS);
				if ((_rows - 2)*(_cols - 2) - is_win == DEFAULT_MINES)
				{
					printf("you win\n");
					break;
				}
			}
			else
			{
				printf("Game over\n");
				printf("try again?\n");
				break;
			}
		}
		else
		{
			printf("enter error,try again\n");
		}
	}
}


void game()
{
	char mine[ROWS][COLS];
	char show[ROWS][COLS];
	memset(mine, '0', sizeof(mine));
	memset(show, '*', sizeof(show));
	SetMines(mine, ROWS, COLS);
	//showBoard(show, ROWS, COLS);
	//showBoard(mine, ROWS, COLS);
	PlayGame(mine, show, ROWS, COLS);

	//printf("begin game!\n");

}