#include<bits/stdc++.h>

#define ll long long int
#define ull unsigned long long int
#define ld long int
#define llu unsigned long long int
#define lu unsigned long int
#define U unsigned int
#define MOD 1000000009
using namespace std;



int main()
{
    int t;

    ll a, b;
    int cnt = 0;

    cin>>a>>b;
    while(a <= b)

    {
        a = a*3ll;
        b = b*2ll;
        cnt++;
    }
    cout<<cnt<<endl;





    return 0;
}

