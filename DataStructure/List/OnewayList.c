/**
*InitList(LinkList *L)
*DestroyList(LinkList *L)
*ListEmpty(LinkList *L)
*ListLength(LinkList *L)
*GetElem(LinkList *L,int i,ElemType *e)
*DispList(LinkList *L)
*LocateList(LinkList *L,ElemType * e)
*ListInsert(LinkList *L,int i,ElemType *e)
*ListDelete(LinkList *L,int i,ElemType *e)
*/
#include<stdio.h>
#include<stdlib.h>

typedef char ElemType;
typedef struct LNode
{
	ElemType  e;
	struct LNode * next;
}LinkList;

void InitList(LinkList ** L)
{
	*L = (LinkList *)malloc(sizeof(LinkList));//Create a instance of LinkList
	(*L)->next = NULL;	
}

int ListInsert(LinkList * L,int i ,ElemType e)
{
	int j = 0;
	LinkList * p = L;
	LinkList * s;
        while(j < i-1 && p != NULL)
	{
		j++;
		p = p->next;
	}
	if(p == NULL)
	{
		return 0;
	}
	else
	{
		s = (LinkList *)malloc(sizeof(LinkList));
		s->e = e;
		s->next = p->next;
		p->next = s;
		return 1;
	}		
}

void DispList(LinkList *L)
{

	LinkList * p = L->next;
	while(p != NULL)
	{
		printf("%c\n",p->e);
		p = p->next;	
	}
	printf("\n");
}


int ListLenght(LinkList *L)
{
	LinkList  * p = L;
	int j = 0;
	while(p->next != NULL)	
	{
		j++;
		p = p->next;
	}
	return j;

}

int ListEmpty(LinkList *L)
{
	return (L->next == NULL);
}


void  GetElem(LinkList * L,int i,ElemType *e)
{
//	printf("%c\n",*e);
	LinkList * p = L->next;
	int index = 0;
	if(i > 0)
	{	
		while(index < i-1 && p !=NULL )
		{
			p = p->next;
			index++;
		}
	 	*e = (p->e);
	}
}

int LocateElem(LinkList *L,ElemType e)
{
	LinkList * p = L;
	int index = 0;
	while(p->next != NULL && p->e!=e)
	{
		index++;
		p = p->next;
	}
	if(p == NULL)
	{
		return -1;
	}
	else
	{
		return index;
	}
}


void ListInsert_other(LinkList * L,int i,ElemType e)
{
	LinkList * p = L;
	LinkList * s = (LinkList *)malloc(sizeof(LinkList));
	int j = 0;
	if(i < 1)
	{
		printf("the i is error!\n");
	}
	while(p != NULL && j < i-1)
	{
		p = p->next;
		
	}
	if(p == NULL)
	{
	 	printf("error\n");
	}
	else
	{
		s->e = e;
		s = p->next;
		p->next = s;
	}
}


void DeleteList(LinkList * L,int i,ElemType *e)
{
	int j = 0;
	LinkList * p = L;
	LinkList *s;
	if(i > 0)
	{
		while(p != NULL && j < i-1)
		{
			p = p->next;
			j++;
		}
		
	}
	if(p == NULL)
	{
		printf("NO ELEMTYPE\n");
	}
	else
	{
		s = p->next;
		p->next = s->next;
		*e = s->e;
		free(s);
	
	}	
}


void DestroyList(LinkList *L)
{
	LinkList *p = L;
	LinkList *q = p->next;
	while(q != NULL)
	{
		free(p);
		p = q;
		q = q->next;
	}
	free(p);
}
int main()
{
	LinkList * h;//this is head of the LinkList
	ElemType *e;
	ElemType value;
 	e = &value;
	printf("InitLinkList!\n");
	InitList(&h);
	printf("Insert some Elemments by the tail interpolation\n");
	ListInsert(h,1,'a');
	ListInsert(h,2,'b');
	ListInsert(h,3,'c');
	ListInsert(h,4,'d');
	ListInsert(h,5,'e');
	printf("print all elemment of LinkList\n");
	DispList(h);
	printf("this lenght of List is %d\n",ListLenght(h));
	printf("this list is empty or not %s\n",(ListEmpty(h)? "yes":"no"));
	GetElem(h,3,e);
	printf("%c\n",*e);
	printf("location of location is %d\n",LocateElem(h,'d'));
	printf("insert elemment \n");
	ListInsert(h,4,'f');
	DispList(h);
	printf("delete elemtype in List and return the elemment by e\n");
	DeleteList(h, 3,e);
	printf("%c\n",*e);
	DispList(h);
	DestroyList(h);
	return 0;	
}



