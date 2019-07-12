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
    int i,j,k;
    int n;
    string inp;
    int mod[20];
    int t;
    scanf("%d",&t);
    while(t--)
    {
        cin>>inp;
        int l=inp.length();

        for(i=2; i<13; i++)
        {
            mod[i]=0;
        }
        int div,a;
        scanf("%d",&div);
        bool res=true;
        for(k=0; k<div; k++)
        {
            scanf("%d",&a);
            for(i=0; i<l; i++)
                mod[a]=(mod[a]*10 + (inp[i]-'0'))%a;
            res=res & !mod[a];
        }
        if(res)
            cout<<inp<<" - Wonderful.\n";
        else
            cout<<inp<<" - Simple.\n";
    }
    return 0;
}

