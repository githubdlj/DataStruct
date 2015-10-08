/********************************************************************
	Time:	  2015/09/01
	Filename: LinkList
	Author:	  dinglj
	
	Purpose:  ������Ļ���ʵ��
*********************************************************************/

#include <stdio.h>
#include <stdlib.h>

//	����Ԫ��
typedef struct  
{
	int data;
}ElemType;

//	������ṹ
typedef struct Node
{
	ElemType e;
	struct Node *next;
}Node;
typedef struct Node *LinkList;	

//��Ҫ��������
//////////////////////////////////////////////////////////////////////////
bool InitList(LinkList &L);	//	��ʼ��
bool ClearList(LinkList &L);

bool InsertElem(LinkList &L, ElemType e, int pos);
bool DeleteElem(LinkList &L, int pos);

bool CreateListByHead(LinkList &L, int num);
bool CreateListByTail(LinkList &L, int num);

bool DestroyList(LinkList &L);

bool GetKthElem(LinkList &L, int k, ElemType &e);



bool isEmpty(LinkList L);

bool visit(Node *s)	//	����Ԫ��
{
	printf("%d\t", s->e.data);
	
	return true;
}
bool TraverseList(LinkList L, bool (*pFunc)(Node * ));	// ����ָ��Ӧ��

//////////////////////////////////////////////////////////////////////////
/********************************************************************
	Method:    InsertElem
	Parameter: 
	Returns:   

	Purpose:   ����Ĳ��� 1���ҵ������ 2�������ڵ� 3������

*********************************************************************/
bool InsertElem(LinkList &L, ElemType e, int pos)
{
	//	Ѱ�Ҳ���λ��
	/////////////////////////////////////////////////
	Node *p = L;
	int k = 1;

	while (p && k < pos)
	{
		p = p->next;
		k++;
	}

	if (!p)		//	�������λ�ò��Ϸ�
	{
		return false;
	}
	//////////////////////////////////////////////////

	//	���������
	Node *s = (Node *)malloc(sizeof(Node));	
	s->e.data = e.data;
	s->next = NULL;

	//	����
	s->next = p->next;
	p->next = s;

	return true;
}

/********************************************************************
	Method:    DeleteElem
	Parameter: 
	Returns:   

	Purpose:   �����ɾ����ע���������:������

*********************************************************************/
bool DeleteElem(LinkList &L, int pos)
{
	if (isEmpty(L))
	{
		return false;
	}

	//	��λ��ɾ����
	////////////////////////////////////////////
	Node *p = L;
	int k = 1;

	while (p && k < pos)
	{
		p = p->next;
		k++;
	}

	if (!p)
	{
		return false;
	}
	//////////////////////////////////////////

	Node *q = p->next;
	p->next = q->next;
	free(q);

	return true;
}

/********************************************************************
	Method:    GetKthElem
	Parameter: ������ λ�ã� ����Ԫ��
	Returns:   

	Purpose:   ��ȡ��k��Ԫ�� 

*********************************************************************/
bool GetKthElem(LinkList L, int k, ElemType &e)
{
	//	��λ����k��Ԫ������λ��
	int step = 1;
	Node *p = L->next;

	while (step < k && p)
	{
		step++;
		p = p->next;
	}

	if (!p)
	{
		return false;
	}

	e.data = p->e.data;

	return true;
}

/********************************************************************
	Method:    InitList
	Parameter: 
	Returns:   

	Purpose:   ��ʼ��������

*********************************************************************/
bool InitList(LinkList &L)
{
	L = (LinkList)malloc(sizeof(Node));
	L->next = NULL;

	return true;
}
/********************************************************************
	Method:    CreateListByHead
	Parameter: ������, Ԫ�ظ���
	Returns:   

	Purpose:   ͷ�巨����������

*********************************************************************/
bool CreateListByHead(LinkList &L, int num)
{
	InitList(L);

	for (int i = 0; i < num; i++)
	{
		//	�����ڵ�
		Node *s = (Node *)malloc(sizeof(Node));
		s->e.data = i + 1;
		s->next = NULL;
		
		//	����
		s->next = L->next;
		L->next = s;
	}

	return true;
}

