/********************************************************************
	Time:	  2015/11/13
	Filename: selectSort
	Author:	  dinglj
	
	Purpose:  简单选择排序
*********************************************************************/
#include "sort.h"

/********************************************************************
	Method:    selectSort
	Parameter: 
	Returns:   

	Purpose:   对数组进行简单选择排序

*********************************************************************/

void selectSort(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        //  从剩下的 n - 1 - i个元素中选出最小的一个
        int minIndex = i;
        for (int j = i + 1; j < n; ++j)     //  从 i + 1开始而不是i,减少了与自身的比较
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        //  交换，将最小值放到前面
        if (minIndex != i)  
        {
            swap(arr[i], arr[minIndex]);
        }
    }
}

/********************************************************************
	Method:    selectSort
	Parameter: 
	Returns:   

	Purpose:   对单链表进行简单选择排序

*********************************************************************/

void selectSort_LinkList(LinkList &L)
{
    for (Node *pOrdered = L->next; NULL != pOrdered; pOrdered = pOrdered->next)
    {
        Node *pMinIndex = pOrdered;

        //  选出最小值结点
        for (Node *pUnOrdered = pOrdered->next; NULL != pUnOrdered; pUnOrdered = pUnOrdered->next)
        {
            if (pUnOrdered->data < pMinIndex->data)
            {
                pMinIndex = pUnOrdered;
            }
        }

        if (pMinIndex != pOrdered)
        {
            swap(pMinIndex->data, pOrdered->data);
        }
    }
}