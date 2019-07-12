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


struct man
{
    int b;
    int inc;
};

typedef pair<int,int>PAIR ;

bool friend operator<( PAIR A, PAIR B)
{
    if(A.first==B.first)
        return A.second<B.Second;
    return A.first<B.first;
}

pair<int,int>P;
int main()
{
    int i,j,k;
    int n,a,b;
    cin>>n;
    vector< pair<int,int> >V[100];
    for(i=0; i<n; i++)
    {
        cin>>a>>b;
        P.first=a;
        P.second=b;
        V[i].PB(P);
    }
    sort(V.begin(), V.end());
}
