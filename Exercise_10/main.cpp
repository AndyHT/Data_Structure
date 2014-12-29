//
//  main.cpp
//  Exercise_10
//
//  Created by 一川 on 14/12/17.
//  Copyright (c) 2014年 一川. All rights reserved.
//  随机函数产生10000个随机数，用快速排序，直接插入排序，冒泡排序，选择排序的排序方法排序，并统计每种排序所花费的排序时间和交换次数。其中，随机数的个数由用户定义，系统产生随机数，并且显示他们的比较次数，排序算法包括冒泡排序，选择排序，直接插入排序，希尔排序，快速排序，堆排序，归并排序和基排序
//
//1、冒泡排序completed
//2、选择排序completed
//3、直接插入排序completed
//4、希尔排序completed
//5、快速排序completed
//6、堆排序completed
//7、归并排序completed
//8、基数排序completed

//#define DEBUG_HEAP
#include <iostream>
#include "linksort.h"
#include "arraysort.h"
#include "minheap.h"
using namespace std;

int main(int argc, const char * argv[]) {
    
    cout<<"**           排序算法比较          **"<<endl;
    cout<<"==================================="<<endl;
    cout<<"**          1————冒泡排序         **"<<endl;
    cout<<"**          2————选择排序         **"<<endl;
    cout<<"**          3————直接插入排序      **"<<endl;
    cout<<"**          4————希尔排序         **"<<endl;
    cout<<"**          5————快速排序         **"<<endl;
    cout<<"**          6————堆排序           **"<<endl;
    cout<<"**          7————归并排序         **"<<endl;
    cout<<"**          8————基数排序         **"<<endl;
    cout<<"**          9————退出程序         **"<<endl;
    cout<<"==================================="<<endl;

    int order = 0;
    ArraySort sort = *new ArraySort();
    int arraySize;
    cout<<"请输入要产生随机数的个数:";
    cin>>arraySize;
    while (9 == order) {
        cout<<"请选择排序算法:";
        cin>>order;
        switch (order) {
            case 1:
                <#statements#>
                break;
            case 2:
                <#statements#>
                break;
            case 3:
                <#statements#>
                break;
            case 4:
                <#statements#>
                break;
            case 5:
                <#statements#>
                break;
            case 6:
                <#statements#>
                break;
            case 7:
                <#statements#>
                break;
            case 8:
                <#statements#>
                break;
            case 9:
                <#statements#>
                break;
            default:
                break;
        }
    }
    
//    LinkSort link = *new LinkSort();
//    link.getRandomLink();
//    ArraySort array = *new ArraySort();
//    int randomNum2[10000];
//    srand(0);//设置种子为0
//    for (int i = 0; i < SIZE; i++) {
//        randomNum2[i] = rand() % (SIZE*10 + 1);
//    }
//    array.getRandomArray();
//    cout<<"completed"<<endl;
//    link.insertSort();
//    array.quickSort(array.getRandomArray(), 0, SIZE);
//    int a[8];
//    a[0] = 49;
//    a[1] = 38;
//    a[2] = 65;
//    a[3] = 97;
//    a[4] = 76;
//    a[5] = 13;
//    a[6] = 27;
//    a[7] = 50;
//    array.copyArray(a);
//    array.copyArray(array.getRandomArray());
//    array.buildMinHeap();
//    array.heapSort();
//    array.shellSort();
//    cout<<"sortCompleted"<<endl;
    return 0;
}
