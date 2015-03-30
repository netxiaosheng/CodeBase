#include<stdio.h>
#include<stdlib.h>
#define MaxSize  100

typedef char ElemType;
typedef struct 
{
	ElemType elem[MaxSize];
	int top;	
}SqStack;

void InitStack(SqStack **s)
{
	*s = (SqStack *)malloc(sizeof(SqStack));
	(*s)->top = -1;
}

void DestroyStack(SqStack * s)
{
	free(s);
}

void Push(SqStack *s,ElemType e)
{
	if(MaxSize-1 == s->top)
	{
		printf("this stack is full\n");
		return;
	}
	(s->top)++;
	s->elem[s->top] = e;
	return ;
	
}

void Pop(SqStack * s)
{
	if(-1 == s->top)
	{
		printf("this stack is empty\n");
	}
	printf("pop  :%c\n",s->elem[s->top]);
	s->top--;
	return ;
}

void DispStack(SqStack * s)
{
	int i;
	for(i = s->top; i >= 0; i--)
	{
		printf("disp :%c\n",s->elem[i]);
	}
}


int main()
{
	SqStack *s;
	InitStack(&s);
	Push(s,'a');
	Push(s,'b');
	Push(s,'c');
	Push(s,'d');
	Push(s,'e');
	DispStack(s);
	Pop(s);
	Pop(s);
	DispStack(s);
	DestroyStack(s);
	return 0;	
}




