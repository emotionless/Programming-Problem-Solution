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

using namespace std;

long long mat[1001][1001];

int main()
{
    int i,j,k;

    for(i=0; i<1001; i++)
    {
        for(j=0; j<=i; j++)
        {
            if(i==0 || j==0 || i==j)
                mat[i][j]=1;
            else
                mat[i][j]=(mat[i-1][j]+mat[i-1][j-1])%1000000007;
        }
    }
    int n,r;
    while(cin>>n>>r)
    {
        cout<<mat[n][r]<<endl;
    }
    return 0;
}
