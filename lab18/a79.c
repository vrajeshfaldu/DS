// 79. Write a program to construct a binary tree from given Postorder and Preorder 
// traversal sequence. 

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

int preIdx =0;
int postIdx =0;

struct TreeNode* buildTreeByPrePos(struct TreeNode* root , int preorder[] , int postorder[]) {

    root = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    root->data = preorder[preIdx++];
    root->left = NULL;
    root->right = NULL;

   if(root->data!=postorder[postIdx]){
        root->left = buildTreeByPrePos(root->left,preorder,postorder);
   }
   if(root->data!=postorder[postIdx]){
        root->right = buildTreeByPrePos(root->right,preorder,postorder);
   }
   postIdx++;

   return root;
}   

void inOrderTraversal(struct TreeNode* root){

    if(root != NULL){
        inOrderTraversal(root->left);
        printf("%d ",root->data);
        inOrderTraversal(root->right);        
    }
}

void main(){

    struct TreeNode* root = NULL;    

    int preorder[] = {10,5,3,1,7,15,13,18};
    int postorder[] = {1,3,7,5,13,18,15,10};
   
    root = buildTreeByPrePos(root , preorder,postorder);         

    printf("root  : \n");
    inOrderTraversal(root);
    printf("\n");        
        
// 3 9 -1 -1 20 15 -1 -1 7 -1 -1 (Balanced)
// 1 2 3 4 -1 -1 4 -1 -1 3 -1 -1 2 -1 -1 (Not Balanced)

//      1
//     / \
//    2   5
//   / \
//  3   4

}
