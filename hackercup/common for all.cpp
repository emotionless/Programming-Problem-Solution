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
#define MAX 10000009


using namespace std;



int main()
{

    int t,cs=1,i,j,k;

    cin>>t;
    char tmp;
    LL n, m;
    while(t--)
    {
        cin>>n>>m;
        if((n*m)%3ll==0)
            cout<<"YES"<<endl;
        else if(n < 3 || m < 3)
            cout<<"NO "<<(n%3)*(m%3)<<endl;
        else
            cout<<"NO "<<(n*m)%3<<endl;

    }
    return 0;
}

/*

5
0-0
1-0
2-0
3-0
4-3


*/
