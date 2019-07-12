#include <iostream>

using namespace std;

class Adder
{
public:
    Adder()
    {
        tot = 0;
    }
    void Add(int val = 0)
    {
        tot += val;
    }
    int get()
    {
        return tot;
    }

private:
    int tot;

};



class Sub
{
public:
    Sub()
    {
        tot = 0;
    }
    void Add(int val = 0)
    {
        tot += val;
    }
    int get()
    {
        return tot;
    }

private:
    int tot;

};

class Mul: public Adder, public Sub
{

};

int main()
{
    int i, j, k;
    Adder adder;
    adder.Add(10);
    adder.Add(20);
    int sum = adder.get();
    cout<<sum<<endl;

    return 0;
}
