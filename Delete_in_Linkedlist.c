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

void deleteLinkedList(struct Node*p,int index){

struct Node*q;


    if(index==1){
        q=head;
        head=head->next;
        free (q);        
        
    }
    else{
        for(int i=0;i<index-1;i++){
              q=p;
              p=p->next;
        }
        q->next=p->next;
        free (p);
      
    }
}

void displayLinkedList(struct Node*p){
    while(p!=NULL){
        printf("%d\t",p->data);
        
        p=p->next;
    }
    printf("\n");
}
void remove_duplicates(struct Node*p){
    struct Node*q;

    q=head->next;

while(q!=NULL){ 
    if((p->data)==(q->data)){
        p->next=q->next;
        free(q);
        q=p->next;
    }
    else{
        p=q;
        q=q->next;
    }
}
}


int main(){
        printf("Enter the size of linked list");
    int n,index,dele;
    scanf("%d",&n);

    printf("Enter the elements u wana add in ur linked list");

    int arr[n];

    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    CreateLinkedList(arr,n);
    displayLinkedList(head);

    
   /* printf("Enter the elements u wana delete in which position in ur linked list");
    scanf("%d",&index);
    
    deleteLinkedList(head,index);
    displayLinkedList(head);*/

    remove_duplicates(head);
    displayLinkedList(head);
}