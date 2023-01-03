//给定整数数组nums和整数k，请返回数组中第k个最大的元素
#include<iostream>
using namespace std;

 //交换函数
void Swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

//冒泡排序,当获得第k个大的元素的时候就停止
void BubbleSort(int A[], int N, int k)
{
    for(int P=N-1; P>=N-k; P--) //冒泡循环k次以后停止
        for(int i=0; i<P; i++)  //此为一趟冒泡，每次找出一个最大元素，被交换到最右端
            if(A[i] > A[i+1])
                Swap(&A[i], &A[i+1]);
    cout<<A[N-k]<<endl;   //冒泡循环k次以后，输出A的第N-k个元素
}

int main()
{
    cout<<"输入样例："<<endl;
    int nums[50];
    int N = 0;   //待排序的元素数
    int k;   //第k个最大的元素
    while(1)
    {
        cin>>nums[N];
        if(nums[N]==-1) break;
        N++;
    }
    cin>>k;

    cout<<"输出样例："<<endl;
    if(k <= N)
        BubbleSort(nums, N, k);  //冒泡排序，找到k就停止
    else
        cout<<"输入的k值超过了整数序列的个数！"<<endl;

    return 0;
}
/*
输入样例：
3 2 1 5 6 4 -1
2
输出结果：
5
*/
