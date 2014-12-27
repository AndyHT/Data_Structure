//
//  minheap.h
//  Exercise_10
//
//  Created by 一川 on 12/27/14.
//  Copyright (c) 2014 一川. All rights reserved.
//

#ifndef __Exercise_10__minheap__
#define __Exercise_10__minheap__

//#include <stdio.h>
#include "sort.h"
#include <iostream>
#define MAX 4294967295
using namespace std;

class MinHeap{
protected:
    int heap[SIZE];
    int heapSize;
public:
    void copyArray(int arrayCopy[]);//copy array
    void buildMinHeap();//建立最小堆
    void minHeapIfy(int heapSize,int current);//维护最小堆
    void filterDown(int current);//下滤
};

#endif /* defined(__Exercise_10__minheap__) */
