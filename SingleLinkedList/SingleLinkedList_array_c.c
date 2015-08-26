#include "SingleLinkedList_array_c.h"
/*		��������		*/
void ShowList(node **Node, cur **Cur)
{
	int i, k;
	printf("#Have %d nodes.These nodes were listed.\n#", CountList(Node, Cur));
	for (i = MAXSIZE - 1, k = 0; ; i = *(*Cur + i), ++k)
	{
		if (k > 0)
		{
			printf("%d", *(*Node + i));
		}
		if (0 == *(*Cur + i))
		{
			break;
		}
		else if (k > 0)
		{
			printf("\t");
		}
	}
	printf("\n");
}

/*		Cur[MAXSIZE - 1]Ϊͷָ�룬Cur[0]ָ��������ͷ�ڵ㣬"0"�����ָ��		*/
/*		ʹ���˶���ָ�룬ע�⣡����		*/
status InitList(node **Node, cur **Cur)
{
	cur i;
	*Node = (node*)calloc(MAXSIZE, sizeof(node));
	*Cur = (cur*)calloc(MAXSIZE, sizeof(cur));
	if ((NULL == *Node) || (NULL == *Cur))
	{
		return (ERROR);
	}
	for (i = 0; i < MAXSIZE - 1; ++i)
	{
		*(*Cur + i) = i + 1;
	}
	*(*Cur + MAXSIZE - 1) = 0;
	return (OK);
}

status ReleaseList(node **Node, cur **Cur)
{
	free(*Node);
	free(*Cur);
	return (OK);
}

/*		����һ���ս�㣬����ֵΪ�ս����±꣬����������Ϊ���򷵻�0		*/
cur MallocNode(node **Node, cur **Cur)
{
	cur flag;
	flag = **Cur;
	if (flag)
	{
		**Cur = *(*Cur + flag);
	}
	return (flag);
}

/*		�ͷŶ�Ӧ�±�Ľ�㡣ע�⣬��Ҫ��ɾ������������Ҳ������ý���Ƿ��Ѿ��ڱ���������		*/
status FreeNode(node **Node, cur **Cur, const cur k)
{
	*(*Cur + k) = **Cur;
	**Cur = k;
	return (OK);
}

cur CountList(node **Node, cur **Cur)
{
	cur flag = 0, i;
	for (i = *(*Cur + MAXSIZE - 1); i != 0; ++flag, i = *(*Cur + i))
	{
	}
	return (flag);
}

/*		�����㡣ʹ�ô�ֵ��ʽ��ʹ��ͷ�巨�������pos��Ԫ��֮ǰ����posС��1��嵽���		*/
status InsertNode(node **Node, cur **Cur, const cur pos, const node ele)
{
	cur i, j = 0, k = 0;
	if (CountList(Node, Cur) >= pos)
	{
		/*		�±�iָ�������λ�õ���һ�����		*/
		if (pos < 1)
		{
			/*		�ҵ����������β���		*/
			for (i = MAXSIZE - 1; 0 != *(*Cur + i); i = *(*Cur + i))
			{
			}
		} 
		else
		{
			/*		ѭ��pos - 1 ��		*/
			for (i = MAXSIZE - 1, k = 0; k < pos - 1; i = *(*Cur + i), ++k)
			{
			}
		}

		/*		��������������		*/
		if ((j = MallocNode(Node, Cur)) != 0)
		{
			*(*Node + j) = ele;
			*(*Cur + j) = *(*Cur + i);
			*(*Cur + i) = j;
			return (OK);
		}
	}
	return (ERROR);
}

/*		ɾ����㡣ɾ����pos����㡣pos��ֵ����0��С�ڵ��ڽ�������		*/
status DeleteNode(node **Node, cur **Cur, const cur pos)
{
	if (pos > 0 && pos <=  CountList(Node, Cur))
	{
		cur i, j;
		for (i = MAXSIZE - 1, j = 0; j < pos - 1; i = *(*Cur + i), ++j)
		{
		}
		j = *(*Cur + i);
		*(*Cur + i) = *(*Cur + j);
		FreeNode(Node, Cur, j);
		return (OK);
	}
	return (ERROR);
}
