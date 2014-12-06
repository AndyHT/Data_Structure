//
//  main.cpp
//  Exercise_8
//
//  Created by 一川 on 14/11/29.
//  Copyright (c) 2014年 一川. All rights reserved.
//项目简介
//假设一个城市有n个小区，要实现n个小区之间的电网都能够相互接通，构造这个城市n个小区之间的电网，使总工程造价最低。请设计一个能够满足要求的造价方案。
//
//项目功能要求：
//在每个小区之间都可以设置一条电网线路，都要付出相应的经济代价。n个小区之间最多可以有n（n-1）/2条线路，选择其中的n-1条使总的耗费最少。
//用无向图解决问题，n个小区之间的电网都能相互接通，既要求为联通图，每条电线有相应权值，需要找出最小生成树

#include <iostream>
#include <vector>
#define RUN
using namespace std;

struct graphEdge{
    int dest;
    int weight;
    graphEdge *nextEdge;
};

struct graphVertex{
    char vertexName;
    graphEdge *edge;
};


class Graph{
private:
    vector<graphVertex> vertexTable;
    
public:
    Graph(){
        vertexTable=*new vector<graphVertex>();
    }
    ~Graph(){
        
    }
    void insertVertex(char vertex);
    void insertEdge(int vertex1,int vertex2,int weight);
    void removeVertex(char vertex);
    void removeEdge(int vertex1,int vertex2);
    bool isEmpty();
    int getWeight(int vertex1,int vertex2);
    int getFirstNeighbor(int vertex);
    int getNextNeighbor(int vertext1,int vertext2);
};

//插入一个节点
void Graph::insertVertex(char vertexName){
    graphVertex newVertex=*new graphVertex();
    newVertex.vertexName=vertexName;
    newVertex.edge=nullptr;
    vertexTable.push_back(newVertex);
}

//插入一条带权值的边
void Graph::insertEdge(int vertex1, int vertex2, int weight){
    
}

//移除一个节点
void Graph::removeVertex(char vertex){
    
}

//移除一条边
void Graph::removeEdge(int vertex1, int vertex2){
    
}

//判断图是否为空
bool Graph::isEmpty(){
    return vertexTable.empty();
}

//得到两个节点边的权值，返回值为权值
int Graph::getWeight(int vertex1, int vertex2){
    return 1;
}

//得到vertex的第一个？？
int Graph::getFirstNeighbor(int vertex){
    return 1;
}

//得到vertex的？？？
int Graph::getNextNeighbor(int vertex1, int vertex2){
    return 1;
}





int main(int argc, const char * argv[]) {
    cout<<"             电网造假模拟系统           "<<endl;
    cout<<"======================================"<<endl;
    cout<<"**          A --- 创建电网顶点        **"<<endl;
    cout<<"**          B --- 添加电网的边        **"<<endl;
    cout<<"**          C --- 构造最小生成树       **"<<endl;
    cout<<"**          D --- 显示最小生成树       **"<<endl;
    cout<<"**          E --- 退出  程序          **"<<endl;
    cout<<"======================================"<<endl;
    
#ifdef RUN
    Graph graph = *new Graph();
    char vertex;
    cout<<"input:";
    cin>>vertex;
    graph.insertVertex(vertex);
#endif
    
}
