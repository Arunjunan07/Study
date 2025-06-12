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
		printf("\nEnter the Number of neighbours of %d  :", i);
		scanf("%d", &k);

		for (int j = 0; j < k; j++)
		{
			printf("Enter the value of %d neighbour of %d : ", j + 1, i);
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
		printf("\nThe neighbours of vertex %d are: ", i);
		while (temp != NULL)
		{
			printf("%d \t", temp->data);
			temp = temp->next;
		}
	}
}

void DFS(Node *ad[], int start, int visited[])
{
	visited[start] = 1;
	printf("%d   ", start);
	Node *temp;
	temp = ad[start];
	while (temp != NULL)
	{
		if (visited[temp->data] == 0)
			DFS(ad, temp->data, visited);
		temp = temp->next;
	}
}

void BFS(Node *ad[], int start, int visited[])
{
	int queue[vertices];
	int front = -1, rear = -1;

	queue[++rear] = start;
	visited[start] = 1;
	front++;
	while (front <= rear)
	{
		printf("%d   ", queue[front]);
		Node *temp;
		temp = ad[queue[front++]];
		while (temp != NULL)
		{
			if (visited[temp->data] != 1)
			{
				queue[++rear] = temp->data;
				visited[temp->data] = 1;
			}
			temp = temp->next;
		}
	}
}

int main()
{
	int start,ch;

	printf("Enter the total number of vertices: ");
	scanf("%d", &vertices);

	int visited[vertices];
	Node *adj[vertices];

	for (int i = 0; i < vertices; i++)
	{
		adj[i] = NULL;
	}

	initGraph(adj);

		while(1)
	{
		printf("\n1.BFS\n2.DFS\n3.Display\n4.Exit\n ");
		printf("Enter your Choice :");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the vertex from which do you wanted to start :");
				scanf("%d",&start);
				for(int k=0;k<vertices;k++)
					visited[k]=0;
				BFS(adj,start,visited); 
				break;
			case 2:
			    printf("Enter the vertex from which do you wanted to start :");
				scanf("%d",&start);
				for(int k=0;k<vertices;k++)
					visited[k]=0;
				DFS(adj,start,visited); 
				break;
		    case 3:
            	printGraph(adj);
			    break;
		    case 4: 
			    exit(0);
			    break;
		}
	}

	return 0;
}