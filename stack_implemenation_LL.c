#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*next;
}*top=NULL;

void push(int x){
    struct Node*t=(struct Node*)malloc(sizeof(struct Node));

    if(t==NULL){
        printf("Stack OVERflow");
        return;
    }
    t->data=x;
    t->next=top;
    top=t;
}

void pop(){
    int x=-1;
    if(top==NULL){
        printf("STack underflow");\
        return;
    }
    struct Node*t;
    t=top;
    top=top->next;
    free(t);
}
int countElements(){
    int count=0;
    struct Node*p;
    p=top;
     while(p!=NULL){
        count++;
        p=p->next;
    }
    return count;
}
void display(){
    struct Node*p;
    p=top;
    int count=countElements();
    int arr[count];

    for(int i=count;i>0;i--){
          arr[i]=p->data;
          p=p->next;  
    }
    
    for(int i=1;i<=count;i++){
         printf("%d\t",arr[i]);
    }
    
}

int main(){

push(10);
push(20);
pop();
display();

    return 0;
}