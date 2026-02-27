#include<iostream>
#include<stdlib.h>
using namespace std;
//链式队列

typedef struct Node
{
    int data;  
    struct Node *next;
} QNode;
typedef struct {
    QNode *f;//队首指针
    QNode *r;//队尾指针
} Queue;
//初始化
Queue InitQueue(){
    Queue q;
    q.f = q.r = (QNode *)malloc(sizeof(QNode));
    q.f->next = NULL;
    return q;
}
//入队
void Enqueue(Queue *q,int k){
    QNode *s = (QNode *)malloc(sizeof(QNode));
    s->data = k;
    s->next = NULL;
    q->r->next = s;
    q->r = s;
}
//出队
void Dequeue(Queue*q){
    if(q->f==q->r){
        printf("队空，无法出队\n");
    }
    else{
        printf("%d\n", q->f->next->data);
        if(q->f->next==q->r){
            q->r = q->f;
        }
        else{
            QNode *p = q->f->next;
            q->f->next = p->next;
            free(p);
            p = NULL;
        }
    }
}

int main()
{
    Queue q = InitQueue();
    Enqueue(&q, 1);
    Enqueue(&q, 2);
    Enqueue(&q, 3);
    Dequeue(&q);
    Dequeue(&q);
    Dequeue(&q);
    Dequeue(&q);


    return 0;
}