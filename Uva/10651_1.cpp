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
int recur(string s);
int cnt;

map<string, int>M;

int main()
{
    int i,j,k;
    int n,t;
    string inp;
    scanf("%d",&t);
    while(t--)
    {
        cin>>inp;
        cnt=100;
        int res=recur(inp);
        printf("%d\n",res);
    }
    return 0;
}

int recur(string s)
{
    if(M[s])
        return M[s];
    string t=s;
    for(int i=0; i<11; i++)
    {
        if(s[i]=='o' && s[i+1]=='o')
        {
            if(i+2<12 && s[i+2]=='-')
            {
                s[i+2]='o';
                s[i]=s[i+1]='-';
                M[s]=recur(s);
                s=t;
            }
            if(i-1>=0 && s[i-1]=='-')
            {
                s[i-1]='o';
                s[i]=s[i+1]='-';
                M[s]=recur(s);
                s=t;
            }
        }
    }
    int c=0;
    for(int i=0; i<12; i++)
        if(s[i]=='o')
            c++;
    if(c<cnt)
        cnt=c;
    return cnt;
}

//  ---oo-------
