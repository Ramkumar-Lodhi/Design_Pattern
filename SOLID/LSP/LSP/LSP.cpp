#include<iostream>
#include <cassert>
#include <vector>

using namespace std;

class Vehicle {
public:
	virtual void startEngine() = 0;
	virtual void move() = 0;
};
class Car : public Vehicle {
public:
	void startEngine() override {
		cout << "Car Engine start " << endl;
	}
	void move() override {
		cout << "Car moving " << endl;
	}
};
class Bycle : public Vehicle {
public:
	void startEngine() override {
		cout << "No engine " << endl; //problem breaking rule
	}
	void move() override {
		cout << "Bycle moving " << endl;
	}
};
int main() {
	vector<Vehicle*>VehicleInfo;
	VehicleInfo.push_back(new Car());
	VehicleInfo.push_back(new Bycle());
	for (auto itr : VehicleInfo) {
		if (itr) {
			itr->startEngine();
			itr->move();
		}
	}
	return 0;
}

//Solution should be like we should have two interface onewithengine and other is noengine;

//class Shape {
//public:
//    virtual uint32_t area() const = 0;
//};
//
//class Rectangle :public Shape {
//public:
//    Rectangle(const uint32_t width, const uint32_t height) : m_width{ width }, m_height{ height } {}
//    uint32_t get_width() const {
//        return m_width;
//    }
//    uint32_t area() const override {
//        return m_width * m_height; 
//    }
//
//protected:
//    uint32_t m_width, m_height;
//};
//
//class Square : public Shape {
//
//    uint32_t length;
//public:
//
//    Square(uint32_t size):length(size){}
//    uint32_t area()const override {
//        return length * length;
//    }
//};
//
//int main() {
//    Shape* ptr = new Square(5);
//    if (ptr) {
//        assert(25 == ptr->area());
//        delete ptr;
//        ptr = nullptr;
//    }
//    ptr = new Rectangle(5, 10);
//    if (ptr) {
//        assert(50 == ptr->area());
//        delete ptr;
//    }
//    return 0;
//}