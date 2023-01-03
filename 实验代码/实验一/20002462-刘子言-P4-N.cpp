//输入队列的元素个数，以及队列中的元素
//将队列中元素从小到大排列
#include<iostream>
#include<queue>
#include<string>
using namespace std;

queue<int>q;

void sort_q(queue<int>q, int n)//排序
{
    int a,b,c,t;
    for(int i=0; i<n-1 ; i++)
    {
        a=q.front();
        q.pop();
        for(int j=0; j<n-1-i; j++)
        {
            b=q.front();
            q.pop();
            if(a<b)
            {
                q.push(a);
                a=b;
            }
            else
                q.push(b);
        }
        q.push(a);
        for(int k=0; k<i; k++)
        {
            c=q.front();
            q.pop();
            q.push(c);
        }
    }

    for(int i=0; i<n; i++) //输出
    {
        t=q.front();
        q.pop();
        cout<<t<<" ";
    }
}

int main()
{
    int n;
    int k;
    cout<<"输入样例："<<endl;
    cin>>n;
    for(int i=0; i<n; i++) //输入
    {
        cin>>k;
        q.push(k);
    }
    cout<<"输出样例："<<endl;
    sort_q(q,n);            //排序与输出

    return 0;
}
/*
输入样例：10
9 4 6 1 8 3 7 0 2 5
输出样例：
0   1   2  3  4  5  6  7  8   9
*/
