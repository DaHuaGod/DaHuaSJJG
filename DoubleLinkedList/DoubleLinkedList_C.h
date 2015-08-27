/*		Author: jianzhedeng		*/
/*		Date: 2015.8.25		*/
/*		Def: ������˫��������ͨ���׺в��ԡ�		*/
#pragma  once
#ifndef DOUBLELINKEDLIST_C_H
#define DOUBLELINKEDLIST_C_H
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define OK (0)
#define ERROR (1)
typedef int status;
/*		�����������ͣ�������Ҫ�����û�����		*/
typedef int ListElemType;
/*		��������������		*/
typedef struct DouNode
{
	ListElemType date;
	struct DouNode *prev;
	struct DouNode *next;
}node, *pNode;

pNode InitList();
pNode ReleaseList(pNode Head);
int CountList(pNode Head);
status InsertNode(pNode Head, const int pos, pNode ele);
status DeleteNode(pNode Head, const int pos);
pNode CreateNode();

void ShowList(pNode Head);

#endif
