//
//  main.cpp
//  Exercise4
//
//  Created by 一川 on 14/10/28.
//  Copyright (c) 2014年 一川. All rights reserved.
//

#include <iostream>
#include <bitset>
#include <fstream>

using namespace std;
class ChessProblem{
private:
    long sum;
    long placedPos;
    long *result;
    int i;
    int size;
    char *chessSize;
public:
    void solveProblem(long row,long ld,long rd);
    void printSum(){
        cout<<"共有"<<sum<<"种摆法"<<endl;
    }
    void printOne(){
        for (int n=0; n<size; n++) {
            cout<<bitset<sizeof(chessSize)>(result[n])<<endl;
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
        //cout<<"第"<<sum+1<<"种情况"<<endl;
        //printOne();
        //cout<<endl;
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