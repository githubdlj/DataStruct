/********************************************************************
	Time:	  2015/09/01
	Filename: CLinkList
	Author:	  dinglj
	
	Purpose:  ѭ���������ʵ��(��������ѭ��������ļ����)
*********************************************************************/

#include <stdio.h>
#include <stdlib.h>

//	��������
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

//	����βָ��,�Ҵ�ͷ�ڵ��ѭ��������ṹ
typedef struct
{
	pNode head;
	pNode tail;
}CLinkList;

//������������
//////////////////////////////////////////////////////////////////////////
bool InitList(CLinkList &L);	//	��ʼ��

bool InsertElemByHead(CLinkList &L, ElemType e);	//	���뵽ͷ��
bool DeleteElemByHead(CLinkList &L);
bool DeleteElemByTail(CLinkList &L);

bool GetKthElem(CLinkList L, int k, ElemType &e);

bool CreateList(CLinkList &L);
bool DestroyList(CLinkList &L);

bool ClearList(CLinkList &L);

bool isEmpty(CLinkList L);

bool visit(Node *s)	//	����Ԫ��
{
	printf("%d\t", s->e.data);

	return true;
}
bool TraverseList(CLinkList L, bool (*pFunc)(Node *));
//////////////////////////////////////////////////////////////////////////

/********************************************************************
	Method:    InitList
	Parameter: 
	Returns:   

	Purpose:   ��ʼ����ͷ�ڵ�ĵ�����

*********************************************************************/
bool InitList(CLinkList &L)
{
	L.head = (Node *)malloc(sizeof(Node));
	L.head->next = L.head;

	L.tail = L.head;

	return true;
}

/********************************************************************
	Method:    InsertElemByHead
	Parameter: 
	Returns:   

	Purpose:   ��ͷ������Ԫ�أ�ע�⣬ѭ������������ͷ����β������Ԫ�أ����������λ�ò���Ԫ�أ������õ�����

*********************************************************************/
bool InsertElemByHead(CLinkList &L, ElemType e)
{
	//	�����ڵ�
	Node *s = (Node *)malloc(sizeof(Node));
	s->e.data = e.data;
	s->next = NULL;

	s->next = L.head->next;
	L.head->next = s;

	if (L.head == L.tail)	//	ע�⣡�������֮ǰ�ǿ���������Ҫ���⴦��
	{
		s->next = L.head;
		L.tail = s;
	}

	return true;
}

bool InsertElemByTail(CLinkList &L, ElemType e)
{
	Node *s = (Node *)malloc(sizeof(Node));
	s->e.data = e.data;
	s->next = NULL;

	L.tail->next = s;
	L.tail = s;
	L.tail->next = L.head;

	return true;
}
/********************************************************************
	Method:    
	Parameter: 
	Returns:   

	Purpose:   ѭ����������ɾ��ͷ��Ԫ�أ�����������ɾ��

*********************************************************************/
bool DeleteElemByHead(CLinkList &L)
{
	if (isEmpty(L))	//	�������Ϊ��
	{
		return false;
	}

	Node *p = L.head->next;
	L.head->next = p->next;
	
	//	���ֻ��һ��Ԫ�أ���Ҫ���⴦��
	if (p == L.tail)
	{
		L.tail = L.head;
	}

	free(p);

	return true;
}

/********************************************************************
	Method:    GetKthElem
	Parameter: ����λ�ã�����Ԫ��
	Returns:   

	Purpose:   

*********************************************************************/
bool GetKthElem(CLinkList L, int k, ElemType &e)
{
	int step = 1;
	Node *p = L.head->next;

	while (step < k && p != L.head)
	{
		step++;
		p = p->next;
	}

	if (L.head == p)
	{
		return false;
	}

	e.data = p->e.data;

	return true;
}
/********************************************************************
	Method:    isEmpty
	Parameter: 
	Returns:   

	Purpose:   �ж������Ƿ�Ϊ��

*********************************************************************/
bool isEmpty(CLinkList L)
{
	if (L.tail == L.head)
	{
		return true;
	}
	return false;
}

/********************************************************************
	Method:    CreateList
	Parameter: 
	Returns:   

	Purpose:   β�巨����ѭ��������

*********************************************************************/
bool CreateList(CLinkList &L, int num)
{
	InitList(L);

	for (int i = 0; i < num; i++)
	{
		Node *s = (Node *)malloc(sizeof(Node));
		s->e.data = i + 1;
		s->next = NULL;

		L.tail->next = s;
		L.tail = s;
		L.tail->next = L.head;
	}

	return true;
}

/********************************************************************
	Method:    ClearList
	Parameter: 
	Returns:   

	Purpose:   �������

*********************************************************************/
bool ClearList(CLinkList &L)
{
	Node *p = L.head->next;
	Node *q = p->next;

	while (L.head != p)	//	ע��͵���������� while (NULL != p)
	{
		q = p->next;
		free(p);
		p = q;
	}

	L.head->next = L.head;
	L.tail = L.head;

	return true;
}

/********************************************************************
	Method:    DestroyList
	Parameter: 
	Returns:   

	Purpose:   ����

*********************************************************************/
bool DestroyList(CLinkList &L)
{
	ClearList(L);

	free(L.head);
	L.head = L.tail = NULL;

	return true;
}

/********************************************************************
	Method:    TraverseList
	Parameter: 
	Returns:   

	Purpose:   

*********************************************************************/
bool TraverseList(CLinkList L, bool (*pFunc)(Node * ))
{
	Node *p = L.head->next;

	while (L.head != p)
	{
		pFunc(p);
		p = p->next;
	}

	printf("\n");

	return true;
}

/********************************************************************
	Method:    OpearationTest
	Parameter: 
	Returns:   

	Purpose:   ���Ժ���

*********************************************************************/
bool OperationTest()
{
	CLinkList L;
	CreateList(L, 3);
	TraverseList(L, visit);

	
	ElemType e;
	e.data = 4;
	InsertElemByHead(L, e);

	
	e.data = 5;
	InsertElemByTail(L, e);

	TraverseList(L, visit);

	
	DeleteElemByHead(L);
	TraverseList(L, visit);
	
	ClearList(L);
	TraverseList(L, visit);
	
	
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