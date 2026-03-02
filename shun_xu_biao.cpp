#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#define maxx 20
typedef struct Arraylist
{
    int *data;
    int s;
} Array;
//初始化
Array InitArray(Array a)
{
    a.data = (int *)malloc(sizeof(int) * maxx);
    if(a.data==NULL)
    {
        printf("空间申请失败\n");
        return a;
    }
    a.s = 0;
    return a;
}
//末尾添加一个数据k
void Add(Array* a,int k)
{
    if(a->s==maxx)
    {
        printf("数组已满\n");
        return;
    }
    a->data[a->s] = k;
    a->s++;
}
//在下标i位置插入数据k
void Insert(Array* a,int k,int i)
{
    if(a->s==maxx)
    {
        printf("数组已满\n");
        return;
    }
    for (int j = a->s - 1; j >= i;j--)
    {
        a->data[j + 1] = a->data[j];
    }
    a->data[i] = k;
    a->s++;
}
//查找数据k所在的下标，能找到则返回下标，否则返回-1
int Find(Array* a,int k)
{
    int i;
    for (i = 0; i < a->s;i++)
    {
        if(a->data[i]==k)
        {
            return i;
        }
    }
    return -1;
}
//在下标i位置删除数据
void Delete(Array* a,int i)
{
    int k = Find(a, i);
    if(k==-1)
    {
        printf("不存在，无法删除\n");
        return;
    }
    if (i < 0||i>a->s)
    {
        printf("下标不合法\n");
        return;
    }
    for (int j = i; j < a->s - 1;j++)
    {
        a->data[j] = a->data[j + 1];
    }
    a->s--;
}
void show(Array a)
{
    if(a.s==0)
    {
        printf("空表\n");
        return;
    }
    for (int i = 0; i < a.s;i++)
    {
        printf("%d ", a.data[i]);
    }
    printf("\n");
}

int main()
{
    Array a;
    a = InitArray(a);
    Add(&a, 1);
    Add(&a, 2);
    Add(&a, 3);
    Add(&a, 4);
    Add(&a, 5);
    show(a);
    Insert(&a, 6, 2);
    show(a);
    Delete(&a, 2);
    show(a);

    return 0;
}