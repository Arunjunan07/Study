class t1 extends  Thread
{
	public void run()
	{
		System.out.println("Child Thread 1");
	}
}

class t2 extends  Thread
{
	public void run()
	{
		System.out.println("Child  thread 2");
	}
}


class thread
{
	public static void main(String l[]){
		System.out.println("main thread");
		t1 o = new t1();
		t2 o1= new t2();
		o1.start();
		o.start();

		System.out.println("main end");
	}	
}	