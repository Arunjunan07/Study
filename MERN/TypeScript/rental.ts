class Vehicle {
    constructor(
        public brand: string,
        public model: string,
        public rentalPrice: number // Price per day
    ) {}

    public calculateRentalCost(days: number): number {
        return this.rentalPrice * days;
    }
}

class Car extends Vehicle {
    constructor(
        brand: string,
        model: string,
        rentalPrice: number,
        public numberOfSeats: number
    ) {
        super(brand, model, rentalPrice);
    }

    public calculateRentalCost(days: number): number {
        const baseCost = super.calculateRentalCost(days);
        return baseCost;
    }
}

class Bike extends Vehicle {
    constructor(
        brand: string,
        model: string,
        rentalPrice: number,
        public engineCC: number
    ) {
        super(brand, model, rentalPrice);
    }

    public calculateRentalCost(days: number): number {
        const baseCost = super.calculateRentalCost(days);
        return baseCost;
    }
}

const car1 = new Car("Toyota", "Camry", 50, 5);
const bike1 = new Bike("Yamaha", "MT-07", 30, 689);

const rentalDays = 3;

console.log(`Car Rental Cost for ${rentalDays} days: ₹${car1.calculateRentalCost(rentalDays)}`);
console.log(`Bike Rental Cost for ${rentalDays} days:₹${bike1.calculateRentalCost(rentalDays)}`);