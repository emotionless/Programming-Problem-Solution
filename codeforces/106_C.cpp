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
#define pii pair<int, int>

#define MOD 1000000007
#define MAX 200009


using namespace std;

vector< pii > V;
int ans[MAX];
int main()
{
    int tc,cs=1,i,j,k;
    int n, m;
    cin>>n;
    pii tmp;
    for(i = 0; i < n; i++)
    {
        cin>>tmp.first;
        tmp.second = i + 1;
        V.pb(tmp);
    }
    sort(V.begin(), V.end());
    reverse(V.begin(), V.end());
    int f = 0, s = 0, fv = 0, sv = 0;
    for(i = 0; i < n; i++)
    {
        if(f == s)
        {
            if(fv <= sv)
            {
                f++;
                fv += V[i].first;
                ans[V[i].second] = 1;
            }
            else
            {
                s++;
                sv += V[i].second;
                ans[V[i].second] = 2;
            }
        }
        else if(f <= s)
        {
            f++;
            fv += V[i].first;
            ans[V[i].second] = 1;
        }
        else
        {
            s++;
            sv += V[i].second;
            ans[V[i].second] = 2;
        }
    }
    cout<<f<<endl;
    for(i = 1; i <= n; i++)
        if(ans[i] == 1)
            cout<<i<<" ";
    cout<<endl;
    cout<<s<<endl;
    for(i = 1; i <= n; i++)
        if(ans[i] == 2)
            cout<<i<<" ";

    return 0;
}

/*

3 2
-4 -60 -30
1 2
2 3



*/
