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

#define INFILE() freopen("homework.txt","r",stdin)
#define OUTFILE()freopen("OUTho.txt","w",stdout)
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
#define MX  10000000
#define inf 1000000000
#define MD  1000000009LL


int vis[MX+5];
int cnt[12][MX+5];
int main()
{
    INFILE();
    OUTFILE();
    int tc,cs=1,i,j,k;
    for( i=2;i<=MX;i++)
    {
        if(!vis[i])
        {
           for(j=i;j<=MX;j+=i)vis[j]++;
        }
    }

    fr(i,0,10)cnt[i][1]=0;

    for(i=2;i<=MX;i++)
    {
        for(j=1;j<=9;j++)
        {
           if(vis[i]==j) cnt[j][i]=cnt[j][i-1]+1;
           else cnt[j][i]=cnt[j][i-1];
        }
    }
    S(tc);
    while(tc--)
    {
        int a,b;
        S2(a,b);
        S(k);
        if(k>=10)
        {
            printf("Case #%d: 0\n",cs++);
        }
        else
        {
            printf("Case #%d: %d\n",cs++,cnt[k][b]-cnt[k][a-1]);
        }
    }
    return 0;
}
