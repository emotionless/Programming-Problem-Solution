#include <iostream>

using namespace std;

class Adder
{
public:

    void get()
    {
        cout<<"In parent class"<<endl;
    }

};



class Sub: public Adder
{
public:

    void get()
    {
        cout<<"In child class"<<endl;
    }
};

int main()
{
    int i, j, k;
    Adder a;
    Sub s;
    a.get();
    s.get();


    return 0;
}
