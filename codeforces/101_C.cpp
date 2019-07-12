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
#define MAX 20009


using namespace std;

pair < int, string > inp[MAX];
vector< pair < string, int > >out;




int main()
{
    int tc,cs=1,i,j,k;
    int n, m;
    cin>>n;
    for(i = 0; i <n; i++)
    {
        cin>>inp[i].yy>>inp[i].xx;
    }
    sort(inp, inp + n);
    for(i = 0; i < n; i++)
    {
        int cn = i;
        int hold = inp[i].xx;
        if(hold > cn)
        {
            cout<<-1<<endl;
            return 0;
        }
        out.insert(out.begin() + hold, make_pair(inp[i].yy, n - i));
    }

    for(i = 0; i < n; i++)
        cout<<out[i].xx<<" "<<out[i].yy<<endl;







    return 0;
}

/*

3 2
-4 -60 -30
1 2
2 3



*/
