//��ƺ���ʹ����ͷ���ĵ�����LԪ�صݼ�����

void Sort(List L)
{
    Position p;
    ElementType temp;
    p=L;                    //pָ���ͷ

    int i=1;                //��i++����¼�����в�Ϊ�յ�dataԪ�ص��ܸ���
    p=p->next;              //pָ���һ��Ԫ��

    //����ð�ݷ�����һ�Σ�ͳ��Ԫ��i���ܸ���
    while(p->next!=NUll)
    {
        if(p->data < p->next->data)
        {
            temp = p->data;
            p->data = p->next->data;
            p->next->data = temp;
        }
        p=p->next;
        i++;
    }
    //����ʹ��ð�ݷ���ʣ�µ�Ԫ������
    for(int j=i-2;j>0;j--)  //j��ʣ�µ�Ҫ����Ĵ���
    {
        p=L;                 //pָ���ͷ
        p=p->next;           //pָ���һ��Ԫ��
        int k=1;
        while(k<=j)         //k��ÿ���������ڱȽϵĴ���
        {
            if(p->data < p->next->data)
            {
                temp = p->data;
                p->data = p->next->data;
                p->next->data = temp;
            }
            p=p->next;
            k++;
        }
    }

}
