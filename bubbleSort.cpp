/********************************************************************
	Time:	  2015/11/11
	Filename: bubbleSort
	Author:	  dinglj
	
	Purpose:  冒泡排序
*********************************************************************/
#include <stdio.h>
//  swap
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

/********************************************************************
	Method:    bubbleSort
	Parameter: 
	Returns:   

	Purpose:   对数组进行冒泡排序

*********************************************************************/
//////////////////////////////////////////////////////////////////////
void bubbleSort_1(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 1; j < n - i; ++j)     //  头部开始排序，尾部保存结果
        {
            if (arr[j - 1] > arr[j])
            {
                swap(arr[j - 1], arr[j]);
            }
        }
    }
}

//////////////////////////////////////////////////////////////////////
void bubbleSort_2(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)        
    {
        for (int j = n - 1; j > i; --j)     //  尾部开始排序，头部保存结果
        {
            if (arr[j - 1] > arr[j])
            {
                swap(arr[j - 1], arr[j]);
            }
        }
    }
}

//////////////////////////////////////////////////////////////////////
void bubbleSort_3(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i; j < n - 1; ++j)     //  头部开始排序，此时结果保存在尾部
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
        swap(arr[i], arr[n - 1]);           //   将尾部结果保存到头部，此时结果从大到小排序
    }
}

//////////////////////////////////////////////////////////////////////
//  此外。还有尾部开始排序，结果保存到尾部
//  bubbleSort_4

//////////////////////////////////////////////////////////////////////
//  OperationTest
void OperationTest_1()
{
	int arr[10] = {5,3,7,7,9,2,5,1,6,7};
	
	bubbleSort_3(arr, 10);
	
	for (int i = 0; i < 10; i++)
	{
		printf("%d\t", arr[i]);	
	}	
}

/********************************************************************
	Method:    bubbleSort
	Parameter: 
	Returns:   

	Purpose:   对单链表进行冒泡排序,从小到大

*********************************************************************/
//  单链表结构
typedef struct Node
{
    int data;
    struct Node *next;
}Node;

typedef Node * LinkList;

//////////////////////////////////////////////////////////////////////
//  实际上是头部排序，将结果保存到头部，类似于bubble_sort3
void bubbleSort_LinkList(LinkList &L)
{
    for (Node *pOuterLoop = L->next; NULL != pOuterLoop->next; pOuterLoop = pOuterLoop->next)
    {
        Node *pInnerLoop = pOuterLoop;
        for (; NULL != pInnerLoop->next; pInnerLoop = pInnerLoop->next)
        {
            if (pInnerLoop->data < pInnerLoop->next->data)
            {
                swap(pInnerLoop->data, pInnerLoop->next->data);
            }
        }
        //  将尾部最小值保存到头部,此时的pInnerLoop指向最后一个节点
        swap(pOuterLoop->data, pInnerLoop->data);
    }
}