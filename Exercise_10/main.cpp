//
//  main.cpp
//  Exercise_10
//
//  Created by 一川 on 14/12/17.
//  Copyright (c) 2014年 一川. All rights reserved.
//  随机函数产生10000个随机数，用快速排序，直接插入排序，冒泡排序，选择排序的排序方法排序，并统计每种排序所花费的排序时间和交换次数。其中，随机数的个数由用户定义，系统产生随机数，并且显示他们的比较次数，排序算法包括冒泡排序，选择排序，直接插入排序，希尔排序，快速排序，堆排序，归并排序和基排序
//1、冒泡排序

#include <iostream>
#include <time.h>
#include "arraysort.h"
#include "linksort.h"
using namespace std;

class Sort{
private:
    int randomNum[10000];
    int exchangeTime;
    clock_t start,end;
    long time;
public:
    Sort(){
        exchangeTime = 0;
    }
    ~Sort(){
        ;
    }
    void getRandomNum();//得到random number
    void bubbleSort();//冒泡排序
};

void Sort::getRandomNum(){//得到random number
    srand(0);//设置种子为0
    for (int i = 0; i < 10000; i++) {
        randomNum[i] = rand() % 10001;
    }
}

void Sort::bubbleSort(){//冒泡排序
    bool exchange;
    int i,j;
    int temp;
    start = clock();
    for (i = 1; i < 10000; i++) {
        exchange = false;
        for (j = 9999; j >= i; j--) {
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

int main(int argc, const char * argv[]) {
    
    
    
    return 0;
}
