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
    int n,t;
    string a,s;
    scanf("%d",&t);
    getchar();
    map<string,int>M;
    vector<string>V;
    while(t--)
    {
        cin>>s;
        getline(cin,a);
        if(M[s])
        {
            M[s]++;
        }
        else
        {
            M[s]++;
            V.PB(s);
        }
    }
    sort(V.begin(),V.end());
    int l=V.size();
    for(i=0;i<l;i++)
    {
        cout<<V[i]<<" "<<M[V[i]]<<endl;
    }
    V.clear();
    return 0;
}

