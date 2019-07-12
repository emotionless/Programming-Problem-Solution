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
#define LL long long long long
#define ULL unsigned long long long long
#define rep(i,a,b) for(i=a;i<=b;i++)
#define R 11
#define C 101

using namespace std;

long long M[101][101];
long long ans[R][C], ways[R][C];
long long shu[4];
long long r,c;

void printmin(long long l, long long r)
{
    if(l==c-1)
    {
        printf("%d",r+1);
    }
    else
    {
        printf("%d ",r+1);
        printmin(l+1,ways[r][l]);
    }
}

int main()
{
    long i,j,k;
    while(cin>>r>>c)
    {
        for(i=0; i<r; i++)
        {
            for(j=0; j<c; j++)
            {
                scanf("%lld",&M[i][j]);
            }
        }
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                ans[i][j]=2147483646;
            }
        }
        for(i=0; i<r; i++)
            ans[i][c-1]=M[i][c-1];

        for(i=c-2; i>=0; i--)
        {
            for(j=0; j<r; j++)
            {
                shu[0]=(j-1+r)%r;
                shu[1]=j;
                shu[2]=(j+1)%r;
                sort(shu,shu+3);
                for(k=0; k<3; k++)
                {
                    if(ans[shu[k]][i+1]+M[j][i]<ans[j][i])
                    {
                        ans[j][i]=ans[shu[k]][i+1]+M[j][i];
                        ways[j][i]=shu[k];
                    }
                }
            }
        }
        long long mn=2147483646,st=0;
        for(i=0; i<r; i++)
        {
            if(ans[i][0]<mn)
            {
                mn=ans[i][0];
                st=i;
            }
        }
        printmin(0,st);
        printf("\n");
        printf("%lld\n",mn);
        clr(M,0);
        clr(ways,0);
        clr(ans,0);
    }
    return 0;
}
