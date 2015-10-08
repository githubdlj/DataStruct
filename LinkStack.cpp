/********************************************************************
	Time:	  2015/09/06
	Filename: LinkStack
	Author:	  dinglj
	
	Purpose: 链栈的实现 
*********************************************************************/

#include <stdio.h>
#include <stdlib.h>

//	元素定义
typedef struct 
{
	int data;
}ElemType;

//	节点定义
typedef struct Node 
{
	ElemType e;
	struct Node *next;
}Node, *pNode;

//	栈定义
typedef pNode LinkStack;

//	基本函数申明
//////////////////////////////////////////////////////////////////////
bool InitStack(LinkStack &S);
bool DestroyStack(LinkStack &S);

bool ClearStack(LinkStack &S);

bool isEmpty(LinkStack S);
bool isFull(LinkStack S);

bool Push(LinkStack &S, ElemType e);
bool Pop(LinkStack &S, ElemType &e);

bool GetTop(LinkStack S, ElemType &e);
//////////////////////////////////////////////////////////////////////

/********************************************************************
	Method:    InitStack
	Parameter: 
	Returns:   

	Purpose:   初始化

*********************************************************************/
bool InitStack(LinkStack &S)
{
	S = (Node *)malloc(sizeof(Node));
	S->next = NULL;

	return true;
}

bool DestroyStack(LinkStack &S)
{
	ClearStack(S);

	free(S);
	S = NULL;

	return true;
}
/********************************************************************
	Method:    ClearStack
	Parameter: 
	Returns:   

	Purpose:   清空栈

*********************************************************************/
bool ClearStack(LinkStack &S)
{
	Node *pDeleteNode = S->next;

	while (pDeleteNode)
	{
		S->next = pDeleteNode->next;
		
		free(pDeleteNode);
		pDeleteNode = S->next;
	}

	return true;
}

/********************************************************************
	Method:    isEmpty
	Parameter: 
	Returns:   

	Purpose:   

*********************************************************************/
bool isEmpty(LinkStack S)
{
	return S->next == NULL;
}

//	永远不会满
bool isFull(LinkStack S)
{
	return false;
}

/********************************************************************
	Method:    Push
	Parameter: 
	Returns:   

	Purpose:   

*********************************************************************/
bool Push(LinkStack &S, ElemType e)
{
	if (isFull(S))
	{
		return false;
	}

	Node *pNewNode = (Node *)malloc(sizeof(Node));
	pNewNode->e.data = e.data;
	pNewNode->next = NULL;

	pNewNode->next = S->next;
	S->next = pNewNode;

	return true;
}

/********************************************************************
	Method:    Pop
	Parameter: 
	Returns:   

	Purpose:   

*********************************************************************/
bool Pop(LinkStack &S, ElemType &e)
{
	if (isEmpty(S))
	{
		return false;
	}

	Node *pTopNode = S->next;
	e.data = pTopNode->e.data;

	S->next = pTopNode->next;
	free(pTopNode);

	return true;
}

/********************************************************************
	Method:    GetTop
	Parameter: 
	Returns:   

	Purpose:   

*********************************************************************/
bool GetTop(LinkStack S, ElemType &e)
{
	if (isEmpty(S))
	{
		return false;
	}

	Node *pTopNode = S->next;
	e.data = pTopNode->e.data;

	return true;
}

/********************************************************************
	Method:    OperationTest
	Parameter: 
	Returns:   

	Purpose:   测试函数

*********************************************************************/

bool OperationTest()
{
	LinkStack S;

	InitStack(S);

	ElemType e;
	e.data = 1;

	Push(S, e);

	e.data = 2;

	Push(S, e);

	Pop(S, e);
	printf("%d\n", e.data);

	e.data = 3;
	Push(S, e);

	Pop(S, e);
	printf("%d\n", e.data);

	DestroyStack(S);	//	销毁栈
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