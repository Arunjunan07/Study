import java.util.*;

 class Graph{
	ArrayList<ArrayList<Integer>> adjList=new ArrayList<>();
	Graph(int v){
		for(int i=0;i<v;i++){
			adjList.add(new ArrayList<Integer>());
		}
	}
	public void addEdge(int u,int v){
		adjList.get(u).add(v);
		adjList.get(v).add(u);
	}
	void bfs(int v)
    {

        int V=adjList.size();
        boolean visited[] = new boolean[V];      
        visited [v]= true;
        Queue <Integer> q = new LinkedList<>();            
        q.add(v);              
 
        while (q.size() != 0)
        {
            int vertex = q.remove();             
            System.out.print(vertex+" ");           
 
            for (int i = 0; i < adjList.get(vertex).size(); i++) 
            {
                int av= adjList.get(vertex).get(i);
                if (!visited[av])                   
                {
                    q.add(av);
                    visited[av]=true;
                    
                }
            }  
        }
    }

public void dfs(int v){
        int V=adjList.size();
        boolean visited[] = new boolean[V];
        dfs2(v,visited);
    }
 public void dfs2(int v,boolean[] visited){
         visited[v]= true;
         System.out.print(v+ " ");
         for (int i = 0; i < adjList.get(v).size(); i++) 
            {
                int av= adjList.get(v).get(i);
                if (!visited[av])                   
                      dfs2(av,visited);
             }
   }
 }
 class bfs_dfs{
	public static void main(String m[]){
		Graph g=new Graph(5);
	  g.addEdge(0,1);
		g.addEdge(2,3);
		g.addEdge(1,2);
		g.addEdge(3,4);
		g.addEdge(0,4);
		g.addEdge(1,4);
		System.out.println("The Breadth First Search :");
		g.bfs(0);
		System.out.println("\nThe Depth First Search :");
		g.dfs(0);
	}
 }
 
		