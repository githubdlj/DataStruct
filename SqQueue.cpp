/********************************************************************
	Time:	  2015/09/06
	Filename: SqQueue
	Author:	  dinglj
	
	Purpose:  循环队列的实现
*********************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20	//	队列空间

//	元素定义
typedef struct
{
	int data;
}ElemType;

//	循环队列定义
typedef struct  
{
	ElemType e[MAXSIZE];

	int front;
	int rear;
}SqQueue;

//	 基本函数
//////////////////////////////////////////////////////////////////////
bool InitQueue(SqQueue &Q);
bool ClearQueue(SqQueue &Q);
bool DestroyQueue(SqQueue &Q);

bool isEmpty(SqQueue Q);
bool isFull(SqQueue Q);

bool EnQueue(SqQueue &Q, ElemType e);
bool DeQueue(SqQueue &Q, ElemType &e);

bool GetHead(SqQueue &Q, ElemType e);
//////////////////////////////////////////////////////////////////////

/********************************************************************
	Method:    InitQueue
	Parameter: 
	Returns:   

	Purpose:   

*********************************************************************/
bool InitQueue(SqQueue &Q)
{
	Q.front = Q.rear = 0;

	return true;
}

bool ClearQueue(SqQueue &Q)
{
	Q.front = Q.rear = 0;

	return true;
}

bool DestroyQueue(SqQueue &Q)
{
	ClearQueue(Q);

	return true;
}

/********************************************************************
	Method:    isEmpty
	Parameter: 
	Returns:   

	Purpose:   

*********************************************************************/
bool isEmpty(SqQueue Q)
{
	return Q.front == Q.rear;
	
	return true;
}

/********************************************************************
	Method:    isFull
	Parameter: 
	Returns:   

	Purpose:   

*********************************************************************/
bool isFull(SqQueue Q)
{
	return Q.front == ( (Q.rear + 1) % MAXSIZE );
}

/********************************************************************
	Method:    EnQueue
	Parameter: 
	Returns:   

	Purpose:   

*********************************************************************/
bool EnQueue(SqQueue &Q, ElemType e)
{
	if (isFull(Q))
	{
		return false;
	}

	Q.e[Q.rear].data = e.data;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	
	return true;
}

/********************************************************************
	Method:    DeQueue
	Parameter: 
	Returns:   

	Purpose:   

*********************************************************************/
bool DeQueue(SqQueue &Q, ElemType &e)
{
	if (isEmpty(Q))
	{
		return false;
	}

	e.data = Q.e[Q.front].data;
	Q.front = (Q.front + 1) % MAXSIZE;

	return true;
}

/********************************************************************
	Method:    GetHead
	Parameter: 
	Returns:   

	Purpose:   

*********************************************************************/
bool GetHead(SqQueue Q, ElemType &e)
{
	if (isEmpty(Q))
	{
		return false;
	}

	e.data = Q.e[Q.front].data;

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
	SqQueue Q;
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