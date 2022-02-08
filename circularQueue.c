#include<stdio.h>
#include<stdlib.h>


struct Queue{
    int size;
    int front;
    int rear;
    int *arr;
};

void createQueue(struct Queue *q,int n){

    q->size=n;
    q->rear=q->front=-1;
    q->arr=(int*)malloc(q->size*sizeof(int));

}


void enQueue(struct Queue*q,int x){
    if(q->front==(q->rear+1)%q->size){
        printf("is full");
    }
    else{

        if(q->front==-1){
           q->front=0;
        }
      
        q->rear=(q->rear+1)%q->size;
        q->arr[q->rear]=x;
       
    }
}

int DeQueue(struct Queue*q){
    int x=-1;
    if(q->front==-1){
        printf("is empty");
    }
    else{
        x=q->arr[q->front];
        if(q->front==q->rear){
            q->front=-1;
            q->rear=-1;
        }
        else{ 
        q->front=(q->front+1)%q->size;
        }
    }
    return x;
}

void display(struct Queue*q){
    if(q->front==-1){
        printf("is empty");
    }
else{

for(int i=q->front;i!=q->rear;i=(i+1)%q->size){
        printf("%d\t",q->arr[i]);
    }
    printf("%d",q->arr[q->rear]);
    printf("\n");
}
    
}

int main(){
struct Queue q;
createQueue(&q,5);
enQueue(&q,1);
enQueue(&q,2);
enQueue(&q,3);
enQueue(&q,4);
enQueue(&q,5);

display(&q);
enQueue(&q,6);
/*DeQueue(&q);
DeQueue(&q);
DeQueue(&q);
DeQueue(&q);
DeQueue(&q);

display(&q);*/


    return 0;
}