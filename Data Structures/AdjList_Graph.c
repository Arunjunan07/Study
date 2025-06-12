
#include<stdio.h>
#include<stdlib.h>

typedef struct Graph_Node
{
	int data;
	struct Graph_Node *next;
} Node;

int vertices;

void initGraph(Node* ad[])
{
	Node *newNode;
	int k, data;

	for (int i = 0; i < vertices; i++)
	{
		Node *last = NULL;
		printf("\nEnter the Number of neighbours of %d  :", i+1);
		scanf("%d", &k);

		for (int j = 0; j < k; j++)
		{
			printf("Enter the value of %d neighbour of %d : ", j + 1, i+1);
			scanf("%d", &data);

			newNode = (Node*)malloc(sizeof(Node));
			newNode->data = data;
			newNode->next = NULL;
			if (ad[i] == NULL)
				ad[i] = newNode;
			else
				last->next = newNode;
			last = newNode;
		}
	}
}

void printGraph(Node *ad[])
{
	Node *temp = NULL;

	for (int i = 0; i < vertices; i++)
	{
		temp = ad[i];
		printf("\nThe neighbours of vertex %d are: ", i+1);
		while (temp != NULL)
		{
			printf("%d \t", temp->data);
			temp = temp->next;
		}
	}
}

int main()
{
	int start;

	printf("Enter the total number of vertices: ");
	scanf("%d", &vertices);

	int visited[vertices];
	Node *adj[vertices];

	for (int i = 0; i < vertices; i++)
	{
		adj[i] = NULL;
	}

	initGraph(adj);
	printGraph(adj);

	return 0;
}