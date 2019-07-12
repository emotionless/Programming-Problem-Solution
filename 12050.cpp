#include <bits/stdc++.h>

///***** Type casting ******///
#define LL long long

///***** C++ **************///
#define set_bit(aa,bb) (aa|(1<<bb))
#define check_bit(aa,bb) (aa&(1<<bb))
#define PB push_back
#define mp(aa, bb) make_pair(aa, bb)
#define aa.xx aa.first
#define aa.yy aa.second

///***** Constant ******//
#define MX 1000007      // 10^6 + 7
#define MOD 1000000007  // 10^9 + 7
#define N 100007        // 10^5 + 7
#define mx 20

using namespace std;

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


/*

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
LL pal[MX];
void init()
{
    pal[1] = pal[2] = 9;
    for(LL i = 3; i < 20; i+=2)
    {
        pal[i] = pal[i + 1] = pal[i - 1] * 10;
    }
}



int main()
{
    int i,j,k;
    int cases=1;
    int t;
    init();
    LL n;
    while(cin>>n && n){
    vector<int>V;

    for(i = 1; i <= mx; i++)
    {
        if(n <= pal[i])
        {
            int m = (i + 1) / 2;
            for(j = 0; j < m; j++)
            {
                int fst = 0;
                if(j == 0)
                    fst = 1;
                for(k = fst; k <= 9; k++)
                {
                    LL p = 1;
                    for(LL a = 1; a < m - j; a++)
                    {
                        p = p * 10;
                    }
                    if(n <= p)
                    {
                        V.PB(k);
                        break;
                    }
                    else
                        n = n - p;
                }
            }
            int len = V.size();
            if(i % 2 == 1)
                len--;
            for(j = len - 1; j >= 0; j--)
                V.PB(V[j]);
            break;
        }
        else
            n = n - pal[i];
    }
    int sz = V.size();
    for(i = 0; i < sz; i++)
    {
        cout<<V[i];
    }
    cout<<endl;
    V.clear();
}





    return 0;
}
/*

2
SQ 1 0
SQ 0 0
SQ 6 0
SQ 5 0



*/
