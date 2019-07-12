#include <bits/stdc++.h>

#define ll long long
#define MAXX 33

using namespace std;

ll ara[MAXX];
ll cum[MAXX];
ll powOfTwo[MAXX];


ll rec(ll n)
{
    if(n < 2) return 0;
    int k = log2(n+1);

    ll till = powOfTwo[k] - 1;


    ll res = cum[k-1];
    ll remain = n - till;
    res = res + max((remain - powOfTwo[k-1]), (ll)0);
    remain--;
/*
    dump(k);
    dump(till);
    dump(res);
    dump(remain);
    dump(n);
    cout<<endl<<endl;
*/
    res += rec(remain);



    return res;
}



int main()
{

    ara[0] = 0;
    cum[0] = 0;
    powOfTwo[0] = 1;

    for(int i=1; i<32; i++)
    {
        ara[i] = cum[i-1] + powOfTwo[i-1];
        cum[i] = cum[i-1] + ara[i];
        powOfTwo[i] = powOfTwo[i-1]*2;
    }


    int kases, kaseno = 0;
    cin>>kases;
    ll in;
    while(kases--)
    {
        cin>>in;
        printf("Case %d: %lld\n", ++kaseno, rec(in));
    }



}
