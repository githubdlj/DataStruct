/********************************************************************
	Time:	  2015/09/07
	Filename: BiTree
	Author:	  dinglj
	
	Purpose:  ��ʽ�������Ļ���ʵ��
*********************************************************************/

#include <stdio.h>
#include <stdlib.h>

//	Ԫ�ض���
typedef struct 
{
	int data;
}ElemType;

//	�ڵ㶨��
typedef struct Node
{
	ElemType e;

	struct Node *LChild;
	struct Node *RChild;
}Node, *pNode;

//	����������
typedef pNode BiTree;

//	��������
//////////////////////////////////////////////////////////////////////
bool InitBiTree(BiTree &T);
bool CreateBiTree(BiTree &T);
bool DestroyBiTree(BiTree &T);

//	����
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

	Purpose:   ��ʼ��������

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

	Purpose:   ���򴴽�������, #��ʾ����
				�����Ƚ������ڵ㣬���Ա�����������������������ߺ��򶼲�����

*********************************************************************/
bool CreateBiTree(BiTree &T)
{
	ElemType e;
	scanf("%d", &e.data);

	if (-1 == e.data)	//	#��ʾ����
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

	Purpose:   �������ٶ�����
				��ò��ú���ɾ�����������������ڵ㣻����������������ɾ���˸��ڵ㣬����ɾ����������������

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

	Purpose:   ����������

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

	Purpose:   ��α���

*********************************************************************/
bool LevelOrderTraverse(BiTree T, bool (*pFunc)(Node *))
{
	pNode Queue[20];		//	�򵥵�һ���ڵ���У�������������
	int front = 0;
	int rear = 0;

	if (T)
	{
		Queue[rear++] = T;	//	���ڵ���ջ 
	}

	while (rear != front)	//	���в���
	{
		Node *visitNode = Queue[front++];	//	������
		pFunc(visitNode);	//	����

		//	���Һ��ӽ������
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

	Purpose:   ���Ժ���

*********************************************************************/
bool OperationTest()
{
	BiTree T;

	//	����
	CreateBiTree(T);

	//	����
	PreOrderTraverse(T, visit);
	printf("\n");
	
	InOrderTraverse(T, visit);
	printf("\n");
	
	PostOrderTraverse(T, visit);
	printf("\n");
	
	LevelOrderTraverse(T, visit);
	printf("\n");
	
	//	����
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