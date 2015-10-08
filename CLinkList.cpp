/********************************************************************
	Time:	  2015/09/01
	Filename: CLinkList
	Author:	  dinglj
	
	Purpose:  循环单链表的实现(单链表是循环单链表的简化情况)
*********************************************************************/

#include <stdio.h>
#include <stdlib.h>

//	数据类型
typedef struct  
{
	int data;
}ElemType;

//	节点结构
typedef struct Node  
{
	ElemType e;
	struct Node *next;
}Node, *pNode;

//	带首尾指针,且带头节点的循环单链表结构
typedef struct
{
	pNode head;
	pNode tail;
}CLinkList;

//各个函数申明
//////////////////////////////////////////////////////////////////////////
bool InitList(CLinkList &L);	//	初始化

bool InsertElemByHead(CLinkList &L, ElemType e);	//	插入到头部
bool DeleteElemByHead(CLinkList &L);
bool DeleteElemByTail(CLinkList &L);

bool GetKthElem(CLinkList L, int k, ElemType &e);

bool CreateList(CLinkList &L);
bool DestroyList(CLinkList &L);

bool ClearList(CLinkList &L);

bool isEmpty(CLinkList L);

bool visit(Node *s)	//	访问元素
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

	Purpose:   初始化带头节点的单链表

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

	Purpose:   在头部插入元素，注意，循环单链表方便在头部、尾部插入元素，如果在其他位置插入元素，不如用单链表

*********************************************************************/
bool InsertElemByHead(CLinkList &L, ElemType e)
{
	//	建立节点
	Node *s = (Node *)malloc(sizeof(Node));
	s->e.data = e.data;
	s->next = NULL;

	s->next = L.head->next;
	L.head->next = s;

	if (L.head == L.tail)	//	注意！如果插入之前是空链，则需要特殊处理
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

	Purpose:   循环单链表方便删除头部元素，其他处不好删除

*********************************************************************/
bool DeleteElemByHead(CLinkList &L)
{
	if (isEmpty(L))	//	如果链表为空
	{
		return false;
	}

	Node *p = L.head->next;
	L.head->next = p->next;
	
	//	如果只有一个元素，需要特殊处理
	if (p == L.tail)
	{
		L.tail = L.head;
	}

	free(p);

	return true;
}

/********************************************************************
	Method:    GetKthElem
	Parameter: 链表，位置，返回元素
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

	Purpose:   判断链表是否为空

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

	Purpose:   尾插法建立循环单链表

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

	Purpose:   清空链表

*********************************************************************/
bool ClearList(CLinkList &L)
{
	Node *p = L.head->next;
	Node *q = p->next;

	while (L.head != p)	//	注意和单链表的区别 while (NULL != p)
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

	Purpose:   销毁

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

	Purpose:   测试函数

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