#include<iostream>

using namespace std;

class Document {};

class IPrinter {
public:
    virtual void print(Document& doc) = 0;
};
class IScanner {
public:
    virtual void scan(Document& doc) = 0;
};
class IFax {
public:
    virtual void fax(Document& doc) = 0;
};

class MultiFunctionPrinter : public IPrinter,public IScanner,public IFax {
public:
    void print(Document& doc) override { }
    void fax(Document& doc) override { }
    void scan(Document& doc) override { }
};
                                                              \
struct Scanner : public IScanner {                   
public:
    void scan(Document& doc) override {
        // Do scanning ...
    }
};