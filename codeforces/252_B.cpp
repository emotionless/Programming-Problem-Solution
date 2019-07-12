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

#define LL long long
#define MX 5000+7
#define clr(aa, bb) memset(aa, bb, sizeof aa)
#define MD 1000000007
#define N 1000007
#define check_bit(a,b) (a & (1<<b))
#define PB push_back
#define FOR(aa,nn) for(aa=0; aa<nn; aa++)
#define vi vector<int>
#define vll vector<long long>


using namespace std;

struct Z
{
    int f,d;
    bool operator<(const Z& A)const
    {
        return f < A.f;
    }
};
int have[30001];
int val[30001];

int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    LL a,b;
    int n,m, k, p;

    vector<Z>V;
    V.clear();

    cin>>n>>m;
    for(i=0; i<n; i++)
    {
        Z tmp;
        cin>>tmp.f>>tmp.d;
        V.PB(tmp);
    }
    sort(V.begin(), V.end());
    int res=0;
    int save = m;
    for(i=0; i<4001; i++)
        val[i]=m;
    for(i=0; i<n;)
    {
        int cd = V[i].f;
        int tot = V[i].d;
        for(j=i+1; j<n; j++)
        {
            if(V[i].f==V[j].f)
                tot+=V[j].d;
            else
                break;
        }
        i= j;
        m=val[cd];
        have[cd]= tot;
        int mn = min(m, have[cd]);
        have[cd]-=mn;
        int ss=have[cd];
        res+=mn;
        m=save;
        int mm = min(m, ss);
        res+=mm;
        m=(m-mm);
        val[cd+1]=m;
    }
    cout<<res<<endl;

    return 0;
}

/*

7 3
5 5 5 5 5 5
1 3 4
4 5 2
6 3 1



*/
