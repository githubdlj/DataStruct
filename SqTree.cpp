/********************************************************************
	Time:	  2015/09/09
	Filename: SqTree
	Author:	  dinglj
	
	Purpose:  ��������ķ�ʽʵ�ֶ��������ô���������򵥣����Ҳ���Ҫ�����ڴ棨�ر����ͷ��ڴ棩
*********************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10		//	���������Ľڵ���

//	Ԫ�ض���
typedef struct  
{
	int data;
}ElemType;

//	�ڵ�Ԫ��
typedef struct Node
{
	ElemType e;
	struct Node *LChild;
	struct Node *RChild;
}Node, *pNode;

//	������
typedef struct 
{
	Node node[MAXSIZE];		//	�ڵ�
	int numNodes;	//	�ڵ����
}BiTree;

BiTree MyTree;

//	��������
//////////////////////////////////////////////////////////////////////
bool InitBiTree();
Node *CreateBiTree();
bool DestroyBiTree(Node *T);

//	����
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
	MyTree.numNodes = 0;	//	ֻ��Ҫ��ʼ���ڵ���Ŀ
	
//	for (int i = 0; i < MyTree.numNodes; i++)
//	{
//		MyTree.node[i].LChild = MyTree.node[i].RChild = NULL;	
//	}
	
	return true;
}

//	��������������һ���½ڵ㣬�൱��pNode newNode = (Node *)malloc(sizeof(Node)), newNode->Child = NULL:
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

	Purpose:   ���򴴽�������

*********************************************************************/
Node *CreateBiTree()
{
	Node *T;

	ElemType e;
	scanf("%d", &e.data);

	if (-1 == e.data)	//	#��ʾ����
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

//	����Ҫ����
bool DestroyBiTree(Node *T)
{
	return true;
}

/********************************************************************
	Method:    
	Parameter: 
	Returns:   

	Purpose:   ����

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