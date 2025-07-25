#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *lptr;
    struct Node *rptr;
};

// struct Node *root = NULL;

// void constructTree(){
//     struct Node *N1 = (struct Node *)malloc(sizeof(struct Node));
//     N1->info = 1;
//     N1->lptr = NULL;
//     N1->rptr = NULL;

//     root = N1;

//     struct Node *N2 = (struct Node *)malloc(sizeof(struct Node));
//     N2->info = 2;
//     N2->lptr = NULL;
//     N2->rptr = NULL;

//     N1->lptr = N2;

//     struct Node *N3 = (struct Node *)malloc(sizeof(struct Node));
//     N3->info = 3;
//     N3->lptr = NULL;
//     N3->rptr = NULL;

//     N2->lptr = N3;

//     struct Node *N4 = (struct Node *)malloc(sizeof(struct Node));
//     N4->info = 4;
//     N4->lptr = NULL;
//     N4->rptr = NULL;

//     N2->rptr = N4;

//     struct Node *N5 = (struct Node *)malloc(sizeof(struct Node));
//     N5->info = 5;
//     N5->lptr = NULL;
//     N5->rptr = NULL;

//     N1->rptr= N5;
// }
struct Node * insertTree(struct Node *root){
    int n,x;
    printf("Enter info of tree:");
    printf("%d",&n);
    root= (struct Node *)malloc(sizeof(struct Node));
    printf("enter 1 for insert data in left or enter 2 for right insert otherwise -1:");
    scanf("%d",&x);
    if(x==-1){
        return NULL;
    } 
    else if(x==1){
    root ->lptr=insertTree(root->lptr);
    }
    else if(x==2){
        root ->lptr=insertTree(root->lptr);
    }
    return root;
}

void preorderTraversal(struct Node *save){
    
    if(save==NULL){
        return;
    }

    printf("%d ",save->info);
    preorderTraversal(save->lptr);
    preorderTraversal(save->rptr);

}
void inOrder(struct Node *save){

    if(save==NULL){
        return;
    }
 
    inOrder(save->lptr);
    printf("%d ",save->info);
    inOrder(save->rptr);

} 
void postOrder(struct Node *save){
    
    if(save==NULL){
        return;
    }
    
    postOrder(save->lptr);
    postOrder(save->rptr);
    printf("%d ",save->info);

} 
void displayTree(struct Node *root){

}

void main(){


    struct Node* root=NULL;
    insertTree(root);
    displayTree(root);
}

//       1
//     /  \/
//    2    5
//   / \/
//  3  4