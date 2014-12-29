//
//  mergearray.cpp
//  Exercise_10
//
//  Created by 一川 on 12/29/14.
//  Copyright (c) 2014 一川. All rights reserved.
//

//将有二个有序数列a[first...mid]和a[mid...last]合并。
void mergeArray(int a[], int first, int mid, int last, int temp[])
{
    int firstOne = first, afterMid = mid + 1;
    int middle = mid,   lastOne = last;
    int k = 0;
    
    while (firstOne <= middle && afterMid <= lastOne)
    {
        if (a[firstOne] <= a[afterMid])
            temp[k++] = a[firstOne++];
        else
            temp[k++] = a[afterMid++];
    }
    
    while (firstOne <= middle)
        temp[k++] = a[firstOne++];
    
    while (afterMid <= lastOne)
        temp[k++] = a[afterMid++];
    
    for (firstOne = 0; firstOne < k; firstOne++)
        a[first + firstOne] = temp[firstOne];
}

void merge(int a[], int first, int last, int temp[])//归并排序
{
    if (first < last)
    {
        int mid = (first + last) / 2;
        merge(a, first, mid, temp);    //左边有序
        merge(a, mid + 1, last, temp); //右边有序
        mergeArray(a, first, mid, last, temp); //再将二个有序数列合并
    }
}