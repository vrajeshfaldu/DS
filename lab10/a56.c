#include<stdio.h>
    #include<stdlib.h>

    struct Node{
        int info;
        struct Node *link;
    };

    struct Node *first=NULL;
    void insertAtFirst(){    
        int n;
        printf("enter value of node:");
        scanf("%d",&n);
        struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
        newnode->info=n;
        newnode->link=first;
        first=newnode;
       
    }
     void display(){
         
         struct Node *save=first;
        while(save!=NULL){
            printf("%d",save->info);
            save=save->link;
        }
    }
     void main(){
     
       
        int x;
        scanf("%d",&x);
        int count=0;
        for(int i=1;i<=x;i++){
        insertAtLast();
        }
         display();
             
    }