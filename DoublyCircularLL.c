#include<stdio.h>
#include<stdlib.h>


struct Node{
    struct Node*prev;
    int data;
    struct Node*next;
}*head,*last;

void CreateLinkedList(int arr[],int n){


    struct Node*temp;

    head=(struct Node*)malloc(sizeof(struct Node));

    head->data=arr[0];
    head->next=NULL;
    last=head;


    for(int i=1;i<n;i++){
        temp=(struct Node*)malloc(sizeof(struct Node));

        temp->data=arr[i];
        temp->next=NULL;
        last->next=temp;
        last=temp;
       
    }
    last->next=head;
    head->prev=last;
}

void insertElements(struct Node*p,int num,int pos){
    struct Node*t=(struct Node*)malloc(sizeof(struct Node));

    t->data=num;
    if(pos>1){
        for(int i=0;i<pos-2;i++){
            p=p->next;
        }
        t->next=p->next;
        t->prev=p;
        p->next=t;
        p->next->prev=t;
        
    }
    else{
        t->next=head;
        last->next=t;
        t->prev=last;
        head->prev=t;
        head=t;
    }

}

void deleteElements(struct Node*p,int pos){
    struct Node*q;

    if(pos==1){
        head=head->next;
        free(p);
        last->next=head;
        head->prev=last;
       
        
    }
    else{
        for(int i=0;i<pos-1;i++){
            q=p;
            p=p->next;
        }
        q->next=p->next;
        p->next->prev=q;
        free(p);
    }
}

void displayLinkedList(struct Node*p){


    do{
        printf("%d\t",p->data);
        p=p->next;
    }while(p!=head);
    printf("\n");
}
void ifLoop(struct Node*p){

struct Node*q=head;
    
while(p && q && q->next){
        p=p->next;
        q=q->next->next;
        if(p==q){
    printf("YES there exits a loop");
    return;
}
}
  printf("NO there is no loop");  
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

   // ifLoop(head);

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


}