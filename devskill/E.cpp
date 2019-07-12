#include<bits/stdc++.h>

#define xx first
#define yy second
#define all(a) a.begin(), a.end()
#define vsort(v) sort(all(v))
#define UNIQUE(a)  sort(all(a)); a.erase(unique(all(a)), a.end())
#define clr(a,k) memset(a,k,sizeof a)
#define bclr(b) memset(b,false,sizeof b)
#define fr(i, a) for(i = 0; i < a; i++)
#define frr(i,a) for(i = a - 1; i >= 0, i--)
#define LL long long
#define pb push_back
#define mp make_pair
///***** bit *****///
#define check_bit(a, b) (a&(1<<b))
#define set_bit(a, b) (a|(1<<b))
#define total_bit(a) __builtin_popcount(a)
///***** Input / Output *****///
#define s1(a) scanf("%d", &a)
#define s2(a, b) scanf("%d %d", &a, &b)
#define s3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define p1(a) printf("%d", a)
#define p2(a, b) printf("%d %d", a, b)
#define p3(a, b, c) printf("%d %d %d", a, b, c)

#define MOD 1000000007
#define MX 1000009
#define LIMIT 1000000000000000ll
#define INT_MAX1 1000000000000001ll
#define s(a) scanf("%d", &a)


LL modulo(LL a, LL b, LL c)
{
    LL res = 0ll, tmp = a;
    while(b > 0)
    {
        if(b % 2 == 1)
            res = (res + tmp) % c;
        tmp = (2*tmp) % c;
        b = b / 2;
    }
    return res;
}


template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)return 1;
    if(e%2==0)
    {
        T t=bigmod(p,e/2,M);
        return modulo(t,t, M)%M;
    }
    return modulo(bigmod(p,e-1,M), p,M) % M;
}
template <class T> inline T gcd(T a,T b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
template <class T> inline T modinverse(T a,T M)
{
    return bigmod(a,M-2,M);
}



using namespace std;



int main()
{

    int i, j, k;
    int t, cases = 1;
    s(t);
    LL a, b, c;
    while(t--)
    {

        scanf("%lld %lld %lld", &a, &b, &c);
        printf("Case %d: %lld\n",cases++,  bigmod(a, b, c));
    }




    return 0;
}

/*

5
9 2 3 4 6
5
10 7 3 2 1
*/
