//
//  labyrinth.h
//  Exercise3
//
//  Created by 一川 on 14-10-17.
//  Copyright (c) 2014年 一川. All rights reserved.
//定义每个方向的function
//算法过程：
//判断通路的方向，将direction赋值为相应方向（从12点方向开始按顺时针为1，2，3，4）
//判断来的方向direction
//根据direction调用方向function
//走到下一位置并记录位置于数据栈
//若没有可前进的方向，回溯到前一位置并且封掉该方向的路口

//function：
//1 direction function；
//2 direction function；
//3 direction function；
//4 direction function；
//回溯 function；
//push function；
//print function；
//0表示墙，1表示路，2表示走过的路


using namespace std;

class Labyrinth{
private:
    int arrLabyrinth[7][7];
    int knight[50][2];
    int i;
public:
    Labyrinth(){
//      arrLabyrinth=new int[7][7];如何动态数组如何开辟
        arrLabyrinth[1][1]=1;
        arrLabyrinth[1][3]=1;
        arrLabyrinth[1][4]=1;
        arrLabyrinth[1][5]=1;
        arrLabyrinth[2][1]=1;
        arrLabyrinth[2][3]=1;
        arrLabyrinth[3][1]=1;
        arrLabyrinth[3][2]=1;
        arrLabyrinth[3][4]=1;
        arrLabyrinth[3][5]=1;
        arrLabyrinth[4][1]=1;
        arrLabyrinth[4][3]=1;
        arrLabyrinth[4][4]=1;
        arrLabyrinth[4][5]=1;
        arrLabyrinth[5][3]=1;
        arrLabyrinth[5][5]=1;
        knight[0][0]=1;
        knight[0][1]=1;
        i=0;
    }
    ~Labyrinth(){}
    void direction1(int x,int y);
    void direction2(int x,int y);
    void direction3(int x,int y);
    void direction4(int x,int y);
    int canGo(int x,int y);
    int backLocation(int x,int y);
    void printPath();
    int returnValueX();
    int returnValueY();
};

void Labyrinth::direction1(int x,int y){
    arrLabyrinth[x][y]=2;
    knight[++i][0]=--x;
    knight[i][1]=y;
}

void Labyrinth::direction2(int x,int y){
    arrLabyrinth[x][y]=2;
    knight[++i][0]=x;
    knight[i][1]=++y;
}

void Labyrinth::direction3(int x,int y){
    arrLabyrinth[x][y]=2;
    knight[++i][0]=++x;
    knight[i][1]=y;
}

void Labyrinth::direction4(int x,int y){
    arrLabyrinth[x][y]=2;
    knight[++i][0]=x;
    knight[i][1]=--y;
}

int Labyrinth::canGo(int x,int y){
    if (1==arrLabyrinth[x-1][y]) {
        return 1;
    }else if(1==arrLabyrinth[x][y+1]){
        return 2;
    }else if(1==arrLabyrinth[x+1][y]){
        return 3;
    }else if(1==arrLabyrinth[x][y-1]){
        return 4;
    }else if(5==x&&5==y){
        return 0;
    }else{
        return -1;
    }
}

int Labyrinth::backLocation(int x,int y){
    if (2==arrLabyrinth[x-1][y]) {
        x--;
        knight[i][0]=0;
        knight[i][1]=0;
        i--;
        return 1;
    }else if (2==arrLabyrinth[x][y+1]){
        y++;
        knight[i][0]=0;
        knight[i][1]=0;
        i--;
        return 1;
    }else if(2==arrLabyrinth[x+1][y]){
        x++;
        knight[i][0]=0;
        knight[i][1]=0;
        i--;
        return 1;
    }else if(2==arrLabyrinth[x][y-1]){
        y--;
        knight[i][0]=0;
        knight[i][1]=0;
        i--;
        return 1;
    }else{
        return 0;
    }
}

void Labyrinth::printPath(){
    while (i>-1) {
        cout<<knight[--i][0]<<knight[i][1]<<endl;
    }
}

int Labyrinth::returnValueX(){
    return knight[i][0];
}

int Labyrinth::returnValueY(){
    return knight[i][1];
}
