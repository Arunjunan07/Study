#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
	int data;
	struct TreeNode *left;
	struct TreeNode *right;
	int height;
} Node;

int getHeight(Node *n) {
	if(n==NULL)
		return -1;
	return n->height;
}

Node *createNode(int d) {
	Node* newNode = (Node *) malloc(sizeof(Node));
	newNode->data = d;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->height = 0;
	return newNode;
}

int max (int a, int b) {
	return (a>b)?a:b;
}

int getBalanceFactor(Node * n){
if(n==NULL){
return 0;
}
return getHeight(n->left) - getHeight(n->right);
}

Node* rightRotate(Node* y){
Node* x = y->left;
Node* T2 = x->right;

x->right = y;
y->left = T2;

x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

return x;
}

Node* leftRotate(Node* x){
Node* y = x->right;
Node* T2 = y->left;

y->left = x;
x->right = T2;

x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

return y;
}

Node* insert(Node* root, int x) {
	if (root == NULL)
		return createNode(x);

	if (x < root->data)
		root->left = insert(root->left, x);
	else if (x > root->data)
		root->right = insert(root->right, x);

	root->height = 1 + max(getHeight(root->left), getHeight(root->right));
	int bf = getBalanceFactor(root);

// LL Case
	if(bf>1 && x < root->left->data) {
		return rightRotate(root);
	}

// LR Case
	if(bf>1 && x > root->left->data) {
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	
// RR Case
	if(bf<-1 && x > root->right->data) {
		return leftRotate(root);
	}
	
// RL Case
	if(bf<-1 && x < root->right->data) {
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	
	return root;
}

void inOrder(Node *root)
{
	if(root != NULL)
	{
		inOrder(root->left);
		printf("%d height is %d \n", root->data,getBalanceFactor(root));
		inOrder(root->right);
	}
}

int main() {
	Node* root = createNode(50);
	root = insert(root, 20);
	root = insert(root, 60);
	root = insert(root, 10);
	root = insert(root, 30);
	root = insert(root, 40);

	inOrder(root);
	return 0;
}