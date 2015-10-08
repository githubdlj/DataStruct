/********************************************************************
	Time:	  2015/09/09
	Filename: BSTree
	Author:	  dinglj
	
	Purpose:  二叉排序树的实现
*********************************************************************/

#include <stdio.h>
#include <stdlib.h>

//	元素
typedef struct 
{
	int key;	//	键值
}ElemType;

//	节点类型
typedef struct Node
{
	ElemType e;
	struct Node *LChild;
	struct Node *RChild;
}Node, *pNode;

//	二叉查找树的定义
typedef pNode BSTree;

//	基本函数
//////////////////////////////////////////////////////////////////////
bool CreateBSTree(BSTree &T, ElemType e[], int n);
bool DestroyBSTree(BSTree &T);

bool InOrderTraverse(BSTree T);	//	先序遍历查找树，实际上是按序遍历

pNode SearchElem(BSTree T, ElemType e);

bool InsertElem(BSTree &T, ElemType e);
bool DeleteElem(BSTree &T, ElemType e);
//////////////////////////////////////////////////////////////////////

/********************************************************************
	Method:    InsertElem
	Parameter: 
	Returns:   

	Purpose:   二叉排序树的插入， 实际上是类似于二叉树的先根创建

*********************************************************************/
bool InsertElem(BSTree &T, ElemType e)
{
	if (NULL == T)	//	如果为空树，直接插入
	{
		T = (Node *)malloc(sizeof(Node));

		T->e.key = e.key;
		T->LChild = NULL;
		T->RChild = NULL;

		return true;
	}

	if (e.key < T->e.key)	//	插入左子树
	{
		InsertElem(T->LChild, e);
	}
	else if (e.key > T->e.key)	//	插入到右子树
	{
		InsertElem(T->RChild, e);
	}
	else	//	不可以插入相同元素
	{	
		return false;	
	}
}

/********************************************************************
	Method:    DeleteElem
	Parameter: 
	Returns:   

	Purpose:   删除元素。 较为复杂，暂时没有实现

*********************************************************************/
bool DeleteELem(BSTree &T, ElemType e)
{
	return true;
}

/********************************************************************
	Method:    CreateBSTree
	Parameter: 二叉排序树， 数组元素
	Returns:   

	Purpose:   二叉排序的的建立

*********************************************************************/
bool CreateBSTree(BSTree &T, ElemType e[], int n)
{
	for (int i = 0; i < n; i++)
	{
		InsertElem(T, e[i]);
	}

	return true;
}

/********************************************************************
	Method:    DestroyBSTree
	Parameter: 
	Returns:   

	Purpose:   后续遍历销毁二叉排序树

*********************************************************************/
bool DestroyBSTree(BSTree &T)
{
	if (T)
	{
		DestroyBSTree(T->LChild);
		DestroyBSTree(T->RChild);

		free(T);
		T = NULL;
	}

	return true;
}

/********************************************************************
	Method:    InOrderTraverse
	Parameter: 
	Returns:   

	Purpose:   中序遍历二叉排序树

*********************************************************************/
bool InOrderTraverse(BSTree T)
{
	if (T)
	{
		InOrderTraverse(T->LChild);

		printf("%d ", T->e.key);

		InOrderTraverse(T->RChild);
	}

	return true;
}

/********************************************************************
	Method:    SearchElem
	Parameter: 
	Returns:   元素所在节点指针

	Purpose:   搜索元素。

*********************************************************************/
pNode SearchElem(BSTree T, ElemType e)
{
	if (T)
	{
		if (T->e.key == e.key)
		{
			return T;
		}

		else if (e.key < T->e.key)
		{
			SearchElem(T->LChild, e);
		}
		else
		{
			SearchElem(T->RChild, e);
		}
	}
	else
	{
		return NULL;
	}
}

/********************************************************************
	Method:    OperationTest
	Parameter: 
	Returns:   

	Purpose:   测试函数

*********************************************************************/
bool OperationTest()
{
	BSTree T = NULL;

	ElemType e[10];
	for (int i = 0; i < 10; i++)
	{
		e[i].key = rand() % 100;
	}

	//	创建
	CreateBSTree(T, e, 10);
	

	InOrderTraverse(T);	//	遍历
	printf("\n");

	e[0].key = 38;
	InsertElem(T, e[0]);	//	插入

	InOrderTraverse(T);	//	遍历
	printf("\n");

	pNode pElem = SearchElem(T, e[0]);	//	查找
	printf("%d\n", pElem->e.key);

	DestroyBSTree(T);	//	销毁

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