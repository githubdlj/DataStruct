/********************************************************************
	Time:	  2015/09/06
	Filename: LinkQueue
	Author:	  dinglj
	
	Purpose:  ���ӵ�ʵ��
*********************************************************************/

#include <stdio.h>
#include <stdlib.h>

// 
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

//	����
typedef struct 
{
	pNode front;
	pNode rear;
}LinkQueue;

//	������������
//////////////////////////////////////////////////////////////////////
bool InitQueue(LinkQueue &Q);
bool DestroyQueue(LinkQueue &Q);

bool ClearQueue(LinkQueue &Q);

bool isEmpty(LinkQueue Q);
bool isFull(LinkQueue Q);

bool EnQueue(LinkQueue &Q, ElemType e);
bool DeQueue(LinkQueue &Q, ElemType &e);

bool GetHead(LinkQueue &Q, ElemType &e);

//////////////////////////////////////////////////////////////////////

/********************************************************************
	Method:    InitQueue
	Parameter: 
	Returns:   

	Purpose:   

*********************************************************************/
bool InitQueue(LinkQueue &Q)
{
	Q.front = (Node *)malloc(sizeof(Node));
	Q.front->next = NULL;

	Q.rear = Q.front;
	
	return true;
}

/********************************************************************
	Method:    DestroyQueue
	Parameter: 
	Returns:   

	Purpose:   ����

*********************************************************************/
bool DestroyQueue(LinkQueue &Q)
{
	ClearQueue(Q);

	free(Q.front);
	Q.front = Q.rear = NULL;

	return true;
}
/********************************************************************
	Method:    ClearQueue
	Parameter: 
	Returns:   

	Purpose:   ���

*********************************************************************/
bool ClearQueue(LinkQueue &Q)
{
	Node *pDeleteNode = Q.front->next;
	while (pDeleteNode)
	{
		Q.front->next = pDeleteNode->next;
		free(pDeleteNode);

		pDeleteNode = Q.front->next;
	}

	Q.rear = Q.front;

	return true;
}

/********************************************************************
	Method:    isEmpty
	Parameter: 
	Returns:   

	Purpose:   

*********************************************************************/
bool isEmpty(LinkQueue Q)
{
	return Q.front == Q.rear;
}

//	���Ӳ�����
bool isFull(LinkQueue Q)
{
	return false;
}

/********************************************************************
	Method:    EnQueue
	Parameter: 
	Returns:   

	Purpose:   

*********************************************************************/
bool EnQueue(LinkQueue &Q, ElemType e)
{
	if (isFull(Q))
	{
		return false;
	}

	Node *pNewNode = (Node *)malloc(sizeof(Node));
	pNewNode->e.data = e.data;
	pNewNode->next = NULL;

	Q.rear->next = pNewNode;
	Q.rear = pNewNode;

	return true;
}

/********************************************************************
	Method:    DeQueue
	Parameter: 
	Returns:   

	Purpose:   

*********************************************************************/
bool DeQueue(LinkQueue &Q, ElemType &e)
{
	if (isEmpty(Q))
	{
		return false;
	}

	Node *pHeadNode = Q.front->next;
	e.data = pHeadNode->e.data;

	Q.front->next = pHeadNode->next;

	if (pHeadNode == Q.rear)	//	��ֻ��һ��Ԫ�أ���Ҫ���⴦��βָ��
	{
		Q.rear = Q.front;
	}

	free(pHeadNode);

	return true;
}

/********************************************************************
	Method:    GetHead
	Parameter: 
	Returns:   

	Purpose:   

*********************************************************************/
bool GetHead(LinkQueue Q, ElemType &e)
{
	if (isEmpty(Q))
	{
		return false;
	}

	Node *pHeadNode = Q.front->next;
	e.data = pHeadNode->e.data;

	return true;
}

/********************************************************************
	Method:    OperationTest
	Parameter: 
	Returns:   

	Purpose:   

*********************************************************************/
bool OperationTest()
{
	LinkQueue Q;
	InitQueue(Q);

	ElemType e;

	e.data = 1;
	EnQueue(Q, e);

	e.data = 2;
	EnQueue(Q, e);

	DeQueue(Q, e);
	printf("%d\n", e.data);

	e.data = 3;
	EnQueue(Q, e);

	DeQueue(Q, e);
	printf("%d\n", e.data);

	DestroyQueue(Q);

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