#include "��ͷ.h"
int main()
{
	FILE* fp;
	int key, i;
	char str[100] = { 0 };
	while (1)
	{
		for (i = 0; str[i] != 0; i++)
			str[i] = 0;
		system("cls");
		printf("�밴�������е���ĸѡ���ܣ�\n[C]reate a table, [L]ist a table exist, [Q]uit:");
		key = getch();
		switch (key)
		{
		case 'c':
		case 'C':printf("\n�������ļ����ƣ�"); 
			gets(str);
			strcat(str, ".hws");
			if ((fp = fopen(str, "w")) == NULL)
			{
				printf("Warning: Failure to create a file!\n");
				printf("��������Լ���...");
				getch();
				continue;
			}
			function1(fp);
			fclose(fp);
			printf("��������Լ���...");
			getch();
			break;
		case 'l':
		case 'L':printf("\n�������ļ����ƣ�");
			gets(str);
			strcat(str, ".hws");
			if ((fp = fopen(str, "r")) == NULL)
			{
				printf("Warning: Failure to open a file!");
				printf("��������Լ���...");
				getch();
				continue;
			}
			function2(fp);
			fclose(fp);
			printf("��������Լ���...");
			getch();
		case 'q':
		case 'Q':return 0;
		default:continue;
		}
	}
	return 0;
}