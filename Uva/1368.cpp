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
#define max4(a,b,c,d) max(a,max(b,max(c,d)))
#define LL long long
#define ULL unsigned long long
#define rep(i,a,b) for(i=a;i<=b;i++)

using namespace std;


int main()
{
    int i,j,k,l;
    char str[51][1001];
    int n,m;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        for(i=0; i<n; i++)
            scanf("%s",str[i]);
        int a,c,g,t;
        int cnt=0;
        string res="";
        for(j=0; j<m; j++)
        {
            a=c=g=t=0;
            for(i=0; i<n; i++)
            {
                if(str[i][j]=='A') a++;
                else if(str[i][j]=='C') c++;
                else if(str[i][j]=='G') g++;
                else if(str[i][j]=='T') t++;
            }
            int mx=max4(a,c,g,t);
            cnt+=(n-mx);
            if(mx==a) res+='A';
            else if(mx==c) res+='C';
            else if(mx==g) res+='G';
            else if(mx==t) res+='T';
        }
        cout<<res<<endl<<cnt<<endl;
    }
    return 0;
}
