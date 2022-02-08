#include<stdio.h>
#include<stdlib.h>


struct Node{
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
}

void displayLinkedList(struct Node*p){
    while(p!=NULL){
        printf("%d\t",p->data);
        p=p->next;
    }
}


int countElements(struct Node*p){
    int count=0;
    while(p!=0){ 
        count++;
        p=p->next;
    }
    return count;
}

void insertElements(struct Node*p,int num,int pos){

     struct Node*t;

    if(pos<0 || pos>countElements(p)){
        printf("Enter a valid postion to insert");
        return;
    }

    else if(pos==0){
       t=(struct Node*)malloc(sizeof(struct Node));
       t->data=num;
       t->next=head;
       head=t;
    }
    else{
          t=(struct Node*)malloc(sizeof(struct Node));
          t->data=num;
          for(int i=0;i<pos-1;i++){
              p=p->next;
          }
          t->next=p->next;
          p->next=t;
    }

}

void InsertOnlyAtLast(int num){
    struct Node*t;
     t=(struct Node*)malloc(sizeof(struct Node));
     t->data=num;
     t->next=NULL;

     /*if(head==NULL){
         head=last=t;
     }

     else{*/
         /*while(p!=NULL){
             p=p->next;
         }
         p->next=t;*/
    // }
    last->next=t;
    last=t;
}

void InsertAtSortedList(struct Node*p,int num){
    struct Node*t,*q;
    t=(struct Node*)malloc(sizeof(struct Node));
     t->data=num;
     t->next=NULL;

     if(head==NULL){
         head=t;
     }
     else{
         while(p!=NULL && (p->data)<num){
             q=p;
             p=p->next;
         }
         if(p==head){
             t->next=head;
             head=t;
         }
         else{
             t->next=q->next;
             q->next=t;
         }
     }

}



int main(){

    printf("Enter the size of linked list");
    int n,add,pos,addLast,addsort;
    scanf("%d",&n);

    printf("Enter the elements u wana add in ur linked list");

    int arr[n];

    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    CreateLinkedList(arr,n);
    displayLinkedList(head);
    int count=countElements(head);
    printf("\n%d",count);

    printf("Enter the elements and the position u wana add in ur linked list");
    scanf("%d%d",&add,&pos);

    insertElements(head,add,pos);
    displayLinkedList(head);

   /* printf("Enter the elements u wana add at last in ur linked list");
    scanf("%d",&addLast);

    InsertOnlyAtLast(addLast);
    displayLinkedList(head);

    printf("Enter the elements u wana add at  in ur sorted linked list");
    scanf("%d",&addsort);

    InsertAtSortedList(head,addsort);
    displayLinkedList(head);*/




}