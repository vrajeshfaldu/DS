// Write a program to create a graph & implement the adjacency list representation of the graph
// Apply dfs and BFS on the given graph.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 20

struct Node {
    int info;
    struct Node* next;
};

void addEdge(struct Node **adjList, int src, int dest){

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = dest;
    newNode->next = adjList[src];
    adjList[src] = newNode;

    // undirected graph
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = src;
    newNode->next = adjList[dest];
    adjList[dest] = newNode;
}

void displayGraph(struct Node **adjList, int V){

    for(int i = 0; i < V; i++){
        struct Node* curr = adjList[i];
        printf("Vertex %d: ", i);
        while(curr){
            printf("%d -> ", curr->info);
            curr = curr->next;
        }
        printf("NULL\n");
    }
}

void dfsUtil(struct Node **adjList, int v, int visited[]){

    visited[v] = 1;
    printf("%d ", v);

    struct Node* curr = adjList[v];
    while(curr){
        if(!visited[curr->info]){
            dfsUtil(adjList, curr->info, visited);
        }
        curr = curr->next;
    }
}

void dfs(struct Node **adjList, int V, int start){

    int visited[MAX] = {0};
    dfsUtil(adjList, start, visited);
}

void push(int queue[], int *rear, int value){

    queue[++(*rear)] = value;
}

int pop(int queue[], int *front, int rear){
    
    if(*front > rear){
        return -1; // Queue is empty
    }
    return queue[(*front)++];
}

bool isEmpty(int front, int rear){
    return front > rear;
}

void bfs(struct Node **adjList, int V, int start){

    int visited[MAX] = {0};
    int queue[MAX];
    int front = 0, rear = -1;

    visited[start] = 1;
    push(queue, &rear, start);

    while(!isEmpty(front, rear)){
        int v = pop(queue, &front, rear);
        printf("%d ", v);

        struct Node* curr = adjList[v];
        while(curr){
            if(!visited[curr->info]){
                visited[curr->info] = 1;
                push(queue, &rear, curr->info);
            }
            curr = curr->next;
        }
    }
}

int main(){

    int V=5;

    // adjList usinng malloc
    struct Node **adjList = (struct Node**)malloc(V * sizeof(struct Node*));

    for(int i = 0; i < V; i++){
        adjList[i] = NULL;
    }

    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 4);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 1, 4);
    addEdge(adjList, 2, 3);
    addEdge(adjList, 3, 4);

    displayGraph(adjList, V);

    printf("DFS starting from vertex 0:\n");
    dfs(adjList, V, 0);

    printf("\nBFS starting from vertex 0:\n");
    bfs(adjList, V, 0);

    return 0;
}
