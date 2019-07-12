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
int main()
{
    freopen("A.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int i,j,k;
    int n;
    char inp[510];
    int m,cases=0;
    scanf("%d",&m);
    getchar();
    while(m--)
    {
        cases++;
        gets(inp);
        int l=strlen(inp);
        int val[30];
        for(i=0; i<30; i++)
            val[i]=0;
        for(i=0; i<l; i++)
        {
            if(isalpha(inp[i]))
            {
                char c=tolower(inp[i]);
                val[c-'a']++;
            }
        }
        sort(val,val+27);
        int res=0;
        for(i=26; i>=0; i--)
        {
            res=res+val[i]*i;
        }
        printf("Case #%d: %d\n",cases,res);
    }
    return 0;
}

