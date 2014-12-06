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
#include <map>
#include <set>
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
    map<int , char> vertexMap;
    set<int> vertexSet;
public:
    Graph(){
        vertexTable = *new vector<graphVertex>();//邻接表vector
        vertexMap = *new map<int, char>();//存放节点名字对应节点编号的map
        vertexSet = *new set<int>();//存放最小生成树set
    }
    ~Graph(){
        
    }
    void insertVertex(char vertex);//增加节点方法
    void insertEdge(int vertex1,int vertex2,int weight);//增加一条带权重的边
    void removeVertex(char vertex);//remove一个节点
    void removeEdge(int vertex1,int vertex2);// remove一条边
    bool isEmpty();//判断图是否为空，空返回true
    int getWeight(int vertex1,int vertex2);//得到vertex1和vertex2两个节点间边的权重
    int getFirstNeighbor(int vertex);//得到vertex的第一个邻接节点
    int getNextNeighbor(int vertext1,int vertext2);//得到vertex1的邻接节点vertex2的下一邻接节点
    void MinSpanTree();
    void printMinSpanTree();
};

//插入一个节点
void Graph::insertVertex(char vertexName){
    graphVertex newVertex=*new graphVertex();//建一个新的节点
    newVertex.vertexName=vertexName;
    newVertex.edge=nullptr;
    vertexTable.push_back(newVertex);
}

//插入一条带权值的边
void Graph::insertEdge(int vertex1, int vertex2, int weight){
    graphEdge newEdge1 = *new graphEdge();
    newEdge1.dest = vertex2;
    newEdge1.weight = weight;
    newEdge1.nextEdge = nullptr;
    graphEdge *temp, *front;
    //将新的edge连接到vertex1的边中
    if (vertexTable[vertex1].edge == nullptr) {//判断vertex1有没有边
        vertexTable[vertex1].edge = &newEdge1;
    }else{
        temp = vertexTable[vertex1].edge;
        front = temp;
        while (temp != nullptr) {
            if (temp == vertexTable[vertex1].edge) {
                temp = temp->nextEdge;
            }else{
                front = temp;
                temp = temp->nextEdge;
            }
        }
        front->nextEdge = &newEdge1;
    }
    
    //将新的edge连接到vertex2的边中
    graphEdge newEdge2 = *new graphEdge();
    newEdge2.dest = vertex1;
    newEdge2.weight = weight;
    newEdge2.nextEdge = nullptr;
    if (vertexTable[vertex2].edge == nullptr) {//判断vertex2有没有边
        vertexTable[vertex2].edge = &newEdge2;
    }else{
        temp = vertexTable[vertex2].edge;
        front = temp;
        while (temp != nullptr) {
            if (temp == vertexTable[vertex2].edge) {
                temp = temp->nextEdge;
            }else{
                front = temp;
                temp = temp->nextEdge;
            }
        }
        front->nextEdge = &newEdge2;
    }
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

//得到vertex的第一个邻接节点
int Graph::getFirstNeighbor(int vertex){
    return 1;
}

//得到vertex1的邻接节点vertex2的下一邻接节点
int Graph::getNextNeighbor(int vertex1, int vertex2){
    return 1;
}

//计算最小生成树
void Graph::MinSpanTree(){
    
}

//打印最小生成树
void Graph::printMinSpanTree(){
    
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
