
#include <stdio.h>

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

int main() {
    printf("\nEnter the number of vertices : ");
	scanf("%d",&V);
	int adjMatrix[V][V];
    int u,v;
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
	printAdjMatrix(adjMatrix);

	return 0;
}