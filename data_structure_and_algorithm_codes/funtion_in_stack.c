#include <stdio.h>
#include <stdlib.h>

//CREATION OF STACK
struct stack{
    int size;
    int top;
    int * arr;
};

//CHECKS IF THE STACK IS EMPTY
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//CHECKS IF THE STACK IS FULL
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//PUSHES AN ELEMENT ON THE TOP OF STACK
void push(struct stack * ptr,int val){
    if(isFull(ptr)){
        printf("Not possible, the stack is full\n");
    }
    else
    {
        ptr->top++; //increase the top pointer by 1
        ptr->arr[ptr->top]=val; //assign the value to the top pointer
    }
    
}

//DELETES THE TOPMOST ELEMENT FROM STACK
int pop(struct stack * ptr){
    if(isempty(ptr)){
        printf("Not possible, the stack is empty\n");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top]; //stores the top value in variable val
        ptr->top=ptr->top-1; //decrease the top pointer by 1
        return val; //returns the top value(top value removed)
    }
    
}

//peek at a position in stack and tells us which element is there in that position
int peek(struct stack* sp, int i){
    int arrayInd = sp->top -i + 1;
    if(arrayInd < 0){
        printf("Not a valid position for the stack\n");
        return -1;
    }
    else{
        return sp->arr[arrayInd];
    }
}

int stackTop(struct stack* sp){
    return sp->arr[sp->top];
}

int stackBottom(struct stack* sp){
    return sp->arr[0];
}



int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size=10;  //gives size to the stack
    sp->top=-1;  //assign top value to -1 which means the stack is empty 
    sp->arr=(int *)malloc(sp->size * sizeof(int));  //creates an array of size of size of stack
    return 0;
}

