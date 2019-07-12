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
#define check_bit(a,b) (a & (1<<b))
#define PB push_back
#define FOR(aa,nn) for(aa=0; aa<nn; aa++)


using namespace std;


int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    int a,b;
    int n,g,m;
    string str;

    cin>>n;
    cin>>str;

    bool vis[3001];
    memset(vis, false, sizeof vis);
    int res=0;
    bool first=true;
    for(i=0; i<n; i++)
    {
        if(vis[i]) continue;
        if(str[i]=='L' && first)
        {
            for(j=i-1; j>=0 && str[j]=='.'; j--)
            {
                vis[j]=true;
            }
        }
        else if(str[i]=='R')
        {
            first=false;
            int cnt=0;
            for(j=i+1; j<n && str[j]=='.'; j++)
            {
                cnt++;
                vis[j]=true;
            }
            i=j;
            if(cnt%2==1 && str[j]=='L')
                res++;
        }
    }

    for(i=0; i<n; i++)
    {
        if(!vis[i] && str[i]=='.')
            res++;
    }
    cout<<res<<endl;




    return 0;
}

/*

4544545454

*/
