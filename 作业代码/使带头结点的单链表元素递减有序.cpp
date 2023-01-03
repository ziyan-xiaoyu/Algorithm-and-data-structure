//设计函数使带有头结点的单链表L元素递减有序

void Sort(List L)
{
    Position p;
    ElementType temp;
    p=L;                    //p指向表头

    int i=1;                //用i++来记录链表中不为空的data元素的总个数
    p=p->next;              //p指向第一个元素

    //先用冒泡法排序一次，统计元素i的总个数
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
    //继续使用冒泡法把剩下的元素排序
    for(int j=i-2;j>0;j--)  //j是剩下的要排序的次数
    {
        p=L;                 //p指向表头
        p=p->next;           //p指向第一个元素
        int k=1;
        while(k<=j)         //k是每次排序相邻比较的次数
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
