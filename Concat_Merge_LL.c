#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*next;
}*head,*last, *head2,*last2;

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

void CreateLinkedList2(int arr2[],int m){
    struct Node*t;

    head2=(struct Node*)malloc(sizeof(struct Node));
    head2->data=arr2[0];
    head2->next=NULL;

    last2=head2;

    for(int i=1;i<m;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=arr2[i];
        t->next=NULL;
        last2->next=t;
        last2=t;
    }
}


void displayLinkedList(struct Node*p){
    while(p!=NULL){
        printf("%d\t",p->data);
        p=p->next;
    }
    printf("\n");
}

void concatenateList(struct Node*p,struct Node*q){

    while(p->next!=NULL){
        p=p->next;
    }

    p->next=q;
}

void mergeSortedList(struct Node*p,struct Node*q){
    struct Node* last;
    if(p->data < q->data){
        last=p;
        p=p->next;
    }
    else{
        last=q;
        q=q->next;
    }

 while(p && q){

        if(p->data < q->data){
             last->next=p;
             p=p->next;
             last=p;
             last->next=NULL;

        }
        else{
            last->next=q;
            q=q->next;
            last=q;
             last->next=NULL;

        }
    }

    if(p!=NULL){
        last->next=p;
    }
    else if(q!=NULL){
        last->next=q;
    }
}

void ifLoop(struct Node*p){

struct Node*q=p;

do{
    p=p->next;
    q=q->next;
    q=q!=NULL?q=q->next:NULL;
}while(p!=q);
if(p==q){
    printf("YES there exits a loop");
}
else{
  printf("NO there is no loop");
}
  
   

}



int main(){
    
    
    printf("Enter the size of linked list 1 and 2");
    int n,m;
    scanf("%d%d",&n,&m);

    printf("Enter the elements u wana add in ur linked list");

    int arr[n],arr2[m];


    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

     printf("Enter the elements u wana add in ur 2nd linked list");


    for(int i=0;i<m;i++){
        scanf("%d",&arr2[i]);
    }


CreateLinkedList(arr,n);
displayLinkedList(head);
CreateLinkedList2(arr2,m);
displayLinkedList(head2);



 //concatenateList(head,head2);


mergeSortedList(head,head2);
printf("\n");
displayLinkedList(head);

//struct Node*t1,*t2;
//t1=head->next->next;
//t2=head->next->next->next;
//t2->next=t1;

//ifLoop(head);
}