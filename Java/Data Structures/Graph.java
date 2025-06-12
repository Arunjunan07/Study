import java.util.ArrayList;


 class GraphRep{

	ArrayList<ArrayList<Integer>> List=new ArrayList<>();
	GraphRep(int v){
		for(int i=0;i<=v;i++){
			List.add(new ArrayList<Integer>());
		}
	}
	public void addEdge(int u,int v){
		List.get(u).add(v);
		List.get(v).add(u);
	}
	public void print(){
		for(int i=1;i<List.size();i++)
		{
			System.out.println("List of vertex="+i);
			for(int j=0;j<List.get(i).size();j++){
				System.out.println(" "+List.get(i).get(j));
			}
		}
	}
 }
 class Graph{
	public static void main(String m[])
	{	
		GraphRep g=new GraphRep(5);
		 g.addEdge(3,4);
		g.addEdge(2,3);
		g.addEdge(1,2);
		g.addEdge(4,5);
		g.addEdge(1,5);
		g.addEdge(2,5); 
		g.print();
	}
}