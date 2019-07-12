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

#define INFILE() freopen("laser_maze.txt","r",stdin)
#define OUTFILE()freopen("outC222.txt","w",stdout)
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
#define MX  2002
#define inf 1000000000000LL
#define MD  1000000009LL

int cs,a,b,n;

ll dp[MX*2][MX][3];
int dpp[MX*2][MX][3];

ll go(int pos,int A,int ls,int B)
{
    if(pos==n) return (A==a && B==b);
    ll &ret=dp[pos][A][ls];
    int &rett=dpp[pos][A][ls];
    if(rett==cs) return ret;
    rett=cs;
    ret=0;
    if(pos==0)
    {
        ret=(ret+go(pos+1,A+1,0,B))%MD;
    }
    else
    {
       if(A>B+1) ret=(ret+go(pos+1,A,1,B+1))%MD;
       if(A>B) ret=(ret+go(pos+1,A+1,0,B))%MD;
    }
    return ret;
}

int main()
{
    int tc,i,j;
    cs=1;
    S(tc);
    while(tc--)
    {
        char ch;
        scanf("%d %c %d",&a,&ch,&b);
        cout<<a<< " : "<<b<<endl;
        n=a+b;
        cout<<n<<endl;
        ll ans1=go(0,0,1,0);
       // ll ans2=go2(0,0,0);
       cout<<ans1<<endl;
       cs++;
    }
    return 0;
}
