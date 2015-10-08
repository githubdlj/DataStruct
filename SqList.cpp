/*-------------------------------------------------------------------------
    
-------------------------------------------------------------------------*/
/********************************************************************
	Time:	  2015/09/01
	Filename: SqList
	Author:	  dinglj
	
	Purpose:  顺序表的基本实现
*********************************************************************/
#include <stdio.h>

#define MAXSIZE 20

// 基本数据类型, 推荐第一种方法，更具弹性
typedef struct  
{
	int data;
//	char e[20]; 
}ElemType;

// #define ElemType int;

// 顺序表
typedef struct  
{
	ElemType e[MAXSIZE];
	int length;
}SqList;


//主要函数申明
//////////////////////////////////////////////////////////////////////////
bool InitList(SqList &L);	//	初始化

bool InsertElem(SqList &L, ElemType e, int pos);
bool DeleteElem(SqList &L, int pos);

bool GetKthElem(SqList L, int k, ElemType &e);

bool CreateList(SqList &L, int num);
bool ClearList(SqList &L);

bool isEmpty(SqList L);

bool visit(ElemType e)	//	访问元素
{
	printf("%d\t", e.data);

	return true;
}
bool TraverseList(SqList L, bool (*pFunc)(ElemType ));	// 函数指针应用
/********************************************************************
	Method:    InitList
	Parameter: 
	Returns:   

	Purpose:   初始化顺序表

*********************************************************************/
bool InitList(SqList &L)
{
	L.length = 0;

	return true;
}

/********************************************************************
	Method:    InsertElem
	Parameter: 顺序表, 被插入元素， 插入位置
	Returns:   

	Purpose:   顺序表的插入

*********************************************************************/
bool InsertElem(SqList &L, ElemType e, int pos)
{
	////////////////////	合法性检测

	//	是否还可以插入
	if (L.length + 1 > MAXSIZE)
	{
		return false;
	}

	//	插入位置检测
	if (pos < 1 || pos > L.length + 1)
	{
		return false;
	}
	///////////////////////////////////////

	
	//	移动元素
	for (int i = L.length - 1; i >= pos - 1; i--)	//	从后往前移动, 注意循环边界
	{
		L.e[i + 1].data = L.e[i].data;
	}

	L.e[pos - 1].data = e.data;
	L.length++;

	return true;
}

/********************************************************************
	Method:    DeleteElem
	Parameter: 顺序表， 删除位置
	Returns:   

	Purpose:   

*********************************************************************/
bool DeleteElem(SqList &L, int pos)
{
	///////////// 合法性检测
	if (0 == L.length)
	{
		return false;
	}

	if (pos < 1 || pos > L.length)
	{
		return false;
	}
	/////////////////////
	
	
	for (int i = pos; i < L.length; i++)	//	从前往后移动元素，注意循环边界
	{
		L.e[i - 1].data = L.e[i].data;
	}

	L.length--;

	return true;
}

/********************************************************************
	Method:    GetKthElem
	Parameter: 顺序表，元素位置，返回值
	Returns:   

	Purpose:   获取第k个元素

*********************************************************************/
bool GetKthElem(SqList L, int k, ElemType &e)
{
	//	合法性检测
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

	Purpose:   简单的创建顺序表，为了测试插入，删除操作

*********************************************************************/
bool CreateList(SqList &L, int num)
{
	InitList(L);	//	初始化

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

	Purpose:   清空

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

	Purpose:   顺序表是否为空

*********************************************************************/
bool isEmpty(SqList L)
{
	return L.length == 0;
}

/********************************************************************
	Method:    TraverseList
	Parameter: 顺序表， 函数指针
	Returns:   

	Purpose:   顺序表的遍历

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

	Purpose:   插入测试

*********************************************************************/
bool InsertTest(SqList &L)
{
	//	测试插入
	ElemType e;
	e.data = 5;
	InsertElem(L, e, 1);
	
	e.data = 6;
	InsertElem(L, e, 4);
	
	e.data = 7;
	
	InsertElem(L, e, 7);

    TraverseList(L, visit);		//	遍历
	
	return true;
}

/********************************************************************
	Method:    DeleteTest
	Parameter: 
	Returns:   

	Purpose:   删除测试

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

	Purpose:   所有操作测试

*********************************************************************/
bool OperationTest()
{
	SqList L;
	
	CreateList(L, 4);
	
	TraverseList(L, visit);
	
	//	插入测试
	InsertTest(L);
	
	//	删除测试
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