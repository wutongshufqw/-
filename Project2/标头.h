#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct FIELD_DATA
{
	int fieldId;
	int fieldLen;
	char fieldType;
	char fieldCaption[11];
	void* pf;
}field;
void fieldInput(field* p, int n, int m);
void dataInput(field* p, int n, int m);
void dataOutput(field* p, int n, int m);
int function1(FILE* fp);
int function2(FILE* fp);