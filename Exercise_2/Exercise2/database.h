//
//  database.h
//  Exercise2
//
//  Created by 一川 on 14-9-28.
//  Copyright (c) 2014年 一川. All rights reserved.
//  

using namespace std;

class Passenger{
public:
    Passenger(int n,int s,int m,int k){//构造函数
        head=NULL;
        pSurvival=NULL;
        allPassNum=n;
        startNum=s;
        deadNum=m;
        remainNum=k;
    }
    ~Passenger(){//析枸函数
        ;
    }
    void deletePassNode();//删除一个节点
    void newPassList();//新建乘客列表
    void printPass();//输出整个List
private:
    int allPassNum;//总乘客人数
    int deadNum;//死亡人数
    int remainNum;//保留人数
    int startNum;//开始位置
    class PassengerNode{//乘客节点
    public:
        int passNum;//乘客节点
        PassengerNode *next;
    };
    PassengerNode *head;//头指针
    PassengerNode *pSurvival;//幸存者指针
};

void Passenger::newPassList(){//新建乘客链表环
    PassengerNode *p1,*p2;
    p1=p2=new PassengerNode();
    head=p1;
    for (int i=1; i<=allPassNum; i++) {
        p1=p2;
        p1->passNum=i;
        p2=new PassengerNode();
        p1->next=p2;
    }
    delete p2;
    p1->next=head;
    p1=p2=NULL;
}

void Passenger::deletePassNode(){//删除乘客
    PassengerNode *p1,*p2;
    p1=head;
    p2=p1->next;
    //找到开始位置
    for (int i=1; i!=startNum; i++) {
        p1=p2;
        p2=p1->next;
    }
    
    for (int i=1,gap=2; allPassNum!=remainNum; gap++) {
        if (gap==deadNum) {
            cout<<"第"<<i<<"个死者的位置是："<<p2->passNum<<endl;
            p1->next=p2->next;
            delete p2;
            p2=p1->next;
            p1=p2;
            pSurvival=p1;//保证始终可以找到链表，防止头节点被删除后丢失链表
            p2=p1->next;
            gap=1;//gap++后正好为2
            allPassNum--;
            i++;
        }else{
            p1=p2;
            p2=p1->next;
        }
    }
}

void Passenger::printPass(){//输出最后幸存者（如果头节点被删除怎么办？）
    cout<<"最后剩下："<<remainNum<<"人"<<endl;
    cout<<"剩余的生者位置为：";
    PassengerNode *p1,*p2;
    p1=p2=pSurvival;
    for ( ; p1->next!=pSurvival;  ) {
        cout<<p1->passNum<<"\t";
        p2=p1->next;
        p1=p2;
    }
}

