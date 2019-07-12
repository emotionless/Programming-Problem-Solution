// find example
#include <iostream>     // std::cout
#include <algorithm>    // std::find
#include <vector>       // std::vector

int main ()
{
    // using std::find with array and pointer:
    int myints[] = { 10, 20, 30, 40 };
    int  p;

    p = std::find (myints + 3, myints+4, 30) - myints;
        std::cout << "Element found in myints: " << p << '\n';

    // using std::find with vector and iterator:
    std::vector<int> myvector (myints,myints+4);
    std::vector<int>::iterator it;

    int i = find (myvector.begin(), myvector.end(), 30) - myvector.begin();
    if (it != myvector.end())
        std::cout << "Element found in myvector: " << i << '\n';
    else
        std::cout << "Element not found in myvector\n";

    return 0;
}
