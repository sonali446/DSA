#include <stdio.h>
#include <stdlib.h>


struct Stack{
    int size;
    int top;
    int *s;
};

void createStack(struct Stack *stack,int n){

//stack=(struct Stack*)malloc(sizeof(struct Stack));
stack->size=n;
stack->top=-1;
stack->s=(int*)malloc(stack->size*(sizeof(int)));

}

void push(struct Stack *stack,int x){
    if(stack->top==stack->size-1){
        printf("OVERFLOW");
    }
    else{
        stack->top++;
        stack->s[stack->top]=x;
    }
    
}

void pop(struct Stack *stack){
    if(stack->top==-1){
        printf("UNDERFLOW");

        return;
    }
    stack->top--;
}

void display(struct Stack *stack){
    for(int i=0;i<=stack->top;i++){
        printf("%d\t",stack->s[i]);
    }
}

int isEmpty(struct Stack *stack){
    if(stack->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct Stack *stack){
    if(stack->top==stack->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int findingElementAtIndex(struct Stack *stack,int pos){
int x=-1;
    if((stack->top-pos)+1 < 0){
        printf("invalid index");
        return 0;
    }
    else{
      x=stack->s[(stack->top-pos)+1];
      return x;
    }
}


int main(){

struct Stack stack;
int n;
printf("Enter the size of stack");
scanf("%d",&n);
createStack(&stack,n);
push(&stack,1);
push(&stack,2);
push(&stack,3);
push(&stack,4);
push(&stack,5);
display(&stack);
printf("\n");
display(&stack);
if(isEmpty(&stack)){
    printf("YES IT IS EMPTY");
}
else{
     printf("No IT IS NOT EMPTY");
}

if(isFull(&stack)){
     printf("YES IT IS FULL");
}
else{
    printf("No IT IS NOT FULL");
}

int element=findingElementAtIndex(&stack,3);
printf("The element at index 3 is %d",element);
    return 0;
}