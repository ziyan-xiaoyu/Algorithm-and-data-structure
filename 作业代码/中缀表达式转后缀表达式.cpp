//用堆栈实现中缀表达式转后缀表达式

#include<iostream>
#include<stack>
#include<string>
using namespace std;

struct Node{
    int num;  //操作数
    char op;      //操作符
};
typedef struct Node expnode;
stack<expnode>s;

int ex_c(char c)//将操作符转换成对应的优先级
{
    int m;
    switch(c)
    {
        case '+': m = 1; break;
        case '-': m = 1; break;
        case '*': m = 2; break;
        case '/': m = 2; break;
        default: break;
    }
    return m;
}

void exchange(string str)
{
    expnode temp;//每次存放一个表达式中的字符
    temp.op = '#';
    s.push(temp);//栈底元素为#

    for(int i=0;i<str.length();)//注意不用自动加1
    {
        if(str[i]>='0' && str[i]<='9')//判断是否为数字
        {
            temp.num = str[i] - '0';//将字符转换成数字储存
            i++;
            while(i<str.length() && str[i]>='0'&&str[i]<='9')//出现了超过一位的数字
            {
                temp.num = temp.num*10 + (str[i] - '0');
                i++;
            }
            cout<<temp.num;
        }
        else if(str[i]=='(')//判断是否为左括号
        {
            temp.op = str[i];
            s.push(temp);
            i++;
        }
        else if(str[i]==')')//判断是否为右括号
        {
            while(!s.empty() && s.top().op!='(')
            {
                cout<<s.top().op;
                s.pop();
            }
            s.pop();//弹出左括号
            i++;
        }
        else//判断是否为运算符
        {
            while(!s.empty() && s.top().op!='(' && s.top().op!='#' && ex_c(str[i])<=ex_c(s.top().op))
            {
                cout<<s.top().op;
                s.pop();
            }
            temp.op = str[i];
            s.push(temp);
            i++;
        }
    }
    while(!s.empty())
    {
        if(s.top().op!='#')
        {
            cout<<s.top().op;
            s.pop();
        }
        else
        {
            s.pop();
        }
    }
}

int main()
{
    string str;

    cout<<"请输入一个中缀表达式："<<endl;
    cin>>str;
    cout<<"转换为后缀表达式为："<<endl;
    exchange(str);

    return 0;
}

