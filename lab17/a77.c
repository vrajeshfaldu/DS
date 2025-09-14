#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Node{
    
    int info;
    struct Node *lptr;
    struct Node *rptr;
};

struct Node* insertNode(struct Node* root) {
    int data;
    printf("Enter the info (-1 for no node): ");
    scanf("%d", &data);

    if (data == -1) {
        return NULL;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = data;
    newNode->lptr = NULL;
    newNode->rptr = NULL;

    printf(" lptr of %d\n", data);
    newNode->lptr = insertNode(newNode->lptr);

    printf(" rptr of %d\n", data);
    newNode->rptr = insertNode(newNode->rptr);

    return newNode;
}
void preorderTraversal(struct Node *save){
    
    if(save==NULL){
        return;
    }
    printf("%d ",save->info);
    preorderTraversal(save->lptr);
    preorderTraversal(save->rptr);
}
bool isSymmentricHelp(struct Node* lptr , struct Node* rptr){

    if(lptr == NULL || rptr == NULL){
        return lptr == rptr;
    }
    else if(lptr->info != rptr->info){
        return false;   
    }

    return isSymmentricHelp(lptr->lptr,rptr->rptr) && isSymmentricHelp(lptr->rptr,rptr->lptr);
}

bool isSymmentric(struct Node* root){

   return root == NULL || isSymmentricHelp(root->lptr,root->rptr);
}   
void main(){
    struct Node *root=NULL;
   root= insertNode(root);
   preorderTraversal(root);
   if(isSymmentricHelp(root->lptr,root->rptr)){
    printf("Symmetric");
   }
   else{
    printf("not Symmetric");
   }
}
// 8 5 3 -1 -1 6 -1 -1 7 6 -1 -1 3 -1 -1
