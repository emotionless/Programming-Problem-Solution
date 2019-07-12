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

//EXTENDED EUCLID

LL exgcd(LL a,LL b,LL &x,LL &y)
{
    if(b==0ll)
    {
        x=1ll,y=0ll;
        return a;
    }
    LL ret=exgcd(b,a%b,y,x);
    y-=(a/b)*x;
    return ret;
}

//CHINESE REMAINDER THEOREM

LL rem[MAX];
LL mod[MAX];

LL CRT1(int n)
{
    for(int i=0; i<n; i++) rem[i]%=mod[i];
    LL ret=rem[0],LCM=mod[0];
    for(int i=1; i<n; i++)
    {
        LL x,y;
        LL gd=exgcd(mod[i],-LCM,x,y);
        LL dif=ret-rem[i];

        if(dif%gd!=0) return -1;

        LCM=LCM/gd*mod[i];
        if(LCM<0) LCM=-LCM;
        x=x*dif/gd;
        ret=(mod[i]*x+rem[i])%LCM;
        if(ret<0ll) ret+=LCM;
    }
    return ret;
}


///***** Template ends here *****///
///********************* Code starts here ****************************
LL seg[4*MAX];
LL mx[4*MAX];
LL arr[MAX];

void build(int ind, int st, int ed)
{
    if(st == ed)
    {
        seg[ind] = arr[st];
        mx[ind] = arr[st];
        return;
    }
    int mid = (st + ed)>>1;
    build(ind << 1, st, mid);
    build(ind << 1 | 1, mid + 1, ed);
    mx[ind] = max(mx[ind << 1], mx[ind << 1 | 1]);
    seg[ind] = seg[ind << 1] + seg[ind << 1 | 1];
    return;
}

void update(int ind, int st, int ed, int l, int r, int val)
{
    if(mx[ind] < val) return;
    if(st == ed)
    {
        seg[ind] = seg[ind]%val;
        mx[ind] = seg[ind] % val;
        return;
    }

    int mid = (st + ed)>>1;
    if(r <= mid)
        update(ind << 1, st, mid, l, r, val);
    else if(l > mid)
        update(ind << 1 | 1, mid + 1, ed, l, r, val);
    else
    {
        update(ind << 1, st, mid, l, mid, val);
        update(ind << 1 | 1, mid + 1, ed, mid + 1, r, val);
    }
    mx[ind] = max(mx[ind << 1] , mx[ind << 1 | 1]);
    seg[ind] = seg[ind << 1] + seg[ind << 1 | 1];
}


LL query(int ind, int st, int ed, int l, int r)
{
    if(st == l && ed == r )
    {
        return seg[ind];
    }

    int mid = (st + ed)>>1;
    if(r <= mid)
        return query(ind << 1, st, mid, l, r);
    else if(l > mid)
        return query (ind << 1 | 1, mid + 1, ed, l, r);
    else
    {
        return query(ind << 1, st, mid, l, mid) + query(ind << 1 | 1, mid + 1, ed, mid + 1, r);
    }
}


void change(int ind, int st, int ed, int pos, int val)
{
    if(st == ed)
    {
        seg[ind] = val;
        mx[ind] = val;
        return;
    }
    int mid = (st + ed)>>1;
    if(pos <= mid)
        change(ind << 1, st, mid, pos, val);
    else
        change(ind << 1 | 1, mid + 1, ed, pos, val);
    mx[ind] = max(mx[ind << 1] , mx[ind << 1 | 1]);
    seg[ind] = seg[ind << 1] + seg[ind << 1 | 1];
}


int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    int A, B;
    int t;
    int n, m;
    s2(n, m);
    for(i = 1; i <= n; i++)
        scanf("%lld", &arr[i]);
    build(1, 1, n);
    int op, a, b;
    LL x;
    while(m--)
    {
        s1(op);
        if(op == 1)
        {
            s2(a, b);
            printf("%lld\n", query(1, 1, n, a, b));
        }
        else if(op == 2)
        {
            s3(a, b, x);
            update(1, 1, n, a, b, x);
        }
        else
        {
            s2(a, b);
            change(1, 1, n, a, b);
        }
    }




    return 0;
}


/*


1
2 3
.*.
*..
1 1 1 3


*/
