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

using namespace std;
int main()
{
    int i,j,k;
    int n;
    bool vis[310];
    string str;
    cin>>str;
    int l=str.length();
    int res=0;
    clr(vis,false);
    for(i=0; i<l; i++)
    {
        if(vis[i])
            continue;
        res++;
        char ch=str[i];
        j=i+1;
        for(k=j; k<l; k++)
        {
            if(str[k]=='.')
                continue;
            if(ch!=str[k])
            {
                vis[k]=true;
                ch=str[k];
                str[k]='.';
            }
        }
    }
    cout<<res<<endl;
}
