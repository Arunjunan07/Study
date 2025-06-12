#include<stdio.h>

#define INF 999;
int n;

void floyds(int p[][n])
{
	int i,j,k;
	for(k=1; k<=n; k++)
		for(i=1; i<=n; i++)
			for(j=1; j<=n; j++)
				if(i==j)
					p[i][j]=0;
				else
					p[i][j]=min(p[i][j],p[i][k]+p[k][j]);
}
int min(int a,int b)
{
	if(a<b)
		return(a);
	else
		return(b);
}

int main()
{
	int start;

	printf("Enter the total number of Vertices :");
	scanf("%d",&n);
	int adj[n][n],dist[n];

	printf("Enter the adj. matrix :\n");
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++)
		{
			scanf("%d",&adj[i][j]);

			if(adj[i][j]==0 && i != j)
				adj[i][j]=INF;
		}
	}

	floyds(adj);
	
	printf("\nShortest path :\n");
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
		{
			if(i!=j)
                printf("%d --> %d => %d \n",i,j,adj[i][j]);		}
	return 0;
}
