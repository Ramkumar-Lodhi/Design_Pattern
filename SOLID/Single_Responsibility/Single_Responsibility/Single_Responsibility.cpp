// Single_Responsibility.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

class Book {
public:
	string name;
	string authorName;
	int year;
	int price;
	string isbn;
public:
	Book() :name(""),authorName(""),year(0),price(0),isbn(""){}

	Book(string name, string authorName, int year, int price, string isbn) {
		this->name = name;
		this->authorName = authorName;
		this->year = year;
		this->price = price;
		this->isbn = isbn;
	}
};
class InvoicePrinter;
class InvoicePersistence;

class Invoice {
public:
	Book book;
	int quantity;
	double discountRate;
	double taxRate;
	double total;
public:
	Invoice():book(), quantity(0), discountRate(0),taxRate(0),total(0){}
	Invoice(Book book, int quantity, double discountRate, double taxRate) {
		this->book = book;
		this->quantity = quantity;
		this->discountRate = discountRate;
		this->taxRate = taxRate;
		this->total = this->calculateTotal();;
	}

	double calculateTotal() {
		double price = ((book.price - ((discountRate/book.price)*100) )* this->quantity);
		double priceWithTaxes = price * (1 + taxRate);
		return priceWithTaxes;
	}
	//void saveToFile(string filename) {
	//	cout << "Saving into File " << filename << endl;
	//	// store data in file/database or somewhere else
	//}
	/*void print() {
		cout << invoice.quantity << " x " << invoice.book.name + " " << invoice.book.price << "$" << endl;
		cout << "Discount Rate: " << invoice.discountRate << endl;
		cout << "Tax Rate: " << invoice.taxRate << endl;
		cout << "Total: " << invoice.total << endl;
	}*/
};

class InvoicePrinter {
private:
	Invoice invoice;

public:
	InvoicePrinter() {}
	InvoicePrinter(Invoice invoice) {
		this->invoice = invoice;
	}

	void print() {
		cout << invoice.quantity << " x " << invoice.book.name + " " << invoice.book.price << "$" << endl;
		cout << "Discount Rate: " << invoice.discountRate << endl;
		cout << "Tax Rate: " << invoice.taxRate << endl;
		cout << "Total: " << invoice.total << endl;
	}
};

class InvoicePersistence {
	Invoice invoice;

public:
	InvoicePersistence() {}
	InvoicePersistence(Invoice invoice) {
		this->invoice = invoice;
	}

	void saveToFile(string filename) {
		cout << "Saving into File " << filename<<endl;
		// store data in file/database or somewhere else
	}
};

int main()
{
	Book b("C++", "Ramkumar Lodhi", 2022, 100, "2XVB3D");
	Invoice bill(b, 2, 10, 18);
	InvoicePrinter printer(bill);
	printer.print();
	InvoicePersistence p(bill);
	p.saveToFile("Information");
	return 0;
}