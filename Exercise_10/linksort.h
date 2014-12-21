//
//  linksort.h
//  Exercise_10
//
//  Created by 一川 on 14/12/20.
//  Copyright (c) 2014年 一川. All rights reserved.
//

struct node{
    int key;
    node *next;
};

class LinkSort{
private:
    node *head;
public:
    LinkSort(){
        head = nullptr;
    }
};