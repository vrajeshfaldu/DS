#include <stdio.h>
#include <stdlib.h>

struct Node{
    
    int info;
    struct Node *lptr;
    struct Node *rptr;
};

struct Node* insertNode(struct Node* root) {
    int data;
    printf("Enter the data (-1 for no node): ");
    scanf("%d", &data);

    if (data == -1) {
        return NULL;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = data;
    newNode->lptr = NULL;
    newNode->rptr = NULL;

    printf(" left of %d\n", data);
    newNode->lptr = insertNode(newNode->lptr);

    printf(" right of %d\n", data);
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
int com(struct Node *root,struct Node *root2){
    if(root==NULL || root2==NULL){
        return root==root2;
    }
    return (root->info==root2->info) && com(root->lptr,root2->lptr) && com(root->rptr,root2->rptr);

}
void main(){


    struct Node* root=NULL;
    root=insertNode(root);
    struct Node* root2=NULL;
    printf("second tree");
    root2=insertNode(root2);
    preorderTraversal(root2);
    int result;
    result=com(root,root2);
    printf("tree is=%d",result);
}
//       1
//     /  \/
//    2    5
//   / \/    \/
//  3  4      6