//
//  main.cpp
//  Exercise4
//
//  Created by 一川 on 14/10/28.
//  Copyright (c) 2014年 霍腾_1352901 All rights reserved.
//

#include <iostream>
#include <bitset>
#include<string>

using namespace std;
class ChessProblem{
private:
    long sum;//总共的方法数
    long placedPos;//放置过棋子的地方
    long *result;//结果栈
    int i;//栈顶
    int size;//size皇后问题
    char *chessSize;//棋盘大小
public:
    void solveProblem(long row,long ld,long rd);
    void printSum(){
        cout<<"共有"<<sum<<"种摆法"<<endl;
    }
    void printOne(){
        for (int n=0; n<size; n++) {
            cout<<bitset<sizeof(chessSize)>(result[n])<<endl;//sizeof(p)在不同编译器上得到结果不同，vs上为指针大小，其他编译器为指针所指内容大小
        }
    }
    ChessProblem(int n){
        size=n;
        sum=0;
        placedPos=(1<<n)-1;
        result=new long[n];
        chessSize=new char[n];
        i=0;
    }
};

void ChessProblem::solveProblem(long row,long ld,long rd){
    if (row!=placedPos) {
        long canPlacePos=placedPos&(~(row|ld|rd));
        while (canPlacePos) {
            long pos=canPlacePos & (~canPlacePos+1);
            canPlacePos-=pos;
            result[i++]=pos;
            solveProblem(row+pos,(ld+pos)<<1,(rd+pos)>>1);
            if (row!=placedPos) {
                i--;
            }else{
                i=0;
            }
        }
    }else{
        cout<<"第"<<sum+1<<"种情况"<<endl;
        printOne();
        cout<<endl;
        sum++;
    }
}

int main() {
    int a;
    cout<<"请输入皇后个数：";
    cin>>a;
    ChessProblem solve(a);
    solve.solveProblem(0,0,0);
    solve.printSum();
    return 0;
}