#include <iostream>

class Car {
public:
    int speed;

private:
    int fuel;

public:
    Car(int initFuel) : speed(0), fuel(initFuel) {}

    void changeSpeed(int increase, int fuelCost) {
        if (fuel - fuelCost >= 0) {
            speed += increase;
            fuel -= fuelCost;
        } else {
            std::cout << "Not enough fuel to change speed!" << std::endl;
        }
    }

    int getFuel() const {
        return fuel;
    }

    int setFuel(int fuel) {
        this->fuel = fuel;
    }
};

class Truck : public Car {
private:
    int liftingCapacity;

public:
    Truck(int initFuel, int initCapacity) : Car(initFuel), liftingCapacity(initCapacity) {}

    void setliftingCapacity(int liftingCapacity) {
        this->liftingCapacity = liftingCapacity;
        }

    int getliftingCapacity() const {
        return liftingCapacity;
        }
};

class Motorcycle : public Car {
private:
    int enginePower;

public:
    Motorcycle(int initFuel, int initPower) : Car(initFuel), enginePower(initPower) {}

    void setEnginePower(int enginePower) {
        this->enginePower = enginePower;
        }

    int getEnginePower() const {
        return enginePower;
    }
};

int main() {
    Truck truck(100, 50);
    truck.changeSpeed(10, 20);
    std::cout << "Truck: speed " << truck.speed << ", fuel " << truck.getFuel() << ", liftingCapacity " << truck.getliftingCapacity() << std::endl;

    Motorcycle motorcycle(50, 20);
    motorcycle.changeSpeed(20, 10);
    std::cout << "Motorcycle: speed " << motorcycle.speed << ", fuel " << motorcycle.getFuel() << ", enginePower " <<  motorcycle.getEnginePower() << std::endl;

    return 0;
}
