#include <iostream>
#include <string>

using namespace std;

class Vehicle {
protected:
	string manufacturer;
	int year;
	string color;


public:
	string getManufacturer() {
		return manufacturer;
	}

	void setManufacturer(string value) {
		manufacturer = value;
	}

	int getYear() {
		return year;
	}

	void setYear(int value2) {
		year = value2;
	}

	string getColor() {
		return color;
	}

	void setColor(string value3) {
		color = value3;
	}


	Vehicle() {
		cout << "\nAn instance has been derived from Vehicle."<< endl;
	}

	Vehicle(string manufacturer, int year, string color) : Vehicle() {

		cout << "\nInstance with full parameters has been derived from Vehicle." << endl;
		this->manufacturer = manufacturer;
		this->year = year;
		this->color = color;
	}

	virtual void start() {
		cout << "Vehicle has been started." << endl;
	}

	virtual void stop() {
		cout << "Vehicle has been stopped." << endl;
	}

	virtual void drive() {
		cout << "Vehicle is being driven.. " << endl;
	}

	virtual string toString() {
		return manufacturer + "-" + to_string(year) + "-" + color;
	}
};

class Car : public Vehicle {

public:
	Car() {
		cout << "\nAn instance has been derived from Car." << endl;
	}
	Car(string manufacturer, int year, string color) :Vehicle(manufacturer, year, color) {

		cout << "\nAn instance with full parameters has been derived from Car." << endl;

	}
	void openSunroof() {
		cout << "The sunroof has been opened.. " << endl;
	}

	void drive()  override {
		cout << "The car manufactured by " << this->manufacturer << " is being driven" << endl;
	}
};

class Bus : public Vehicle {
public:

	Bus(string manifacturer, int year, string color) : Vehicle(manifacturer, year, color) {
		cout << "\nAn instance with full parameters has been created by Bus Class." << endl;
	}

	void scheduling() {
		cout << "Scheduled." << endl;
	}

	void drive()  override {
		cout << "The bus manufactured by " << this->manufacturer << " is being driven" << endl;
	}
};

class SchoolBus : public Bus {
public:
	SchoolBus(string manufacturer, int year, string color)
		: Bus(manufacturer, year, color) {
		cout << "\nAn instance with full parameters has been derived from School Bus." << endl;
	}

	void getFare() {
		cout << "getFare() has been called.." << endl;
	}

	void drive()  override {
		cout << "The school bus manufactured by " << this->manufacturer << " is being driven" << endl;
	}

};

int main() {

	Vehicle item2 = Vehicle("Skoda", 2019, "White");
	cout << "Vehicle " << item2.getManufacturer() << endl;

	Car item1 = Car("TOGG", 2022, "Red");
	cout << item1.toString() << endl;
	item1.openSunroof();

	Car item3 = Car("Opel", 2020, "Black");
	cout << item3.toString() << endl;
	item3.openSunroof();

	Bus item4 = Bus("Isuzu", 2016, "Red");
	cout << item4.toString() << endl;
	item4.scheduling();

	SchoolBus item5 = SchoolBus("Isuzu", 2014, "Yellow");
	cout << item5.toString() << endl;
	item5.scheduling();
	item5.getFare();

	item1.drive();
	item1.stop();
	item3.drive();
	item3.stop();
	item4.drive();
	item4.stop();
	item5.drive();
	item5.stop();



	char c = getchar();
	return 0;
}