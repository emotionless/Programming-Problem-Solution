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
#define MX 200009
#define PB push_back
#define MOD 1000000007



using namespace std;

/*

LL gcd(LL a,LL b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}

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




bool is_prime[MAX];
L prime[MAX];

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
}


long NOD(long n)
{
    int  i,j,k;
    long sq=sqrt(n);
    long res=1;
    for(i=0; prime[i]<=sq; i++)
    {
        int cnt=1;
        if(n%prime[i]==0)
        {
            while(n%prime[i]==0)
            {
                cnt++;
                n=n/prime[i];
                if(n==1) break;
            }
            res*=cnt;
            sq=sqrt(n);
        }
    }
    if(n>1) res*=2;
    return res;
}
*/

#define MAXX 100000

struct Z
{
    LL c;
    bool is;
    int ind;
    bool operator <(const Z& A) const
    {
        return c < A.c ;
    }
};

vector<Z>V1, V2;

LL sum1[MX];
LL sum2[MX];

int main()
{
    LL m;
    int  i;
    int n;
    cin>>n>>m;
    Z tmp;
    for(i = 0; i < n; i++)
    {
        cin>>tmp.c>>tmp.is;
        tmp.ind = i + 1;
        if(tmp.is)
            V1.PB(tmp);
        else
            V2.PB(tmp);
    }

    sort(V1.begin(), V1.end());
    reverse(V1.begin(), V1.end());
    sort(V2.begin(), V2.end());
    reverse(V2.begin(), V2.end());

    int a = 0, b = 0;
    LL res = 0;
    int sz1 = V1.size();
    int sz2 = V2.size();
    int j = 0, k = 0;
    for(i = 0; i < n; i++)
    {
        LL f = 0, s = 0;
        if(j >= 0 && j < sz1)
            f = V1[j++].c;
        if(k >= 0 && k < sz2)
            s = V2[k++].c;
        if((f >= s) && f)
        {
            a++;
            res += f;
            k--;
        }
        else if(s)
        {
            b++;
            res += s;
            j--;
        }
        if(res >= m) break;
    }
    vector<int>R;
    R.clear();
    int tot = a + b;
    for(i = 0; i < sz1; i++)
        sum1[i] = sum1[i - 1] + V1[i].c;
    for(i = sz1; i >= 1; i--)
        sum1[i] = sum1[i - 1];
    for(i = 0; i < sz2; i++)
        sum2[i] = sum2[i - 1] + V2[i].c;
    for(i = sz2; i >= 1; i--)
        sum2[i] = sum2[i - 1];

    for(i = min(sz1, a + b); i >= 0; i--)
    {
        LL sss = sum1[i];
        int rst = tot - (i);

        if(rst >= 0)
            sss += sum2[rst];
        if(sss >= m)
        {
            for(j = 0; j < i; j++)
                R.push_back(V1[j].ind);
            for(j = 0; j < rst; j++)
                R.PB(V2[j].ind);
            break;
        }
    }
    cout<<tot<<" "<<i<<endl;
    sort(R.begin(), R.end());
    int tt = R.size();
    for(i = 0; i < tt; i++)
        cout<<R[i]<<" ";
















    return 0;
}
/*


4 7
3 1
7 0
5 1
4 1



*/
