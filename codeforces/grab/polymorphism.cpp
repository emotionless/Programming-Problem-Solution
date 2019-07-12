#include <iostream>

using namespace std;

class shape
{
    protected:
        int width, height;
    public:
    shape(int a = 0, int b = 0)
    {
        width = a;
        height = b;
    }
    virtual int area()
    {
        cout<<"In parent area"<<endl;
        return width*height;
    }

};


class Rectangle: public shape
{
public:
    Rectangle( int a=0, int b=0):shape(a, b) {}
    int area()
    {
        cout<<"In child area"<<endl;
        return (height*width)/2;
    }
};

class Triangle: public shape
{
public:
    Triangle( int a=0, int b=0):shape(a, b) { }
    int area()
    {
        cout<<"In triangle class"<<endl;
        return (width*height)/3;
    }
};


int main()
{
    int i, j, k;
    shape *shp;
    shape sh(6, 4);
    Rectangle rec(10, 9);
    Triangle tri(8, 6);
//
    shp = &rec;
    cout<<shp->area()<<endl;

    shp = &tri;
    cout<<shp->area()<<endl;





    return 0;
}
