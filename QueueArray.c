#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int size;
    int front;
    int rear;
    int *arr;
};


void createQueue(struct Queue*q,int n){

    q->size=n;
    q->front =q->rear=-1;
    q->arr=(int *)malloc(q->size*(sizeof(int)));

    }

void enQueue(struct Queue*q,int x){
  if(q->rear==q->size-1){
      printf("its full");
  }
  else{
      q->rear++;
      q->arr[q->rear]=x;
  }
}

int DeQueue(struct Queue *q){
    int x=-1;
    if(q->rear==q->front){
        printf("its empty");
    }
    else{
        q->front++;
        x=q->arr[q->front];

    }
    return x;
}

void display(struct Queue*q){

    for(int i=q->front+1;i<=q->rear;i++){
        printf("%d",q->arr[i]);
    }
}

int main(){
struct Queue q;
    createQueue(&q,5);
    enQueue(&q,2);
    enQueue(&q,3);
    DeQueue(&q);
    display(&q);
}