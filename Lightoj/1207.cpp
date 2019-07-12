#include<bits/stdc++.h>

#define xx first
#define yy second
#define vsort(v) sort(v.begin(),v.end())
#define clr(a,k) memset(a,k,sizeof a)
#define bclr(b) memset(b,false,sizeof b)
#define LL long long
#define pb push_back
#define MP make_pair
#define MOD 100009
#define MX 200005

using namespace std;

int seg[4*MX];

void insert(int ind, int st, int ed, int l, int r, int val)
{
    if(st == l && ed == r)
    {
        seg[ind] = val;
        return;
    }
    int mid = (st + ed) / 2;
    if(r <= mid)
        insert(ind * 2, st, mid, l, r, val);
    else if(l > mid)
        insert(ind * 2 + 1, mid + 1, ed, l, r, val);
    else
    {
        insert(ind * 2, st, mid, l, mid, val);
        insert(ind * 2 + 1, mid + 1, ed, mid + 1, r, val);
    }

}

int query(int ind, int st, int ed, int pos, int mx)
{
    if(st == ed)
    {
        if(seg[ind])
            mx = max(mx, seg[ind]);
        return mx;
    }
    int mid = (st + ed)/2;
    if(seg[ind])
        mx = max(mx, seg[ind]);
    if(pos <= mid)
        return query(ind * 2, st, mid, pos, mx);
    else
        return query(ind * 2 + 1, mid + 1, ed, pos, mx);
}


int arr[MX];

int main()
{
    int i, j, k;

    int n;
    int t, a, b, cases = 1;
    scanf("%d", &t);
    while(t--)
    {
            scanf("%d", &n);
        memset(seg, 0, sizeof seg);
        for(i = 0; i < n; i++)
        {
                scanf("%d %d", &a, &b);
            insert(1, 1, MX, a, b, i + 1);
        }
        int cnt = 0;
        memset(arr, 0, sizeof arr);
        for(i = 1; i <= n*2; i++)
        {
            int get = query(1, 1, MX, i, 0);
            if(get)
            {
                if(!arr[get])
                {
                    arr[get] = 1;
                    cnt++;
                }
            }
        }
        printf("Case %d: %d\n",cases++,cnt);
    }

    return 0;
}
