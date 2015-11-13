/********************************************************************
	Time:	  2015/11/13
	Filename: selectSort
	Author:	  dinglj
	
	Purpose:  ��ѡ������
*********************************************************************/
#include "sort.h"

/********************************************************************
	Method:    selectSort
	Parameter: 
	Returns:   

	Purpose:   ��������м�ѡ������

*********************************************************************/

void selectSort(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        //  ��ʣ�µ� n - 1 - i��Ԫ����ѡ����С��һ��
        int minIndex = i;
        for (int j = i + 1; j < n; ++j)     //  �� i + 1��ʼ������i,������������ıȽ�
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        //  ����������Сֵ�ŵ�ǰ��
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

	Purpose:   �Ե�������м�ѡ������

*********************************************************************/

void selectSort_LinkList(LinkList &L)
{
    for (Node *pOrdered = L->next; NULL != pOrdered; pOrdered = pOrdered->next)
    {
        Node *pMinIndex = pOrdered;

        //  ѡ����Сֵ���
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