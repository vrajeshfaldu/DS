#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node *lptr;
    struct Node *rptr;
};

struct Node* insertTree(struct Node *root, int n) {
    if (root == NULL) {
        root = (struct Node *)malloc(sizeof(struct Node));
        root->info = n;
        root->lptr = NULL;
        root->rptr = NULL;
        return root;
    }

    if (n < root->info) {
        printf("Insert left of %d\n", root->info);
        root->lptr = insertTree(root->lptr, n);
    } else if (n > root->info) {
        printf("Insert right of %d\n", root->info);
        root->rptr = insertTree(root->rptr, n);
    }

    return root;
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
    while (1) {
        printf("Enter info of node: ");
        scanf("%d", &n);
        if (n == -1) break;
        root = insertTree(root, n);
    }

    printf("\npreorder Tree:\n");
    displayTree(root);
}
