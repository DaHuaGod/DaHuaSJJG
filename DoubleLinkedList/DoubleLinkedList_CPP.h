/*		Author: jianzhedeng		*/
/*		Date: 2015.8.26		*/
/*		Def: ������˫���������ѷ�װ��		*/
#pragma  once
#ifndef DOUBLELINKEDLIST_CPP_H
#define DOUBLELINKEDLIST_CPP_H
#include <iostream>
#include <cstdlib>
using namespace std;
#define OK (0)
#define ERROR (1)
typedef int status;

template <typename T>
class DLList
{
private:
	T *Head;
public:
	/*		���ɴ�ͷ����˫������������ֵΪͷָ�롣		*/
	T *InitList()
	{
		T *Head = NULL;

		Head = (T *)calloc(1, sizeof(T));
		Head->next = NULL;
		Head->prev = NULL;

		this->Head = Head;
		return (Head);
	}

	T *ReleaseList()
	{
		for ( ; NULL != Head->next; DeleteNode(Head, 1))
		{
		}
		free(Head);
		return (NULL);
	}

	int CountList()
	{
		int i = 0;
		T *p = NULL;
		for (i = 0, p = Head; p->next != NULL; p = p->next, ++i)
		{
		}
		return (i);
	}

	/*		�����㡣�����pos�����֮ǰ��pos < 1ʱ���嵽���������eleΪָ����������ָ�롣		*/
	status InsertNode(const int pos, T *ele)
	{
		if (ele != NULL && Head != NULL && pos <= CountList())
		{
			int i = 0;
			T *p = NULL;

			/*		pָ�򱻲�����֮ǰ�Ľ�� 		*/
			if (pos < 1)
			{
				for (p = Head; p->next != NULL; p = p->next)
				{
				}
			} 
			else
			{
				/*		ѭ��pos - 1��		*/
				for (p = Head, i = 0; i < pos - 1; p = p->next, ++i)
				{
				}
			}
			/*		������		*/
			ele->next = p->next;
			ele->prev = p;
			if (ele->next != NULL)
			{
				ele->next->prev = ele;
			}
			p->next = ele;
			return (OK);
		}
		return (ERROR);
	}

	/*		ɾ����㡣ɾ����pos����㡣		*/
	status DeleteNode(const int pos)
	{
		if (Head != NULL && pos > 0 && pos <= CountList())
		{
			int i;
			T *p;
			/*		ѭ��pos - 1��		*/
			for (i = 0, p = Head; i < pos - 1; p = p->next, ++i)
			{
			}
			if (p->next->next == NULL)
			{
				free(p->next);
				p->next = NULL;
			} 
			else
			{
				p->next = p->next->next;
				free(p->next->prev);
				p->next->prev = p;
			}
			return (OK);
		}
		return (ERROR);
	}

	/*		����һ����㣬��ʹ��rand������ʼ��		*/
	T *CreateNode()
	{
		T *p;
		p = (T *)calloc(1, sizeof(T));
		return (p);
	}


};
#endif