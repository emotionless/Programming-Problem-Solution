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
#define xx first
#define yy second
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
map<LL, pair< pair<LL, LL> , int> >M;
pair <LL, LL> P;

void solve(LL a, LL b, int t)
{
  //  cout<<a<<" "<<b<<endl;
    LL mul = a * b;

    if(!mul) return;
    P = make_pair(a, b);
    pair< pair< int, int > , int > PP = make_pair(P, t);
    M[mul] = PP;

    if(a % 2==0)
        solve(a/2, b, t + 1);
    if(a % 3==0)
        solve(a - a/3, b, t + 1);
    if(b % 2==0)
        solve(a, b/2, t + 1);
    if(b % 3==0)
        solve(a, b - b/3, t + 1);
}
int ans1, ans2, ans3, ans4;
LL mn;
void solve1(LL a, LL b, int t)
{
    LL mul = a * b;
    if(M.find(mul) != M.end())
    {
        if(mul)
        {
            pair< pair< LL, LL> , int >PP = M[mul];
            LL res = PP.yy + t;
            if(res < mn)
            {
                mn = res;
                ans1 = PP.xx.xx;
                ans2 = PP.xx.yy;
                ans3 = a;
                ans4 = b;
            }

          //  return;
        }
    }
    if(!mul) return;

    if(a % 2==0)
        solve1(a/2, b, t + 1);
    if(a % 3==0)
        solve1(a- a/3, b, t + 1);
    if(b % 2==0)
        solve1(a, b/2, t + 1);
    if(b % 3==0)
        solve1(a, b - b/3, t + 1);
}





int main()
{
    int i,j;
    int cases=1;
    LL a, b, c, d;
    cin>>a>>b;
    cin>>c>>d;
    mn = INT_MAX;
    solve(a, b, 0);
    solve1(c, d, 0);

    if(mn == INT_MAX)
    {
        cout<<-1<<endl;
        return 0;
    }

    cout<<mn<<endl;
    cout<<ans1<<" "<<ans2<<endl;
    cout<<ans3<<" "<<ans4<<endl;




    return 0;
}
/*


12
1 1 1 1 1 1 1 1 1 1 1 1



*/
