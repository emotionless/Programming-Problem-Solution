#include <bits/stdc++.h>

using namespace std;

class A
{
public:
    virtual string getName()
    {
        return "A";
    }
};


class B:public A
{
public:
    string getName()
    {
        return "B";
    }

};


class C:public B
{
public:
    string getName()
    {
        return "C";
    }

};

int main()
{
    int i, j, k;

    C c;
    B b;
    A *a;
    a = &b;
    cout<<a->getName()<<endl;
    a = &c;
    cout<<a->getName()<<endl;


    return 0;
}

