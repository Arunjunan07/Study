
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int data;
	struct TreeNode *left;
	struct TreeNode *right;
}Node;

Node* createNode(int d) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = d;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

Node* search(Node * root, int x) {
	if (root == NULL || root->data == x)
		return root;
	else if (x > root->data)
		return search(root->right, x);
	else
		return search(root->left, x);
}

Node* insert(Node * root, int x) {
	if (root == NULL)
		return createNode(x);
	else if (x > root->data)
		root->right = insert(root->right, x);
	else
		root -> left = insert(root->left, x);
	return root;
}

Node* findMin(Node * root) {
	if (root == NULL)
		return NULL;
	else if (root->left != NULL)
		return findMin(root->left);
	return root;
}

Node* findMax(Node * root) {
	if (root == NULL)
		return NULL;
	else if (root->right != NULL)
		return findMax(root->right);
	return root;
}

Node* delete(Node * root, int x) {
	if (root == NULL)
		return NULL;
	if (x > root->data)
		root->right = delete(root->right, x);
	else if (x < root->data)
		root->left = delete(root->left, x);
	else {
		if (root->left == NULL && root->right == NULL) {
			free(root);
			return NULL;
		}
		else if (root->left == NULL || root->right == NULL) {
			Node *temp;
			if (root->left == NULL)
				temp = root->right;
			else
				temp = root->left;
			free(root);
			return temp;
		}
		else {
			Node *temp = findMin(root->right);
			root->data = temp->data;
			root->right = delete(root->right, temp->data);
		}
	}
	return root;
}

void inorder(Node *root) {
	if (root != NULL)
	{
		inorder(root->left);
		printf(" %d ", root->data);
		inorder(root->right);
	}
}

int main() {
	Node *root = createNode(20);
	insert(root, 5);
	insert(root, 1);
	insert(root, 15);
	insert(root, 9);
	insert(root, 7);
	insert(root, 12);
	insert(root, 30);
	insert(root, 25);

	inorder(root);
	printf("\n");

	root = delete(root, 1);
	root = delete(root, 9);

	inorder(root);
	printf("\n");
	
    Node* min=findMin(root);
	printf("Min : %d\n",min->data);
	Node* max=findMax(root);
	printf("Max : %d\n",max->data);
	
	printf("\n");
	int val=30;
	Node* result = search(root, val);
    if (result)
        printf(" %d found in the BST.\n", val);
    else
        printf("%d not found in the BST.\n", val);
  
	return 0;
}
