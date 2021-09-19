#include <iostream>

using namespace std;

class IBackpack
{
public:
    virtual void assemble() = 0;
    virtual ~IBackpack() {}
};

class PlainBackpack : public IBackpack
{
public:
    virtual void assemble() override {
        cout << "\n ShoulderStraps and mainCompartment";
    }
};

class BackpackDecorator : public IBackpack
{
private:
    IBackpack* m_Decorator;
public:
    BackpackDecorator(IBackpack* decorator) :m_Decorator(decorator) {}

    virtual void assemble() override {
        m_Decorator->assemble();
    }
    virtual ~BackpackDecorator() {
        if (m_Decorator) {
            delete m_Decorator;
        }
    }
};

class WithLaptopSlot : public BackpackDecorator
{
public:
    WithLaptopSlot(IBackpack* dcrator) :BackpackDecorator(dcrator) {}
    virtual void assemble() override {
        BackpackDecorator::assemble();
        cout << " + LaptopSlot";
    }
};

class WithUSBCharge : public BackpackDecorator
{
public:
    WithUSBCharge(IBackpack* dcrator) :BackpackDecorator(dcrator) {}
    virtual void assemble() override {
        BackpackDecorator::assemble();
        cout << " + USBCharge";
    }
};

class WithWaterBottle : public BackpackDecorator
{
public:
    WithWaterBottle(IBackpack* dcrator) :BackpackDecorator(dcrator) {}
    virtual void assemble() override {
        BackpackDecorator::assemble();
        cout << " + WaterBottle";
    }
};

int main()
{
    IBackpack * pBackpack = new WithWaterBottle(
                                new WithUSBCharge(
                                    new WithLaptopSlot(
                                        new BackpackDecorator(
                                            new PlainBackpack())
                                    )
                                )
                            );

    pBackpack->assemble();
    delete pBackpack;
}