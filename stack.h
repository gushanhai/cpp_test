#include<iostream>
#include<assert.h>
#include<stdlib.h>


#define STDataType int

typedef struct stack
{
	STDataType* a;
	int top;
	int capcity;
}ST;

void STInit(ST* ps);
void STPush(ST* ps, int x);