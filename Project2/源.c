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
				printf("Warning: Failure to create a file!");
				continue;
			}
			function1(fp);
			fclose(fp);
		}
	}
	return 0;
}