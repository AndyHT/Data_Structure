//
//  arraysort.cpp
//  Exercise_10
//
//  Created by 一川 on 12/27/14.
//  Copyright (c) 2014 一川. All rights reserved.
//

#include "arraysort.h"
#include <iostream>
using namespace std;

//得到random number函数,completed
int* ArraySort::getRandomArray(){
    srand((int)clock());//设置种子为随机时间
//    srand(0);//设置种子为0
    for (int i = 0; i < SIZE; i++) {
        randomNum[i] = rand() % (SIZE*10 + 1);
    }
    return randomNum;
}

//冒泡排序函数，completed
void ArraySort::bubbleSort(){
    bool exchange;
    int i,j;
    int temp;
    start = clock();
    for (i = 1; i < SIZE; i++) {
        exchange = false;
        for (j = SIZE - 1; j >= i; j--) {
            if (randomNum[j] < randomNum[j-1]) {
                temp = randomNum[j];
                randomNum[j] = randomNum[j-1];
                randomNum[j-1] = temp;
                exchange = true;
                exchangeTime++;
            }
        }
        if (!exchange) {
            break;
        }
    }
    end = clock();
    time = (end - start)/MYCLOCKS_PER_SEC;
}

//选择排序函数，completed
void ArraySort::selectSort(){
    int temp;
    int minNum;
    start = clock();
    for (int i = 0; i < SIZE; i++) {
        minNum = i;
        for (int j = SIZE - 1; j > i; j--) {
            if (randomNum[minNum] > randomNum[j]) {
                minNum = j;
            }
        }
        if (minNum != i) {
            temp = randomNum[i];
            randomNum[i] = randomNum[minNum];
            randomNum[minNum] = temp;
            exchangeTime++;
        }
    }
    end = clock();
    time = (end - start)/MYCLOCKS_PER_SEC;
}

//希尔排序,completed(需要统计交换次数)
void ArraySort::shellSort(){
    void shell_sort(int arr[], int len);
    shell_sort(randomNum, SIZE);
}

//快速排序,completed
void ArraySort::quickSort(int array[],int left,int right){
    if (left < right)
    {
        int i = left, j = right, x = array[left];
        while (i < j)
        {
            while(i < j && array[j] >= x){ // 从右向左找第一个小于x的数
                j--;
            }
            if(i < j){
                array[i++] = array[j];
            }
            while(i < j && array[i] < x){ // 从左向右找第一个大于等于x的数
                i++;
            }
            if(i < j){
                array[j--] = array[i];
            }
        }
        array[i] = x;
        quickSort(array, left, i - 1); // 递归调用
        quickSort(array, i + 1, right);
    }
}

//堆排序,completed(需要统计交换次数)
void ArraySort::heapSort(){
    heapSize = SIZE;
    exchangeTime = 0;
    start = clock();
    for (int i = 0 ; i < SIZE; i++) {
        randomNum[i] = heap[0];
        heap[0] = heap[SIZE-(i + 1)];
        minHeapIfy(heapSize - i,0);
    }
    exchangeTime = changeTimes;
    end = clock();
    time = (end - start)/MYCLOCKS_PER_SEC;
}

//归并排序,completed(需要统计交换次数)
void ArraySort::mergeSort(){
    int *p = new int[SIZE];
    void merge(int a[], int first, int last, int temp[]);
    start = clock();
    merge(randomNum, 0, SIZE - 1, p);
    end = clock();
    time = (end - start)/MYCLOCKS_PER_SEC;
    delete[] p;
}

//基数排序,completed(需要统计交换次数)
void ArraySort::radixSort(){
    void radix_sort(int data[], int n);
    start = clock();
    radix_sort(randomNum, SIZE);
    end = clock();
    time = (end - start)/MYCLOCKS_PER_SEC;
}



int maxBit(int data[], int n) //辅助函数，求数据的最大位数
{
    int d = 1; //保存最大的位数
    int p = 10;
    for(int i = 0; i < n; ++i)
    {
        while(data[i] >= p)
        {
            p *= 10;
            ++d;
        }
    }
    return d;
}
void radix_sort(int data[], int n) //基数排序
{
    int d = maxBit(data, n);
    int *tmp = new int[n];
    int *count = new int[10]; //计数器
    int i, j, k;
    int radix = 1;
    for(i = 1; i <= d; i++) //进行d次排序
    {
        for(j = 0; j < 10; j++)
            count[j] = 0; //每次分配前清空计数器
        for(j = 0; j < n; j++)
        {
            k = (data[j] / radix) % 10; //统计每个桶中的记录数
            count[k]++;
        }
        for(j = 1; j < 10; j++)
            count[j] = count[j - 1] + count[j]; //将tmp中的位置依次分配给每个桶
        for(j = n - 1; j >= 0; j--) //将所有桶中记录依次收集到tmp中
        {
            k = (data[j] / radix) % 10;
            tmp[count[k] - 1] = data[j];
            count[k]--;
        }
        for(j = 0; j < n; j++) //将临时数组的内容复制到data中
            data[j] = tmp[j];
        radix = radix * 10;
    }
    delete []tmp;
    delete []count;
}



void shell_sort(int arr[], int len) {
    int gap, i, j;
    int temp;
    for (gap = len >> 1; gap > 0; gap >>= 1)
        for (i = gap; i < len; i++) {
            temp = arr[i];
            for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap)
                arr[j + gap] = arr[j];
            arr[j + gap] = temp;
        }
}













