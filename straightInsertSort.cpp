/********************************************************************
	Time:	  2015/11/12
	Filename: straightInsertSort
	Author:	  dinglj
	
	Purpose:  ֱ�Ӳ�������
*********************************************************************/
#include "sort.h"

/********************************************************************
	Method:    straightInsertSort
	Parameter: 
	Returns:   

	Purpose:   ���������ֱ�Ӳ�������

*********************************************************************/
void straightInsertSort(int arr[], int n)
{
    //  ��һ��λ�ô���ڱ�����һ��Ԫ���Ѿ��������Դ�i = 2��ʼ
    for (int i = 2; i <= n; ++i)
    {
        arr[0] = arr[i];    //  1�������ڱ���2���ݴ������Ԫ��

        for (int j = i - 1; arr[0] < arr[j]; --j)   //  Ϊ��ʹ�������ȶ�����ȡ�Ⱥ�
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = arr[0];   
    }
}   //  �ڱ����á�1���������ж϶�� j > 0 �жϡ�2�����������Ԫ��arr[i] 

/********************************************************************
	Method:    straightInsertSort_Linklist
	Parameter: 
	Returns:   

	Purpose:   �Ե��������ֱ�Ӳ�������

*********************************************************************/
// void straightInsertSort_Linklist(LinkList &L)
// {
//     for (Node *pOrdered = L->next; NULL != pOrdered->next; pOrdered = pOrdered->next)
//     {
//         Node *pInsertNode = pOrdered->next;     //  �������Ԫ��
//         
//         Node *pInsertIndexPre = L;          //  ����λ�õ�ǰ��
//         Node *pInsertIndex = L->next;       //  ����λ��
//         
//         while (pInsertIndex != pInsertNode && pInsertNode->data >= pInsertIndex->data)
//         {
//             pInsertIndexPre = pInsertIndexPre->next;
//             pInsertIndex = pInsertIndex->next;
//         }
// 
//         //  ���뵽pInsertIndex
//         pOrdered->next = pInsertNode->next;
//         pInsertNode->next = pInsertIndex;
//         pInsertIndexPre->next = pInsertNode;
//     }
// }

void straightInsertSort_LinkList(LinkList &L)
{
    Node *pOrdered = L;
    Node *pUnOrdered = pOrdered->next;     //  ��һ���ڵ㿪ʼ����
    pOrdered->next = NULL;      //  ��ʼ����������Ϊ��

    while (pUnOrdered)      //  ������������뵽��������
    {
        Node *pInsertNode = pUnOrdered;  //  ������ڵ�Ϊ������һ���ڵ�
        pUnOrdered = pInsertNode->next;

        Node *pLocation = L;     //  ����λ��
        Node *pLocationNext = pLocation->next;

        //   Ѱ�Ҳ���λ��
        while (pLocationNext && pLocationNext->data <= pInsertNode->data)     //  Ϊ��ʹ�������ȶ���ȡ�Ⱥ�
        {
            pLocation = pLocation->next;
            pLocationNext = pLocationNext->next;
        }

        //   �����½ڵ�
        pInsertNode->next = pLocation->next;
        pLocation->next = pInsertNode;
    }
}