

#include <stdio.h>
#include <stdlib.h>


int V,E;

void insertEdge(int arr[][V], int i, int j) {
	arr[i][j] = 1;
	arr[j][i] = 1;
}

void printAdjMatrix(int arr[][V]) {
	int i, j;
	for (i = 0; i < V; i++) {
		printf("%d: ", i);
		for (j = 0; j < V; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}


void dfs(int adj[][V],int visited[], int start)
{
	printf("%d\t",start);
	visited[start] =1;
	for(int i=0;i<V;i++)
	{
		if(visited[i]!=1 && adj[start][i]==1)
		{
			dfs(adj,visited,i);
		}
	}	
}

void bfs(int adj[][V], int start)
{
	int visited[V],queue[V],front=-1,rear=-1;

	for(int i=0;i<V;i++)
		visited[i] =0;

	front++;
	queue[++rear] = start;
	visited[start] = 1;

	while(front<=rear)
	{
		start = queue[front++];
		printf("%d\t",start);
		for(int i=0;i<V;i++)
		{
			if(adj[start][i]==1 && visited[i] != 1)
			{
				queue[++rear] = i;
				visited[i] =1;
			}
		}
	}
}


int main() {
    printf("\nEnter the number of vertices : ");
	scanf("%d",&V);
	int adjMatrix[V][V],visited[V];;
    int u,v,ch,start;
    for (int i = 0; i < V; i++){
		for (int j = 0; j < V; j++)
		    adjMatrix[i][j] = 0;
    }
    printf("\nEnter the number of Edges : ");
	scanf("%d",&E);
	printf("Enter the edges (vertex1 vertex2):\n");
	for(int i=0;i<E;i++)
	{
	    scanf("%d %d",&u,&v);
	    insertEdge(adjMatrix,u,v);
	}
	
	while(1)
	{
		printf("\n1.BFS\n2.DFS\n3.Display\n4.Exit\n ");
		printf("Enter your Choice :");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the Vertex fron which do you wanted to start : ");
				scanf("%d",&start);
				bfs(adjMatrix,start);
				break;
			case 2:
				printf("Enter the Vertex fron which do you wanted to start : ");
				scanf("%d",&start);
				for(int i =0;i<V;i++)
					visited[i] = 0;
				dfs(adjMatrix,visited, start);
				break;
		    case 3:
	            printAdjMatrix(adjMatrix);
			    break;
		    case 4: 
			    exit(0);
			    break;
		}
	}
	return 0;
}