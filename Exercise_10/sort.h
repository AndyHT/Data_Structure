//
//  sort.h
//  Exercise_10
//
//  Created by 一川 on 12/27/14.
//  Copyright (c) 2014 一川. All rights reserved.
//

#ifndef Exercise_10_sort_h
#define Exercise_10_sort_h

#define SIZE 10000
#include <time.h>
#include <iostream>

class Sort{
protected:
    clock_t start,end;
    long time;
    int exchangeTime;
public:
    void print(){
        std::cout<<"Time:"<<time<<std::endl;
        std::cout<<"Exchange Times:"<<exchangeTime<<std::endl;
    }
};

#endif
