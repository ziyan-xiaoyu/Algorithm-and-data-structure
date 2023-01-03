//计算中缀表达式的结果（栈结构表示）
//现将中缀表达式转化为后缀表达式，再运用新栈进行单次计算

#include<iostream>
#include<stack>
#include<string>
using namespace std;

struct Node{
    double num;   //操作数
    char op;      //操作符
};
typedef struct Node expnode;
stack<expnode>s;

int ex_c(char c)    //将操作符转换成对应的优先级
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

double answer_count(char c, double n1, double n2)   //cout操作符时就进行“单次”运算
{
    double answer0;
    switch(c)
    {
        case '+': answer0 = n1+n2; break;
        case '-': answer0 = n1-n2; break;
        case '*': answer0 = n1*n2; break;
        case '/': answer0 = n1/n2; break;
        default: break;
    }
    return answer0;
}

void Expression_Calculate(string str)   //将中缀表达式转化为后缀表达式，不输出，直接计算（数字入栈，符号判断）
{
    stack<double>numS;  //存后缀表达式中的操作数的栈
    expnode temp;        //每次存放表达式中的一个字符
    double k;           //用于处理小数的0.1,0.01
    double n1,n2;       //记录每次参加运算的两个数
    double answer;      //记录每次运算的结果

    temp.op = '#';
    s.push(temp);    //栈底元素为#
    //numS.push(-1);   //栈底元素为-1

    for(int i=0;i<str.length();)//注意不用自动加1
    {
        if(str[i]>='0' && str[i]<='9')//判断是否为数字
        {
            temp.num = str[i] - '0';//将字符转换成数字储存
            i++;
            while(i<str.length() && str[i]>='0'&&str[i]<='9')//整数部分出超过一位数字
            {
                temp.num = temp.num*10 + (str[i] - '0');
                i++;
            }
            if(str[i]=='.')
            {
                i++;
                k=0.1;
                while(i<str.length() && str[i]>='0'&&str[i]<='9')
                {
                    temp.num = temp.num + (str[i] - '0')*k;
                    i++;
                    k=k*0.1;
                }
            }
            //cout<<temp.num;
            numS.push(temp.num);//操作数按后缀顺序入栈
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
                //cout<<s.top().op;
                n2 = numS.top();//取操作数栈栈顶元素
                numS.pop();//取出后就出栈
                n1 = numS.top();//再取一个栈顶元素
                numS.pop();//取出后就出栈
                answer = answer_count(s.top().op, n1, n2);//调用单次运算函数计算
                numS.push(answer);//计算得到的新的值入操作数的栈
                s.pop();//已经运算的操作符出栈
            }
            s.pop();//弹出左括号
            i++;
        }
        else if(str[i]=='=')//判断是否为等号
        {
            break;
        }
        else//判断是否为运算符
        {
            while(!s.empty() && s.top().op!='(' && s.top().op!='#' && ex_c(str[i])<=ex_c(s.top().op))
            {
                //cout<<s.top().op;
                n2 = numS.top();
                numS.pop();
                n1 = numS.top();
                numS.pop();
                answer = answer_count(s.top().op, n1, n2);//调用函数计算
                numS.push(answer);//计算得到的新的值入操作数的栈
                s.pop();
            }
            temp.op = str[i];
            s.push(temp);
            i++;
        }
    }
    while(!s.empty())//如果符号栈不为空
    {
        if(s.top().op!='#')
        {
            //cout<<s.top().op<<endl;
            n2 = numS.top();
            numS.pop();
            n1 = numS.top();
            numS.pop();
            answer = answer_count(s.top().op, n1, n2);//调用函数计算
            numS.push(answer);//计算得到的新的值入操作数的栈
            s.pop();
        }
        else
        {
            s.pop();//当只剩栈底元素“#”时，将其出栈
        }
    }
    printf("%.2f",numS.top());
    //cout<<numS.top();//输出最终结果，即操作数栈中的最后一个值
}

int main()
{
    string str_M;   //中缀表达式串儿
    cout<<"请输入一个中缀表达式："<<endl;
    cin>>str_M;

    cout<<"表达式计算的结果为："<<endl;
    Expression_Calculate(str_M);//表达式计算

    return 0;
}
/*
输入样例：20*(4.5–3)=
输出结果：30.00
*/
