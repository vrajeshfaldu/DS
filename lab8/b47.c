// 47. Write a menu driven program to implement following operations on a circular 
// queue using an Array 
// • Insert 
// • Delete 
// • Display all elements of the queue 

#include <stdio.h>

#define cap 5

int queue[cap];
int currSize = 0 , front = -1, rear = -1;

void enqueue(int val){      //insert

    if(currSize == cap){
        printf("Queue Is OverFlow.\n");
        return;
    }

    rear++;
    rear = rear % cap;          // move rear circularly

    queue[rear] = val;

    currSize++;

    printf("%d Is Enqueue.\n",val);
    
}

void dequeue(){         //delete
    
    if(currSize == 0){
        printf("Queue Is Empty.\n");
        return;
    }
    
    printf("%d Is Dequeue.\n",queue[front++]);

    front = front % cap;            // move front circularly

    currSize--;

}

void display(){

   if(currSize == 0){
    printf("Queue Is Empty.\n");
   }

   int count , i;

   for(i=front , count = 0 ; count < currSize ; count++){

        printf("%d ", queue[i]);
        i = (i + 1) % cap;   // circular movement

    }

    printf("\n");
}

void main(){

    int choice, val;
    while(1){
        
        printf("1. ENQUEUE\n");
        printf("2. DEQUEUE\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter value to Enqueue: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting..!\n");
                return;
            default:
                printf("Invalid Choice!\n");
    }
    }
}
