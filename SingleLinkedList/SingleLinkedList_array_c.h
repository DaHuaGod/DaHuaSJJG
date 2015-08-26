/*		Author: jianzhedeng		*/
/*		Date: 2015.8.25		*/
/*		Def: ��̬�ĵ������ʵ�֣��׺в���ͨ��		*/
#pragma  once
#ifndef SINGLELINKEDLIST_ARRAY_C_H
#define SINGLELINKEDLIST_ARRAY_C_H
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define OK (0)
#define ERROR (1)
typedef int status;
/*		���徲̬��������������������ͱ��������ͷ�ڵ㽫��ռ��һ��		*/
#define MAXSIZE (1024)
/*		���������ͣ�������Ҫ�����û�����		*/
typedef int node;
/*		�����α����ͣ�ͨ��ʹ��int���ɣ�����Ҫ�޸�		*/
typedef int cur;

status InitList(node **Node, cur **Cur);
status ReleaseList(node **Node, cur **Cur);
cur MallocNode(node **Node, cur **Cur);
status FreeNode(node **Node, cur **Cur, const cur k);
cur CountList(node **Node, cur **Cur);
status InsertNode(node **Node, cur **Cur, const cur pos, const node ele);
status DeleteNode(node **Node, cur **Cur, const cur pos);

void ShowList(node **Node, cur **Cur);

#endif
