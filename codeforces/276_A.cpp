#include <bits/stdc++.h>

#define LL long long
#define MX 2009
#define clr(aa, bb) memset(aa, bb, sizeof aa)
#define MD 1000000007
#define check_bit(a,b) (a & (1<<b))
#define set_bit(a,b) (a | (1<<b))
#define PB push_back
#define FOR(aa,nn) for(aa=0; aa<nn; aa++)
#define vi vector<int>
#define vll vector<long long>
#define mp make_pair
#define pi pair<int, int>
#define ll long long
#define MOD  1000000007ll
#define check(aa , bb) (aa & (1<<bb))
#define PB push_back
#define MX 1000000000000000009ll

#define PI 3.14159265358979323846264338328

using namespace std;
int n,mx;
int nbit;

LL dp[35][35];
LL a, b;

LL solve(int pos, int tot, LL mask)
{
    if(pos == n)
    {
        if(mask <= b && tot == nbit)
            return mask;
        return MX;
    }
    LL &ret = dp[pos][tot];
    if(ret != -1) return ret;
    ret = MX;
    if(check(a, pos))
        ret = solve(pos + 1, tot + 1, set_bit(mask, pos));
    else
        ret = min(solve(pos + 1, tot + 1, set_bit(mask, pos)), solve(pos + 1, tot, mask));
    cout<<pos<<" "<<tot<<" "<<mask<<" "<<ret<<endl;
    return ret;
}




int bits(LL n)
{
    int ret = 0;
    for(LL i = 0; i < 32; i++)
    {
        if(check(n, i))
            ret = i;
    }
    return ret;
}



int main()
{
    int i, j, k;

    int t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;

        for(i = 63; i <)


    }
    return 0;
}

/*

4
4 3 3 3



*/
