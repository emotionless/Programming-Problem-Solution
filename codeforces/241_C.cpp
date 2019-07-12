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
#define MD 1000000007
#define N 1000007
#define check_bit(a,b) (a & (1<<b))
#define PB push_back
#define FOR(aa,nn) for(aa=0; aa<nn; aa++)


using namespace std;

struct Z
{
    int id, c, p;
    bool operator<(const Z& A) const
    {
        if(A.p==p) return A.c>c;
        return A.p<p;
    }
};

struct ZZ
{
    int idd, seat;
    bool operator<(const ZZ& A) const
    {
        return A.seat>seat;
    }
};

vector<Z>V;
vector<ZZ>VV;
bool vis[1003];

int BS(int num)
{
    int st=0, ed=VV.size()-1;
    int mid;
    while(st<ed)
    {
        mid=(st+ed)/2;
        if(VV[mid].seat>=num)
            ed=mid;
        else
            st=mid+1;
    }
    for(int i=ed; i<VV.size(); i++)
        if(!vis[i] && VV[i].seat>=num)
            return i;
    return VV.size();
}

struct ZZZZ
{
    int id,pos;
    bool operator<(const ZZZZ& A) const{
    return A.id>id;
    }
};

int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    int a,b;
    Z tmp;
    int n;
    vector<ZZZZ>res;
    cin>>n;

    for(i=0; i<n; i++)
    {
        tmp.id=i;
        cin>>tmp.c;
        cin>>tmp.p;
        V.PB(tmp);
    }
    sort(V.begin(), V.end());
    LL sum=0;
    int q;
    cin>>q;
    ZZ tmpp;
    for(i=0; i<q; i++)
    {
        cin>>a;
        tmpp.idd=i;
        tmpp.seat=a;
        VV.PB(tmpp);
    }
    sort(VV.begin(), VV.end());

    for(i=0; i<n; i++)
    {

        int p=V[i].p;
        int c=V[i].c;
        int pos=BS(c);
      //  cout<<c<<" "<<pos<<endl;
        if(pos<q)
        {
            ZZZZ tmppp;
            sum+=p;
            tmppp.id=(V[i].id);
            tmppp.pos=(VV[pos].idd);
            vis[pos]=true;
            res.PB(tmppp);
        }
    }
    sort(res.begin(), res.end());
    int szz=res.size();
    cout<<szz<<" "<<sum<<endl;
    for(i=0; i<szz; i++)
        cout<<res[i].id+1<<" "<<res[i].pos+1<<endl;
    VV.clear();
    V.clear();
    res.clear();
    memset(vis, false, sizeof vis);
    return 0;
}

/*

3
10 50
2 100
1 100
3
4 6 9

5
2 100
3 300
3 300
1 200
1 100
5
3 2 1 1 1


2
10 10
5 5
1
5


*/
