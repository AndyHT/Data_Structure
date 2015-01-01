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
        changeTimes = 0;
//        randomNum = new int[size];
//        SIZE = size;
    }
    ~ArraySort(){
        ;
        
    }
    int* getRandomArray();//得到random number数组
    void print(int i){
        std::cout<<"排序所用时间:"<<time<<" ms"<<std::endl;
        switch (i) {
            case 1:
                std::cout<<"冒泡排序交换次数:"<<exchangeTime<<std::endl;
                break;
            case 2:
                std::cout<<"选择排序交换次数:"<<exchangeTime<<std::endl;
                break;
            case 4:
                std::cout<<"希尔排序交换次数:"<<exchangeTime<<std::endl;
                break;
            case 5:
                std::cout<<"快速排序交换次数:"<<exchangeTime<<std::endl;
                break;
            case 6:
                std::cout<<"堆排序交换次数:"<<exchangeTime<<std::endl;
                break;
            case 7:
                std::cout<<"归并排序交换次数:"<<exchangeTime<<std::endl;
                break;
            case 8:
                std::cout<<"基数排序交换次数:"<<exchangeTime<<std::endl;
                break;
        }
        time = 0;
        exchangeTime = 0;
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
