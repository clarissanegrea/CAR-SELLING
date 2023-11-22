#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Car {
public:
    string make;
    string model;
    int year;
    double price;

    Car(string make, string model, int year, double price)
        : make(make), model(model), year(year), price(price) {}
};


void displayMenu() {
    cout << "1. View Cars\n";
    cout << "2. Add a Car\n";
    cout << "3. Sell a Car\n";
    cout << "4. Exit\n";
}


void viewCars(const vector<Car>& inventory) {
    cout << "Inventory:\n";
    for (const auto& car : inventory) {
        cout << car.make << " " << car.model << " (" << car.year << ") - $" << car.price << "\n";
    }
}


void addCar(vector<Car>& inventory) {
    string make, model;
    int year;
    double price;

    cout << "Enter Make: ";
    cin >> make;

    cout << "Enter Model: ";
    cin >> model;

    cout << "Enter Year: ";
    cin >> year;

    cout << "Enter Price: $";
    cin >> price;

    Car newCar(make, model, year, price);
    inventory.push_back(newCar);

    cout << "Car added to inventory.\n";
}


void sellCar(vector<Car>& inventory) {
    if (inventory.empty()) {
        cout << "Inventory is empty. Cannot sell a car.\n";
        return;
    }

    viewCars(inventory);

    int index;
    cout << "Enter the index of the car to sell: ";
    cin >> index;

    if (index >= 0 && index < inventory.size()) {
        cout << "Sold " << inventory[index].make << " " << inventory[index].model << ".\n";
        inventory.erase(inventory.begin() + index);
    } else {
        cout << "Invalid index. No car sold.\n";
    }
}

int main() {
    vector<Car> carInventory;

    int choice;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                viewCars(carInventory);
                break;

            case 2:
                addCar(carInventory);
                break;

            case 3:
                sellCar(carInventory);
                break;

            case 4:
                cout << "Exiting the system.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
