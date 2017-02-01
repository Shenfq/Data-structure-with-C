#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

int len = 6;
typedef struct Queue{
    int *pBase;
    int front;
    int rear;
}QUEUE;

void init(QUEUE *);
bool en_queue(QUEUE *, int val);
bool out_queue(QUEUE *pQ,int *);
void traverse_queue(QUEUE *);
bool full_queue(QUEUE *);
bool empty_queue(QUEUE * pQ);

int main(void) {
    QUEUE Q;
    init(&Q);
    en_queue(&Q, 1);
    en_queue(&Q, 2);
    en_queue(&Q, 3);
    en_queue(&Q, 4);

    traverse_queue(&Q);

    int out;
    out_queue(&Q,&out);
    traverse_queue(&Q);
    printf("queue outer:  %d",out);
    return 0;
}


void init(QUEUE *pQ){
    pQ->pBase = (int *)malloc(sizeof(int) * len);
    pQ->front = 0;
    pQ->rear = 0;
}
bool full_queue(QUEUE *pQ){
    if( (pQ->rear+1)%len == pQ->front )
        return true;
    else
        return false;
}
bool en_queue(QUEUE *pQ, int val){
    if( full_queue(pQ)){
        return false;
    } else {
        pQ->pBase[pQ->rear] = val;
        pQ->rear = (pQ->rear+1)%len;
        return true;
    }
}

void traverse_queue(QUEUE *pQ){
    int i = pQ->front;
    while(i!=pQ->rear){
        printf("%d  ",pQ->pBase[i]);
        i = (i+1)%len;
    }
    printf("\n");
    return ;
}
bool empty_queue(QUEUE * pQ){
    if(pQ->front == pQ->rear)
        return true;
    else
        return false;
}
bool out_queue(QUEUE *pQ,int * pVal){
    if(empty_queue(pQ)){
        return false;
    } else {
        *pVal = pQ->pBase[pQ->front];
        pQ->front = (pQ->front+1) % len;
        return true;
    }
}
