#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*next;
}*head,*last;

void CreateLinkedList(int arr[],int n){
    struct Node*t;

    head=(struct Node*)malloc(sizeof(struct Node));
    head->data=arr[0];
    head->next=NULL;

    last=head;

    for(int i=1;i<n;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=arr[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void displayLinkedList(struct Node*p){
    while(p!=NULL){
        printf("%d\t",p->data);
        p=p->next;
    }
}

void reverseLinkedList(struct Node*p,int n){

    int arr[n];
   
    for(int i=n-1;i>=0;i--){
       arr[i]=p->data;
       p=p->next;
    }
   
    p=head;
    for(int j=0;j<n;j++){
        p->data=arr[j];
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


printf("\n");
reverseLinkedList(head,n);
printf("\n");
displayLinkedList(head);

    return 0;
}