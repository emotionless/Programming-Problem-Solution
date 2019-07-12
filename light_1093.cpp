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
int MAXN=1000001;
int MAX[MAXN],MIN[MAXN];






int main()
{
    int i;
    int n,q,num,cases=0,t;

    scanf("%d %d",&n,&q);
    node *root=new node(1,n);
    rep(i,1,n)
    {
        scanf("%d",&num);
        insert(root,i,num);
    }
    int res=0;
    for(i=1; i<=n-q+1; i++)
    {
        int a,b;
        a=i;
        b=i+q-1;
        int f=query1(root,a,b);
        int s=query2(root,a,b);
        res=max(res,f-s);
    }
    printf("Case %d: ",++cases);
    printf("%d\n",res);
    return 0;
}
