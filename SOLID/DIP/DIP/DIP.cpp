// DIP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


class IMonitor {
public:
    virtual void Screen() = 0;
};

class Monitor : public IMonitor {
public:
    void Screen() override {}
};

class Ikeyboard {
public:
    virtual void functionality() = 0;
};

class QwertyKeyboard :public Ikeyboard {
public:
    void functionality() override {}
};

class Desktop {
    IMonitor *m_monitor;
    Ikeyboard *m_keyboard;
public:
    Desktop(IMonitor *m, Ikeyboard *k) {
        m_monitor = m;
        m_keyboard = k;
    }
};

int main()
{
    Desktop d_obj(new Monitor, new QwertyKeyboard());
    return 0;
}