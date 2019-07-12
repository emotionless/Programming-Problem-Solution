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

char inp[10010];

int convert(char c)
{
    if(c>='0' && c<='9')
        return c-'0';
    else if(c>='A' && c<='Z')
        return c-'A'+10;
    else
        return c-'a'+36;
}

void clear()
{
    if(!isalnum(inp[0]))
    {
        int l=strlen(inp);
        for(int i=1; i<=l; i++)
            inp[i-1]=inp[i];
    }
}

char high()
{
    char mx='1';
    int l=strlen(inp);
    for(int i=0; i<l; i++)
        if(inp[i]>mx)
            mx=inp[i];
    return convert(mx)+1;
}

int main()
{
    int i,j,k;
    int n;
    while(scanf("%s",inp)==1)
    {
        clear();
        int sum=0;
        int l=strlen(inp);
        for(i=0; i<l; i++)
        {
            sum+=convert(inp[i]);
        }
        // cout<<sum<<endl;
        int div=high();
        bool p=true;
        for(i=div; i<=62; i++)
        {
            if(sum%(i-1)==0)
            {
                printf("%d\n",i);
                p=false;
                break;
            }
        }
        if(p)
            printf("such number is impossible!\n");
    }
    return 0;
}
