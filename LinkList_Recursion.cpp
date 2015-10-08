/********************************************************************
	Time:	  2015/09/16
	Filename: LinkList_Recursion
	Author:	  dinglj
	
	Purpose:  ������Ĳ��ֵݹ�ʵ��
*********************************************************************/

//	ͷ�ļ�
#include <stdio.h>
#include <stdlib.h>

//	Ԫ��
typedef struct  
{
	int data;
}ElemType;

//	�ڵ�ṹ
typedef struct Node
{
	ElemType e;
	struct Node *next;
}Node, *pNode;

//	������ṹ
typedef pNode LinkList;


//////////////////////////////////////////////////////////////////////

//	����Ԫ��
bool visit(Node *pElemNode)
{
	if (pElemNode)
	{
		printf("%d\t", pElemNode->e.data);
		return true;
	}

	return false;
}

//	��ʼ����������ͷ�ڵ�
bool InitList(LinkList &L)
{
	L = NULL;

	return true;
}

//	���������ĵݹ�����
bool CreateList(LinkList &L);
bool DestroyList(LinkList &L);

bool TraverseList(LinkList L);

pNode TransposeList(LinkList L);	//	����ת��

//////////////////////////////////////////////////////////////////////

/********************************************************************
	Method:    CreateList
	Parameter: 
	Returns:   

	Purpose:   �ݹ齨�����������ڶ����������������

*********************************************************************/
bool CreateList(LinkList &L)
{
	ElemType e;
	scanf("%d", &e.data);

	if (-1 == e.data)	//	-1Ϊ���������־
	{
		L = NULL;
	}
	else
	{
		L = (Node *)malloc(sizeof(Node));
		L->next = NULL;
		L->e.data = e.data;

		CreateList(L->next);
	}

	return true;
}

/********************************************************************
	Method:    DestroyList
	Parameter: 
	Returns:   

	Purpose:   �ݹ��������Ա��������ڶ������ĺ����������

*********************************************************************/
bool DestroyList(LinkList &L)
{
	if (L)
	{
		DestroyList(L->next);

		free(L);
		L = NULL;
	}

	return true;
}

/********************************************************************
	Method:    TraverseList
	Parameter: 
	Returns:   

	Purpose:   �ݹ���������������ڶ����������������

*********************************************************************/
bool TraverseList(LinkList L)
{
	if (L)
	{
		visit(L);

		TraverseList(L->next);
	}
	
	return true;
}



/********************************************************************
	Method:    TransposeList
	Parameter: 
	Returns:   

	Purpose:   �ݹ�͵�ת�õ����������ڶ������ĺ��������������ת�ñ�����ת�ü򵥣�����������

*********************************************************************/

//////////////////////////////////////////////////////////////////////
//	����ķ���
//	1,2,3,4,5����2,1.����ԭ����ת�ˣ���������ͷָ��ָ���˽ڵ�2�������ǽڵ�5
bool TransposeList_1(LinkList &L)
{
	if (NULL == L->next)
	{
		return true;	
	}
	else
	{
		TransposeList(L->next);

		L->next->next = L;
		Node *pHead = L;
		L = L->next;
		pHead->next = NULL;
		
		return true;
	}
}

//////////////////////////////////////////////////////////////////////
//	��ȷ�ķ���
pNode TransposeList(LinkList L)
{
	if (NULL == L->next)
	{
		return L;	
	}
	else
	{
		Node *pHead = TransposeList(L->next);

		L->next->next = L;
		L->next = NULL;
		
		return pHead;
	}
}
/********************************************************************
	Method:    OperationTest
	Parameter: 
	Returns:   

	Purpose:   

*********************************************************************/
bool OperationTest()
{
	LinkList L;
	
	InitList(L);	//	��ʼ��
	CreateList(L);

	TraverseList(L);
	printf("\n");
	//////////////////////////////////////////////////////////////////////

	//
	TransposeList_1(L);
//	L = TransposeList(L);	//	ת��
	TraverseList(L);
	printf("\n");

	//////////////////////////////////////////////////////////////////////
	DestroyList(L);

	TraverseList(L);
	printf("\n");

	return true;
}

/********************************************************************
	Method:    main
	Parameter: 
	Returns:   

	Purpose:   

*********************************************************************/
int main()
{
	OperationTest();

	return true;
}
