/********************************************************************
	Time:	  2015/11/12
	Filename: straightInsertSort
	Author:	  dinglj
	
	Purpose:  直接插入排序
*********************************************************************/
#include "sort.h"

/********************************************************************
	Method:    straightInsertSort
	Parameter: 
	Returns:   

	Purpose:   对数组进行直接插入排序

*********************************************************************/
void straightInsertSort(int arr[], int n)
{
    //  第一个位置存放哨兵，第一个元素已经有序，所以从i = 2开始
    for (int i = 2; i <= n; ++i)
    {
        arr[0] = arr[i];    //  1、设置哨兵。2、暂存待插入元素

        for (int j = i - 1; arr[0] < arr[j]; --j)   //  为了使得排序稳定，不取等号
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = arr[0];   
    }
}   //  哨兵作用。1、减少了判断多次 j > 0 判断。2、保存待插入元素arr[i] 

/********************************************************************
	Method:    straightInsertSort_Linklist
	Parameter: 
	Returns:   

	Purpose:   对单链表进行直接插入排序

*********************************************************************/
// void straightInsertSort_Linklist(LinkList &L)
// {
//     for (Node *pOrdered = L->next; NULL != pOrdered->next; pOrdered = pOrdered->next)
//     {
//         Node *pInsertNode = pOrdered->next;     //  带插入的元素
//         
//         Node *pInsertIndexPre = L;          //  插入位置的前驱
//         Node *pInsertIndex = L->next;       //  插入位置
//         
//         while (pInsertIndex != pInsertNode && pInsertNode->data >= pInsertIndex->data)
//         {
//             pInsertIndexPre = pInsertIndexPre->next;
//             pInsertIndex = pInsertIndex->next;
//         }
// 
//         //  插入到pInsertIndex
//         pOrdered->next = pInsertNode->next;
//         pInsertNode->next = pInsertIndex;
//         pInsertIndexPre->next = pInsertNode;
//     }
// }

void straightInsertSort_LinkList(LinkList &L)
{
    Node *pOrdered = L;
    Node *pUnOrdered = pOrdered->next;     //  第一个节点开始无序
    pOrdered->next = NULL;      //  初始化有序链表为空

    while (pUnOrdered)      //  将无序链表插入到有序链表
    {
        Node *pInsertNode = pUnOrdered;  //  待插入节点为无序表第一个节点
        pUnOrdered = pInsertNode->next;

        Node *pLocation = L;     //  插入位置
        Node *pLocationNext = pLocation->next;

        //   寻找插入位置
        while (pLocationNext && pLocationNext->data <= pInsertNode->data)     //  为了使得排序稳定，取等号
        {
            pLocation = pLocation->next;
            pLocationNext = pLocationNext->next;
        }

        //   插入新节点
        pInsertNode->next = pLocation->next;
        pLocation->next = pInsertNode;
    }
}