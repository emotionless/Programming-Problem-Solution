#include<bits/stdc++.h>

#define xx first
#define yy second
#define vsort(v) sort(v.begin(),v.end())
#define clr(a,k) memset(a,k,sizeof a)
#define bclr(b) memset(b,false,sizeof b)
#define LL long long
#define pb push_back
#define MP make_pair
#define MOD 1000000007
#define MX 100000

using namespace std;

LL arr[100001];
LL seg[4*100001];

void update(int ind, int st, int ed, int pos, LL val)
{
    if(st == pos && ed == pos)
    {
        seg[ind] += val;
        seg[ind] = seg[ind] % MOD;
        return;
    }
    int mid = (st + ed) / 2;

    if(pos <= mid)
        update(ind * 2, st, mid, pos, val);
    else
        update(ind * 2 + 1, mid + 1, ed, pos, val);
    seg[ind] = (seg[ind * 2] + seg[ind * 2 + 1]) % MOD;
}

LL query(int ind, int st, int ed, int l, int r)
{
    if(st == l && ed == r)
        return seg[ind];

    int mid = (st + ed)/2;
    if(r <= mid)
        return query(ind * 2, st, mid, l, r);
    else if(l > mid)
        return query(ind * 2 + 1, mid + 1, ed, l, r);
    else
        return query(ind * 2, st, mid, l, mid) + query(ind * 2 + 1, mid + 1, ed, mid + 1, r);
}


int main()
{
    int i, j, k;
    int n;
    int t, cases = 1;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(i = 0; i < n; i++)
            scanf("%lld", &arr[i]);
        clr(seg, 0);
        set<LL>S(arr, arr+n);
        vector<LL>V(S.begin(), S.end());
        int sz = V.size();
        for(i = 0; i < n; i++)
        {
            int cn = arr[i];
            int low = 0;
            int high = sz - 1;
            int mid;
            while(low < high)
            {
                mid = (low + high)>>1;
                if(V[mid] == cn){
                    low = mid;
                    break;
                }
                if(V[mid] < cn)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            low++;
            LL res = query(1, 1, sz + 1 , 1, low) + 1;
            res = res % MOD;
            update(1, 1, sz + 1 , low + 1, res);

        }
        printf("Case %d: %lld\n", cases++, seg[1]);
    }

    return 0;
}
