/********************************************************************
	Time:	  2015/11/12
	Filename: sort
	Author:	  dinglj
	
	Purpose:  包含排序的一些初始数据，以及链表结构
*********************************************************************/
#include <stdio.h>
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////
//  全局数组
#define SIZE 10
int randomArr[SIZE] = {3,4,4,1,2,6,5,2,3,0};
int orderedArr[SIZE] = {0,1,2,2,3,3,4,4,5,6};
int orderedArr_reverse[SIZE] = {6,5,4,4,3,3,2,2,1,0};

//  还需测试数组为空，数组仅有一个元素的情况  

//////////////////////////////////////////////////////////////////////
//  单链表结构
typedef struct Node
{
    int data;
    struct Node *next;
}Node;

typedef Node * LinkList;

/********************************************************************
	Method:    链表建立、输出、销毁操作
	Parameter: 
	Returns:   

	Purpose:   

*********************************************************************/
//  链表创建
void CreateList(LinkList &L, int arr[], int n)
{
    //  创建头结点
    L = (Node *)malloc(sizeof(Node));
    L->next = NULL;

    //  头插法创建链表
    for (int nodeNum = 0; nodeNum < n; ++nodeNum)
    {
        Node *pNewNode = (Node*)malloc(sizeof(Node));
        pNewNode->data = arr[n - 1 - nodeNum];
        pNewNode->next = NULL;

        //  插入
        pNewNode->next = L->next;
        L->next = pNewNode;
    }
}

//  销毁链表
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

//  输出链表
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
//  输出数组内容
void PrintArr(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}