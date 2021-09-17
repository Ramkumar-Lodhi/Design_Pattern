#include <iostream>
#include<string>

using namespace std;

class Singleton {
private:
    static Singleton* instance;
public:
    Singleton() = default;
    Singleton(const Singleton& rhs) = delete;
    Singleton& operator=(const Singleton& rhs) = delete;
    static Singleton* GetInstance();
    void printMemeberInfo() {
        if(this)
            cout << "This from instance id " << this<<"\n";
    }
};

Singleton* Singleton::instance = 0;

Singleton* Singleton::GetInstance() {
    if (instance == nullptr) {
        instance = new Singleton(); //fill if empty
    }
    return instance; //return
}


int main()
{
    //unique_ptr<Singleton> sObj = make_unique<Singleton>(Singleton::GetInstance());
    Singleton* sOb2 = Singleton::GetInstance();
    //sObj->printMemeberInfo();
    sOb2->printMemeberInfo();

    return 0;
}
