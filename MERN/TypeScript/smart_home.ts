namespace SmartHome {
    export namespace Lighting {
        export class Light {
            private isOn: boolean = false;

            public turnOn(): void {
                this.isOn = true;
                console.log("Light is turned ON.");
            }

            public turnOff(): void {
                this.isOn = false;
                console.log("Light is turned OFF.");
            }
        }

        export class Fan {
            private isOn: boolean = false;

            public turnOn(): void {
                this.isOn = true;
                console.log("Fan is turned ON.");
            }

            public turnOff(): void {
                this.isOn = false;
                console.log("Fan is turned OFF.");
            }
        }
    }

    
    export namespace ClimateControl {
        export class AirConditioner {
            private temperature: number = 24;
            private isOn: boolean = false;

            public turnOn(): void {
                this.isOn = true;
                console.log("Air Conditioner is turned ON.");
            }

            public turnOff(): void {
                this.isOn = false;
                console.log("Air Conditioner is turned OFF.");
            }

            public setTemperature(temp: number): void {
                this.temperature = temp;
                console.log(`Air Conditioner temperature set to ${this.temperature}°C.`);
            }
        }
    }

    export namespace Security {
        export class SecuritySystem {
            private isEnabled: boolean = false;

            public enable(): void {
                this.isEnabled = true;
                console.log("Security System is Enabled.");
            }

            public disable(): void {
                this.isEnabled = false;
                console.log("Security System is DISABLED.");
            }
        }
    }
}

const livingRoomLight = new SmartHome.Lighting.Light();
livingRoomLight.turnOn();
livingRoomLight.turnOff();

const ceilingFan = new SmartHome.Lighting.Fan();
ceilingFan.turnOn();
ceilingFan.turnOff();

// Climate Control
const ac = new SmartHome.ClimateControl.AirConditioner();
ac.turnOn();
ac.setTemperature(22);
ac.turnOff();

// Security Control
const homeSecurity = new SmartHome.Security.SecuritySystem();
homeSecurity.enable();
homeSecurity.disable();