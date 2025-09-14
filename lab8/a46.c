// Write a menu driven program to implement following operations on the Queue using an Array

// ENQUEUE
// DEQUEUE
// DISPLAY

#include <stdio.h>
#include <stdlib.h>
#define MAX 100


int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue is full!\n");
    } else {
        if (front == -1) {
            front = 0; // Initialize front if queue was empty
        }
        rear++;
        queue[rear] = value;
        printf("Enqueued: %d\n", value);
    }
}

void dequeue() {

    if (front == -1 ) {
        printf("Queue is empty!\n");
    } else {
        printf("Dequeued: %d\n", queue[front]);
        front++;
        if (front > rear) { // Reset queue if it becomes empty
            front = rear = -1;
        }
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    printf("\nMenu:\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Exit\n");

    while (1) {
        
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
