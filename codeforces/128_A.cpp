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



int main()
{
    int i,k,j,n;
    int x,a,b,ca,cb,t;
    cin>>x>>t>>a>>b>>ca>>cb;
    bool p=true;
    for(i=0; i<t; i++)
    {
        int tot=(a-ca*i);
        if(tot==x)
        {
            cout<<"YES"<<endl;
            p=0;
            break;
        }
        for(j=0; j<t; j++)
        {
            tot=(a-ca*i)+(b-cb*j);
            if(tot==x)
            {
                cout<<"YES"<<endl;
                p=0;
                break;
            }
            tot=(b-cb*j);
            if(tot==x)
            {
                cout<<"YES"<<endl;
                p=0;
                break;
            }
        }
        if(p==0)
        break;
    }
    if(x==0)
        cout<<"YES"<<endl;
    else if(p)
        cout<<"NO\n";



    return 0;
}

/*



*/
