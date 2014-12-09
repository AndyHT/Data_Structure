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
#include <set>
#include <string>
#include <map>
#define RUN
using namespace std;

//各种节点struct
struct graphEdge{
    int dest;
    int weight;
    graphEdge *nextEdge;
};

struct graphVertex{
    char vertexName;
    graphEdge *edge;
};

struct minSpanTreeNode{
    char vertexName1;
    int edgeWeight;
    char vertexName2;
};

bool compare ( graphEdge const& a, graphEdge const& b ){
    return a.weight < b.weight;
}

class Graph{
private:
    int size;
    map<char ,int> vertexMap;//存放节点名称和节点值map
    vector<graphVertex> vertexTable;//邻接表vector
    set<int> vertexSet;//存放最小生成树set
    vector<minSpanTreeNode> minSpanTree;//存放最小生成树
    vector<graphEdge> edgeSequence;//用于边按权重排序
    
public:
    Graph(int a){
        size = a;
        vertexTable = *new vector<graphVertex>();
        vertexSet = *new set<int>();
        minSpanTree = *new vector<minSpanTreeNode>();
        edgeSequence = *new vector<graphEdge>();
    }
    ~Graph(){
        
    }
    void insertVertex(char vertex);//增加节点方法
    void insertEdge(char vertex1,char vertex2,int weight);//插入一条带权重的边
    void removeVertex(char vertex);//remove一个节点
    void removeEdge(int vertex1,int vertex2);// remove一条边
    bool isEmpty();//判断图是否为空，空返回true
    int getWeight(int vertex1,int vertex2);//得到vertex1和vertex2两个节点间边的权重
    int getFirstNeighbor(int vertex);//得到vertex的第一个邻接节点
    int getNextNeighbor(int vertext1,int vertext2);//得到vertex1的邻接节点vertex2的下一邻接节点
    void getMinSpanTree(char startVertex);//计算最小生成树
    void printMinSpanTree();//打印最小生成树
};



//方法实现
//插入一个节点
void Graph::insertVertex(char vertexName){
    graphVertex newVertex=*new graphVertex();//建一个新的节点
    newVertex.vertexName=vertexName;
    newVertex.edge=nullptr;
    vertexMap.insert(pair<char, int>(vertexName,vertexTable.size()));//将节点名字和节点值存入vertexMap中
    vertexTable.push_back(newVertex);
}