/********************************************************************
	Method:    CreateListByTail
	Parameter: ������Ԫ�ظ���
	Returns:   

	Purpose:   β�巨����������

*********************************************************************/
bool CreateListByTail(LinkList &L, int num)
{
	InitList(L);

	Node *tail = L;

	for (int i = 0; i < num; i++)
	{
		Node *s = (Node *)malloc(sizeof(Node));
		s->e.data = i + 1;
		s->next = NULL;

		tail->next = s;
		tail = s;
	}

	return true;
}

/********************************************************************
	Method:    ClearList
	Parameter: 
	Returns:   

	Purpose:   �������

*********************************************************************/
bool ClearList(LinkList &L)
{
	Node *p = L->next;
	Node *q = p->next;

	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}

	L->next = NULL;

	return true;
}

/********************************************************************
	Method:    DestroyList
	Parameter: 
	Returns:   

	Purpose:   ����������������٣����ڴ�й¶��ע���ClearList������

*********************************************************************/
bool DestroyList(LinkList &L)
{
	ClearList(L);

	free(L);
	L = NULL;

	return true;
}
/********************************************************************
	Method:    TraverseList
	Parameter: ����������ָ��
	Returns:   

	Purpose:   ���������

*********************************************************************/
bool TraverseList(LinkList L, bool (*pFunc)(Node * ))
{
	Node *s = L->next;
	while (s)
	{
		pFunc(s);
		s = s->next;
	}
	printf("\n");

	return true;
}

bool isEmpty(LinkList L)
{
	if (NULL == L->next)
	{
		return true;
	}
	return false;
}
/********************************************************************
	Method:    CreateListByHeadTest
	Parameter: 
	Returns:   

	Purpose:   ͷ�巨����

*********************************************************************/
bool CreateListByHeadTest(LinkList &L)
{
	CreateListByHead(L, 3);	//	����3��Ԫ�ص�����
	TraverseList(L, visit);

	/*
	//	����0��Ԫ��
	LinkList L1;
	CreateListByHead(L1, 0);
	TraverseList(L1);
	
	//	����1��Ԫ��
	LinkList L2;
	CreateListByHead(L2, 1);
	TraverseList(L2);
	*/

	return true;
}

/********************************************************************
	Method:    CreateListByTail
	Parameter: 
	Returns:   

	Purpose:   β�巨����

*********************************************************************/
bool CreateListByTailTest(LinkList &L)
{
	CreateListByTail(L, 5);
	TraverseList(L, visit);

	return true;
}

/********************************************************************
	Method:    InsertTest
	Parameter: 
	Returns:   

	Purpose:   �������

*********************************************************************/
bool InsertTest(LinkList &L)
{
	ElemType e;
	e.data = 6;
	InsertElem(L, e, 4);	//	���뵽���һ��λ��

	e.data = 7;
	InsertElem(L, e, 1);	//	���뵽��һ��λ��

	e.data = 8;
	InsertElem(L, e, 2);	//	���뵽�м�ĳһλ��

	TraverseList(L, visit);

	/////////////////////////////////////////
	/*
	LinkList L1;
	CreateListByHead(L1, 0);	

	e.data = 1;
	InsertElem(L1, e, 1);	//	�ڿ������в���Ԫ��

	TraverseList(L1);
	*/

	return true;
}

/********************************************************************
	Method:    DeleteTest
	Parameter: 
	Returns:   

	Purpose:	ɾ��Ԫ�ز���  

*********************************************************************/
bool DeleteTest(LinkList &L)
{
	DeleteElem(L, 6);	//	ɾ�����һ��Ԫ��
	DeleteElem(L, 2);	//	ɾ���м�Ԫ��
	DeleteElem(L, 1);	//	ɾ����һ��Ԫ��
	
	TraverseList(L, visit);
	
	return true;
}

/********************************************************************
	Method:    ClearListtest
	Parameter: 
	Returns:   

	Purpose:   ��ղ���

*********************************************************************/
bool ClearListTest(LinkList &L)
{
	ClearList(L);
	TraverseList(L, visit);

	return true;
}
/********************************************************************
	Method:    OperatorTest
	Parameter: 
	Returns:   

	Purpose:   ���Ժ���

*********************************************************************/
bool OperationTest()
{
	LinkList L;

	CreateListByHeadTest(L);	//	ͷ�巨����

	InsertTest(L);	//	�������

	DeleteTest(L);	//	ɾ������

	ClearListTest(L);

	LinkList L2;
	CreateListByTailTest(L2);	// β�巨����

	ClearList(L2);

	DestroyList(L);		//	����
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