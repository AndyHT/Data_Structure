//
//  linksort.h
//  Exercise_10
//
//  Created by 一川 on 12/27/14.
//  Copyright (c) 2014 一川. All rights reserved.
//

#ifndef __Exercise_10__linksort__
#define __Exercise_10__linksort__

#include <stdio.h>
#include "sort.h"

struct node{
    long key;
    node *next;
};

class LinkSort :public Sort{
private:
    node *head;
public:
    LinkSort(){
        head = nullptr;
        exchangeTime = 0;
        time = start = end = 0;
    }
    ~LinkSort(){
        ;
    }
    void getRandomLink();//得到随机数链表
    void insertSort();//插入排序
    void shellSort();//希尔排序
};



#endif /* defined(__Exercise_10__linksort__) */
