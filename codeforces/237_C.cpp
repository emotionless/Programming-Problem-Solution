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
#define MOD 1000000000+7
#define N 1000007
#define check_bit(a,b) (a & (1<<b))
#define PB push_back
#define FOR(aa,nn) for(aa=0; aa<nn; aa++)


using namespace std;

struct Z
{
    int dis, pos;
    Z() {}
    Z(int a, int b)
    {
        dis=a;
        pos=b;
    }
    bool operator<(const Z& A) const
    {
        return dis<A.dis;
    }
};

int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    int a,b,K;
    int n,g;
    vector<Z>V;
    vector<int>res, con[100001];
    cin>>n>>K;
    for(i=1; i<=n; i++)
    {
        int dis;
        cin>>dis;
        con[dis].PB(i);
        V.PB(Z(dis, i));
    }
    sort(V.begin(), V.end());

    if(V[0].dis!=0)
    {
        cout<<-1<<endl;
        return 0;
    }
    if(n>1)
    {
        if(V[0].dis==V[1].dis)
        {
            cout<<-1<<endl;
            return 0;
        }
    }
    int con_num[100001];

    memset(con_num, 0, sizeof con_num);
   // vector<int>res;
    for(i=1; i<n; i++)
    {
        int cd=V[i].dis;
        int cp=V[i].pos;
        for(j=0; j<con[cd-1].size(); j++)
        {
            int cn=con[cd-1][j];
            if(con_num[cn]<K)
            {
                res.PB(cn);
                res.PB(cp);
                con_num[cn]++;
                con_num[cp]++;
                break;
            }
        }
        if(j==con[cd-1].size())
        {
            cout<<-1<<endl;
            return 0;
        }
    }
    int m=res.size();
    cout<<m/2<<endl;

    for(i=0; i<m; i+=2)
        cout<<res[i]<<" "<<res[i+1]<<endl;
    V.clear();
    res.clear();
    for(i=0; i<=n; i++)
        con[i].clear();

    return 0;
}

/*

10 6
1 1 0 2 2 3 3 4 4 5

*/
