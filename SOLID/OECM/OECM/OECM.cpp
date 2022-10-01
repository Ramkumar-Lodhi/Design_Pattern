#include <iostream>
#include <string>
#include <cassert>

using namespace std;

class operation {
public:
	virtual int calculation(int first, int second) = 0;
};
class Addition: public operation {
public:
	int calculation(int first, int second) override {
		return first + second;
	}
};
class Substraction :public operation {
public:
	int calculation(int first, int second) override {
		return first - second;
	}
};
int main() {
	operation *op = new Addition();
	if (!op) return;
	assert(op->calculation(5, 10) == 15);

	op = new Substraction();
	if (!op) return;
	assert(op->calculation(5, 11) == -6);
	return 0;
}
//class Book {
//public:
//	string name;
//	string authorName;
//	int year;
//	int price;
//	string isbn;
//public:
//	Book() :name(""), authorName(""), year(0), price(0), isbn("") {}
//
//	Book(string name, string authorName, int year, int price, string isbn) {
//		this->name = name;
//		this->authorName = authorName;
//		this->year = year;
//		this->price = price;
//		this->isbn = isbn;
//	}
//};
//class InvoicePrinter;
//class InvoicePersistence;
//
//class Invoice {
//public:
//	Book book;
//	int quantity;
//	double discountRate;
//	double taxRate;
//	double total;
//public:
//	Invoice() :book(), quantity(0), discountRate(0), taxRate(0), total(0) {}
//	Invoice(Book book, int quantity, double discountRate, double taxRate) {
//		this->book = book;
//		this->quantity = quantity;
//		this->discountRate = discountRate;
//		this->taxRate = taxRate;
//		this->total = this->calculateTotal();;
//	}
//
//	double calculateTotal() {
//		double price = ((book.price - ((discountRate / book.price) * 100)) * this->quantity);
//		double priceWithTaxes = price * (1 + taxRate);
//		return priceWithTaxes;
//	}
//};
//
//class InvoicePrinter {
//private:
//	Invoice invoice;
//
//public:
//	InvoicePrinter() {}
//	InvoicePrinter(Invoice invoice) {
//		this->invoice = invoice;
//	}
//
//	void print() {
//		cout << invoice.quantity << " x " << invoice.book.name + " " << invoice.book.price << "$" << endl;
//		cout << "Discount Rate: " << invoice.discountRate << endl;
//		cout << "Tax Rate: " << invoice.taxRate << endl;
//		cout << "Total: " << invoice.total << endl;
//	}
//};
//
//class InvoicePersistence {
//
//public:
//	virtual void saveToFile(Invoice invoice) = 0;
//};
//
//class DatabasePersistence :public InvoicePersistence {
//public:
//	void saveToFile(Invoice invoice) override {
//		cout << " DatabasePersistence " << __FUNCTION__ << endl;
//	}
//};
//
//class FilePersistence :public InvoicePersistence {
//public:
//	void saveToFile(Invoice invoice) override {
//		cout << " FilePersistence " << __FUNCTION__ << endl;
//	}
//};
//
//int main()
//{
//	Book b("C++", "Ramkumar Lodhi", 2022, 100, "2XVB3D");
//	Invoice bill(b, 2, 10, 18);
//	InvoicePrinter printer(bill);
//	printer.print();
//    InvoicePersistence *invoiceInfo = new DatabasePersistence();
//	invoiceInfo->saveToFile(bill);
//	return 0;
//}