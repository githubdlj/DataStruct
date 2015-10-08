/********************************************************************
	Time:	  2015/09/02
	Filename: SqStack
	Author:	  dinglj
	
	Purpose:  顺序栈的实现
*********************************************************************/

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
#define MAXSIZE 20	//	最大的栈空间大小

//	元素定义
typedef struct  
{
	int data;
}ElemType;

typedef struct  
{
	ElemType e[MAXSIZE];
	int top;	//	栈顶指针
}SqStack;

//////////////////////////////////////////////////////////////////////
//	基本函数申明
bool InitStack(SqStack &S);
bool DestroyStack(SqStack &S);

bool ClearStack(SqStack &S);

bool isFull(SqStack S);
bool isEmpty(SqStack S);

bool Push(SqStack &S, ElemType e);
bool Pop(SqStack &S, ElemType &e);

bool GetTop(SqStack S, ElemType &e);



//////////////////////////////////////////////////////////////////////

/********************************************************************
	Method:    InitStack
	Parameter: 
	Returns:   

	Purpose:   初始化空栈

*********************************************************************/
bool InitStack(SqStack &S)
{
	S.top = -1;	//	top = -1表示栈空

	return true;
}

/********************************************************************
	Method:    ClearStack
	Parameter: 
	Returns:   

	Purpose:   清空栈

*********************************************************************/
bool ClearStack(SqStack &S)
{
	S.top = -1;
	
	return true;
}

bool DestroyStack(SqStack &S)
{
	ClearStack(S);

	return true;
}

/********************************************************************
	Method:    isEmpty
	Parameter: 
	Returns:   

	Purpose:   判断是否为空栈

*********************************************************************/
bool isEmpty(SqStack S)
{
	return S.top == -1;
}

/********************************************************************
	Method:    isFull
	Parameter: 
	Returns:   

	Purpose:   顺序栈入栈时需要判断栈是否满

*********************************************************************/
bool isFull(SqStack S)
{
	return S.top == MAXSIZE - 1;
}

/********************************************************************
	Method:    Push
	Parameter: 
	Returns:   

	Purpose:   入栈

*********************************************************************/
bool Push(SqStack &S, ElemType e)
{
	if (isFull(S))
	{
		return false;
	}

	S.top++;
	S.e[S.top].data = e.data;

	return true;
}

/********************************************************************
	Method:    Pop
	Parameter: 
	Returns:   

	Purpose:   出栈

*********************************************************************/
bool Pop(SqStack &S, ElemType &e)
{
	if (isEmpty(S))
	{
		return false;
	}

	e.data = S.e[S.top].data;
	S.top--;

	return true;
}

/********************************************************************
	Method:    GetTop
	Parameter: 
	Returns:   

	Purpose:   获取栈顶元素

*********************************************************************/
bool GetTop(SqStack S, ElemType &e)
{
	if (isEmpty(S))
	{
		return false;
	}

	e.data = S.e[S.top].data;

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
	SqStack S;

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