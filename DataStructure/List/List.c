#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	int Data[20];
	int Last;
}List;
List L, *Ptrl;

// Make Empty List
List *MakeEmpty()
{
	List *Ptrl;
	Ptrl = (List *)malloc(sizeof(List));
	Ptrl->Last = -1;
	return Ptrl;
}

//Find
int Find(int x,List *Ptrl)
{
	int i = 0;
	while(i <= Ptrl->Last && Ptrl->Data[i]!= x)
	{
		i++;
	}
	
 	if(i > Ptrl->Last)
	{
		return -1;
	}
	else return i;
}

//Insert
void Insert(int x,int value,List *Ptrl)
{
	int j;
	
	if(Ptrl->Last+1 == 20)
	{
		printf("this List if full");
		return ;
	}
	if(x < 1 || x > Ptrl->Last+2)
	{
		
		printf("this index is illegal");
		return ;
	}
	for(j = Ptrl->Last; j >= x-1 ; j--)
	{
		Ptrl->Data[j+1] = Ptrl->Data[j];
	}
       
	Ptrl->Data[x-1] = value;
	Ptrl->Last++;
	return;
}

//Delete
void Delete(int x,List *Ptrl)
{
	int j;
	if(x < 1 || x > Ptrl->Last+1)
	{
		printf("this index is illegal");
		return;
	}
	for(j = x;j <= Ptrl->Last;j++)
	{
		Ptrl->Data[j-1] = Ptrl->Data[j];
	}
      	Ptrl->Last--;
	return;
}
void Print(List *Ptrl)
{
	int i = 0;
	for(;i <= Ptrl->Last;i++)
	{
		printf("%d\n",Ptrl->Data[i]);
	}
}
int main()
{
	int i = 0;
	int index = -1;
	Ptrl = MakeEmpty();	  
	for(i;i < 13; i++)
	{
		Ptrl->Data[i] = i+1;
		printf("%d\n",i+1);
           	Ptrl->Last += 1;
	}
	
	index = Find(10,Ptrl);
	printf("%dindex\n",index);
        Insert(6,99,Ptrl);
        Print(Ptrl);
        Delete(10,Ptrl);
	Print(Ptrl);
	return 0;
}
