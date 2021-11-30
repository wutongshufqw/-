#include "标头.h"
void fieldInput(field* p, int n, int m)//字段创建
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		(p + i)->fieldId = i + 1;
		printf("请输入第%d个字段的类型（int 输入 i;string 输入 s 及长度;char 输入 c;float 输入 f;double 输入 d;long 输入 l;long long 输入 L):\n", i + 1);
		j = getch();
		switch (j)
		{
		case 'i':
		case 'I':(p + i)->fieldType = 'i'; (p + i)->fieldLen = sizeof(int); break;
		case 's':
		case 'S':(p + i)->fieldType = 's'; printf("请输入字符串长度："); scanf("%d", &j); (p + i)->fieldLen = (j + 1) * sizeof(char); break;
		case 'c':
		case 'C':(p + i)->fieldType = 'c'; (p + i)->fieldLen = sizeof(char); break;
		case 'f':
		case 'F':(p + i)->fieldType = 'f'; (p + i)->fieldLen = sizeof(float); break;
		case 'd':
		case 'D':(p + i)->fieldType = 'd'; (p + i)->fieldLen = sizeof(double); break;
		case 'l':(p + i)->fieldType = 'l'; (p + i)->fieldLen = sizeof(long); break;
		case 'L':(p + i)->fieldType = 'L'; (p + i)->fieldLen = sizeof(long long); break;
		default:i--; continue;
		}
		if ((p + i)->fieldType == 's')
			while (getchar() != '\n');
		printf("请输入字段名称：");
		gets((p + i)->fieldCaption);
		system("cls");
		printf("序号\t\t字段类型\t字段名称\n");
		for (j = 0; j <= i; j++)
			printf("%d\t\t%c\t\t%s\n", (p + j)->fieldId, (p + j)->fieldType, (p + j)->fieldCaption);
	}
	for (i = 0; i < n; i++)
		(p + i)->pf = malloc((p + i)->fieldLen * m);
}
void dataInput(field* p, int n, int m)
{
	int i, j;
	for (i = 0; i < m; i++)
	{
		printf("请输入第%d名学生的信息:\n", i + 1);
		for (j = 0; j < n; j++)
		{
			printf("请输入%s:", (p + j)->fieldCaption);
			switch ((p + j)->fieldType)
			{
			case 'i': scanf("%d", (int*)((p + j)->pf) + i); break;
			case 's': scanf("%s", (char*)((p + j)->pf) + i * (p + j)->fieldLen); break;
			case 'c': scanf("%c", (char*)((p + j)->pf) + i); break;
			case 'f': scanf("%f", (float*)((p + j)->pf) + i); break;
			case 'd': scanf("%lf", (double*)((p + j)->pf) + i); break;
			case 'l': scanf("%ld", (long*)((p + j)->pf) + i); break;
			case 'L': scanf("%lld", (long long*)((p + j)->pf) + i); break;
			}
			while (getchar() != '\n');
		}
		system("cls");
	}
}
void dataOutput(field* p, int n, int m)
{
	int i, j;
	for (i = 0; i < n; i++)
		printf("%s", (p + i)->fieldCaption);
	printf("\n");
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			switch ((p + j)->fieldType)
			{
			case 'i': printf("%d\t", *((int*)((p + j)->pf) + i)); break;
			case 's': printf("%s\t", (char*)((p + j)->pf) + i * (p + j)->fieldLen); break;
			case 'c': printf("%c\t", *((char*)((p + j)->pf) + i)); break;
			case 'f': printf("%.2f\t", *((float*)((p + j)->pf) + i)); break;
			case 'd': printf("%.2lf\t", *((double*)((p + j)->pf) + i)); break;
			case 'l': printf("%ld\t", *((long*)((p + j)->pf) + i)); break;
			case 'L': printf("%lld\t", *((long long*)((p + j)->pf) + i)); break;
			}
		}
		printf("\n");
	}
}
int function1(FILE* fp)
{
	int n, m;
	printf("请输入字段数目：");
	scanf("%d", &n);
	field* p = (field*)malloc(n * sizeof(field));
	printf("请输入学生人数：");
	scanf(" %d", &m);
	fprintf(fp, "%d%d", n, m);
	getchar();
	fieldInput(p, n, m);
	system("cls");
	dataInput(p, n, m);
	dataOutput(p, n, m);
	fwrite(p, sizeof(field), n, fp);
	for (int i = 0; i < n; i++)
		fwrite(p[i].pf, p[i].fieldLen, m, fp);
	return 0;
}