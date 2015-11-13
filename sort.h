/********************************************************************
	Time:	  2015/11/12
	Filename: sort
	Author:	  dinglj
	
	Purpose:  ���������һЩ��ʼ���ݣ��Լ�����ṹ
*********************************************************************/
#include <stdio.h>
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////
//  ȫ������
#define SIZE 10
int randomArr[SIZE] = {3,4,4,1,2,6,5,2,3,0};
int orderedArr[SIZE] = {0,1,2,2,3,3,4,4,5,6};
int orderedArr_reverse[SIZE] = {6,5,4,4,3,3,2,2,1,0};

//  �����������Ϊ�գ��������һ��Ԫ�ص����  

//////////////////////////////////////////////////////////////////////
//  ������ṹ
typedef struct Node
{
    int data;
    struct Node *next;
}Node;

typedef Node * LinkList;

/********************************************************************
	Method:    ����������������ٲ���
	Parameter: 
	Returns:   

	Purpose:   

*********************************************************************/
//  ������
void CreateList(LinkList &L, int arr[], int n)
{
    //  ����ͷ���
    L = (Node *)malloc(sizeof(Node));
    L->next = NULL;

    //  ͷ�巨��������
    for (int nodeNum = 0; nodeNum < n; ++nodeNum)
    {
        Node *pNewNode = (Node*)malloc(sizeof(Node));
        pNewNode->data = arr[n - 1 - nodeNum];
        pNewNode->next = NULL;

        //  ����
        pNewNode->next = L->next;
        L->next = pNewNode;
    }
}

//  ��������
void DestroyList(LinkList &L)
{
    Node *pDeleteNode = L->next;
    while (pDeleteNode)
    {
        L->next = pDeleteNode->next;
        free(pDeleteNode);
        pDeleteNode = L->next;
    }
    free(L);
}

//  �������
void PrintList(LinkList L)
{
    Node *pNodeIndex = L->next;
    while (pNodeIndex)
    {
        printf("%d\t", pNodeIndex->data);
        pNodeIndex = pNodeIndex->next;
    }
    printf("\n");
}

/********************************************************************
	Method:    swap
	Parameter: 
	Returns:   

	Purpose:   

*********************************************************************/
//  swap
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

//////////////////////////////////////////////////////////////////////
//  �����������
void PrintArr(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}