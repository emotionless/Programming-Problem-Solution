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
#define MAX (101)
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
    LL num;
    int val;
    Z() {}
    Z(int _, LL __)
    {
        num = _;
        val = __;
    }
    bool operator <(const Z& A) const
    {
        if(val == A.val) return num > A.num;
        return val > A.val;
    }
};

vector<Z>vec;

int main()
{
    int i,j;
    int cases=1;
    LL num;
    int t;
    int m;
    int n;
    cin>>n;
    vector<int>V;
    V.clear();
    map<LL, int>M;
    M.clear();
    for(i = 0; i < n; i++)
    {
        cin>>num;
        M[num]++;
        V.PB(num);
    }

    sort(V.begin(), V.end());

    V.erase(unique(V.begin(), V.end()), V.end());
    int sz = V.size();
    for(i = 0; i < sz; i++)
    {
        vec.PB(Z(V[i], M[V[i]]));
    }
    sort(vec.begin(), vec.end());
    int k = 0;
    vector<LL>res;
    res.clear();
    while(k <= n / 3)
    {
        k++;
        int sz = vec.size();
        LL f = 0, s = 0;
        int parce = 0;
        for(i = 0; i < sz; i++)
        {
            //  cout<<V[i]<<endl;
            if(M[vec[i].num] == 0) continue;
            if(!f)
            {
                f = vec[i].num;
            }
            else if(!s)
            {
                s = vec[i].num;
            }
            else
            {
                res.PB(f);
                res.PB(s);
                res.PB(vec[i].num);
                M[f]--;
                M[s]--;
                M[vec[i].num]--;

                f = s = 0;
                parce++;
            }
            // cout<<f<<endl;
        }
        if(parce == 0) break;
    }
    int szz = res.size();
    cout<<szz/3<<endl;
    for(i = 0; i < szz; i+=3){
        LL a = max(res[i], max(res[i + 1], res[i + 2]));
        LL b = min(res[i], min(res[i + 1], res[i + 2]));
        LL c = res[i] + res[i + 1] + res[i + 2];
        cout<<a<<" "<<c - a - b<<" "<<b<<endl;
    }




    return 0;
}
/*


4 3
0 1 12
0 2 20
1 2 17
3
0 1
0 2
0 3



*/
