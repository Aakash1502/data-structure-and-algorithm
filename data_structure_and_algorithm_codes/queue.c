#include <stdio.h>
#include <stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int* arr;
};

int isfull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}

int isempty(struct queue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}

void enque(struct queue *q, int val){
    if(isfull(q)){
        printf("queue is full");
    }
    else
    {
        q->r=q->r+1;
        q->arr[q->r] = val; 
    }
    
}

int deque(struct queue *q){
    int a=-1;
    if(isempty(q)){
        printf("queue is empty");
    }
    else
    {
        q->f++;
        return q->arr[q->f];
    }
    return a;
    
}

int main()
{
    struct queue q;
    q.size=100;
    q.f=q.r=-1;
    q.arr = (int*)malloc(q.size*sizeof(int));
    //enque few elements
    enque(&q, 12);// first in so first out(FIFO)
    enque(&q, 13);
    enque(&q, 14);
    deque(&q);
    
    return 0;
}
