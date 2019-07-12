#include<bits/stdc++.h>

#define xx first
#define yy second
#define all(a) a.begin(), a.end()
#define vsort(v) sort(all(v))
#define UNIQUE(a)  sort(all(a)); a.erase(unique(all(a)), a.end())
#define clr(a,k) memset(a,k,sizeof a)
#define bclr(b) memset(b,false,sizeof b)
#define fr(i, a) for(i = 0; i < a; i++)
#define frr(i,a) for(i = a - 1; i >= 0; i--)
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


#define MOD 1000000007
#define MAX 100009



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
bool lazy[8*MAX];

void update(int ind, int st, int ed, int l, int r)
{

    if(st == l && ed == r)
    {
        seg[ind] = (ed - st + 1) - seg[ind];
        lazy[ind] = lazy[ind] ^ 1;
        return;
    }

    int mid = (st + ed)/2;
    if(r <= mid)
        update(ind * 2, st, mid, l, r);
    else if(l > mid)
        update(ind * 2 + 1, mid + 1, ed, l, r);
    else
    {
        update(ind * 2, st, mid, l, mid);
        update(ind * 2 + 1, mid + 1, ed, mid + 1, r);
    }

    seg[ind] = seg[ind * 2] + seg[ind * 2 + 1];
    if(lazy[ind])
        seg[ind] = (ed - st + 1) - seg[ind];
}


int query(int ind, int st, int ed, int l, int r)
{
    int mid = (st + ed)/2;

    if(st == l && ed == r)
    {
        return seg[ind];
    }

    int ans = 0;
    if(r <= mid)
        ans = query(ind * 2, st, mid, l, r);
    else if(l > mid)
        ans = query(ind * 2 + 1, mid + 1, ed, l, r);
    else
        ans = query(ind * 2, st, mid, l, mid)+ query(ind * 2 + 1, mid + 1, ed, mid + 1, r);
    if(lazy[ind])
        ans = (r - l + 1) - ans;
    return ans;
}

int main()
{
//    READ;
//    WRITE;
    int i, j, type;
    int t, op, a, b, q, n;
    scanf("%d %d", &n, &q);
    while(q--)
    {
        scanf("%d %d %d", &op, &a, &b);

        a++;
        b++;
        if(op == 0)
        {
            update(1, 1, n, a, b);
//            for(i = 1; i <= 8; i++)
//                cout<<i<<" "<<seg[i]<<" "<<lazy[i]<<endl;
        }
        else
        {
            int ans = query(1, 1, n, a, b);
            printf("%d\n", ans);
        }
    }



    return 0;
}

/*


4 10
1 0 3
0 0 3
1 0 3




4 7
0 1 2
0 0 3
1 3 3




4 7
1 0 3
0 1 2
1 0 1
1 0 0
0 0 3
1 0 3
1 3 3



*/
