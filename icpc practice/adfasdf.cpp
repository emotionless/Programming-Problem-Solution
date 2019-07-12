/* " A computer would deserve to be called intelligent if it
could deceive a human into believing that it was human. "
                                            - Alan Turing */
#include<bits/stdc++.h>
using namespace std;
#define D               double
#define LL              long long
#define ULL             unsigned long long
#define SF              scanf
#define PF              printf
#define FOR(i, a, b)    for(int i = a; i < b; i++)
#define REV(i, a, b)    for(int i = a - 1; i >= b; i--)
#define SET(a, v)       memset(a, v, sizeof a)
#define VI              vector<int>
#define PB              push_back
#define ALL(v)          v.begin(), v.end()
#define MII             map<int, int>
#define MSI             map<string, int>
#define PII             pair<int, int>
#define MP              make_pair
#define X               first
#define Y               second
// return the index     (match ? first match : immediate greater)
#define lbA(a, n, x)    lower_bound(a, a + n, x) - a
#define lbV(v, x)       lower_bound(ALL(v), x) - v.begin()
// return the index     (match ? last match + 1 : immediate greater)
#define ubA(a, n, x)    upper_bound(a, a + n, x) - a
#define ubV(v, x)       upper_bound(ALL(v), x) - v.begin()
template <class T> inline T bigmod(T b, T p, T M) {
    LL ret = 1;
    for(; p > 0; p >>= 1) {
        if(p & 1) ret = (ret * b) % M;
        b = (b * b) % M;
    }
    return (T) ret;
}
template <class T> inline T __lcm(T a, T b) {
    return (a * b) / __gcd(a, b);
}
int dx4[] = {1, 0, -1, 0}; // 4 directions
int dy4[] = {0, 1, 0, -1};
int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1}; // 8 directions
int dy8[] = {1, -1, -1, 0, 1, -1, 0, 1};
int kx8[] = {1, 1, 2, 2, -1, -1, -2, -2}; // Knight Moves
int ky8[] = {2, -2, 1, -1, 2, -2, 1, -1};
//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
// int tc;SF("%d",&tc);FOR(cs,1,tc+1){}
const LL                LINF = 1e18;
const int               INF = 1e9, NIL = -1;
const int               N = 1e5 + 5, M = 1e9 + 7;

struct z {
    LL a, b, d;
    z() {}
    z(LL _a, LL _b, LL _d) {
        a = _a, b = _b, d = _d;
    }
    bool friend operator < (z x, z y) {
        if(x.d != y.d) return x.d < y.d;
        return x.a < y.a;
    }
} a[N];

int n;
LL L, c[N], seg1[4 * N], seg2[4 * N];

void update1(int c, int s, int e, int p, LL v) {
    if(s == e) {
        seg1[c] = v;
        return;
    }
    int mid = (s + e) / 2, L = 2 * c, R = L + 1;
    if(p <= mid) update1(L, s, mid, p, v);
    else update1(R, mid + 1, e, p, v);
    seg1[c] = max(seg1[L], seg1[R]);
}

LL query1(int c, int s, int e, int l, int r) {
    if(s == l && e == r) return seg1[c];
    int mid = (s + e) / 2, L = 2 * c, R = L + 1;
    if(r <= mid) return query1(L, s, mid, l, r);
    else if(l > mid) return query1(R, mid + 1, e, l, r);
    else {
        LL x = query1(L, s, mid, l, mid);
        LL y = query1(R, mid + 1, e, mid + 1, r);
        return max(x, y);
    }
}

void update2(int c, int s, int e, int p, LL v) {
    if(s == e) {
        seg2[c] = v;
        return;
    }
    int mid = (s + e) / 2, L = 2 * c, R = L + 1;
    if(p <= mid) update2(L, s, mid, p, v);
    else update2(R, mid + 1, e, p, v);
    seg2[c] = max(seg2[L], seg2[R]);
}

LL query2(int c, int s, int e, int l, int r) {
    if(s == l && e == r) return seg2[c];
    int mid = (s + e) / 2, L = 2 * c, R = L + 1;
    if(r <= mid) return query2(L, s, mid, l, r);
    else if(l > mid) return query2(R, mid + 1, e, l, r);
    else {
        LL x = query2(L, s, mid, l, mid);
        LL y = query2(R, mid + 1, e, mid + 1, r);
        return max(x, y);
    }
}

int main() {
    SF("%d%lld", &n, &L);
    FOR(i, 1, n + 1) {
        LL x, y;
        scanf("%lld%lld", &x, &y);
        a[i] = z(x, y, x - y);
    }
    sort(a + 1, a + n + 1);
    FOR(i, 1, n + 1) {
        SF("%lld", &c[i]);
        update1(1, 1, n, i, a[i].a);
        update2(1, 1, n, i, a[i].d);
    }
//    cout << "ok" << endl;
    LL good = 0, bad = 0;
    int ans = -1;
    FOR(i, 1, n + 1) {
        LL mx = query1(1, 1, n, 1, n);
        if(good + mx >= L) {
            ans = i;
            break;
        }
        bad += c[i];
//        cout << i << " " << bad << endl;
        LL need = bad - good;
        int lo = 1, hi = n, idx = -1;
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            if(query2(1, 1, n, 1, mid) > need) {
                idx = mid;
                hi = mid - 1;
            } else lo = mid + 1;
        }
//        cout << idx << endl;
        if(idx != -1) {
            good += a[idx].d;
            update1(1, 1, n, idx, -M - M);
            update2(1, 1, n, idx, -M - M);
        } else break;

    }
    PF("%d\n", ans);
    return 0;
}
