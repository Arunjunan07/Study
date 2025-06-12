#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} Node;


Node* createNode(int d) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = d;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertLeft(Node* r, int val) {
    Node* newNode = createNode(val);
    r->left = newNode;
}

void insertRight(Node* r, int val) {
    Node* newNode = createNode(val);
    r->right = newNode;
}

Node* deleteLeaves(Node* root, int x) {
    if (root == NULL) 
        return NULL; 
    root->left = deleteLeaves(root->left, x); 
    root->right = deleteLeaves(root->right, x); 
    if (root->data == x && root->left == NULL && root->right == NULL) { 
        free(root);
        return NULL; 
    } 
    return root; 
}

void preOrder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    Node *root = createNode(3);
    insertLeft(root, 10);
    insertRight(root, 12);
    insertRight(root->right, 18);
    insertLeft(root->right, 14);
    
    printf("PreOrder: ");
    preOrder(root);
    printf("\n");
    
    printf("InOrder: ");
    inOrder(root);
    printf("\n");
    
    printf("PostOrder: ");
    postOrder(root);
    printf("\n");
    
    root = deleteLeaves(root, 14);
    
    printf("InOrder: ");
    inOrder(root);
    printf("\n");
    
    return 0;
}
