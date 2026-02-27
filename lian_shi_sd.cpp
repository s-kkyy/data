#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
// 链式结点结构
typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *pre;
} Node;
typedef struct
{
    Node *l;
    Node *r;
} Deque;
// 认为l指向真正的左端数据，r指向真正的右端数据的下一个位置
// 初始化
Deque InitDeque()
{
    Deque q;
    // 创建一个带头结点的链表
    Node *s = (Node *)malloc(sizeof(Node));
    s->next = s->pre = NULL;
    q.l = q.r = s;
    return q;
}
// 左端入队
void LInsert(Deque *q, int k)
{
    // 创建一个结点s
    Node *s = (Node *)malloc(sizeof(Node));
    s->data = k;
    s->pre = NULL;
    s->next = q->l;
    q->l->pre = s;
    q->l = s;
}
// 右端入队
void RInsert(Deque *q, int k)
{
    // 创建一个结点s
    Node *s = (Node *)malloc(sizeof(Node));
    q->r->data = k;
    q->r->next = s;
    s->pre = q->r;
    s->next = NULL;
    q->r = s;
}
// 左端出队
void LDelete(Deque *q)
{
    if (q->l == q->r)
    {
        printf("队空，无法出队\n");
        return;
    }
    Node *p = q->l;
    printf("%d左侧出队\n", p->data);
    q->l = q->l->next;
    q->l->pre = NULL;
    free(p);
}
// 右侧出队
void RDelete(Deque *q)
{
    if (q->l == q->r)
    {
        printf("队空，无法出队\n");
        return;
    }
    Node *p = q->r;
    q->r = q->r->pre;
    printf("%d右侧出队\n", p->pre->data);
    q->r->next = NULL;
    free(p);
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
    LDelete(&q);
    return 0;
}
