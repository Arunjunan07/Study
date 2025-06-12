// Product Module
class Product {
    constructor(
        public id: number,
        public name: string,
        public price: number,
        public stock: number
    ) {}

    public updateStock(quantity: number): void {
        this.stock -= quantity;
    }
}

// Customer Module
class Customer {
    constructor(
        public id: number,
        public name: string,
        public email: string
    ) {}
}

// Order Module
class Order {
    public orderId: number;
    public customer: Customer;
    public products: Product[];
    public totalAmount: number;

    constructor(orderId: number, customer: Customer) {
        this.orderId = orderId;
        this.customer = customer;
        this.products = [];
        this.totalAmount = 0;
    }

    public addProduct(product: Product, quantity: number): void {
        if (product.stock >= quantity) {
            this.products.push(product);
            this.totalAmount += product.price * quantity;
            product.updateStock(quantity);
        } else {
            console.log(`Not enough stock for product: ${product.name}`);
        }
    }
}

// ShoppingCart Module
class ShoppingCart {
    private products: Product[] = [];
    private customer: Customer | null = null;

    public setCustomer(customer: Customer): void {
        this.customer = customer;
    }

    public addProduct(product: Product): void {
        this.products.push(product);
    }

    public placeOrder(orderId: number): Order | null {
        if (!this.customer) {
            console.log("Customer is not set.");
            return null;
        }

        const order = new Order(orderId, this.customer);
        for (const product of this.products) {
            order.addProduct(product, 1);
        }

        this.products = [];
        return order;
    }
}

// ECommerceSystem Namespace
namespace ECommerceSystem {
    export const createProduct = (id: number, name: string, price: number, stock: number): Product => {
        return new Product(id, name, price, stock);
    };

    export const createCustomer = (id: number, name: string, email: string): Customer => {
        return new Customer(id, name, email);
    };

    export const createShoppingCart = (): ShoppingCart => {
        return new ShoppingCart();
    };
}

const product1 = ECommerceSystem.createProduct(1, "Laptop", 1000, 10);
const product2 = ECommerceSystem.createProduct(2, "Mouse", 20, 50);

const customer = ECommerceSystem.createCustomer(1, "John Wick", "john@gmail.com");

const shoppingCart = ECommerceSystem.createShoppingCart();
shoppingCart.setCustomer(customer);
shoppingCart.addProduct(product1);
shoppingCart.addProduct(product2);

const order = shoppingCart.placeOrder(1);
if (order) {
    console.log(`Order ID: ${order.orderId}, Total Amount: $${order.totalAmount}`);
}