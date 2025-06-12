class OrderNode {
    constructor(public orderId: number, public orderDescription: string, public next: OrderNode | null = null) {}
  }
  
  class OrderQueue {
    private head: OrderNode | null = null;
  
    addOrder(orderId: number, orderDescription: string): void {
      const newOrder = new OrderNode(orderId, orderDescription);
      if (!this.head) {
        this.head = newOrder;
      } else {
        let temp = this.head;
        while (temp.next) {
          temp = temp.next;
        }
        temp.next = newOrder;
      }
      console.log(`Order ${orderId} added: ${orderDescription}`);
    }
  
    processOrder(): void {
      if (this.head) {
        console.log(`Processing Order ${this.head.orderId}: ${this.head.orderDescription}`);
        this.head = this.head.next; 
      } else {
        console.log("No pending orders to process.");
      }
    }
  
    displayOrders(): void {
      if (!this.head) {
        console.log("No pending orders.");
        return;
      }
  
      let temp = this.head;
      console.log("Pending Orders:");
      while (temp) {
        console.log(`Order ${temp.orderId}: ${temp.orderDescription}`);
        temp = temp.next;
      }
    }
}
const orderQueue = new OrderQueue();
  
orderQueue.addOrder(101, "Smartphone");
orderQueue.addOrder(102, "Laptop");
orderQueue.addOrder(103, "Headphones");
  
orderQueue.displayOrders();
orderQueue.processOrder();
orderQueue.displayOrders();
orderQueue.processOrder();
orderQueue.displayOrders();
orderQueue.processOrder();
orderQueue.processOrder();