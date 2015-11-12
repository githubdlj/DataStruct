/********************************************************************
	Time:	  2015/11/12
	Filename: sort
	Author:	  dinglj
	
	Purpose:  ���������һЩ��ʼ���ݣ��Լ�����ṹ
*********************************************************************/
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////
//  ȫ������
#define SIZE 10
const int arr[SIZE] = {3,4,4,1,2,6,5,2,3,0};
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
