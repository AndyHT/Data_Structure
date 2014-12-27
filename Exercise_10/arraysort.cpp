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

int* ArraySort::getRandomArray(){//得到random number函数,completed
    srand(0);//设置种子为0
    for (int i = 0; i < SIZE; i++) {
        randomNum[i] = rand() % (SIZE*10 + 1);
    }
    return randomNum;
}

void ArraySort::bubbleSort(){//冒泡排序函数，completed
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
    time = (end - start)/CLOCKS_PER_SEC;
}

void ArraySort::selectSort(){//选择排序函数，completed
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
    time = (end - start)/CLOCKS_PER_SEC;
}

void ArraySort::quickSort(int array[],int left,int right){//快速排序,completed
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

void ArraySort::heapSort(){//堆排序,completed
    heapSize = SIZE;
    for (int i = 0 ; i < SIZE; i++) {
        randomNum[i] = heap[0];
        heap[0] = heap[SIZE-(i + 1)];
        minHeapIfy(heapSize - i,0);
    }
}



