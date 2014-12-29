//
//  arraysort.h
//  Exercise_10
//
//  Created by 一川 on 12/27/14.
//  Copyright (c) 2014 一川. All rights reserved.
//

#ifndef __Exercise_10__arraysort__
#define __Exercise_10__arraysort__

#include <stdio.h>
#include "sort.h"
#include "minheap.h"

class ArraySort :public Sort,public MinHeap{
private:
    int randomNum[SIZE];//随机数组
public:
    ArraySort(){
        exchangeTime = 0;
        time = start = end = 0;
//        randomNum = new int[size];
//        SIZE = size;
    }
    ~ArraySort(){
        ;
        
    }
    int* getRandomArray();//得到random number数组
    void print(){
        std::cout<<"Time:"<<time<<std::endl;
        std::cout<<"Exchange Times:"<<exchangeTime<<std::endl;
    }
    void bubbleSort();//冒泡排序
    void selectSort();//选择排序
    void shellSort();//希尔排序
    void quickSort(int s[],int i,int r);//快速排序
    void heapSort();//堆排序
    void mergeSort();//归并排序
    void radixSort();//基数排序
};

#endif /* defined(__Exercise_10__arraysort__) */
