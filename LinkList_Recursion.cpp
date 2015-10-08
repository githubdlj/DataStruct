/********************************************************************
	Time:	  2015/09/16
	Filename: LinkList_Recursion
	Author:	  dinglj
	
	Purpose:  单链表的部分递归实现
*********************************************************************/

//	头文件
#include <stdio.h>
#include <stdlib.h>

//	元素
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

//	单链表结构
typedef pNode LinkList;


//////////////////////////////////////////////////////////////////////

//	访问元素
bool visit(Node *pElemNode)
{
	if (pElemNode)
	{
		printf("%d\t", pElemNode->e.data);
		return true;
	}

	return false;
}

//	初始化链表，不带头节点
bool InitList(LinkList &L)
{
	L = NULL;

	return true;
}

//	基本函数的递归申明
bool CreateList(LinkList &L);
bool DestroyList(LinkList &L);

bool TraverseList(LinkList L);

pNode TransposeList(LinkList L);	//	链表转置

//////////////////////////////////////////////////////////////////////

/********************************************************************
	Method:    CreateList
	Parameter: 
	Returns:   

	Purpose:   递归建立链表（类似于二叉树的先序遍历）

*********************************************************************/
bool CreateList(LinkList &L)
{
	ElemType e;
	scanf("%d", &e.data);

	if (-1 == e.data)	//	-1为输入结束标志
	{
		L = NULL;
	}
	else
	{
		L = (Node *)malloc(sizeof(Node));
		L->next = NULL;
		L->e.data = e.data;

		CreateList(L->next);
	}

	return true;
}

/********************************************************************
	Method:    DestroyList
	Parameter: 
	Returns:   

	Purpose:   递归销毁线性表（（类似于二叉树的后序遍历））

*********************************************************************/
bool DestroyList(LinkList &L)
{
	if (L)
	{
		DestroyList(L->next);

		free(L);
		L = NULL;
	}

	return true;
}

/********************************************************************
	Method:    TraverseList
	Parameter: 
	Returns:   

	Purpose:   递归遍历单链表（类似于二叉树的先序遍历）

*********************************************************************/
bool TraverseList(LinkList L)
{
	if (L)
	{
		visit(L);

		TraverseList(L->next);
	}
	
	return true;
}



/********************************************************************
	Method:    TransposeList
	Parameter: 
	Returns:   

	Purpose:   递归就地转置单链表（类似于二叉树的后序遍历），后序转置比先序转置简单，类似于销毁

*********************************************************************/

//////////////////////////////////////////////////////////////////////
//	错误的方法
//	1,2,3,4,5会变成2,1.错误原因，逆转了，但是最后的头指针指向了节点2，而不是节点5
bool TransposeList_1(LinkList &L)
{
	if (NULL == L->next)
	{
		return true;	
	}
	else
	{
		TransposeList(L->next);

		L->next->next = L;
		Node *pHead = L;
		L = L->next;
		pHead->next = NULL;
		
		return true;
	}
}

//////////////////////////////////////////////////////////////////////
//	正确的方法
pNode TransposeList(LinkList L)
{
	if (NULL == L->next)
	{
		return L;	
	}
	else
	{
		Node *pHead = TransposeList(L->next);

		L->next->next = L;
		L->next = NULL;
		
		return pHead;
	}
}
/********************************************************************
	Method:    OperationTest
	Parameter: 
	Returns:   

	Purpose:   

*********************************************************************/
bool OperationTest()
{
	LinkList L;
	
	InitList(L);	//	初始化
	CreateList(L);

	TraverseList(L);
	printf("\n");
	//////////////////////////////////////////////////////////////////////

	//
	TransposeList_1(L);
//	L = TransposeList(L);	//	转置
	TraverseList(L);
	printf("\n");

	//////////////////////////////////////////////////////////////////////
	DestroyList(L);

	TraverseList(L);
	printf("\n");

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
