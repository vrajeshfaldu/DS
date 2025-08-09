#include <stdio.h>
#include <stdlib.h>

struct Node{
    
    int info;
    struct Node *lptr;
    struct Node *rptr;
};


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
\

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