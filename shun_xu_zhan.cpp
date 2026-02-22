#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
#define maxx 10
typedef struct
{
    int *data;
    int top;
} Stack;
// 初始化栈
Stack InitStack()
{
    Stack s;
    s.data = (int *)malloc(sizeof(int) * maxx);
    if (s.data == NULL)
    {
        printf("内存分配失败\n");
        return s;
    }
    s.top = 0;
    return s;
}
// 入栈
void Push(Stack *s, int k)
{
    if (s->top == maxx)
    {
        printf("栈满，无法入栈\n");
        return;
    }
    s->data[s->top] = k;
    s->top++;
}
// 判断栈是否为空
int IsEmpty(Stack *s)
{
    if (s->top == 0)
    {
        return 1; // 栈为空
    }
    return 0;
}
// 出栈
void Pop(Stack *s)
{
    if (IsEmpty(s) == 1)
    {
        printf("栈空，无法出栈\n");
        return;
    }
    s->top--;
}
// 获取栈顶元素
int Get(Stack s)
{
    if (IsEmpty(&s) == 1)
    {
        printf("栈空\n");
        return -1;
    }
    return s.data[s.top - 1];
}

int main()
{
    Stack s = InitStack();
    Push(&s, 1);
    Push(&s, 2);
    Push(&s, 3);
    printf("%d\n", Get(s));
    Pop(&s);
    printf("%d\n", Get(s));
    Pop(&s);
    printf("%d\n", Get(s));
    Pop(&s);
    printf("%d\n", Get(s));
}