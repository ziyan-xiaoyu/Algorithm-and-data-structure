//������������ö�������ʽ�洢
//�����������е�k������ֵ��k<=n��

#include<iostream>
using namespace std;

typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    char Data;//������������Ϊ�ַ���
    BinTree Left;
    BinTree Right;
};
int i=0;

//�������򴴽��ķ���,�����������ֵ����������
void CreatBT(TNode **Node)//�˴����ݵĲ���Ϊ����ָ��
{
	char data;
	cin>>data;

	*Node = (BinTree)malloc(sizeof(TNode));
	if(data == '#')
    {
		*Node = NULL;
	}
	else// if ((data != '#') && (*Node))
    {
		(*Node)->Data = data;
		(*Node)->Left = NULL;
		(*Node)->Right = NULL;
		CreatBT(&(*Node)->Left);
		CreatBT(&(*Node)->Right);
	}
}

//�ҵ���������е�k��ֵ�����
void PreTra_k(BinTree BT, int k)
{
    if(BT)
    {
        i++;
        if(i==k)
        {
            cout<<BT->Data;
            return;
        }
        if(BT->Left) PreTra_k(BT->Left, k);
        if(BT->Right) PreTra_k(BT->Right, k);
    }
}

int main()
{
    BinTree BT=NULL;
    cout<<"����һ�ö�������"<<endl;
    CreatBT(&BT);

    int k=0;
    cout<<"��Ҫ����˶������ڼ�������ֵ��";
    cin>>k;
    PreTra_k(BT, k);

    return 0;
}


