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

LL arr[5001];

LL solve(int l, int r)
{
    if(l > r) return 0;
    LL ret = r - l + 1;
    LL mn = 100000000;
    int i;
    for(i = l; i <= r; i++)
    {
        if(arr[i] == 0)
            return min(ret, solve(l, i - 1) + solve(i + 1, r));
        mn = min(arr[i], mn);
    }
    for(i = l; i <= r; i++)
        arr[i] = arr[i] - mn;
    return min(ret, solve(l, r) + mn);
}

int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i, j;
    int a, b, h, m, n;
    cin>>n;
    for(i = 1; i <= n; i++)
        cin>>arr[i];
    LL res = solve(1, n);

    cout<<res<<endl;



    return 0;
}

/*

7 3
5 5 5 5 5 5
1 3 4
4 5 2
6 3 1



*/
