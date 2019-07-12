#include <bits/stdc++.h>

#define LL long long
#define MX 5000+7
#define MOD 1000000007
#define N 1000007
#define check_bit(a,b) (a & (1<<b))
#define PB push_back
#define FOR(aa,nn) for(aa=0; aa<nn; aa++)
#define vi vector<int>
#define vll vector<long long>


using namespace std;
int d, k;
LL dp[101][2];

LL solve(int ind, bool is)
{
    if(ind==0)
    {
        if(is) return 1LL;
        return 0LL;
    }
    if(ind<0) return 0;

    LL &ret= dp[ind][is];

    if(ret!=-1) return ret;
    ret=0LL;

    for(int i=1; i<=k; i++)
    {
        ret=(ret+solve(ind-i, is || (i>=d)))%MOD;
    }
    return ret%MOD;
}




int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    int a,b;
    int n, m, u,v;
    cin>>n>>k>>d;

    memset(dp, -1, sizeof dp);

    LL res= solve(n, 0)%MOD;
    cout<<res%MOD<<endl;

    return 0;
}

/*

15
2 1
3 2
4 3
5 4
6 5
7 6
8 7
9 8
10 9
11 10
12 11
13 12
14 13
15 14
0 1 0 0 1 1 1 1 1 1 0 0 0 1 1
1 1 1 1 0 0 1 1 0 1 0 0 1 1 0


*/
