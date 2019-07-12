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
#define vi vector<int>
#define vll vector<long long>


using namespace std;

LL seg[4*100001];

void insert(int ind, int st, int ed, int pos, int val)
{
    if(st == ed)
    {
        seg[ind] = val;
        return;
    }
    int mid = (st + ed) / 2;

    int lft = ind * 2;
    int rgt = lft + 1;
    if(pos <= mid)
        insert(lft, st, mid, pos, val);
    else
        insert(rgt, mid + 1, ed, pos, val);
    seg[ind] = seg[lft] + seg[rgt];
}

void update(int ind, int st, int ed, int l, int r, LL mod)
{
    if(st > ed || st > r || ed < l) return;
    if(st == ed)
    {
        seg[ind] = seg[ind] % mod;
        return;
    }
    int mid = (st + ed) / 2;

    int lft = ind * 2;
    int rgt = lft + 1;

    update(lft, st, mid, l, r, mod);
    update(rgt, mid + 1, ed, l, r, mod);

    seg[ind] = seg[lft] + seg[rgt];
}

void update_value(int ind, int st, int ed, int pos, LL val)
{
    if(st == ed)
    {
        seg[ind] = val;
        return;
    }
    int mid = (st + ed) / 2;

    int lft = ind * 2;
    int rgt = lft + 1;

    if(pos <= mid)
        update_value(lft, st, mid, pos, val);
    else
        update_value(rgt, mid + 1, ed, pos, val);
    seg[ind] = seg[lft] + seg[rgt];
}

LL query(int ind, int st, int ed, int l, int r)
{
    if(st == l && ed == r)
        return seg[ind];

    int mid = (st + ed) / 2;

    int lft = ind * 2;
    int rgt = lft + 1;
    if(r <= mid)
        return query(lft, st, mid, l, r);
    else if(l > mid)
        return query(rgt, mid + 1, ed, l, r);
    else
        return query(lft, st, mid, l, mid) + query(rgt, mid + 1, ed, mid + 1, r);

}


int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    int a,b;
    int n, m;
    LL val;
    cin>>n>>m;

    for(i = 1; i <= n; i++)
    {
        cin>>val;
        insert(1, 1, n, i, val);
    }
    int l, r, pos, op;
    while(m--)
    {
        cin>>op;
        if(op == 1)
        {
            cin>>l>>r;
            cout<<query(1, 1, n, l, r)<<endl;
        }
        else if(op == 2)
        {
            cin>>l>>r>>val;
            update(1, 1, n, l, r, val);
        }
        else
        {
            cin>>pos>>val;
            update_value(1, 1, n, pos, val);
        }
    }

    return 0;
}

/*

7 3
5 5 5 5 5 5
1 3 4
4 5 2
6 3 1



*/
