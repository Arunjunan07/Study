class Stack<T> {
   public items: T[] = [];

    push(element: T): void {
        this.items.push(element);
    }

    pop(): T | undefined {
        if (this.isEmpty()) {
            console.log("Stack is empty");
            return undefined;
        }
        return this.items.pop();
    }

    isEmpty(): boolean {
        return this.items.length === 0;
    }

    size(): number {
        return this.items.length;
    }

    print(): void {
        console.log(this.items.toString());
    }
}

const stack = new Stack<number>();

stack.push(10);
stack.push(20);
stack.push(30);

console.log("Stack size is: " + stack.size());

stack.print();

console.log(stack.pop());

stack.print();
