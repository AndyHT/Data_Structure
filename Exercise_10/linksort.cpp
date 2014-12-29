//
//  linksort.cpp
//  Exercise_10
//
//  Created by 一川 on 12/27/14.
//  Copyright (c) 2014 一川. All rights reserved.
//

#include "linksort.h"
#include <iostream>
using namespace std;

void LinkSort::getRandomLink(){//得到随机数链表，completed
//    SIZE = size;
    srand(0);
    node *p1,*p2;
    p1 = p2 =nullptr;
    for (int i = 0; i < SIZE; i++) {
        p1 = new node();
        p1->key = random() % (SIZE*10 + 1);
        if (0 == i) {
            head = p1;
        }else{
            p2->next = p1;
        }
        p2 = p1;
    }
    p1->next = nullptr;
}

void LinkSort::insertSort(){//插入排序,completed
    node *p1,*p2,*p3;
    node *temp;
    temp = nullptr;
    p1 = p2 = p3 = head;
    start = clock();
    for (int i = 0; i < SIZE - 1; i++) {
        p2 = p1->next;
        if (p1->key > p2->key) {
            p3 = head;
            for (int j = 0; j <= i; j++) {
                if (p3->key > p2->key) {
                    if (0 == j) {
                        p1->next = p2->next;
                        p2->next = head->next;
                        head = p2;
                    }else{
                        p1->next = p2->next;
                        p2->next = p3;
                        temp->next = p2;
                    }
                    exchangeTime++;
                    break;
                }else{
                    temp = p3;
                    p3 = p3->next;
                }
            }
        }else{
            p1 = p2;
        }
    }
    end = clock();
    time = (end - start)/CLOCKS_PER_SEC;
}
