//������׺���ʽ�Ľ����ջ�ṹ��ʾ��
//�ֽ���׺���ʽת��Ϊ��׺���ʽ����������ջ���е��μ���

#include<iostream>
#include<stack>
#include<string>
using namespace std;

struct Node{
    double num;   //������
    char op;      //������
};
typedef struct Node expnode;
stack<expnode>s;

int ex_c(char c)    //��������ת���ɶ�Ӧ�����ȼ�
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

double answer_count(char c, double n1, double n2)   //cout������ʱ�ͽ��С����Ρ�����
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

void Expression_Calculate(string str)   //����׺���ʽת��Ϊ��׺���ʽ���������ֱ�Ӽ��㣨������ջ�������жϣ�
{
    stack<double>numS;  //���׺���ʽ�еĲ�������ջ
    expnode temp;        //ÿ�δ�ű��ʽ�е�һ���ַ�
    double k;           //���ڴ���С����0.1,0.01
    double n1,n2;       //��¼ÿ�βμ������������
    double answer;      //��¼ÿ������Ľ��

    temp.op = '#';
    s.push(temp);    //ջ��Ԫ��Ϊ#
    //numS.push(-1);   //ջ��Ԫ��Ϊ-1

    for(int i=0;i<str.length();)//ע�ⲻ���Զ���1
    {
        if(str[i]>='0' && str[i]<='9')//�ж��Ƿ�Ϊ����
        {
            temp.num = str[i] - '0';//���ַ�ת�������ִ���
            i++;
            while(i<str.length() && str[i]>='0'&&str[i]<='9')//�������ֳ�����һλ����
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
            numS.push(temp.num);//����������׺˳����ջ
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
                //cout<<s.top().op;
                n2 = numS.top();//ȡ������ջջ��Ԫ��
                numS.pop();//ȡ����ͳ�ջ
                n1 = numS.top();//��ȡһ��ջ��Ԫ��
                numS.pop();//ȡ����ͳ�ջ
                answer = answer_count(s.top().op, n1, n2);//���õ������㺯������
                numS.push(answer);//����õ����µ�ֵ���������ջ
                s.pop();//�Ѿ�����Ĳ�������ջ
            }
            s.pop();//����������
            i++;
        }
        else if(str[i]=='=')//�ж��Ƿ�Ϊ�Ⱥ�
        {
            break;
        }
        else//�ж��Ƿ�Ϊ�����
        {
            while(!s.empty() && s.top().op!='(' && s.top().op!='#' && ex_c(str[i])<=ex_c(s.top().op))
            {
                //cout<<s.top().op;
                n2 = numS.top();
                numS.pop();
                n1 = numS.top();
                numS.pop();
                answer = answer_count(s.top().op, n1, n2);//���ú�������
                numS.push(answer);//����õ����µ�ֵ���������ջ
                s.pop();
            }
            temp.op = str[i];
            s.push(temp);
            i++;
        }
    }
    while(!s.empty())//�������ջ��Ϊ��
    {
        if(s.top().op!='#')
        {
            //cout<<s.top().op<<endl;
            n2 = numS.top();
            numS.pop();
            n1 = numS.top();
            numS.pop();
            answer = answer_count(s.top().op, n1, n2);//���ú�������
            numS.push(answer);//����õ����µ�ֵ���������ջ
            s.pop();
        }
        else
        {
            s.pop();//��ֻʣջ��Ԫ�ء�#��ʱ�������ջ
        }
    }
    printf("%.2f",numS.top());
    //cout<<numS.top();//������ս������������ջ�е����һ��ֵ
}

int main()
{
    string str_M;   //��׺���ʽ����
    cout<<"������һ����׺���ʽ��"<<endl;
    cin>>str_M;

    cout<<"���ʽ����Ľ��Ϊ��"<<endl;
    Expression_Calculate(str_M);//���ʽ����

    return 0;
}
/*
����������20*(4.5�C3)=
��������30.00
*/
