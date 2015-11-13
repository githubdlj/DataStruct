/********************************************************************
	Time:	  2015/11/13
	Filename: quickSort
	Author:	  dinglj
	
	Purpose:  快速排序
*********************************************************************/
#include "sort.h"

//////////////////////////////////////////////////////////////////////
//  将序列分成2部分， 并返回分割点
int partion(int arr[], int low, int high)
{
    int temp = arr[low];  //  low为第一个坑
    int pivot = arr[low];   //  选取枢纽

    while (low < high)
    {
        while (low < high && arr[high] >= pivot)    //  注意，需要取到等号
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