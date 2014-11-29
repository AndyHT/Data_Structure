//
//  main.cpp
//  Exercise3
//
//  Created by 一川 on 14-10-10.
//  Copyright (c) 2014年 一川. All rights reserved.
//  迷宫问题，回溯法解决,用栈做数据结构
//死循环了

#include <iostream>
#include "labyrinth.h"
using namespace std;

int main() {
    Labyrinth labyrinth;//=*new Labyrinth();
    int a;
    a=labyrinth.canGo(labyrinth.returnValueX(), labyrinth.returnValueY());
    while (a!=0) {
        a=labyrinth.canGo(labyrinth.returnValueX(), labyrinth.returnValueY());
        if (1==a) {
            labyrinth.direction1(labyrinth.returnValueX(),labyrinth.returnValueY());
        }else if(2==a){
            labyrinth.direction1(labyrinth.returnValueX(),labyrinth.returnValueY());
        }else if(3==a){
            labyrinth.direction1(labyrinth.returnValueX(),labyrinth.returnValueY());
        }else if(4==a){
            labyrinth.direction1(labyrinth.returnValueX(),labyrinth.returnValueY());
        }else if(0==a){
            labyrinth.printPath();
        }else if(-1==a){
            labyrinth.backLocation(labyrinth.returnValueX(), labyrinth.returnValueY());
        }else{
            cout<<"???"<<endl;
        }

    }
    labyrinth.printPath();
//    a=labyrinth.canGo(labyrinth.returnValueX(), labyrinth.returnValueY());
//    if (1==a) {
//        labyrinth.direction1(labyrinth.returnValueX(),labyrinth.returnValueY());
//    }else if(2==a){
//        labyrinth.direction1(labyrinth.returnValueX(),labyrinth.returnValueY());
//    }else if(3==a){
//        labyrinth.direction1(labyrinth.returnValueX(),labyrinth.returnValueY());
//    }else if(4==a){
//        labyrinth.direction1(labyrinth.returnValueX(),labyrinth.returnValueY());
//    }else if(0==a){
//        labyrinth.printPath();
//    }else if(-1==a){
//        labyrinth.backLocation(labyrinth.returnValueX(), labyrinth.returnValueY());
//    }else{
//        cout<<"???"<<endl;
//    }
//    switch (a){//labyrinth.canGo(labyrinth.returnValueX(), labyrinth.returnValueY())) {
//        case 1:
//            labyrinth.direction1(labyrinth.returnValueX(),labyrinth.returnValueY());
//            break;
//        case 2:
//            labyrinth.direction2(labyrinth.returnValueX(), labyrinth.returnValueY());
//            break;
//        case 3:
//            labyrinth.direction3(labyrinth.returnValueX(), labyrinth.returnValueY());
//            break;
//        case 4:
//            labyrinth.direction4(labyrinth.returnValueX(), labyrinth.returnValueY());
//            break;
//        case -1:
//            labyrinth.backLocation(labyrinth.returnValueX(), labyrinth.returnValueY());
//            break;
//        default:
//            cout<<"!!!"<<endl;
//            break;
//    }
    return 0;
}
