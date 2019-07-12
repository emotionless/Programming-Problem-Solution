#include <bits/stdc++.h>

#define LL long long
#define MX 100009
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
#define MOD 1000000007ll
#define M 100000

#define PI 3.14159265358979323846264338328

using namespace std;

ll bigmod(ll x, int n)
{
    if(n == 0) return 1;
    ll y = bigmod(x, n/2);
    y = y * y % MD;
    if(n&1) y = y * x % MD;
    return y;
}
int sum[100005+7];
int cnt[100005+7];

vector<int>v;
ll func(int X)
{
    int i;

    v.clear();
    for(i=1; i*i<=X; i++) if(X%i == 0)
        {
            v.push_back(i);
            if(i*i != X) v.push_back(X/i);
        }
    sort(v.begin(),v.end());

    ll prod1 = 1, prod2 = 1;
    int sz = v.size();

    v.push_back(100005);
    for(i = 0; i < sz; i++)
        prod1 = prod1 * bigmod(i+1, sum[v[i+1]] - sum[v[i]]) % MD;
    v[sz-1] = 100005;
    for(i = 0; i < sz - 1; i++)
        prod2 = prod2 * bigmod(i+1, sum[v[i+1]] - sum[v[i]]) % MD;

    return (prod1 - prod2 + MD) % MD;
}


int main()
{
    int N,i;

    int n;
    cin>>n;
    int cnt = 0, a, b;
    for(i = 0; i < n; i++)
    {
        cin>>a>>b;
        if(b - a >= 2)
            cnt++;
    }
    cout<<cnt<<endl;

    return 0;
}

/*





*/
