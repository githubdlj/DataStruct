/********************************************************************
	Time:	  2015/11/13
	Filename: quickSort
	Author:	  dinglj
	
	Purpose:  ��������
*********************************************************************/
#include "sort.h"

//////////////////////////////////////////////////////////////////////
//  �����зֳ�2���֣� �����طָ��
int partion(int arr[], int low, int high)
{
    int temp = arr[low];  //  lowΪ��һ����
    int pivot = arr[low];   //  ѡȡ��Ŧ

    while (low < high)
    {
        while (low < high && arr[high] >= pivot)    //  ע�⣬��Ҫȡ���Ⱥ�
            high--;

        if (low < high)
            arr[low++] = arr[high];

        while (low < high && arr[low] <= pivot)
            low++;

        if (low < high)
            arr[high--] = arr[low];
    }

    arr[low] = temp;

    return low;
}

//  quickSort
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int k = partion(arr, low, high);

        quickSort(arr, low, k - 1);
        quickSort(arr, low + 1, high);
    }
}