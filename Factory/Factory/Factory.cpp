#include <iostream>
#include <string>
#include <string_view>
#include <compare>
using namespace std;

class Computer
{
public:
    virtual void Run() = 0;
    virtual void Stop() = 0;
    virtual ~Computer() {};
};

class Laptop : public Computer
{
public:
    void Run() override { 
        mHibernating = false; 
        cout << __FUNCTION__;
    }
    void Stop() override {
        mHibernating = true; cout << __FUNCTION__;
    }
    virtual ~Laptop() {};
private:
    bool mHibernating = false;
};

class Desktop : public Computer
{
public:
    void Run() override { 
        mOn = true; cout << __FUNCTION__;
    }
    void Stop() override { 
        mOn = false;
        cout << __FUNCTION__;
    };
    virtual ~Desktop() {};
private:
    bool mOn =false;
};

class Tap : public Computer
{
public:
    void Run() override { 
        status = true;
        cout << __FUNCTION__;
    }
    void Stop() override { 
        status = false;
        cout << __FUNCTION__;
    }
    virtual ~Tap() {}
private:
    bool status = false;
};

class ComputeFactory {
public:
    static Computer* NewComputer(string_view description) {

        if (description == "Desktop") {
            return new Desktop();
        } else if (description == "Laptop") {
            return new Laptop();
        } else if(description == "Tap") {
            return new Tap();
        } else {
            cout << "Invalid requirement";
            return nullptr;
        }
    }
};

int main()
{
    Computer* bptr = ComputeFactory::NewComputer("Laptop");
    if (bptr) {
        bptr->Run();
        bptr->Stop();
    }
}