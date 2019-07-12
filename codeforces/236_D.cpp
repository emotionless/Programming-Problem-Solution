#include <cstring>
#include <cassert>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <climits>
#define LL long long
#define set_bit(aa,bb) (aa|(1<<bb))
#define check_bit(aa,bb) (aa&(1<<bb))
#define PB push_back
#define MOD 1000000007
#define INF INT_MAX
#define sc(a) scanf("%d", &a)
#define pb push_back
#define pii pair<int, int>
#define mp make_pair

#define LL long long
#define ll long long
#define MAX 1000009
#define SZ(a) a.size()
#define MD 1000000007
#define N 1000007
#define check_bit(a,b) (a & (1<<b))
#define PB push_back
#define FOR(aa,nn) for(aa=0; aa<nn; aa++)


using namespace std;

ll ext_gcd (ll a,ll b,ll &x,ll &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = ext_gcd (b, a%b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return d;
}

///***** Coding start here *****///




bool is_prime[MAX];
LL prime[MAX];
int sz;
bool sieve()
{
    long i,j;
    prime[0]=2;
    int k=1;
    int sq=(sqrt(MAX));
    for(i=3; i<=sq; i+=2)
    {
        if(!is_prime[i])
        {
            for(j=i*i; j<=MAX; j+=(2*i))
                is_prime[j]=1;
        }
    }
    for(j=3; j<=MAX; j+=2)
    {
        if(!is_prime[j])
        {
            prime[k++]=j;
        }
    }
    sz = k;
}


map<LL, int>M;

LL val[5009];

LL arr[5009];

int low_prime(LL a)
{
    int i;
    LL sq = sqrt(a);
    int ret = 0;
    for(i = 0; i < sz && prime[i] <= sq; i++)
    {
        if(a%prime[i] == 0)
        {
            int cnt = 0;
            while(a%prime[i] == 0)
            {
                a = a/prime[i];
                cnt++;
            }
            ret +=  (M[prime[i]])?-cnt:cnt;
        }
    }
    if(a > 1)
    {
        if(M[a]) return ret - 1;
        return ret + 1;
    }

    return ret;
}



int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;

    int n, m;
    int cases = 1;
    int t;
    string str;
    sieve();
    cin>>n>>m;
    for(i = 0; i < n; i++)
        cin>>arr[i];
    for(i = 0; i < m; i++)
    {
        cin>>val[i];
        M[val[i]]=1;
    }

    for(i = n - 1; i >= 0; i--)
    {
        LL gcd = arr[0];
        for(j = 1; j <= i; j++)
            gcd = __gcd(gcd, arr[j]);
        if(low_prime(gcd) < 0)
            for(j = 0; j <= i; j++)
            arr[j] = arr[j]/gcd;
    }
    LL res = 0;

    for(i = 0; i < n; i++)
    {
        int get = low_prime(arr[i]);
//        cout<<i<<" "<<get<<endl;
        res += get;
    }
    cout<<res<<endl;














    return 0;
}
/*


29 1
55296 10368 6912 165888 20736 331776 36864 41472 1152 221184 1728 2304 18432 82944 73728 147456 576 13824 442368 864 288 5184 663552 110592 4608 3456 2592 27648 9216
3


*/

/*


5 1
10 11 12 12 14
5


*/
