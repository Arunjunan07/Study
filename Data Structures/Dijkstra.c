#include<stdio.h>

#define INF 999;

int n;

void dij(int adj[][n],int s,int dist[])
{
	int count,visited[n],min;

	for(int i=1; i<=n; i++) {
		visited[i]=0;
		dist[i]=adj[s][i];
	}
	count=2;
	while(count<=n)
	{
		int u;
		min=INF;
		for(int i=1; i<=n; i++) {
			if(dist[i]<min && !visited[i]) {
				min=dist[i];
				u=i;
			}
		}
		visited[u]=1;
		count++;

		for(int i=1; i<=n; i++) {
			if((dist[u]+adj[u][i]<dist[i]) && !visited[i])
				dist[i]=dist[u]+adj[u][i];
		}
	}

}

int main()
{
	int start;

	printf("Enter the total number of Vertices :");
	scanf("%d",&n);
	int adj[n][n],dist[n];

	printf("Enter the adj. matrix :\n");
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++)
		{
			scanf("%d",&adj[i][j]);
			
			if(adj[i][j]==0 && i != j)
				adj[i][j]=INF;
		}
	}
	printf("Enter the starting Vertex :");
	scanf("%d",&start);

	dij(adj,start,dist);

	printf("\nShortest path :\n");
	for(int i=1; i<=n; i++){
		if(i!=start)
			printf("%d --> %d => %d \n",start,i,dist[i]);
	}
	return 0;
}
