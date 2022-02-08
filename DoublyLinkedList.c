#include<stdio.h>
#include<stdlib.h>


struct Node{
    struct Node*prev;
    int data;
    struct Node*next;
}*head,*last;

void CreateLinkedList(int arr[],int n){
    struct Node*t;

    head=(struct Node*)malloc(sizeof (struct Node));
    head->data=arr[0];
    head->prev=head->next=NULL;
    last=head;

    for(int i=1;i<n;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=arr[i];
        t->next=NULL;
        last->next=t;
        t->prev=last;
        last=t;
    }
}

void insertElements(struct Node*p,int num,int pos){
    struct Node*t=(struct Node*)malloc(sizeof(struct Node));

    t->data=num;

    if(pos==0){
        head->prev=t;
        t->next=head;
        t->prev=NULL;
        head=t;
        
    }
    else{
        for(int i=0;i<num-2;i++){
            p=p->next;
        }
        t->next=p->next;
        t->prev=p;
        p->next=t;

        if(p->next!=NULL){
            p->next->prev=t;
        }
    }
}

void deleteElements(struct Node*p,int pos){

    struct Node*q;

    if(pos==1){
         head=head->next;
         free(p);
         head->prev=NULL;
    }
    else{

        for(int i=0;i<pos-1;i++){
            q=p;
            p=p->next;
        }
        q->next=p->next;
        if(p->next!=NULL){
            p->next->prev=q;
        }
        free(p);
    }
}

void displayLinkedList(struct Node*p){
    
    while(p!=NULL){
        printf("%d\t",p->data);
        p=p->next;
    }
}

int main(){

     printf("Enter the size of linked list");
    int n;
    scanf("%d",&n);

    printf("Enter the elements u wana add in ur linked list");

    int arr[n];

    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    CreateLinkedList(arr,n);
    displayLinkedList(head);
 
    printf("Enter the element and pos u wana add in ur linked list");
    int add,addpos;
    scanf("%d%d",&add,&addpos);

    insertElements(head,add,addpos);
    displayLinkedList(head);

    printf("Enter the pos u wana delete in ur linked list");
    int del;
    scanf("%d",&del);

    deleteElements(head,del);
    displayLinkedList(head);

    return 0;
}