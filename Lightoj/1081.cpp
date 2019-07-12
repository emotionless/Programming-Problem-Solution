#include<bits/stdc++.h>

#define xx first
#define yy second
#define all(a) a.begin(), a.end()
#define vsort(v) sort(all(v))
#define UNIQUE(a)  sort(all(a)); a.erase(unique(all(a)), a.end())
#define clr(a,k) memset(a,k,sizeof a)
#define bclr(b) memset(b,false,sizeof b)
#define fr(i, a) for(i = 0; i < a; i++)
#define frr(i,a) for(i = a - 1; i >= 0, i--)
#define LL long long
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define vi vector<int>
#define vll vector<long long>
///***** bit *****///
#define check_bit(a, b) (a&(1<<b))
#define set_bit(a, b) (a|(1<<b))
#define total_bit(a) __builtin_popcount(a)
///***** Input / Output *****///
// IO
#define READ  freopen("C:\\Users\\back_bencher\\Desktop\\input.txt","r",stdin)
#define WRITE freopen("C:\\Users\\back_bencher\\Desktop\\output.txt","w",stdout)
#define use_cin  ios_base::sync_with_stdio(0); cin.tie(0);


#define s1(a) scanf("%d", &a)
#define s2(a, b) scanf("%d %d", &a, &b)
#define s3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define p1(a) printf("%d", a)
#define p2(a, b) printf("%d %d", a, b)
#define p3(a, b, c) printf("%d %d %d", a, b, c)
#define eps 1e-9


#define MOD 1000000007
#define MAX 179003



using namespace std;
///******* Template ********///


template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)return 1;
    if(e%2==0)
    {
        T t=bigmod(p,e/2,M);
        return (t*t)%M;
    }
    return (bigmod(p,e-1,M)*p)%M;
}
template <class T> inline T gcd(T a,T b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
template <class T> inline T modinverse(T a,T M)
{
    return bigmod(a,M-2,M);
}

//int dr[] = {-1, 0, 1, 0}; int dc[] = {0, 1, 0, -1}; /// 4 sides
//int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1}; dc[] = {0, 1, 1, 1, 0, -1, -1, -1}; /// 8 sides


///***** Template ends here *****///
///********************* Code starts here ****************************

int seg[8*MAX];

void update(int ind, int x1, int y1, int x2, int y2, int x, int y, int val)
{
    if(x1 > x || x2 < x || y1 > y || y2 < y || x1 > x2 || y1 > y2) return;
    if(x1 == x2  && y1 == y2)
    {
        seg[ind] = val;
        return;
    }

    update(ind * 4 - 2, x1, y1, (x1 + x2)/2, (y1 + y2)/2, x, y, val);
    update(ind * 4 - 1, (x1 + x2)/2 + 1, y1, x2, (y1 + y2)/2, x, y, val);
    update(ind * 4 + 0, x1, (y1 + y2) /2 + 1, (x1 + x2)/2, y2, x, y, val);
    update(ind * 4 + 1, (x1 + x2)/2 + 1, (y1 + y2) /2 + 1, x2, y2, x, y, val);

    seg[ind] = max(max(seg[ind * 4 - 2] ,seg[ind * 4 - 1]), max( seg[ind * 4 + 0] , seg[ind * 4 + 1]));
}


int query(int ind, int x1, int y1, int x2, int y2, int x, int y, int xx, int yy)
{
    if(x > x2 || y > y2 || xx < x1 || yy < y1 || x1 > x2 || y1 > y2)
        return 0;

    if(x <= x1 && y <= y1 && x2 <= xx && y2 <= yy)
        return seg[ind];

    int ret = query(ind * 4 - 2, x1, y1, (x1 + x2)/2, (y1 + y2)/2, x, y, xx, yy);
    ret = max(ret, query(ind * 4 - 1, (x1 + x2)/2 + 1, y1, x2, (y1 + y2)/2, x, y, xx, yy));
    ret = max(ret, query(ind * 4 + 0, x1, (y1 + y2) /2 + 1, (x1 + x2)/2, y2, x, y, xx, yy));
    ret = max(ret, query(ind * 4 + 1, (x1 + x2)/2 + 1, (y1 + y2) /2 + 1, x2, y2, x, y, xx, yy));
    return ret;
}

int main()
{
//    READ;
//    WRITE;
    int i, j, k;
    int cases = 1, t;
    int n, m, q, op;
    int x1, x2, y1, y2;
    /// lightoj 1266

    scanf("%d", &t);
    while(t--)
    {
        memset(seg, 0, sizeof seg);
        scanf("%d %d", &n, &q);
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                scanf("%d", &x1);
                update(1, 1, 1, 501, 501, i, j, x1);
            }
        }
        printf("Case %d:\n", cases++);
        while(q--)
        {
            int d;
            scanf("%d %d %d", &x1, &y1, &d);
            x2 = x1 + d - 1;
            y2 = y1 + d - 1;
            int res = query(1, 1, 1, 501, 501, x1, y1, x2, y2);
            printf("%d\n", res);
        }
    }

    return 0;
}

/*


9
0 1 1
0 2 6
0 5 5
1 0 0 6 5

*/
