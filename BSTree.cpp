/********************************************************************
	Time:	  2015/09/09
	Filename: BSTree
	Author:	  dinglj
	
	Purpose:  ������������ʵ��
*********************************************************************/

#include <stdio.h>
#include <stdlib.h>

//	Ԫ��
typedef struct 
{
	int key;	//	��ֵ
}ElemType;

//	�ڵ�����
typedef struct Node
{
	ElemType e;
	struct Node *LChild;
	struct Node *RChild;
}Node, *pNode;

//	����������Ķ���
typedef pNode BSTree;

//	��������
//////////////////////////////////////////////////////////////////////
bool CreateBSTree(BSTree &T, ElemType e[], int n);
bool DestroyBSTree(BSTree &T);

bool InOrderTraverse(BSTree T);	//	���������������ʵ�����ǰ������

pNode SearchElem(BSTree T, ElemType e);

bool InsertElem(BSTree &T, ElemType e);
bool DeleteElem(BSTree &T, ElemType e);
//////////////////////////////////////////////////////////////////////

/********************************************************************
	Method:    InsertElem
	Parameter: 
	Returns:   

	Purpose:   �����������Ĳ��룬 ʵ�����������ڶ��������ȸ�����

*********************************************************************/
bool InsertElem(BSTree &T, ElemType e)
{
	if (NULL == T)	//	���Ϊ������ֱ�Ӳ���
	{
		T = (Node *)malloc(sizeof(Node));

		T->e.key = e.key;
		T->LChild = NULL;
		T->RChild = NULL;

		return true;
	}

	if (e.key < T->e.key)	//	����������
	{
		InsertElem(T->LChild, e);
	}
	else if (e.key > T->e.key)	//	���뵽������
	{
		InsertElem(T->RChild, e);
	}
	else	//	�����Բ�����ͬԪ��
	{	
		return false;	
	}
}

/********************************************************************
	Method:    DeleteElem
	Parameter: 
	Returns:   

	Purpose:   ɾ��Ԫ�ء� ��Ϊ���ӣ���ʱû��ʵ��

*********************************************************************/
bool DeleteELem(BSTree &T, ElemType e)
{
	return true;
}

/********************************************************************
	Method:    CreateBSTree
	Parameter: ������������ ����Ԫ��
	Returns:   

	Purpose:   ��������ĵĽ���

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

	Purpose:   �����������ٶ���������

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

	Purpose:   �����������������

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
	Returns:   Ԫ�����ڽڵ�ָ��

	Purpose:   ����Ԫ�ء�

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

	Purpose:   ���Ժ���

*********************************************************************/
bool OperationTest()
{
	BSTree T = NULL;

	ElemType e[10];
	for (int i = 0; i < 10; i++)
	{
		e[i].key = rand() % 100;
	}

	//	����
	CreateBSTree(T, e, 10);
	

	InOrderTraverse(T);	//	����
	printf("\n");

	e[0].key = 38;
	InsertElem(T, e[0]);	//	����

	InOrderTraverse(T);	//	����
	printf("\n");

	pNode pElem = SearchElem(T, e[0]);	//	����
	printf("%d\n", pElem->e.key);

	DestroyBSTree(T);	//	����

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