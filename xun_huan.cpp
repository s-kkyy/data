#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#define maxx 10
using namespace std;
//循环队列
typedef struct {
    int *data;
    int f, r;
}queue;
//初始化
queue Initqueue(){
    queue q;
    q.data = (int *)malloc(sizeof(int) * maxx);
    q.f = q.r = 0;
    return q;
}
//入队
void Enqueue(queue* q,int k){
    if(q->f==(q->r+1)%maxx){
        printf("队满，无法入队\n");
    }
    q->data[q->r] = k;
    q->r = (q->r + 1) % maxx;
}
//判空
int IsEmpty(queue*q){
    if(q->f==q->r){
        return 1;
    }
    return 0;
}
//出队
void Dequeue(queue*q){
    if(IsEmpty(q)==1)
    {
        printf("队空，无法出队\n");
    }
    else{
        printf("%d\n", q->data[q->f]);
        q->f = (q->f + 1) % maxx;
    }
}

int main()
{
    queue q = Initqueue();
    Enqueue(&q, 1);
    Enqueue(&q, 2);
    Enqueue(&q, 3);
    Dequeue(&q);
    Dequeue(&q);
    Dequeue(&q);
    Dequeue(&q);
    printf("%d\n", IsEmpty(&q));

    return 0;
}