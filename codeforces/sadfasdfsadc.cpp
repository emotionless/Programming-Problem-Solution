#include <bits/stdc++.h>

using namespace std;
int main()
{
    int i = 0;
    for(i = 0; i <= 100; i++)
    {
        long long f = pow(16,  round(pow(2.0, (double)i)));
        long long s = pow(2, round(pow(16.0, (double)i)));
        if(f == s)
            cout<<i<<endl<<f<<endl;
    }
    return 0;
}

