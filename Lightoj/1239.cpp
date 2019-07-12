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
#define MX 120001
#define PB push_back
#define PI 3.14159265
#define eps 1e-9


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

struct Z
{
    LL x,y;
    bool operator<(const Z& A)const
    {
        if(x==A.x) return y<A.y;
        return x<A.x;
    }
};

double len(Z a, Z b)
{
    return sqrt((a.y - b.y) * (a.y - b.y) + (a.x - b.x) * (a.x - b.x));
}

double ck_angle(Z A, Z B, Z C)
{
    double a=len(B,C);
    double b=len(A,B);
    double c=len(A,C);

    double angle=(a*a + b*b - c*c)/(2.0*a*b);
    angle = acos(angle);
    return (angle*180.0)/PI;
}


double cross(Z A, Z B, Z C)
{
    return  (C.y - A.y) * (B.x - A.x) - (B.y - A.y) * (C.x - A.x);
}


vector<Z> convex_hull(vector<Z> point)
{
    sort(point.begin(), point.end());
    int n = point.size();

    vector<Z>hull(2*n);


    int k = 0, i;
    for(i = 0; i<n; i++)
    {
        while(k>=2 && cross(hull[k-2], hull[k-1], point[i])<=0) k--;
        hull[k++] = point[i];
    }

    int t = k+1;
    for(i=n-2; i>=0; i--)
    {
        while(k>=t && cross(hull[k-2], hull[k-1], point[i])<=0) k--;
        hull[k++]=point[i];
    }
    hull.resize(k);
    return hull;
}


vector<Z>point;

double dis(Z A, Z B)
{
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}



int main()
{
    int i,j,k;
    int cases=1;
    int t;
    int n, d;
    Z tmp;
    cin>>t;
    while(t--)
    {
        scanf("%d %d", &n, &d);
        for(i=0; i<n; i++)
        {
            cin>>tmp.x;
            cin>>tmp.y;
            point.PB(tmp);
        }
        vector<Z>V = convex_hull(point);

        int sz=V.size();
        double ans=0.0;
        for(i=0; i<sz-1; i++)
        {
            ans+=dis(V[i], V[i+1]);
        }
        printf("Case %d: %.8lf\n", cases++, ans+PI*2.0*d);
        point.clear();
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

