// 48. Write a menu driven program to implement following operations on the 
// Doubled Ended Queue using an Array 
// • Insert at front end, Insert at rear end 
// • Delete from front end, Delete from rear end 
// • Display all elements of the queue

#include <stdio.h>

#define MAX 5

int dequeue[MAX];
int front = -1, rear = -1;
int currSize = 0;

void insertAtFront(int val){        

    if(front == 0 && rear != -1){
        printf("DoubleEnded Queue Is Full At Front.\n");
        return ;
    }

    if(front == -1){
        front = rear = 0;
    }
    else{
        front--;
    }

    dequeue[front] = val;
   
}

void insertAtLast(int val){         //InsertAtRear

   if(rear == MAX - 1){
        printf("DoubleEnded Queue Is Full At Rear.\n");
        return ;
   }

   if(front == -1){
        front = rear = 0;
   }
   else{
        rear++;
   }

   dequeue[rear] = val;

}

int deleteAtFront(){

    if(front == -1){
        printf("DoubleEnded Queue Is Empty.\n");
        return -1;
    }
    
    int val = dequeue[front];

    if(rear == front){
        rear = front = -1;
   }
   else{
        front++;
   }

    return val; 
    
   
}
int deleteAtLast(){

   if(rear == -1){
    printf("DoubleEnded Queue Is Empty.\n");
    return -1;
   }

    int val = dequeue[rear];

   if(rear == front){
        rear = front = -1;
   }
   else{
        rear--;
   }

    return val; 
}

void display(){
   
    if(front == -1){
        printf("DoubleEnded Queue Is Empty.\n");
        return;
    }

    printf("Deque: ");
    for(int i=front ; i<=rear ; i++){
        printf("%d ",dequeue[i]);
    }
    printf("\n");
}

void main(){

    int choice, val;
    do {
       
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete at Front\n");
        printf("4. Delete at Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: printf("Enter value: "); scanf("%d",&val); insertAtFront(val); break;
            case 2: printf("Enter value: "); scanf("%d",&val); insertAtLast(val); break;
            case 3: printf("Deleted %d\n", deleteAtFront()); break;
            case 4: printf("Deleted %d\n", deleteAtLast()); break;
            case 5: display(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }

    } while(choice!=6);

}
