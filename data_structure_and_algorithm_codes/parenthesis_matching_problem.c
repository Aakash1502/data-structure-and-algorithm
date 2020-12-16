
#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

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
void push(struct stack * ptr,char val){
    if(isFull(ptr)){
        printf("Not possible, the stack is full\n");
    }
    else
    {
        ptr->top++; //increase the top pointer by 1
        ptr->arr[ptr->top]=val; //assign the value to the top pointer
    }
    
}

char pop(struct stack * ptr){
    if(isEmpty(ptr)){
        printf("Not possible, the stack is empty\n");
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top]; //stores the top value in variable val
        ptr->top=ptr->top-1; //decrease the top pointer by 1
        return val; //returns the top value(top value removed)
    }
    
}

int parenthesismatch(char * exp){
    struct stack* sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    for (int i = 0;exp[i]!='\0'; i++)
    {
        if (exp[i]=='(')
        {
            push(sp, '(');
        }
        else if (exp[i]==')')
        {
            if (isEmpty(sp)){
                return 0;
            }
            pop(sp);
        }
        
        
    }
    if(isEmpty(sp)){
        return 1;
    }
    else
    {
        return 0;
    }
    
    
}

int main()
{
    char * exp = "8*(9)";
    if(parenthesismatch(exp)){
        printf("The parenthesis is matching");
    }
    else
    {
        printf("The parenthesis is not matching");
    }
    return 0;
}