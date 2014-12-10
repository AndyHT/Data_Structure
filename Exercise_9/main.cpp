//
//  main.cpp
//  Exercise9
//
//  Created by 一川 on 14/11/20.
//  Copyright (c) 2014年 一川. All rights reserved.
//项目简介：
//依次输入关键字并建立二叉排序树，实现二叉排序数的插入和查找功能。
//
//项目功能简介：
//二叉排序树就是指将原来已有的数据根据大小构成一棵二叉树，二叉树中的所有结点数据满足一定的大小关系，所有的左子树中的结点均比根结点小，所有的右子树的结点均比根结点大。
//二叉排序树查找是指按照二叉排序树中结点的关系进行查找，查找关键自首先同根结点进行比较，如果相等则查找成功；如果比根节点小，则在左子树中查找；如果比根结点大，则在右子树中进行查找。这种查找方法可以快速缩小查找范围，大大减少查找关键的比较次数，从而提高查找的效率。


#include <iostream>
using namespace std;

struct BstNode{//二叉树节点
    int data;
    BstNode *leftChild;
    BstNode *rightChild;
};

class BST{//二叉树类
public:
    BST(){
        rootNode=NULL;
        ptr=frontPtr=rootNode;
    }
    ~BST(){
        ;
    }
    int insertNode(int data);//插入函数
    BstNode* searchData(int data);//查找函数
    void inOrder(BstNode *p);//中序遍历二叉树
    void printBST();//打印输出二叉树
    
private:
    BstNode *rootNode;
    BstNode *ptr,*frontPtr;
};

int BST::insertNode(int tempData){//插入函数
    BstNode *p=new BstNode;
    p->data=tempData;
    p->leftChild=p->rightChild=NULL;
    ptr=rootNode;
    frontPtr=rootNode;
    if (rootNode==NULL) {
        rootNode=p;
    }else{
        while (ptr!=NULL) {
            if (ptr->data>tempData) {
                frontPtr=ptr;
                ptr=ptr->leftChild;
            }else if (ptr->data<tempData) {
                frontPtr=ptr;
                ptr=ptr->rightChild;
            }else if (ptr->data==tempData) {
                cout<<"exist!"<<endl;
                return 0;
            }
        }
        if (frontPtr->data>tempData) {
            frontPtr->leftChild=p;
        }else if (frontPtr->data<tempData){
            frontPtr->rightChild=p;
        }
    }
    return 1;
}

BstNode* BST::searchData(int tempData){//查找函数
    ptr=rootNode;
    while (ptr!=NULL) {
        if (ptr->data>tempData) {
            ptr=ptr->leftChild;
        }else if (ptr->data<tempData) {
            ptr=ptr->rightChild;
        }else if (ptr->data==tempData) {
            return ptr;
        }
    }
    return NULL;
}

void BST::inOrder(BstNode *p){//中序遍历函数
    if (p!=NULL) {
        inOrder(p->leftChild);
        cout<<p->data<<"-";
        inOrder(p->rightChild);
    }
}

void BST::printBST(){//打印输出二叉树
    inOrder(rootNode);
    cout<<endl;
}


int main() {
    
    cout<<"**      二叉排序树        **"<<endl;
    cout<<"==========================="<<endl;
    cout<<"**    1--建立二叉排序树    **"<<endl;
    cout<<"**    2--插入元素         **"<<endl;
    cout<<"**    3--查询元素         **"<<endl;
    cout<<"**    4--退出程序         **"<<endl;
    cout<<"==========================="<<endl;
    int order,data;
    BST binTree=BST();
    while (1) {
        cout<<"Please select:";
        cin>>order;
        switch (order) {
            case 1:
                cout<<"Please input key to create Bsort_tree:"<<endl;
                while (1){
                    cin>>data;
                    if (data==-1) {
                        break;
                    }else{
                        binTree.insertNode(data);
                    }
                }
                binTree.printBST();
                break;
            case 2:
                cout<<"Please input insert number:";
                cin>>data;
                if(binTree.insertNode(data)){
                    binTree.printBST();
                }else{
                    cout<<"fail"<<endl;
                }
                break;
            case 3:
                cout<<"Please input search number:";
                cin>>data;
                if(NULL!=binTree.searchData(data)){
                    cout<<"success"<<endl;
                    binTree.printBST();
                }else{
                    cout<<"fail"<<endl;
                }
                break;
            case 4:
                exit(0);
            default:
                cout<<"input error"<<endl;
                break;
        }
    }
    
}
