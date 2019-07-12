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
#define rep(i,a,b) for(i=a;i<=b;i++)
#define loop(n) for(int o=1;o<=n;o++)

using namespace std;

struct Z
{
    int x,y,cost;
    bool operator <(const Z& data)const
    {
        return cost > data.cost;
    }
}point;



int mat[100][100];


int main()
{
    int i,j,k;
    int n;
    cin>>n;
    vector<Z>V;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&mat[i][j]);
            point.x=i;
            point.y=j;
            point.cost=mat[i][j];
            V.PB(point);
        }
    }
    sort(V.begin(), V.end());
    int sz=V.size();
    int cnt=0;
    for(i=0;i<sz;i++)
    {
        Z temp=V[i];
        int x=temp.x;
        int y=temp.y;
        int cost=temp.cost;
        if(vis[x][y])
        continue;
        cnt++;

    }
}


void grid(int x, int y)
{
    if(x<0 || x>=row || y<0 || y>=colomn)
    return;
    vis[x][y]=true;

}
