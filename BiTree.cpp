/********************************************************************
	Time:	  2015/09/07
	Filename: BiTree
	Author:	  dinglj
	
	Purpose:  链式二叉树的基本实现
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

	struct Node *LChild;
	struct Node *RChild;
}Node, *pNode;

//	二叉树定义
typedef pNode BiTree;

//	基本操作
//////////////////////////////////////////////////////////////////////
bool InitBiTree(BiTree &T);
bool CreateBiTree(BiTree &T);
bool DestroyBiTree(BiTree &T);

//	遍历
bool visit(Node *p)
{
	if (p)
	{
		printf("%d\t", p->e.data);
	}
	
	return true;	
}

bool PreOrderTraverse(BiTree T, bool (*pFunc)(Node *));
bool InOrderTraverse(BiTree T, bool (*pFunc)(Node *));
bool PostOrderTraverse(BiTree T, bool (*pFunc)(Node *));
bool LevelOrderTraverse(BiTree T, bool (*pFunc)(Node *));
//////////////////////////////////////////////////////////////////////

/********************************************************************
	Method:    InitBiTree
	Parameter: 
	Returns:   

	Purpose:   初始化二叉树

*********************************************************************/
bool InitBiTree(BiTree &T)
{
	T = NULL;

	return true;
}
/********************************************************************
	Method:    CreateBiTree
	Parameter: 
	Returns:   

	Purpose:   先序创建二叉树, #表示空树
				必须先建立根节点，所以必须先序建立二叉树，中序或者后序都不可以

*********************************************************************/
bool CreateBiTree(BiTree &T)
{
	ElemType e;
	scanf("%d", &e.data);

	if (-1 == e.data)	//	#表示空树
	{
		T = NULL;
	}
	else
	{
		T = (Node *)malloc(sizeof(Node));
		T->e.data = e.data;

		CreateBiTree(T->LChild);
		CreateBiTree(T->RChild);
	}

	return true;
}

/********************************************************************
	Method:    DestroyBiTree
	Parameter: 
	Returns:   

	Purpose:   后序销毁二叉树
				最好采用后序删除二叉树，保留根节点；若采用先序，则首先删除了根节点，导致删除左右子树不方便

*********************************************************************/
bool DestroyBiTree(BiTree &T)
{
	if (T)
	{
		DestroyBiTree(T->LChild);
		DestroyBiTree(T->RChild);

		free(T);
		T = NULL;
	}
	
	return true;
}
/********************************************************************
	Method:    
	Parameter: 
	Returns:   

	Purpose:   遍历二叉树

*********************************************************************/
bool PreOrderTraverse(BiTree T, bool (*pFunc)(Node *))
{
	if (T)
	{
		pFunc(T);

		PreOrderTraverse(T->LChild, visit);
		PreOrderTraverse(T->RChild, visit);
	}

	return true;
}

bool InOrderTraverse(BiTree T, bool (*pFunc)(Node *))
{
	if (T)
	{
		InOrderTraverse(T->LChild, visit);

		pFunc(T);

		InOrderTraverse(T->RChild, visit);
	}

	return true;
}

bool PostOrderTraverse(BiTree T, bool (*pFunc)(Node *))
{
	if (T)
	{
		PostOrderTraverse(T->LChild, visit);
		PostOrderTraverse(T->RChild, visit);

		pFunc(T);
	}

	return true;
}
/********************************************************************
	Method:    LeverOrderTraverse
	Parameter: 
	Returns:   

	Purpose:   层次遍历

*********************************************************************/
bool LevelOrderTraverse(BiTree T, bool (*pFunc)(Node *))
{
	pNode Queue[20];		//	简单的一个节点队列，用来辅助遍历
	int front = 0;
	int rear = 0;

	if (T)
	{
		Queue[rear++] = T;	//	根节点入栈 
	}

	while (rear != front)	//	队列不空
	{
		Node *visitNode = Queue[front++];	//	出队列
		pFunc(visitNode);	//	访问

		//	左右孩子进入队列
		if (visitNode->LChild)
		{
			Queue[rear++] = visitNode->LChild;
		}

		if (visitNode->RChild)
		{
			Queue[rear++] = visitNode->RChild;
		}
	}

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
	BiTree T;

	//	创建
	CreateBiTree(T);

	//	遍历
	PreOrderTraverse(T, visit);
	printf("\n");
	
	InOrderTraverse(T, visit);
	printf("\n");
	
	PostOrderTraverse(T, visit);
	printf("\n");
	
	LevelOrderTraverse(T, visit);
	printf("\n");
	
	//	销毁
	DestroyBiTree(T);

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