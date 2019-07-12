#include<bits/stdc++.h>

#define xx first
#define yy second
#define vsort(v) sort(v.begin(),v.end())
#define clr(a,k) memset(a,k,sizeof a)
#define bclr(b) memset(b,false,sizeof b)
#define LL long long
#define pb push_back
#define MP make_pair
#define MOD 1000000007
#define MX 100000

using namespace std;

struct Z
{
    int t, h, m;
    bool operator<(const Z& A) const
    {
        if(h==A.h) return m>A.m;
        return h<A.h;
    }
};

vector<Z>V;


int main()
{
    int i, j, k;
    int n, h, m;
    int sum = 0;
    cin>>n>>sum;
    Z tmp;
    V.clear();
    for(i=0; i < n; i++)
    {
        cin>>j>>h>>m;
        tmp.t = j;
        tmp.h=h;
        tmp.m=m;
        V.pb(tmp);
    }
    sort(V.begin(), V.end());
    int cnt = 0;
    int sum1 = sum;
    int pre=0;
    int tot=0;
    bool vis[2001];
    memset(vis, false, sizeof vis);

    while(tot<=2500)
    {
        for(i=0; i < n; i++)
        {
            if(vis[i]) continue;
            if(V[i].h>sum1) break;

            if(V[i].t==pre) continue;
            sum1+=V[i].m;
           // cout<<V[i].m<<" ";
            cnt++;
            pre=V[i].t;

            vis[i]=true;
        }
        tot++;
    }

    int cnt2 = 0;
    int sum2 = sum;
    int pre2=1;
    int tot2=0;
    memset(vis, false, sizeof vis);

    while(tot2<=2501)
    {
        for(i=0; i < n; i++)
        {
            if(vis[i]) continue;
            if(V[i].h>sum2) break;

            if(V[i].t==pre2) continue;
            sum2+=V[i].m;
            cnt2++;
            pre2=V[i].t;
            cout<<i<<" ";

            vis[i]=true;
        }
        tot2++;
    }


    cout<<max(cnt,cnt2)<<endl;


    return 0;
}
/*


5 4
0 3 1
0 4 5
1 4 1
0 10 2
1 12 1


*/
