#include <bits/stdc++.h>

#define LL long long
#define MAX 100000
#define MD 1000000007
#define N 1000007
#define check_bit(a,b) (a & (1<<b))
#define PB push_back
#define FOR(aa,nn) for(aa=0; aa<nn; aa++)


using namespace std;


LL bigmod(LL p,LL e,LL M)
{
    if(e==0)return 1;
    if(e%2==0)
    {
        LL t=bigmod(p,e/2,M);
        return (t*t)%M;
    }
    return (bigmod(p,e-1,M)*p)%M;
}




LL modinverse(LL a,LL M)
{
    return bigmod(a,M-2,M);
}


int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    string str, tmp;
    int t, x;
    LL n;
    cin>>t;
    while(t--){
    cin>>n;

    LL tot = (n * (n - 1)) / 2ll;

    LL per = tot / n;
    LL rest = tot % n;

    LL res1 = (bigmod(per + 1, 2ll, MD) * rest) % MD;
    res1 = (res1 + ((bigmod(per, 2ll, MD) % MD) * (n - rest)) % MD) % MD;
    n--;
    LL res2 = (((((n * (n + 1)) % MD) * (2ll * n + 1)%MD) % MD)* modinverse(6ll, MD)) % MD;
    cout<<res1<<" "<<res2<<endl;




    }


    return 0;
}

/*

*/
