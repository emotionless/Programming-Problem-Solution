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
#define pii pair<int, int>
#define mp make_pair
#define vi vector<int>
#define vll vector<long long>
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
#define MAX 200009


using namespace std;


LL bigmod(LL p,LL e,LL M)
{
    if(e==0)return 1;
    if(e%2ll==0)
    {
        LL t=bigmod(p,e/2,M);
        return (t*t)%M;
    }
    return (bigmod(p,e-1,M)*p)%M;
}

int main()
{
    LL tc,t,n, cs=1,i,j,k;
    string str;
    int m;
    cin>>n;
    cin>>str;
    LL len = str.length();
    LL s = 0, c = 0, g = 0, a = 0;
    t = 0;
    for(i = 0; i < len; i++)
    {
        if(str[i] == 'T' && !t)
            s++, t = 1;
        if(str[i] == 'C' && !c)
            s++, c= 1;
        if(str[i] == 'A' && !a)
            s++, a = 1;
        if(str[i] == 'G' && !g)
            s++, g = 1;
    }
    cout<<bigmod(s, n, MOD)<<endl;

















    return 0;
}

/*

32
ACTGACTGACTGACTGACTGACTGACTGACTG

*/
