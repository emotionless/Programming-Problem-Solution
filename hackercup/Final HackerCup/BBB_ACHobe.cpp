/*******************************************************************************
 *                                                                             *
 *             ==>>BG_PeaceMind(BISHAL)                            @NEPAL      *
 *******************************************************************************/
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
#define MX  10000

struct Trie
{
	int num,next[27];
}trie[MX*27];

int nw;
char s[MX];

void Ins(char s[])
{
	int p=1;
	for(int i=0;s[i];i++)
    {
		if (trie[p].next[s[i]-'a']==0)
		{
			trie[p].next[s[i]-'a']=++nw;
			trie[nw].num=0;
		}
		p=trie[p].next[s[i]-'a'];
		trie[p].num++;
    }
}

int Srch(char s[])
{
	int p=1,cnt=0;
	for(int i=0;s[i];i++)
	{
		if (trie[p].num==1)
        {
            //cout<<cnt<<endl;
            return cnt;
        }
		//printf("%c",s[i]);
		cnt++;
		p=trie[p].next[s[i]-'a'];
	}
	return cnt;
}

int main()
{
    int tc,n,cs=1,i,j,k;
    S(tc);
    while(tc--)
    {
        clr(trie);
        S(n);
        getchar();
        int sm=0;
        nw=1;
        fr(i,0,n-1)
        {
           gets(s);
           Ins(s);
           sm+=Srch(s);
           nl;
        }
        nl;
        printf("Case #%d: %d\n",cs++,sm);
    }
    return 0;
}

