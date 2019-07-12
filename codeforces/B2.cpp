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
#define eps 1e-9
#define PB(A) push_back(A)
#define clr(a,b) memset(a,b,sizeof(a))
#define LL long long
#define ULL unsigned long long
#define rep(i,a,b) for(i=a;i<=b;i++)
#define loop(b) for(int i=1;i<=b;i++)

using namespace std;


int GCD(int a, int b);

long go[100001];
map<long, bool>M;
int main()
{
    long i,j,k;
    long n,s,t;
    cin>>n>>s>>t;
    for(i=1; i<=n; i++)
    {
        scanf("%d",&go[i]);
    }

    long cnt=0;
    long curr=s,next;
    bool c=0;
    if(s==t)
    {
        cout<<0<<endl;
    }
    else
    {
        while(1)
        {
            M[curr]=true;
            next=go[curr];
            if(M[next])
            {
                c=1;
                break;
            }
            cnt++;
            if(next==t)
                break;
            curr=next;
        }
        if(c)
            cout<<-1<<endl;
        else
            cout<<cnt<<endl;
    }
    M.clear();
    return 0;
}
