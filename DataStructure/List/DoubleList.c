/*
*
*/
#include<stdio.h>
#include<stdlib.h>

typedef  char ElemType;
typedef struct DNode
{
	ElemType e;
	struct DNode * prior;
	struct DNode * next;
}DLinkList;

void InitList(DLinkList ** h)
{
	*h = (DLinkList *)malloc(sizeof(DLinkList));
	(*h)->prior=(*h)->next = NULL;
}

void DLinkListInsert(DLinkList * L,int i ,ElemType e)
{
	DLinkList * p = L;
	DLinkList * s;
	int j = 0;
	while(p != NULL && j < i-1)
	{
		p = p->next;
		j++;
	}
	if(p == NULL)
	{
		
	}
	else
	{
		s = (DLinkList *)malloc(sizeof(DLinkList));
		s->e = e;
		s->next = p->next;
		if(p->next != NULL)
		{
			s->next->prior = s; 
		}
		s->prior = p;
		p->next = s;
		
	}
}

void DLinkListDelete(DLinkList *L,int i)
{
	int j = 0;
	DLinkList * p = L;
	DLinkList * s;
	while(p != NULL && j < i-1)
	{
		p = p->next;
		j++;
	}
	if(p == NULL)
	{}
	else
	{
		s = p->next;
		if(s ==NULL)
		return ;
		p->next = s->next;
		s->next->prior = p;
		free(s);
		
	}
}

void DispList(DLinkList * L)
{
	DLinkList * p = L->next;
	while(p != NULL)
	{
		printf("%c\n",p->e);
		p = p->next;
	}	
}


int main()
{
	DLinkList *h;
	InitList(&h);
	DLinkListInsert(h,1,'a');
	DLinkListInsert(h,2,'b');
	DLinkListInsert(h,3,'c');
	DLinkListInsert(h,4,'d');
	DLinkListInsert(h,5,'e');
	DLinkListInsert(h,6,'f');
	DispList(h);
	DLinkListDelete(h,2);
	DispList(h);
	return 0;

}
