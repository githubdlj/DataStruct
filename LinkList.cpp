/********************************************************************
	Time:	  2015/09/01
	Filename: LinkList
	Author:	  dinglj
	
	Purpose:  单链表的基本实现
*********************************************************************/

#include <stdio.h>
#include <stdlib.h>

//	数据元素
typedef struct  
{
	int data;
}ElemType;

//	单链表结构
typedef struct Node
{
	ElemType e;
	struct Node *next;
}Node;
typedef struct Node *LinkList;	

//主要函数申明
//////////////////////////////////////////////////////////////////////////
bool InitList(LinkList &L);	//	初始化
bool ClearList(LinkList &L);

bool InsertElem(LinkList &L, ElemType e, int pos);
bool DeleteElem(LinkList &L, int pos);

bool CreateListByHead(LinkList &L, int num);
bool CreateListByTail(LinkList &L, int num);

bool DestroyList(LinkList &L);

bool GetKthElem(LinkList &L, int k, ElemType &e);



bool isEmpty(LinkList L);

bool visit(Node *s)	//	访问元素
{
	printf("%d\t", s->e.data);
	
	return true;
}
bool TraverseList(LinkList L, bool (*pFunc)(Node * ));	// 函数指针应用

//////////////////////////////////////////////////////////////////////////
/********************************************************************
	Method:    InsertElem
	Parameter: 
	Returns:   

	Purpose:   链表的插入 1、找到插入点 2、建立节点 3、插入

*********************************************************************/
bool InsertElem(LinkList &L, ElemType e, int pos)
{
	//	寻找插入位置
	/////////////////////////////////////////////////
	Node *p = L;
	int k = 1;

	while (p && k < pos)
	{
		p = p->next;
		k++;
	}

	if (!p)		//	如果插入位置不合法
	{
		return false;
	}
	//////////////////////////////////////////////////

	//	建立插入点
	Node *s = (Node *)malloc(sizeof(Node));	
	s->e.data = e.data;
	s->next = NULL;

	//	插入
	s->next = p->next;
	p->next = s;

	return true;
}

/********************************************************************
	Method:    DeleteElem
	Parameter: 
	Returns:   

	Purpose:   链表的删除，注意特殊情况:空链表

*********************************************************************/
bool DeleteElem(LinkList &L, int pos)
{
	if (isEmpty(L))
	{
		return false;
	}

	//	定位到删除点
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
	Parameter: 单链表， 位置， 返回元素
	Returns:   

	Purpose:   获取第k个元素 

*********************************************************************/
bool GetKthElem(LinkList L, int k, ElemType &e)
{
	//	定位到第k个元素所在位置
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

	Purpose:   初始化单链表

*********************************************************************/
bool InitList(LinkList &L)
{
	L = (LinkList)malloc(sizeof(Node));
	L->next = NULL;

	return true;
}
/********************************************************************
	Method:    CreateListByHead
	Parameter: 单链表, 元素个数
	Returns:   

	Purpose:   头插法建立单链表

*********************************************************************/
bool CreateListByHead(LinkList &L, int num)
{
	InitList(L);

	for (int i = 0; i < num; i++)
	{
		//	建立节点
		Node *s = (Node *)malloc(sizeof(Node));
		s->e.data = i + 1;
		s->next = NULL;
		
		//	插入
		s->next = L->next;
		L->next = s;
	}

	return true;
}

/********************************************************************
	Method:    CreateListByTail
	Parameter: 单链表，元素个数
	Returns:   

	Purpose:   尾插法建立单链表

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

	Purpose:   链表清空

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

	Purpose:   销毁链表，如果不销毁，则内存泄露；注意和ClearList的区别

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
	Parameter: 单链表，函数指针
	Returns:   

	Purpose:   输出单链表

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

	Purpose:   头插法测试

*********************************************************************/
bool CreateListByHeadTest(LinkList &L)
{
	CreateListByHead(L, 3);	//	插入3个元素的链表
	TraverseList(L, visit);

	/*
	//	插入0个元素
	LinkList L1;
	CreateListByHead(L1, 0);
	TraverseList(L1);
	
	//	插入1个元素
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

	Purpose:   尾插法测试

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

	Purpose:   插入测试

*********************************************************************/
bool InsertTest(LinkList &L)
{
	ElemType e;
	e.data = 6;
	InsertElem(L, e, 4);	//	插入到最后一个位置

	e.data = 7;
	InsertElem(L, e, 1);	//	插入到第一个位置

	e.data = 8;
	InsertElem(L, e, 2);	//	插入到中间某一位置

	TraverseList(L, visit);

	/////////////////////////////////////////
	/*
	LinkList L1;
	CreateListByHead(L1, 0);	

	e.data = 1;
	InsertElem(L1, e, 1);	//	在空链表中插入元素

	TraverseList(L1);
	*/

	return true;
}

/********************************************************************
	Method:    DeleteTest
	Parameter: 
	Returns:   

	Purpose:	删除元素测试  

*********************************************************************/
bool DeleteTest(LinkList &L)
{
	DeleteElem(L, 6);	//	删除最后一个元素
	DeleteElem(L, 2);	//	删除中间元素
	DeleteElem(L, 1);	//	删除第一个元素
	
	TraverseList(L, visit);
	
	return true;
}

/********************************************************************
	Method:    ClearListtest
	Parameter: 
	Returns:   

	Purpose:   清空测试

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

	Purpose:   测试函数

*********************************************************************/
bool OperationTest()
{
	LinkList L;

	CreateListByHeadTest(L);	//	头插法测试

	InsertTest(L);	//	插入测试

	DeleteTest(L);	//	删除测试

	ClearListTest(L);

	LinkList L2;
	CreateListByTailTest(L2);	// 尾插法测试

	ClearList(L2);

	DestroyList(L);		//	销毁
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