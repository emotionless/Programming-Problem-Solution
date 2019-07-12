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

#define LL long long
#define MX 5000+7
#define MOD 1000000000+7
#define N 1000007
#define clrdp(aa) memset(aa, -1, sizeof aa)
#define zero(aa) memset(aa, 0, sizeof aa)
#define check_bit(a,b) (a & (1<<b))
#define set_bit(a,b) (a | (1<<b))
#define PB push_back
#define FOR(aa,nn) for(aa=0; aa<nn; aa++)


using namespace std;

string num;
LL dp[1<<16][21];
LL mx;
int sz, m, base;

LL solve(LL mask, int md)
{
    if(mask==mx)
    {
        if(md%m==0) return 1;
        return 0;
    }
    LL &ret=dp[mask][md];
    if(ret!=-1) return ret;
    ret=0;
    md=md*base;
    for(int i=0; i<sz; i++)
    {
        int cn=num[i]-'0';
        if(cn>9)
            cn=num[i]-'A'+10;
        if(check_bit(mask, i)) continue;
        ret+=solve(set_bit(mask, i), (md+cn)%m);
    }
   // cout<<mask<<" "<<ret<<endl;
    return ret;
}

int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    int cases=0,a,b, t;
    cin>>t;
    while(t--)
    {
        cin>>base>>m;
        cin>>num;
        sz=num.size();
        mx=(1<<sz)-1;

        clrdp(dp);

        LL res=solve(0, 0);
        cases++;
        cout<<"Case "<<cases<<": "<<res<<endl;
    }
    return 0;
}

/*
1
16 2
ABCDEF0123456789

*/
