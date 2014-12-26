//
//  mysort.h
//  Exercise_10
//
//  Created by 一川 on 14/12/20.
//  Copyright (c) 2014年 一川. All rights reserved.
//

#include "sort.h"
using namespace std;

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

void ArraySort::print(){
    cout<<"Time:"<<time<<endl;
    cout<<"Exchange Times:"<<exchangeTime<<endl;
}

void ArraySort::getRandomNum(){//得到random number
    srand(0);//设置种子为0
    for (int i = 0; i < 10000; i++) {
        randomNum[i] = rand() % 10001;
    }
}

void ArraySort::bubbleSort(){//冒泡排序函数，pass
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

void ArraySort::selectSort(){//选择排序函数，pass
    int temp;
    int minNum;
    start = clock();
    for (int i = 0; i < 10000; i++) {
        minNum = i;
        for (int j = 9999; j > i; j--) {
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
