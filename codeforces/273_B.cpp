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

#define PI 3.14159265358979323846264338328

using namespace std;



int main()
{
    int i, j, k;
    LL n, m;
    cin>>n>>m;

    LL ans = n - (m - 1);
    ans = (ans * (ans - 1))/2;

    LL ans2 = 0;
    LL a = n / m;
    LL b = n % m;
    ans2 = b * ((a * (a + 1))/2) + (m - b) *((a*(a - 1))/2);
    cout<<ans2<<" "<<ans<<endl;












    return 0;
}

/*

4
4 3 3 3



*/
