/********************************************************************
	Time:	  2015/09/09
	Filename: SqTree
	Author:	  dinglj
	
	Purpose:  采用数组的方式实现二叉树，好处在于数组简单，并且不需要管理内存（特别是释放内存）
*********************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10		//	二叉树最大的节点数

//	元素定义
typedef struct  
{
	int data;
}ElemType;

//	节点元素
typedef struct Node
{
	ElemType e;
	struct Node *LChild;
	struct Node *RChild;
}Node, *pNode;

//	二叉树
typedef struct 
{
	Node node[MAXSIZE];		//	节点
	int numNodes;	//	节点个数
}BiTree;

BiTree MyTree;

//	基本操作
//////////////////////////////////////////////////////////////////////
bool InitBiTree();
Node *CreateBiTree();
bool DestroyBiTree(Node *T);

//	遍历
bool visit(Node *p)
{
	if (p)
	{
		printf("%d\t", p->e.data);
	}

	return true;	
}

bool PreOrderTraverse(Node *T, bool (*pFunc)(Node *));
bool InOrderTraverse(Node *T, bool (*pFunc)(Node *));
bool PostOrderTraverse(Node *T, bool (*pFunc)(Node *));
bool LevelOrderTraverse(Node *T, bool (*pFunc)(Node *));
//////////////////////////////////////////////////////////////////////

bool InitBiTree()
{
	MyTree.numNodes = 0;	//	只需要初始化节点数目
	
//	for (int i = 0; i < MyTree.numNodes; i++)
//	{
//		MyTree.node[i].LChild = MyTree.node[i].RChild = NULL;	
//	}
	
	return true;
}

//	辅助函数，创建一个新节点，相当于pNode newNode = (Node *)malloc(sizeof(Node)), newNode->Child = NULL:
pNode NewNode()
{
	MyTree.node[MyTree.numNodes].LChild = MyTree.node[MyTree.numNodes].RChild = NULL;
	
	MyTree.numNodes++;

	return &MyTree.node[MyTree.numNodes];
}

/********************************************************************
	Method:    CreateBiTree
	Parameter: 
	Returns:   

	Purpose:   先序创建二叉树

*********************************************************************/
Node *CreateBiTree()
{
	Node *T;

	ElemType e;
	scanf("%d", &e.data);

	if (-1 == e.data)	//	#表示空树
	{
		T = NULL;
	}
	else
	{
		T = NewNode();
		T->e.data = e.data;

		T->LChild = CreateBiTree();
		T->RChild = CreateBiTree();
	}

	return T;
}

//	不需要销毁
bool DestroyBiTree(Node *T)
{
	return true;
}

/********************************************************************
	Method:    
	Parameter: 
	Returns:   

	Purpose:   遍历

*********************************************************************/
bool PreOrderTraverse(Node *T, bool (*pFunc)(Node *))
{
	if (T)
	{
		pFunc(T);

		PreOrderTraverse(T->LChild, visit);
		PreOrderTraverse(T->RChild, visit);
	}

	return true;
}

bool InOrderTraverse(Node &T, bool (*pFunc)(Node *))
{
	return true;
}

bool PostOrderTraverse(Node *T, bool (*pFunc)(Node *))
{
	return true;
}

bool LevelOrderTraverse(Node *T, bool (*pFunc)(Node *))
{
	return true;
}

/********************************************************************
	Method:    OperatoinTest
	Parameter: 
	Returns:   

	Purpose:   

*********************************************************************/
bool OperationTest()
{
	InitBiTree();
		
	Node *T = CreateBiTree();

	printf("ok\n");
	PreOrderTraverse(T, visit);

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