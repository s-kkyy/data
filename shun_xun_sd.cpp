#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
// 认为l指向真正的左端数据，r指向真正的右端数据的下一个位置
// 循环数据（数学的方式实现）
#define maxx 5
typedef struct
{
    int *data;
    int l, r;
    int sum;
} Deque;
// 初始化
Deque InitDeque()
{
    Deque q;
    q.data = (int *)malloc(sizeof(int) * maxx);
    q.l = q.r = 0;
    q.sum = 0;
    return q;
}
// 左端入队
void LInsert(Deque *q, int k)
{
    if (q->sum == maxx)
    {
        printf("队满，无法入队\n");
        return;
    }
    q->l = (q->l - 1 + maxx) % maxx;
    q->data[q->l] = k;
    q->sum++;
}
// 右端入队
void RInsert(Deque *q, int k)
{
    if (q->sum == maxx)
    {
        printf("队满，无法入队\n");
        return;
    }
    q->data[q->r] = k;
    q->r = (q->r + 1) % maxx;
    q->sum++;
}
// 左端出队
void LDelete(Deque *q)
{
    if (q->sum == 0)
    {
        printf("队空，无法出队\n");
        return;
    }
    printf("%d左端出队\n", q->data[q->l]);
    q->l = (q->l + 1) % maxx;
    q->sum--;
}
// 右端出队
void RDelete(Deque *q)
{
    if (q->sum == 0)
    {
        printf("队空，无法出队\n");
        return;
    }
    q->r = (q->r - 1 + maxx) % maxx;
    printf("%d右端出队\n", q->data[q->r]);
    q->sum--;
}

int main()
{
    Deque q = InitDeque();
    LInsert(&q, 1);
    LInsert(&q, 2);
    RInsert(&q, 3);
    RInsert(&q, 4);
    LDelete(&q);
    RDelete(&q);
    LDelete(&q);
    RDelete(&q);
    RDelete(&q);
    return 0;
}
