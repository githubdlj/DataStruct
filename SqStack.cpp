/********************************************************************
	Time:	  2015/09/02
	Filename: SqStack
	Author:	  dinglj
	
	Purpose:  ˳��ջ��ʵ��
*********************************************************************/

#include <stdio.h>

//////////////////////////////////////////////////////////////////////
#define MAXSIZE 20	//	����ջ�ռ��С

//	Ԫ�ض���
typedef struct  
{
	int data;
}ElemType;

typedef struct  
{
	ElemType e[MAXSIZE];
	int top;	//	ջ��ָ��
}SqStack;

//////////////////////////////////////////////////////////////////////
//	������������
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

	Purpose:   ��ʼ����ջ

*********************************************************************/
bool InitStack(SqStack &S)
{
	S.top = -1;	//	top = -1��ʾջ��

	return true;
}

/********************************************************************
	Method:    ClearStack
	Parameter: 
	Returns:   

	Purpose:   ���ջ

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

	Purpose:   �ж��Ƿ�Ϊ��ջ

*********************************************************************/
bool isEmpty(SqStack S)
{
	return S.top == -1;
}

/********************************************************************
	Method:    isFull
	Parameter: 
	Returns:   

	Purpose:   ˳��ջ��ջʱ��Ҫ�ж�ջ�Ƿ���

*********************************************************************/
bool isFull(SqStack S)
{
	return S.top == MAXSIZE - 1;
}

/********************************************************************
	Method:    Push
	Parameter: 
	Returns:   

	Purpose:   ��ջ

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

	Purpose:   ��ջ

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

	Purpose:   ��ȡջ��Ԫ��

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

	Purpose:   ���Ժ���

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