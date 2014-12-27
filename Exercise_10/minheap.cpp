//
//  minheap.cpp
//  Exercise_10
//
//  Created by 一川 on 12/27/14.
//  Copyright (c) 2014 一川. All rights reserved.
//

#include "minheap.h"

void MinHeap::buildMinHeap(){//建立最小堆,completed
    for (int i = SIZE/2 - 1; i >= 0; i--) {
        filterDown(i);
    }
}

void MinHeap::minHeapIfy(){//维护最小堆
    filterDown(0);
}

void MinHeap::filterDown(int current){//下滤,completed
    int leftChild,rightChild;
    int temp;
    leftChild = current*2 + 1;
    rightChild = current*2 + 2;
    if (rightChild >= SIZE && leftChild < SIZE) {//只有左孩子
        if (heap[current] > heap[leftChild]) {
            temp = heap[current];
            heap[current] = heap[leftChild];
            heap[leftChild] = temp;
            filterDown(leftChild);
        }
    }else if (leftChild >= SIZE && rightChild < SIZE){//只有右孩子
        if (heap[current] > heap[rightChild]) {
            temp = heap[current];
            heap[current] = heap[rightChild];
            heap[rightChild] = temp;
            filterDown(rightChild);
        }
    }else if (leftChild < SIZE && rightChild < SIZE){//两个孩子都有
        if (heap[current] > heap[leftChild] || heap[current] > heap[rightChild]) {
            temp = heap[current];
            if (heap[leftChild] < heap[rightChild]) {//与左孩子交换
                heap[current] = heap[leftChild];
                heap[leftChild] = temp;
                filterDown(leftChild);
            }else if (heap[rightChild] < heap[leftChild]){//与右孩子交换
                heap[current] = heap[rightChild];
                heap[rightChild] = temp;
                filterDown(rightChild);
            }else{//孩子相等时默认与左孩子交换
                heap[current] = heap[leftChild];
                heap[leftChild] = temp;
                filterDown(leftChild);
            }
        }
    }
    //没有孩子时直接退出函数
}

void MinHeap::copyArray(int arrayCopy[]){
    for (int i = 0; i < SIZE; i++) {
        heap[i] = arrayCopy[i];
    }
}
