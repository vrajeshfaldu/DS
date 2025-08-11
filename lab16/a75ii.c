#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node *lptr;
    struct Node *rptr;
};

struct Node* insertTree(struct Node *root, int n) {
    if (root == NULL){
        root = (struct Node *)malloc(sizeof(struct Node));
        root->info = n;
        root->lptr = NULL;
        root->rptr = NULL;
        return root;
    }

    if(n<root->info){

        printf("Insert lptr of %d\n", root->info);
        root->lptr = insertTree(root->lptr, n);

    }

    else if(n > root->info){

        printf("Insert rptr of %d\n",root->info);
        root->rptr=insertTree(root->rptr,n);

    }
    
    return root;
}
// 1st method
struct Node * delete(struct Node *root,int n){

    if(root==NULL){
        return root;
    }
    else if(n<root->info){
        root->lptr=delete(root->lptr,n);
    }
    else if(n>root->info){
        root->rptr=delete(root->rptr,n);
    }
    else{
        // if(root->lptr == NULL && root->rptr == NULL){  
        //     return NULL;

        // }
        struct Node *temp=root->rptr;
        struct Node *dummy=root;
        root=root->lptr;
        free(dummy);
        struct Node *curr=root;


        while(curr->rptr!=NULL){
            curr=curr->rptr;
        }
        curr->rptr=temp;
    }
    return root;
}
// 2nd method 
struct Node* deleteNode(struct Node* root, int info) {

    if (root == NULL){
        return root;
    }

    if (info < root->info){
        root->lptr = deleteNode(root->lptr, info);
    } 

    else if (info>root->info){
        root->rptr = deleteNode(root->rptr, info);
    } 

    else {     // info match thai gyo

        if(root->lptr == NULL && root->rptr == NULL){
            return NULL;
        }

        else if (root->lptr == NULL) {              // only rptr child
            struct Node* temp = root->rptr;
            free(root);
            return temp;              // rptr child 
        } 

        else if (root->rptr == NULL) {           // only lptr child
            struct Node* temp = root->lptr;
            free(root);
            return temp;
        }

        struct Node* temp = root->rptr;
        while (temp!=NULL && temp->lptr != NULL) {
            temp = temp->lptr;
        }
        root->info = temp->info;
        root->rptr = deleteNode(root->rptr, temp->info);
    }
   return root;
}

struct Node * search(struct Node *root,int n){
    
    if( n <root->info){
        root->lptr = search(root->lptr, n);
    }
     else if( n >root->info){
        root->rptr = search(root->rptr, n);
     }
     else if(root==NULL){
        printf("your element is not available in tree");
    }
    else{
        printf("your element is  available in tree");
    }
   
}

void displayTree(struct Node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->info);
    displayTree(root->lptr);
    displayTree(root->rptr);
}

void main() {
    struct Node* root = NULL;
    int n;

    printf("Enter elements (-1 to stop):\n");
    while (1){
        printf("Enter info of node: ");
        scanf("%d", &n);
        if (n == -1) break;
        root = insertTree(root,n);
    }

    printf("\npreorder Tree:\n");
     displayTree(root);

    int p;
    printf("\nEnter number which you want to delete:");
    scanf("%d",&p);
    // deleteNode(root,p);
    delete(root,p);
    displayTree(root);
}
