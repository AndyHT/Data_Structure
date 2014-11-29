//
//  main.cpp
//  Exercise2
//
//  Created by 一川 on 14-9-28.
//  Copyright (c) 2014年 一川. All rights reserved.
//

#include <iostream>
#include "database.h"

int main() {
    cout<<"现有N人围成一圈，从第S个人开始一次报数，报M的人出局，再由下一个人开始报数，如此循环直至剩下K个人为止"<<endl;
    cout<<"请输入生死游戏的总人数N：";
    int n;
    cin>>n;
    while (n<1) {
        cout<<"输入数字必须大于0，请重新输入"<<endl;
        cin>>n;
    }
    cout<<"请输入游戏开始的位置S：";
    int s;
    cin>>s;
    while (s<0||s>n) {
        cout<<"输入数字必须大于0且小与总人数，请重新输入"<<endl;
        cin>>s;
    }
    cout<<"请输入死亡数字M：";
    int m;
    cin>>m;
    while (m<2) {
        cout<<"输入数字必须大于1，请重新输入"<<endl;
        cin>>m;
    }
    cout<<"请输入剩余的生者人数K：";
    int k;
    cin>>k;
    while (k<1||k>n) {
        cout<<"输入数字必须大于0且小与总人数，请重新输入"<<endl;
        cin>>k;
    }
    
    Passenger passenger(n,s,m,k);
    passenger.newPassList();
    passenger.deletePassNode();
    passenger.printPass();
    system("pause");
    return 0;
}
