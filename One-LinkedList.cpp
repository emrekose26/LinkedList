#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
struct bagli
{
	int veri;
	bagli *next;
};
typedef struct bagli LL;
void s_ekle(LL **B,int veri)
{
	LL *yeni=(LL *)malloc(sizeof(LL));

	yeni->veri=veri;
	yeni->next=NULL;
	if (*B==NULL)
	{
		*B=yeni;
		return;
	}
	LL *son=*B;
	while(son) 
	{
		if(son->next==NULL) 	
		{
			son->next = yeni;
			return;
		}
		son = son->next;
	}
}
void o_ekle(LL **B,int veri)
{
	LL *yeni=(LL*)malloc(sizeof(LL));
	yeni->veri=veri;
	yeni->next=*B;
	*B=yeni;
}
void yazdir(LL *B)
{
	LL *son = B;
	while(son) 
	{
		printf("%d\n",son->veri);
		son = son->next;
	}
	printf("\n");
}
void o_cikar(LL **B)
{
	if(B==NULL)
		return;
	LL *tmp=*B;
	*B=tmp->next;
	_freea(tmp);   }
void s_cikar(LL **B)
{
	if(B==NULL)
		return;
	LL *son=*B;
	LL *tmp;
	while(son) 
	{
		if(son->next->next==NULL) 	
		{
			tmp=son->next->next;
			son->next=NULL;
			_freea(tmp);

		}
		son = son->next;
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	int n=10;
	int dizi[100];
	//dizi=new int[n];
	LL *liste=NULL;
	s_ekle(&liste,5);
	s_ekle(&liste,10);
	s_ekle(&liste,15);
	s_ekle(&liste,20);
	s_ekle(&liste,7);
	o_ekle(&liste,9);
	o_ekle(&liste,99);
	o_ekle(&liste,999);
	o_cikar(&liste);
	s_cikar(&liste);
	yazdir(liste);
	getchar();
	return 0;
}

