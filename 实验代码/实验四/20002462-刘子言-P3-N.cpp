//������������nums������k���뷵�������е�k������Ԫ��
#include<iostream>
using namespace std;

 //��������
void Swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

//ð������,����õ�k�����Ԫ�ص�ʱ���ֹͣ
void BubbleSort(int A[], int N, int k)
{
    for(int P=N-1; P>=N-k; P--) //ð��ѭ��k���Ժ�ֹͣ
        for(int i=0; i<P; i++)  //��Ϊһ��ð�ݣ�ÿ���ҳ�һ�����Ԫ�أ������������Ҷ�
            if(A[i] > A[i+1])
                Swap(&A[i], &A[i+1]);
    cout<<A[N-k]<<endl;   //ð��ѭ��k���Ժ����A�ĵ�N-k��Ԫ��
}

int main()
{
    cout<<"����������"<<endl;
    int nums[50];
    int N = 0;   //�������Ԫ����
    int k;   //��k������Ԫ��
    while(1)
    {
        cin>>nums[N];
        if(nums[N]==-1) break;
        N++;
    }
    cin>>k;

    cout<<"���������"<<endl;
    if(k <= N)
        BubbleSort(nums, N, k);  //ð�������ҵ�k��ֹͣ
    else
        cout<<"�����kֵ�������������еĸ�����"<<endl;

    return 0;
}
/*
����������
3 2 1 5 6 4 -1
2
��������
5
*/
