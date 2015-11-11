/********************************************************************
	Time:	  2015/11/11
	Filename: bubbleSort
	Author:	  dinglj
	
	Purpose:  ð������
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

	Purpose:   ���������ð������

*********************************************************************/
//////////////////////////////////////////////////////////////////////
void bubbleSort_1(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 1; j < n - i; ++j)     //  ͷ����ʼ����β��������
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
        for (int j = n - 1; j > i; --j)     //  β����ʼ����ͷ��������
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
        for (int j = i; j < n - 1; ++j)     //  ͷ����ʼ���򣬴�ʱ���������β��
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
        swap(arr[i], arr[n - 1]);           //   ��β��������浽ͷ������ʱ����Ӵ�С����
    }
}

//////////////////////////////////////////////////////////////////////
//  ���⡣����β����ʼ���򣬽�����浽β��
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

	Purpose:   �Ե��������ð������,��С����

*********************************************************************/
//  ������ṹ
typedef struct Node
{
    int data;
    struct Node *next;
}Node;

typedef Node * LinkList;

//////////////////////////////////////////////////////////////////////
//  ʵ������ͷ�����򣬽�������浽ͷ����������bubble_sort3
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
        //  ��β����Сֵ���浽ͷ��,��ʱ��pInnerLoopָ�����һ���ڵ�
        swap(pOuterLoop->data, pInnerLoop->data);
    }
}