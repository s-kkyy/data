#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
// 链栈
typedef struct Node
{
    int data;
    struct Node *next;
} Snode, *linkStack;
// 初始化
linkStack InitStack()
{
    linkStack s = (linkStack)malloc(sizeof(Snode));
    if (s == NULL)
    {
        printf("内存分配失败\n");
        return NULL;
    }
    s->next = NULL;
    return s;
}
// 入栈
void Push(linkStack s, int k)
{
    if (s == NULL)
    {
        printf("栈未初始化\n");
        return;
    }
    linkStack newnode = (linkStack)malloc(sizeof(Snode));
    if (newnode == NULL)
    {
        printf("内存分配失败\n");
        return;
    }
    newnode->data = k;
    newnode->next = s->next;
    s->next = newnode;
}
// 判空
int IsEmpty(linkStack s)
{
    if (s->next == NULL)
    {
        return 1; // 栈空
    }
    return 0;
}
// 出栈
void Pop(linkStack s)
{
    if (IsEmpty(s) == 1)
    {
        printf("栈空，无法出栈\n");
        return;
    }
    linkStack p = s->next;
    s->next = p->next;
    free(p);
    p = NULL;
    return;
}
// 获取栈顶元素
int Get(linkStack s)
{
    if (IsEmpty(s) == 1)
    {
        printf("栈空\n");
        return -1;
    }
    return s->next->data;
}
int main()
{
    linkStack s = InitStack();
    Push(s, 1);
    Push(s, 2);
    Push(s, 3);
    printf("%d\n", Get(s));
    Pop(s);
    printf("%d\n", Get(s));
    Pop(s);
    Pop(s);
    printf("%d\n", Get(s));
}
