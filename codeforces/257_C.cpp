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


int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i, j;
    LL n, m, K;
    cin>>n>>m>>K;
    if(K > (n-1)+(m-1))
    {
        cout<<-1<<endl;
        return 0;
    }
    LL ans = 0;
    if(n < m)
        swap(n, m);
    if(K <= (n - 1))
    {
        ans = ((n)/(K+1))*m;
        ans = max(ans, m / (K + 1) * n);
    }
    else
    {
        LL rest = K - (n - 1);
        ans = (m / (rest + 1));

    }
    cout<<ans<<endl;


    return 0;
}

/*

7 3
5 5 5 5 5 5
1 3 4
4 5 2
6 3 1



*/
