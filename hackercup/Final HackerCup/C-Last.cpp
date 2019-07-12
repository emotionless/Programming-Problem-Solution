/***************************************************************
 *                                                             *
 *             ==>>BG_PeaceMind(BISHAL)                 @NEPAL *
 ***************************************************************/
#include<bits/stdc++.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
#include<math.h>
#include<string>
#include<climits>
#include<algorithm>
#include<sstream>
#include<fstream>
#include<map>
#include<vector>
#include<queue>
#include<set>
#include<stack>
#include<utility>
#include<iomanip>
#define PI acos(-1.0)
#define nl puts("")
#define SZ(x) x.size()
#define pb(x) push_back(x)
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mpr(a,b) make_pair(a,b)
#define S(a) scanf("%d",&a)
#define P(a) printf("%d",a)
#define SL(a) scanf("%lld",&a)
#define S2(a,b) scanf("%d%d",&a,&b)
#define SL2(a,b) scanf("%lld%lld",&a,&b)
#define all(v) v.begin(),v.end()
#define clr(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define fr(i,a,n) for(i=a;i<=n;i++)
#define rf(i,a,n) for(i=n;i>=a;i--)
#define MXE(x) *max_element(all(x))
#define MNE(x) *min_element(all(x))

#define INFILE() freopen("winning_at_sports.txt","r",stdin)
#define OUTFILE()freopen("OutC_final.txt","w",stdout)
#define LB(v,k) lower_bound(v.begin(),v.end(),k)
#define _cin ios_base::sync_with_stdio(0),cin.tie(0)
#define ct(x) cerr<<__LINE__<< ":: "<<#x<<"= "<<x<<endl
#define fi(it,n) for(__typeof(n.begin()) it=n.begin();it!=n.end();it++)
using namespace std;
typedef long long ll;
/// if(q1<=l && r<=q2)
/// atoi( str.c_str() ); // char string to int
/// sprintf(str,"%d",num);// num to char string
///int month[]={-1,31,28,31,30,31,30,31,31,30,31,30,31}; //Not Leap Yr
///int dx[]= {1,0,-1,0};int dy[]= {0,1,0,-1}; //4 Dir
///int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 Dir
///int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight
/************************************************************************
 * /////////////////////////////////////////////////////////////////////*
 ************************************************************************/
///         0123456789
#define MX  2005
#define inf 1000000000000LL
#define MD  1000000007LL

int cs,a,b,n;

ll dp[MX*2][MX];
int dpp[MX*2][MX];

ll go(int pos,int A,int B)
{
    if(pos==n) return (A==a && B==b);
    ll &ret=dp[pos][A];
    int &rett=dpp[pos][A];
    if(rett==cs) return ret;
    rett=cs;
    ret=0LL;
    if(pos==0)
    {
        ret=(ret+go(pos+1,A+1,B))%MD;
    }
    else
    {
       if(A>(B+1)) ret=(ret+go(pos+1,A,B+1))%MD;
       if(A>B) ret=(ret+go(pos+1,A+1,B))%MD;
    }
    return ret;
}

ll go2(int pos,int A,int B)
{
    if(B==b && A<=a) return 1LL;
    if(pos==n) return (A==a && B==b);
    ll &ret=dp[pos][B];
    int &rett=dpp[pos][B];
    if(rett==cs) return ret;
    rett=cs;
    ret=0LL;
    if(pos==0)
    {
        ret=(ret+go2(pos+1,A,B+1))%MD;
    }
    else
    {
       if(A<B) ret=(ret+go2(pos+1,A+1,B))%MD;
       if(A<=B) ret=(ret+go2(pos+1,A,B+1))%MD;
    }
    return ret;
}

int main()
{
    INFILE();
    OUTFILE();
    int tc,i,j,css=1;
    cs=1;
    S(tc);
    while(tc--)
    {
        char ch;
        scanf("%d %c %d",&a,&ch,&b);
        if(b>=a)
        {
            printf("Case #%d: %lld %lld\n",css++,0LL,0LL);
            continue;
        }
        //cout<<a<< " : "<<b<<endl;
        n=a+b;
       // cout<<n<<endl;
        ll ans1=go(0,0,0);
        cs++;
        ll ans2=go2(0,0,0);
       //cout<<ans1<<endl;
        cs++;
        printf("Case #%d: %lld %lld\n",css++,ans1,ans2);
    }
    return 0;
}
