#include"mine.h"

static void menu()
{
	printf("1,play   2,exit\n");
	printf("please input:");
}

int main()
{
	int select = 0;
	while (1)
	{
		menu();
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			game();
			break;
		case 2:
			exit(0);
			break;
		default:
			break;
		}
	}
	//system("pause");
	return 0;
}