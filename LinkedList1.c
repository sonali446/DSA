#include<stdio.h>
#include<stdlib.h>

struct Node{

    int data;
    struct Node*next;
}*head;


void CreateLinkedList(int arr[],int size){

head= (struct Node*)malloc(sizeof(struct Node));

struct Node *last,*t;

head->data=arr[0];
head->next=NULL;

last=head;

for(int i=1;i<10;i++){
    t=(struct Node*)malloc(sizeof (struct Node));

    t->data=arr[i];
    t->next=NULL;
    last->next=t;
    last=t;
}


}

void display(struct Node*p){
int count=0;
int sum=0;
    while(p!=NULL){
        printf("%d ",p->data);
        count++;
       
        sum=sum+p->data;
        
        p=p->next;
    }
 printf("\nTotal Number of Elements %d ",count);
printf("\nTotal sum of Elements %d ",sum);
}

//To find the max element in an list

void FindMaxElement(struct Node*p){

int max=0;
while(p!=NULL){
    if(p->data>max){
        max=p->data;
        p=p->next;
    }
}
printf("\nThe largest element is %d",max);
}

struct Node* SearchElemen(struct Node*p,int num){
    while(p!=NULL)
{
    if(p->data==num){
        return p;
    }
    p=p->next;

}
return NULL;
}


int main(){

int arr[]={1,2,3,4,5,6,7,8,9,10};

CreateLinkedList(arr,10);
display(head);
FindMaxElement(head);

int *pos=SearchElemen(head,6);
printf("\nThe element is foud at position %d",(pos));

    return 0;
}