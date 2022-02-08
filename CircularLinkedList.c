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
    last->next=head;
}

void deleteLinkedList(struct Node*p,int pos){
   struct Node*q;
    if(pos==1){
        if(head->next==head){
             free (head);
             head=NULL;
        }
        else{
            last->next=head->next;
            head=head->next;
            free (p);
        }
    }
    else{
        for(int i=0;i<pos-1;i++){
            q=p;
            p=p->next;
        }
        q->next=p->next;
        free(p);
    }
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

void displayLinkedList(struct Node*p){


    do{
        printf("%d\t",p->data);
        p=p->next;
    }while(p!=head);
    printf("\n");
}

void insertElements(struct Node*p,int num,int pos){

struct Node*t=(struct Node*)malloc(sizeof(struct Node));
 t->data=num;
    if(pos==0){

        if(head==NULL){
            
            head=t;
            head->next=head;
        }
        else{ 
      
       t->next=head;
       last->next=t;
       head=t;
        }
    }
    else{
       for(int i=0;i<pos-1;i++){
           p=p->next;
       }
       t->next=p->next;
       p->next=t;
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

   ifLoop(head);

  insertElements(head,4,4);
  displayLinkedList(head);
  deleteLinkedList(head,1);
  



    

}
