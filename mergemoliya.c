#include<stdio.h>
#include<stdlib.h>
// merge n list
struct node{
    int info;
    struct node * link;
};

void insertEnd(struct node * arr[],int n){
    int add;
    for(int i=0;i<n;i++){
        add = 0;
        struct node * save = NULL;
    printf("Enter info for list no.%d\n",i+1);
        while(1){
            printf("Enter info to be added (or -1 to end) : ");
            scanf("%d",&add);
            if(add == -1)break;
            if(arr[i] == NULL){
                arr[i] = (struct node *)malloc(sizeof(struct node));
                arr[i]->info = add;
                arr[i]->link = NULL;
                save = arr[i];
            }else{
                struct node * newNode = (struct node * )malloc(sizeof(struct node));
                save->link = newNode;
                newNode->info = add;
                newNode->link = NULL;
                save = newNode;
            }
        }
    }
}

void merge(struct node * arr[],int n){
    struct node * save = NULL;
    for(int i=0;i<n-1;i++){
    save = arr[i];
        while (save->link != NULL)
    {
        save = save->link;
    }
    save->link = arr[i+1];
    }
}

             
void sort(struct node * save){
    struct node * temp = save;
    int temper=0;
    while(save != NULL){
        temp = save->link;
        while(temp != NULL){
            if(temp->info < save->info){
                temper = save->info;
                save->info = temp->info;
                temp->info = temper;
            }
            temp = temp->link;
        }
        save = save->link;
    }
}

void display(struct node * save)
{
    while (save != NULL)
    {
        printf("%d ",save->info);
        save = save->link;
    }
    printf("\n");
}

void main(){
    printf("enter no of list you wanna create : ");
    int n;
    scanf("%d",&n);
    struct node * array[n];
    for(int i=0;i<n;i++){
        array[i] = NULL;
    }
    insertEnd(array,n);
    merge(array,n);
    // for(int i=0;i<n;i++){
    //     display(array[i]);
    // }
    sort(array[0]);
    display(array[0]);
}