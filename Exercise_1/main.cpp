//
//  main.cpp
//  Exercise1
//
//  Created by 霍腾 学号：1352901 on 14-9-27.
//  Copyright (c) 2014年  All rights reserved.
//

#include <iostream>
#include "studentData.h"

int main() {
    cout<<"首先请建立考生信息系统！"<<endl;
    StuData stuDataTable;
    stuDataTable.newStuData();
    int order;
    cout<<"请选择您要进行的操作（1为插入，2为删除，3为查找，4为修改，5为统计，0为取消操作）"<<endl;
    for ( ;  ;  ) {
        cout<<"请选择您要进行的操作：";
        cin>>order;
        switch (order) {
            case 1:
                stuDataTable.insertStuData();
                break;
            case 2:
                stuDataTable.deleteStuData();
                break;
            case 3:
                stuDataTable.findStuData();
                break;
            case 4:
                stuDataTable.changeStuData();
                break;
            case 5:
                stuDataTable.printStuData();
                break;
            case 0:
                cout<<"系统将退出"<<endl;
                exit(0);
            default:
                cout<<"输入有误，请重新输入"<<endl;
                break;
        }
    }
}

