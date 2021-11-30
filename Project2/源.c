#include "标头.h"
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
		printf("请按方括号中的字母选择功能：\n[C]reate a table, [L]ist a table exist, [Q]uit:");
		key = getch();
		switch (key)
		{
		case 'c':
		case 'C':printf("\n请输入文件名称："); 
			gets(str);
			strcat(str, ".hws");
			if ((fp = fopen(str, "w")) == NULL)
			{
				printf("Warning: Failure to create a file!");
				continue;
			}
			function1(fp);
			fclose(fp);
			break;
		case 'l':
		case 'L':printf("\n请输入文件名称：");
			gets(str);
			strcat(str, ".hws");
			if ((fp = fopen(str, "r")) == NULL)
			{
				printf("Warning: Failure to open a file!");
				continue;
			}
			function2(fp);
			fclose(fp);
		}
	}
	return 0;
}