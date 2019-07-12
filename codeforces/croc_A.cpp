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
#define FOR(i,a,b) for(i=a;i<=b;i++)

using namespace std;

int main()
{
    int n,i,k;
    string inp;
    getline(cin,inp);
    int len=inp.length();
    bool l=false;
    i=0;
    while(i<len)
    {
        char c=inp[i];
        if(c==34)
        {
            if(l)
            {
                cout<<">\n";
                l=0;
            }
            else
            {
                cout<<"<";
                l=1;
            }
            i++;
        }
        else if(l)
        {
            cout<<inp[i];
            i++;
        }
        else if(l==false && c!=32)
        {
            cout<<"<";
            while(i<len && inp[i]!=32 && inp[i]!=34)
            {
                cout<<inp[i];
                i++;
            }
            cout<<">\n";
        }
        else
        i++;
    }
    return 0;
}


