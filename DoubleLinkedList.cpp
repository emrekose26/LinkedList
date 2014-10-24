
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
struct bagli
{
	int veri;
	bagli *next;
	bagli *previous;
};
typedef struct bagli LL;
void s_ekle(LL **B,int veri)
{
	LL *yeni=(LL *)malloc(sizeof(LL));

	yeni->veri=veri;
	yeni->next=NULL;
	yeni->previous=NULL;
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
			yeni->previous=son;
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
	yeni->previous=NULL;
	(*B)->previous=yeni;
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
	(*B)->next->previous=NULL;
	*B=(*B)->next;
	_freea(tmp);
}
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
	LL *liste=NULL;
	s_ekle(&liste,5);
	s_ekle(&liste,10);
	s_ekle(&liste,15);
	s_ekle(&liste,20);
	yazdir(liste);
	o_cikar(&liste);
	yazdir(liste);
	o_ekle(&liste,9);
	yazdir(liste);
	s_ekle(&liste,99);
	yazdir(liste);
	s_ekle(&liste,999);
	yazdir(liste);
	s_cikar(&liste);
	yazdir(liste);
	getchar();
	return 0;
}
