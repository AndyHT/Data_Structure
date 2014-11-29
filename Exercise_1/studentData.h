//
//  studentData.h
//  Exercise1
//
//  Created by 霍腾 学号：1352901 on 14-9-27.
//  Copyright (c) 2014年  All rights reserved.
//

#include<iostream>
#include<string>
using namespace std;

struct stu{
    int stuNum;
    string stuName;
    string stuSex;
    int stuAge;
    string stuMajor;
    stu *next;
    stu *front;
};

class StuData{
private:
    stu *head;
    stu *tail;
    int tableSize;//Node个数
    
public:
    int newStuData();//新建表
    int insertStuData();//插入元素
    int deleteStuData();//删除元素
    int changeStuData();//修改元素
    int findStuData();//查找元素
    void printStuData();//打印元素
};

int StuData::newStuData(){//新建函数
    stu *p1,*p2;
    int n;
    cout<<"请输入考生人数：";
    cin>>n;
    tableSize=n;
    p1=p2=new stu();
    head=p1;
    p1->front=NULL;
    p2=new stu();
    p1->next=p2;
    p1=p2;
    cout<<"请依次输入考生的考号，姓名，性别，年龄以及报考类别！"<<endl;
    for ( int i=1 ; i<=n ; i++) {
        cin>>p1->stuNum>>p1->stuName>>p1->stuSex>>p1->stuAge>>p1->stuMajor;
        p2=new stu();
        p1->next=p2;
        p2->front=p1;
        p1=p2;
    }
    p1=p2->front;
    p1->next=NULL;
    tail=p1;
    delete p2;
    p1=p2=NULL;
    
    return 1;
}

int StuData::insertStuData(){//插入函数
    cout<<"请输入你要插入的考生的位置：";
    int n;
    cin>>n;
    if (n>tableSize) {
        cout<<"输入的插入位置大于总人数"<<endl;
        return -1;
    }
    stu *p1,*p2,*p3;
    p1=p2=head->next;
    p3=new stu();
    cout<<"请依次输入考生的考号，姓名，性别，年龄以及报考类别！"<<endl;
    cin >>p3->stuNum >>p3->stuName >>p3->stuSex >>p3->stuAge >>p3->stuMajor;
    for(int i=1;i!=n&&p2->next!=NULL;i++){
        p1=p2;
        p2=p1->next;
    }
    if (NULL==p2->next) {
        p1->next=p3;
        p3->front=p1;
        p3->next=NULL;
    }
    p1=p2->front;
    p1=p3;
    p3->front=p1;
    p3->next=p2;
    p2->front=p3;
    
    return 1;
}

int StuData::deleteStuData(){//删除函数
    stu *p1,*p2;
    p1=p2=head;
    cout<<"请输入要删除的考生的考号：";
    long n;
    cin>>n;
    while (p1->stuNum!=n) {
        p1=p2->next;
        p2=p1;
        if (NULL==p1) {
            return -1;
        }
    }
    cout<<"你删除的考生信息是：";
    cout<<p1->stuNum<<"\t"<<p1->stuName<<"\t"<<p1->stuSex<<"\t"<<p1->stuAge<<"\t"<<p1->stuMajor<<endl;
    p1=p2->front;
    p1->next=p2->next;
    delete p2;
    p2=p1->next;
    p2->front=p1;
    p1=p2=NULL;
    
    return 1;
}

int StuData::changeStuData(){//修改函数
    cout<<"请输入要修改的考生的考号：";
    long n;
    cin>>n;
    stu *p1,*p2;
    p1=p2=head->next;
    while (p1->stuNum!=n) {
        if (p2!=NULL) {
            p1=p2->next;
            p2=p1;
        }else{
            return -1;
        }
        p1=p2->next;
        p2=p1;
    }
    cout<<"请输入修改后的考生信息：";
    cin>>p1->stuNum>>p1->stuName>>p1->stuSex>>p1->stuAge>>p1->stuMajor;
    p1=p2=NULL;
    
    return 1;
}

int StuData::findStuData(){//查找函数
    cout<<"请输入要查找的考生的考号：";
    long n;
    cin>>n;
    stu *p1,*p2;
    p1=p2=head->next;
    while (p1->stuNum!=n) {
        if (p1!=NULL) {
            p1=p2->next;
            p2=p1;
        }else{
            return -1;
        }
        p1=p2->next;
        p2=p1;
    }
    cout<<"考号\t姓名\t性别\t年龄\t报考类别"<<endl;
    cout<<p1->stuNum<<"\t"<<p1->stuName<<"\t"<<p1->stuSex<<"\t"<<p1->stuAge<<"\t"<<p1->stuMajor<<endl;

    
    return 1;
}

void StuData::printStuData(){//统计函数
    stu *p1,*p2;
    p1=p2=head->next;
    cout<<"考号\t姓名\t性别\t年龄\t报考类别"<<endl;
    while (p1!=NULL) {
        cout<<p1->stuNum<<"\t"<<p1->stuName<<"\t"<<p1->stuSex<<"\t"<<p1->stuAge<<"\t"<<p1->stuMajor<<endl;
        p1=p2->next;
        p2=p1;
    }
}





















