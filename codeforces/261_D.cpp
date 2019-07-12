#include <bits/stdc++.h>

#define LL long long
#define MX 1000009
#define clr(aa, bb) memset(aa, bb, sizeof aa)
#define MD 1000000007
#define N 1000007
#define check_bit(a,b) (a & (1<<b))
#define set_bit(a,b) (a | (1<<b))
#define PB push_back
#define FOR(aa,nn) for(aa=0; aa<nn; aa++)
#define vi vector<int>
#define vll vector<long long>


using namespace std;

int seg[4*MX];


void insert(int ind, int st, int ed, int pos, int val)
{
    if(st == ed)
    {
        seg[ind] += val;
        //cout<<"Come "<<pos<< " "<<ind<<endl;
        return;
    }
    int mid = (st + ed) / 2;

    if(pos <= mid)
        insert(ind * 2, st, mid, pos, val);
    else
        insert(ind * 2 + 1, mid + 1, ed, pos, val);
    seg[ind] = seg[ind * 2] + seg[ind * 2 + 1];
}

int query(int ind, int st, int ed, int l, int r)
{
    if(st == l && ed == r){
        //cout<<l<<" "<<r<<" "<<ind<<endl;
        //cin>>l;
        return seg[ind];
    }
    int mid = (st + ed) / 2;
    if(r <= mid)
        return query(ind * 2, st, mid, l, r);
    else if(l > mid)
        return query(ind * 2 + 1, mid + 1, ed, l, r);
    else
        return query(ind * 2, st, mid, l, mid) + query(ind * 2 + 1, mid + 1, ed, mid + 1, r);
}

LL arr[MX];
LL rgt[MX];
LL val[MX];


int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i, j;
    int t;
    int n;
    cin>>n;
    for(i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    map<LL, int>M;
    for(i = 0; i < n; i++)
    {
        int cn = arr[i];
        M[cn]++;
        val[i] = M[cn];
    }
    M.clear();
    for(i = n - 1; i >= 0; i--)
    {
        int cn = arr[i];
        M[cn]++;
        rgt[i] = M[cn];
        insert(1, 1, n, M[cn], 1);
    }
//    for(i = 1; i <=12; i++)
//        cout<<i<<" "<<seg[i]<<endl;
    LL sum = 0;
    for(i = 0; i < n; i++)
    {
        int x = val[i] - 1;
        insert(1, 1, n, rgt[i], -1);
        if(x){
            int get = query(1, 1, n, 1, x);
          //  cout<<i<<" "<<rgt[i]<<" "<<get<<endl;
            sum += (get);
        }
    }
    cout<<sum<<endl;


    return 0;
}

/*

7 3
5 5 5 5 5 5
1 3 4
4 5 2
6 3 1



*/
