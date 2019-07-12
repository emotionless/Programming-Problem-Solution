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
#define MAX 200009


using namespace std;


int main()
{
    LL r, x, y,x1,y1;
    cin>>r>>x>>y>>x1>>y1;
    r = r * 2;
    LL len = ((x1-x) * (x1-x)  + (y1-y) * (y1-y));
    r = r * r;
    LL res = len / r + (len%r?1:0);
    double tr = res;

    double rs = sqrt(tr);
    LL a = rs;
    if(rs == a)
    cout<<a<<endl;
    else
        cout<<a+1<<endl;








    return 0;
}

/*

3 2
-4 -60 -30
1 2
2 3



*/
