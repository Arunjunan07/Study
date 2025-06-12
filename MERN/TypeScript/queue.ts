class Queue<T> {
    public items: T[] = [];

    enqueue(element: T): void {
        this.items.push(element);
    }

    dequeue(): T | undefined {
        if (this.isEmpty()) {
            console.log("Queue is empty");
            return undefined;
        }
        return this.items.shift();
    }

    isEmpty(): boolean {
        return this.items.length === 0;
    }

    print(): void {
        console.log(this.items.toString());
    }
}

const queue = new Queue<number>();

queue.enqueue(10);
queue.enqueue(20);
queue.enqueue(30);

queue.print();

console.log(queue.dequeue());

queue.print();
