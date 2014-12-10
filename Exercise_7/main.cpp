//
//  main.cpp
//  Exercise7
//
//  Created by 一川 on 14/11/8.
//  Copyright (c) 2014年 一川. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Expression{
private:
    char *stackNum;//store number in this stack
    char *stackSymbol;//stroe symbol in this stack
    string infixNotation;
public:
    Expression(string a){//constructor to initialize stackNum and stackSymbol
        infixNotation=a;
        stackNum=new char[infixNotation.length()];
        stackSymbol=new char[infixNotation.length()];
    }
    void changeExpression();//change infix notation to Polish notation
    void printPolish(){//逆扫描stackNum堆栈，输出波兰表达式
        for (int i=sizeof(stackNum); i>=0; i--) {
            cout<<stackNum[i];
        }
        cout<<endl;
    }
    void printRePolish(){//正向扫描stackNum堆栈，输出逆波兰表达式
        for (int i=0; i<=sizeof(stackNum); i++) {
            cout<<stackNum[i];
        }
        cout<<endl;
    }
};

void Expression::changeExpression(){
    int j=0,k=0;//定义变量j：stackNum堆栈下标，k：stackSymbol堆栈下标
    for (long i=infixNotation.length()-1; i>=0; i--) {//循环扫描表达式
        switch (infixNotation[i]) {
            case '+':
                if ('*'==stackSymbol[k-1]||'/'==stackSymbol[k-1]) {//若stackSymbol堆栈最上层运算符优先级大于＋，将优先级大的转移到stackNum堆栈
                    do{
                        stackNum[j]=stackSymbol[k-1];
                        stackSymbol[k-1]='\0';
                        j++;
                        k--;
                    }while('*'==stackSymbol[k-1]||'/'==stackSymbol[k-1]);
                }else{//将运算符压入stackSymbol堆栈
                    stackSymbol[k]=infixNotation[i];
                    k++;
                }
                break;
            case '-':
                if ('*'==stackSymbol[k-1]||'/'==stackSymbol[k-1]) {
                    do{
                        stackNum[j]=stackSymbol[k-1];
                        stackSymbol[k-1]='\0';
                        j++;
                        k--;
                    }while('*'==stackSymbol[k-1]||'/'==stackSymbol[k-1]);
                }else{
                    stackSymbol[k]=infixNotation[i];
                    k++;
                }
                break;
            case '*'://将运算符压入stackSymbol堆栈
                stackSymbol[k]=infixNotation[i];
                k++;
                break;
            case '/'://将运算符压入stackSymbol堆栈
                stackSymbol[k]=infixNotation[i];
                k++;
                break;
            case '('://若遇到（，将stackSymbol中运算符弹出压入stackNum，直到遇到）
                while (')'!=stackSymbol[k-1]) {
                    stackNum[j]=stackSymbol[k-1];
                    stackSymbol[k-1]='\0';
                    j++;
                    k--;
                }
                stackSymbol[k-1]='\0';
                k--;
                break;
            case ')'://将运算符压入stackSymbol堆栈
                stackSymbol[k]=infixNotation[i];
                k++;
                break;
            default://将数字压入stackNum堆栈
                stackNum[j]=infixNotation[i];
                j++;
                break;
        }
    }
    for ( ; k>=0; k--) {//将stackSymbol的运算符全部弹出压入stackNum
        stackNum[j]=stackSymbol[k-1];
        stackSymbol[k]='\0';
        j++;
    }
}

int main() {
    string expression;
    cout<<"请输入表达式：";
    cin>>expression;
    Expression polishExpression=*new Expression(expression);
    Expression reversePolishExpression=*new Expression(expression);
    polishExpression.changeExpression();
    cout<<"波兰表达式：";
    polishExpression.printPolish();
    cout<<"中缀表达式："<<expression<<endl;
    reversePolishExpression.changeExpression();
    cout<<"逆波兰表达式：";
    reversePolishExpression.printRePolish();
}
