//�ö�ջʵ����׺���ʽת��׺���ʽ

#include<iostream>
#include<stack>
#include<string>
using namespace std;

struct Node{
    int num;  //������
    char op;      //������
};
typedef struct Node expnode;
stack<expnode>s;

int ex_c(char c)//��������ת���ɶ�Ӧ�����ȼ�
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
    expnode temp;//ÿ�δ��һ�����ʽ�е��ַ�
    temp.op = '#';
    s.push(temp);//ջ��Ԫ��Ϊ#

    for(int i=0;i<str.length();)//ע�ⲻ���Զ���1
    {
        if(str[i]>='0' && str[i]<='9')//�ж��Ƿ�Ϊ����
        {
            temp.num = str[i] - '0';//���ַ�ת�������ִ���
            i++;
            while(i<str.length() && str[i]>='0'&&str[i]<='9')//�����˳���һλ������
            {
                temp.num = temp.num*10 + (str[i] - '0');
                i++;
            }
            cout<<temp.num;
        }
        else if(str[i]=='(')//�ж��Ƿ�Ϊ������
        {
            temp.op = str[i];
            s.push(temp);
            i++;
        }
        else if(str[i]==')')//�ж��Ƿ�Ϊ������
        {
            while(!s.empty() && s.top().op!='(')
            {
                cout<<s.top().op;
                s.pop();
            }
            s.pop();//����������
            i++;
        }
        else//�ж��Ƿ�Ϊ�����
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

    cout<<"������һ����׺���ʽ��"<<endl;
    cin>>str;
    cout<<"ת��Ϊ��׺���ʽΪ��"<<endl;
    exchange(str);

    return 0;
}

