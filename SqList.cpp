/*-------------------------------------------------------------------------
    
-------------------------------------------------------------------------*/
/********************************************************************
	Time:	  2015/09/01
	Filename: SqList
	Author:	  dinglj
	
	Purpose:  ˳���Ļ���ʵ��
*********************************************************************/
#include <stdio.h>

#define MAXSIZE 20

// ������������, �Ƽ���һ�ַ��������ߵ���
typedef struct  
{
	int data;
//	char e[20]; 
}ElemType;

// #define ElemType int;

// ˳���
typedef struct  
{
	ElemType e[MAXSIZE];
	int length;
}SqList;


//��Ҫ��������
//////////////////////////////////////////////////////////////////////////
bool InitList(SqList &L);	//	��ʼ��

bool InsertElem(SqList &L, ElemType e, int pos);
bool DeleteElem(SqList &L, int pos);

bool GetKthElem(SqList L, int k, ElemType &e);

bool CreateList(SqList &L, int num);
bool ClearList(SqList &L);

bool isEmpty(SqList L);

bool visit(ElemType e)	//	����Ԫ��
{
	printf("%d\t", e.data);

	return true;
}
bool TraverseList(SqList L, bool (*pFunc)(ElemType ));	// ����ָ��Ӧ��
/********************************************************************
	Method:    InitList
	Parameter: 
	Returns:   

	Purpose:   ��ʼ��˳���

*********************************************************************/
bool InitList(SqList &L)
{
	L.length = 0;

	return true;
}

/********************************************************************
	Method:    InsertElem
	Parameter: ˳���, ������Ԫ�أ� ����λ��
	Returns:   

	Purpose:   ˳���Ĳ���

*********************************************************************/
bool InsertElem(SqList &L, ElemType e, int pos)
{
	////////////////////	�Ϸ��Լ��

	//	�Ƿ񻹿��Բ���
	if (L.length + 1 > MAXSIZE)
	{
		return false;
	}

	//	����λ�ü��
	if (pos < 1 || pos > L.length + 1)
	{
		return false;
	}
	///////////////////////////////////////

	
	//	�ƶ�Ԫ��
	for (int i = L.length - 1; i >= pos - 1; i--)	//	�Ӻ���ǰ�ƶ�, ע��ѭ���߽�
	{
		L.e[i + 1].data = L.e[i].data;
	}

	L.e[pos - 1].data = e.data;
	L.length++;

	return true;
}

/********************************************************************
	Method:    DeleteElem
	Parameter: ˳��� ɾ��λ��
	Returns:   

	Purpose:   

*********************************************************************/
bool DeleteElem(SqList &L, int pos)
{
	///////////// �Ϸ��Լ��
	if (0 == L.length)
	{
		return false;
	}

	if (pos < 1 || pos > L.length)
	{
		return false;
	}
	/////////////////////
	
	
	for (int i = pos; i < L.length; i++)	//	��ǰ�����ƶ�Ԫ�أ�ע��ѭ���߽�
	{
		L.e[i - 1].data = L.e[i].data;
	}

	L.length--;

	return true;
}

/********************************************************************
	Method:    GetKthElem
	Parameter: ˳���Ԫ��λ�ã�����ֵ
	Returns:   

	Purpose:   ��ȡ��k��Ԫ��

*********************************************************************/
bool GetKthElem(SqList L, int k, ElemType &e)
{
	//	�Ϸ��Լ��
	if (k < 1 || k > L.length)
	{
		return false;
	}

	e.data = L.e[k - 1].data;

	return true;
}


/********************************************************************
	Method:    CreateList
	Parameter: 
	Returns:   

	Purpose:   �򵥵Ĵ���˳���Ϊ�˲��Բ��룬ɾ������

*********************************************************************/
bool CreateList(SqList &L, int num)
{
	InitList(L);	//	��ʼ��

	for (int i = 0; i < num; i++)
	{
		L.e[i].data = i + 1;
	}
	L.length = num;
	
	return true;
}

/********************************************************************
	Method:    ClearList
	Parameter: 
	Returns:   

	Purpose:   ���

*********************************************************************/

bool ClearList(SqList &L)
{
	L.length = 0;
	
	return true;
}

/********************************************************************
	Method:    isEmpty
	Parameter: 
	Returns:   

	Purpose:   ˳����Ƿ�Ϊ��

*********************************************************************/
bool isEmpty(SqList L)
{
	return L.length == 0;
}

/********************************************************************
	Method:    TraverseList
	Parameter: ˳��� ����ָ��
	Returns:   

	Purpose:   ˳���ı���

*********************************************************************/
bool TraverseList(SqList L, bool (*pFunc)(ElemType))
{
	for (int i = 0; i < L.length; i++)
	{
		pFunc(L.e[i]);
	}

	printf("\n");

	return true;
}
/********************************************************************
	Method:    InsertTest
	Parameter: 
	Returns:   

	Purpose:   �������

*********************************************************************/
bool InsertTest(SqList &L)
{
	//	���Բ���
	ElemType e;
	e.data = 5;
	InsertElem(L, e, 1);
	
	e.data = 6;
	InsertElem(L, e, 4);
	
	e.data = 7;
	
	InsertElem(L, e, 7);

    TraverseList(L, visit);		//	����
	
	return true;
}

/********************************************************************
	Method:    DeleteTest
	Parameter: 
	Returns:   

	Purpose:   ɾ������

*********************************************************************/
bool DeleteTest(SqList &L)
{
	DeleteElem(L, 7);
	DeleteElem(L, 4);
	DeleteElem(L, 1);	

	TraverseList(L, visit);
	
	return true;
}

/********************************************************************
	Method:    OperationTest
	Parameter: 
	Returns:   

	Purpose:   ���в�������

*********************************************************************/
bool OperationTest()
{
	SqList L;
	
	CreateList(L, 4);
	
	TraverseList(L, visit);
	
	//	�������
	InsertTest(L);
	
	//	ɾ������
	DeleteTest(L);
	
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