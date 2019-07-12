#include <cstring>
#include <cassert>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <climits>
#define scan(a) scanf("%d",&a);
#define s2(a,b) scanf("%d %d",&a,&b)
#define PI 2acos(-1.0)
#define s1(a) scanf("%d",&a);
#define INF 2<<15
#define PB(A) push_back(A)
#define clr(a,b) memset(a,b,sizeof(a))
#define LL long long
#define ULL unsigned long long
#define FOR(i,a,b) for(i=a;i<=b;i++)
#define loop(n) for(int o=1;o<=n;o++)
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%ld",&a)

template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)return 1;
    if(e%2==0)
    {
        T t=bigmod(p,e/2,M);
        return (t*t)%M;
    }
    return (bigmod(p,e-1,M)*p)%M;
}
template <class T> inline T gcd(T a,T b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
template <class T> inline T modinverse(T a,T M)
{
    return bigmod(a,M-2,M);
}


using namespace std;

int main()
{
    int i,j;
    int r=cityMap.size();
    int cnt[30];
    for(i=0; i<30; i++)
        cnt[i]=0;
    for(int i=0; i<r; i++)
    {
        int c=cityMap[i].size();
        for(int j=0; j<c; j++)
        {
            if(isalpha(cityMap[i][j]))
            {
                cnt[cityMap[i][j]-'A'+1]++;
            }
        }
    }
    int tem=POIs.size();
    string res="";
    bool vis[30]={false};
    for(j=0; j<tem; j++)
    {
        for(i=1;i<27;i++)
        {
            if(cnt[i]==POIs[j] && vis[i]==false)
            {
                res+=(i+'A'-1);
                vis[i]=true;
            }
        }
    }
    return 0;
}

/*

M....M
...R.M
R..R.R
3 4


XXXXXXXZXYYY
1 8 3


...........
...........
...........
..........T
1


AIAAARRI.......GOAI.
.O..AIIGI.OAAAGI.A.I
.A.IAAAARI..AI.AAGR.
....IAI..AOIGA.GAIA.
I.AIIIAG...GAR.IIAGA
IA.AOA....I....I.GAA
IOIGRAAAO.AI.AA.RAAA
AI.AAA.AIR.AGRIAAG..
AAAAIAAAI...AAG.RGRA
.J.IA...G.A.AA.II.AA
16 7 1 35 11 66

*/
