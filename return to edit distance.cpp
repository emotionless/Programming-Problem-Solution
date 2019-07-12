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
#define MAX 1000

using namespace std;
int main()
{
    int i,j,k;
    int n,a1,b;
    int val[1000],a[1000];
    cin>>n;
    map<int,int>M;
    for(i=1; i<=n; i++)
    {
        scanf("%d",&a1);
        M[a1]=i;
    }
    for(i=1; i<=n; i++)
    {
        scanf("%d",&b);
        a[i]=M[b];
    }

    int s[MAX],f1[MAX],f2[MAX],mid;
    int top=0;
    int res=0;
    s[top=0]=-1;
    int maxv=0,minv=0;
    for(i=1; i<=n; i++)
    {
        if(a[i]>s[top])
        {
            s[++top]=a[i];
            f1[i]=top;
        }
        else
        {
            maxv=top;
            minv=0;
            while(1)
            {
                mid=(maxv+minv+1)/2;
                if(mid==maxv)
                    break;
                if(s[mid]<a[i])
                    minv=mid;
                else
                    maxv=mid;
            }
            s[mid]=a[i];
            f1[i]=mid;
        }
        res=max(res,f1[i]);
    }
    printf("%d\n",(n-res)*2);


    return 0;
}

/*

5
1 3 5 4 2
1 5 4 3 2

4
1 2 4 3
3 4 2 1

*/
