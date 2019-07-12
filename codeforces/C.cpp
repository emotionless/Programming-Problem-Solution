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

using namespace std;


int GCD(int a, int b);

int main()
{
    int n;
    string inp,out;
    cin>>inp;
    cin>>out;
    int l1=inp.length();
    int l2=out.length();
    if(l1!=l2)
    {
        cout<<"NO\n";
    }
    else
    {
        bool p=true;
        int cnt=0;
        for(int i=0; i<l1; i++)
        {
            int cnt0=0,cnt1=0;
            for(i=0; i<l1; i++)
            {
                if(inp[i]=='0')
                    cnt0++;
                if(out[i]=='0')
                    cnt1++;
            }
            if(cnt0==l1 && cnt1<l1)
            {
                cout<<"NO\n";
            }
            else if(cnt1==l1 && cnt0<l1)
            {
                cout<<"NO\n";
            }
            else
                cout<<"YES\n";
        }
    }
    return 0;
}
