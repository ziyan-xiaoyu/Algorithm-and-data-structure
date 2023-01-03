//�ÿ�����������ݽ�����������
#include<iostream>
using namespace std;

 //��������
void Swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

//��������
void InsertionSort(int A[], int N)
{
    int P, i;
    int temp;
    for(P=1; P<N; P++)
    {
        temp = A[P];        //ȡ��δ����Ԫ���еĵ�һ��Ԫ��
        for(i=P; i>0&&A[i-1]>temp; i--)
            A[i] = A[i-1];  //�����������������е�Ԫ�رȽϲ�����
        A[i] = temp;        //�ҵ��˺��ʵ�λ�ã��Ž�ȥ
    }
}

//ȷ����Ԫ����
int Median3(int A[], int Left, int Right)
{
    int Center = (Left+Right)/2;
    if(A[Left] > A[Center])
        Swap(&A[Left], &A[Center]);
    if(A[Left] > A[Right])
        Swap(&A[Left], &A[Right]);
    if(A[Center] > A[Right])
        Swap(&A[Center], &A[Right]);
    //��ʱ������A[Left]<=A[Center]<=A[Right]

    Swap(&A[Center], &A[Right-1]);   //����׼Pivot�ص��ұ�
    //ֻ��Ҫ����A[Left+1]...A[Right-2]
    return A[Right-1];              //���ػ�׼Pivot
}

//���ĵݹ麯��
void Qsort(int A[], int Left, int Right)
{
    int Pivot, Cutoff = 5;  //CutoffΪ��ֵ
    int Low, High;

    if(Cutoff <= Right-Left)  //�������Ԫ�س�ֶ࣬�����������
    {
        Pivot = Median3(A, Left, Right);  //ѡ��׼
        Low = Left;
        High = Right -1;
        while(1)  //�������бȻ�׼С���Ƶ���׼��ߣ�����Ƶ��ұ�
        {
            while(A[++Low] < Pivot);
            while(A[--High] > Pivot);
            if(Low < High)
                Swap(&A[Low], &A[High]);
            else
                break;
        }
        Swap(&A[Low], &A[Right-1]);  //����׼������ȷ��λ��
        Qsort(A, Left, Low-1);       //�ݹ������
        Qsort(A, Low+1, Right);      //�ݹ����ұ�
    }
    else
        InsertionSort(A+Left, Right-Left+1);  //Ԫ��̫�٣���ֱ�Ӳ������򣨼�����
}

int main()
{
    cout<<"����������"<<endl;
    int N;  //�������Ԫ����
    cin>>N;
    int A[N];
    for(int i=0; i<N; i++)
        cin>>A[i];

    cout<<"���������"<<endl;
    Qsort(A, 0, N-1);  //���ÿ��ź���
    for(int i=0; i<N; i++)
        cout<<A[i]<<" ";
    return 0;
}
/*
����������
10
49 35 68 99 70 13 25 50 111 60
���������
13 25 35 49 50 60 68 70 99 111
*/
