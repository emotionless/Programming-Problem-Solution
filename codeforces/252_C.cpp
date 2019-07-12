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
#define clr(aa, bb) memset(aa, bb, sizeof aa)
#define MD 1000000007
#define N 1000007
#define check_bit(a,b) (a & (1<<b))
#define PB push_back
#define FOR(aa,nn) for(aa=0; aa<nn; aa++)
#define vi vector<int>
#define vll vector<long long>


using namespace std;
bool vis[3001][3001];

int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    int a,b;
    int n,m, k, p;

    scanf("%d%d%d",&n,&m,&k);

    i=1;
    j=0;
    int l=0;
    for(p=1; p<k; p++)
    {
        if(!l)
            j++;
        else
            j--;
        if(j>m)
            j=m, i++, l=1;
        else if(j<1)
            j=1, i++, l=0;
        printf("2 ");
        cout<<i<<" "<<j;
        vis[i][j]=1;
        if(!l)
            j++;
        else
            j--;
        if(j>m)
            j=m, i++, l=1;
        else if(j<1)
            j=1, i++, l=0 ;

        vis[i][j]=1;
        cout<<" "<<i<< " "<<j;
            printf("\n");
    }
    printf("%d",n*m-((k-1)*2));

    if(l==0)
    {
        for(k=j+1; k<=m; k++)
            cout<<" "<<i<<" "<<k;
        i++;
        if(i<=n){
        for(j=m; j>=1; j--)
            printf(" %d %d",i, j);
        }
    }
    else
    {
        for(k=j-1; k>=1; k--)
            cout<<" "<<i<<" "<<k;
    }

    for(k=i+1; k<=n; k++)
    {
        for(j=1; j<=m; j++)
            printf(" %d %d",k, j);
        k++;
        if(k>n) break;
        for(j=m; j>=1; j--)
            printf(" %d %d",k, j);
    }
    return 0;
}

/*

7 3
5 5 5 5 5 5
1 3 4
4 5 2
6 3 1



*/
