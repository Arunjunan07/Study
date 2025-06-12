class BinTree{	
	Node root;
	class Node{
		int data;
		Node left,right;
		public Node(int d){
			data=d;
			left=null;
			right=null;
		}
	}
	public BinTree(int d){
		root=new Node(d);
	}
	public void insertLeft(Node r,int val){
		Node newNode=new Node(val);
		r.left=newNode;
	}
	public void insertRight(Node r,int val){
		Node newNode=new Node(val);
		r.right=newNode;
	}
	public static Node deleteLeaves(Node root, int x) { 
    if (root == null) 
        return null; 
    root.left = deleteLeaves(root.left, x); 
    root.right = deleteLeaves(root.right, x); 
    if (root.data == x && root.left == null && root.right == null) { 
        return null; 
    } 
    return root; 
} 
	public static void preOrder(Node root){
		if(root!=null){
			System.out.print(root.data+" ");
			preOrder(root.left);
			preOrder(root.right);
		}
	}
	public static void inOrder(Node root){
		if(root!=null){
			inOrder(root.left);
			System.out.print(root.data+" ");
			inOrder(root.right);
		}
	}
	public static void postOrder(Node root){
		if(root!=null){
			postOrder(root.left);
			postOrder(root.right);
			System.out.print(root.data+" ");
		}
	}
}

public class BinaryTree{
	public static void main(String[] s){
		BinTree tree =new BinTree(3);
		tree.insertLeft(tree.root,10);
		tree.insertRight(tree.root,12);
		tree.insertRight(tree.root.right,18);
		tree.insertLeft(tree.root.right,14);
		System.out.print("PreOrder ");
		BinTree.preOrder(tree.root);
		System.out.println();
		System.out.print("InOrder ");
		BinTree.inOrder(tree.root);
		System.out.println();
		System.out.print("PostOrder ");
		BinTree.postOrder(tree.root);
		BinTree.deleteLeaves(tree.root,14);
	}
}