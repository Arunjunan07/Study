public class AdjMatrix {

    int Count;

    int matrix[][];
    AdjMatrix(int Count) {
        this.Count=Count;
        matrix = new int[Count][Count];
    }
    public void addEdge(int u, int v) {
        matrix[u][v] = 1;
        matrix[v][u] = 1;
    }
    public void deleteEdge(int u, int v)
    {
        matrix[u][v] = 0;
		matrix[v][u] = 0;

    }

    public void print() {
        System.out.println("Representation of Graph in the form of Adjacency Matrix: ");
        for (int i = 0; i <Count; i++) {
            for (int j = 0; j <Count; j++) {
                System.out.print(matrix[i][j] + "   ");
            }
            System.out.println();
        }
		
	}

  public static void main(String[] args) {

        AdjMatrix adj = new AdjMatrix(5);
        adj.addEdge(0, 1);
        adj.addEdge(0, 4);
        adj.addEdge(1, 2);
        adj.addEdge(1, 3);
        adj.addEdge(1, 4);
        adj.addEdge(2, 3);
        adj.addEdge(3, 4);
        adj.print();

        System.out.println("\nDeleting an edge from 3 to 4");

        adj.deleteEdge(3, 4);

        adj.print();
    }
}