//插入一条带权值的边
void Graph::insertEdge(char vertexName1, char vertexName2, int weight){
    int vertexNum1 = vertexMap.find(vertexName1)->second;
    int vertexNum2 = vertexMap.find(vertexName2)->second;
    
    graphEdge *temp = nullptr;//临时指针用于将newEdge链入链表
    
    graphEdge *newEdge1 = new graphEdge();
    newEdge1->dest = vertexNum2;
    newEdge1->weight = weight;
    newEdge1->nextEdge = nullptr;
    
    //将新的edge连接到vertex1的边中
    temp = vertexTable[vertexNum1].edge;
    if (temp == nullptr) {//判断vertex1有没有边
        vertexTable[vertexNum1].edge = newEdge1;
    }else{
        while (temp->nextEdge != nullptr) {
            temp = temp->nextEdge;
        }
        temp ->nextEdge = newEdge1;
    }
    
    graphEdge *newEdge2 = new graphEdge();
    newEdge2->dest = vertexNum1;
    newEdge2->weight = weight;
    newEdge2->nextEdge = nullptr;
    
    //将新的edge连接到vertex2的边中
    temp = vertexTable[vertexNum2].edge;
    if (temp == nullptr) {//判断vertex2有没有边
        vertexTable[vertexNum2].edge = newEdge2;
    }else{
        while (temp->nextEdge != nullptr) {
            temp = temp->nextEdge;
        }
        temp ->nextEdge = newEdge2;
    }
    temp = nullptr;
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
int Graph::getFirstNeighbor(int vertexNum){
    if (vertexTable[vertexNum].edge != nullptr){
        return vertexTable[vertexNum].edge->dest;
    }else{
        return -1;
    }
}

//得到vertex1的邻接节点vertex2的下一邻接节点
int Graph::getNextNeighbor(int vertex1Num, int vertex2Num){
    graphEdge *p;
    p=vertexTable[vertex1Num].edge;
    while (p != nullptr && p->dest != vertex2Num) {
        p = p->nextEdge;
    }
    return p->nextEdge->dest;
}

//计算最小生成树
void Graph::getMinSpanTree(char startVertex){
    graphEdge *temp = nullptr;
    minSpanTreeNode node = *new minSpanTreeNode();
    auto minWeightVertexNum = vertexMap.find(startVertex)->second;
    while ( vertexSet.size() != size) {
        vertexSet.insert(minWeightVertexNum);//将节点值vertexNum存入vertexSet中
        for ( auto a : vertexSet) {//将符合条件的边存入edgeSequence中
            temp = vertexTable[a].edge;
            while ( temp != nullptr) {
                if ( !vertexSet.count(temp->dest) ) {
                    edgeSequence.push_back(*temp);
                }
                temp = temp->nextEdge;
            }
        }
        sort(edgeSequence.begin(), edgeSequence.end() , &compare);//按权重对edgeSequence的边进行排序
        
        //将找到的最小权重边存入minSpanTree中
        node.vertexName1 = vertexTable[minWeightVertexNum].vertexName;//不应该将minWeightVertexNum的节点名存入node.vertexName1中,它有可能不是最小权重边的节点,如何解决这个问题!!!!!!!!
        
        node.vertexName2 = vertexTable[edgeSequence[0].dest].vertexName;
        node.edgeWeight = edgeSequence[0].weight;
        minSpanTree.push_back(node);
        
        minWeightVertexNum =  edgeSequence[0].dest;
        edgeSequence.clear();
    }
}

//打印最小生成树
void Graph::printMinSpanTree(){
    for (minSpanTreeNode a : minSpanTree){
        cout<<a.vertexName1;
        cout<<"-<"<<a.edgeWeight<<">-";
        cout<<a.vertexName2<<'\t';
    }
    cout<<endl;
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
    int graphSize;
    cout<<"sise:6"<<endl;
    graphSize = 6;
    Graph testGraph = *new Graph(graphSize);
    char vertex[] = {'a','b','c','d','e','f'};
    cout<<"vertex:'a','b','c','d','e','f'"<<endl;
    for (char a: vertex){
        testGraph.insertVertex(a);//测试insertVertex()函数,pass
    }
    
    testGraph.insertEdge('a' , 'b', 1);//测试insertEdge()函数,pass
    testGraph.insertEdge('a' , 'c', 1);
    testGraph.insertEdge('b' , 'd', 1);
    testGraph.insertEdge('d' , 'e', 1);
    testGraph.insertEdge('e' , 'f', 1);
    cout<<"电网建成"<<endl;
    
    testGraph.getMinSpanTree('a');//测试getMinSpanTree()函数,pass(has a small problem)
    testGraph.printMinSpanTree();//pass
    cout<<"endl"<<endl;
#else
    char order;
    int graphSize;
    string orderString;
    char vertexName1;
    char vertexName2;
    int edgeWeight;
    Graph *minSpanTree = nullptr;
    while (1) {
        cout<<"请选择操作:";
        cin>>order;
        switch (order) {
            case 'a':
            case 'A':
                cout<<"请输入顶点的个数:";
                cin>>graphSize;
                minSpanTree = new Graph(graphSize);
                cout<<"请依次输入各顶点的名称:";
                cin>>graphSize;
                for (char verTexName :orderString){
                    if (verTexName != ' ') {
                        minSpanTree->insertVertex(verTexName);
                    }
                }
                cout<<endl;
                break;
            case 'b':
            case 'B':
                if (nullptr == minSpanTree) {
                    cout<<"请先创建电网顶点!"<<endl;
                }else{
                    while (1) {
                        cout<<"请输入两个顶点及边:";
                        scanf("%c %c %d",vertexName1,vertexName2,edgeWeight);//scanf怎么用？
                        if (vertexName1 == '?') {
                            break;
                        }
                        minSpanTree->insertEdge(vertexName1, vertexName2, edgeWeight);
                        }
                    }
                cout<<endl;
                break;
            case 'c':
            case 'C':
                if (nullptr == minSpanTree) {
                    cout<<"请先创建电网顶点!"<<endl;
                }else{
                    cout<<"请输入起始顶点:";
                    cin>>vertexName1;
                    minSpanTree->getMinSpanTree(vertexName1);
                    cout<<"生成Prim最小生成树!"<<endl;
                    cout<<endl;
                }
                break;
            case 'd':
            case 'D':
                if (nullptr == minSpanTree) {
                    cout<<"请先创建电网顶点!"<<endl;
                }else{
                    cout<<"最小生成树的顶点及边为:"<<endl;
                    minSpanTree->printMinSpanTree();

                }
                break;
            case 'e':
            case 'E':
                exit(0);
                break;
            default:
                cout<<"输入有误，请重新输入!"<<endl;
                break;
        }

    }
#endif
    
}
