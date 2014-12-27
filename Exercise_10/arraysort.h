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

class ArraySort :public Sort{
private:
    int randomNum[10000];//随机数组
public:
    ArraySort(){
        exchangeTime = 0;
        time = 0;
    }
    ~ArraySort(){
        ;
        
    }
    void print();//输出交换次数和时间
    void getRandomNum();//得到random number
    void bubbleSort();//冒泡排序
    void selectSort();//选择排序
};

#endif /* defined(__Exercise_10__arraysort__) */
