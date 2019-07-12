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
    string str,temp;
    int l;
    map<string,bool>mp;
    int n;
    cin>>n;
    map<string,bool>M;
    while(n--)
    {
        cin>>str;
        l=str.length();

        for(i=0; i<l; i++)
        {
            for(j=0; j+i<=l; j++)
            {
                temp=str.substr(i,j);
                M[temp]=true;
                //cout<<temp<<endl;
            }
        }
    }
    string tmp;
    queue<string>Q;
    Q.push("");
    while(!Q.empty())
    {
        tmp=Q.front();
        Q.pop();
        if(tmp!="" && M[tmp]==false)
        {
            cout<<tmp<<endl;
            break;
        }
        for( char i='a'; i<='z'; i++)
        {
            Q.push(tmp+i);
        }
    }
    return 0;
}
