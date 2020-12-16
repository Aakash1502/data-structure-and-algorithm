#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int stackTop(struct stack* sp){
    return sp->arr[sp->top];
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

int precedence(char ch){
    if (ch == '*' || ch == '/')
    {
        return 3;
    }
    else if (ch == '+' || ch == '-')
    {
        return 2;
    }
    else
    {
        return 0;
    }
    
}

int isOperator(char ch){
    if (ch == '*' || ch == '/' || ch == '+' || ch == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

char * infixtopostfix(char* infix){
    struct stack * sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char * postfix = (char *)malloc((strlen(infix)+1) * sizeof(char)); //it is an empty character array result postfix will be filled in this
    int i = 0; //track infix traversal
    int j = 0; // track postfix addition
    while (infix[i]!='\0')
    {
        if(!isOperator(infix[i])){
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else
        {
            if(precedence(infix[i])>precedence(stackTop(sp))){
                push(sp, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(sp);
                j++;
            }
            
        }
        
    }
    while (!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }

    postfix[j] = '\0';
    return postfix;
    
}

int main()
{
    char * infix = "a-b+t/6";
    printf("Postfix is %s", infixtopostfix(infix));
    return 0;
}
