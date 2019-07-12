#include <bits/stdc++.h>

#define LL long long
#define MX 100009
#define clr(aa, bb) memset(aa, bb, sizeof aa)
#define MD 1000000007
#define N 1000007
#define check_bit(a,b) (a & (1<<b))
#define set_bit(a,b) (a | (1<<b))
#define PB push_back
#define FOR(aa,nn) for(aa=0; aa<nn; aa++)
#define vi vector<int>
#define vll vector<long long>


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

int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i, j;
    LL y, x, n;
    cin>>x>>y;
    cin>>n;
    LL div = ceil((double)n / 3.0);

    if(div % 2 == 0)    // even
    {
        x = x * (-1);
        y = y * (-1);
        int rest = n % 3;
        if(rest == 0)
            cout<<(bigmod(y - x, 1, MD) + MD)%MD<<endl;
        else if(rest == 1)
            cout<<(bigmod(x, 1, MD) + MD)%MD<<endl;
        else
            cout<<(bigmod(y, 1, MD) + MD)%MD<<endl;
    }
    else
    {
        int rest = n % 3;
        if(rest == 0)
            cout<<(bigmod(y - x, 1, MD) + MD)%MD<<endl;
        else if(rest == 1)
            cout<<(bigmod(x, 1, MD) + MD)%MD<<endl;
        else
            cout<<(bigmod(y, 1, MD) + MD)%MD<<endl;
    }

    return 0;
}

/*

7 3
5 5 5 5 5 5
1 3 4
4 5 2
6 3 1



*/
