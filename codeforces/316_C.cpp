#include<bits/stdc++.h>


#define mp make_pair
#define vi vector<int>
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

#define use_cin  ios_base::sync_with_stdio(0); cin.tie(0);


#define s1(a) scanf("%d", &a)
#define s2(a, b) scanf("%d %d", &a, &b)
#define s3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define p1(a) printf("%d", a)
#define p2(a, b) printf("%d %d", a, b)
#define p3(a, b, c) printf("%d %d %d", a, b, c)
#define eps 1e-9


#define MOD 1000000007
#define MAX 300009



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

LL arr[MAX];

int seg[8*MAX];

void insert(int ind, int st, int ed, int pos, int val)
{
    if(st == ed)
    {
        seg[ind] = val;
        return;
    }
    int  mid = (st + ed)/2;
    if(pos <= mid)
        insert(ind*2, st,  mid, pos, val);
    else
        insert(ind * 2 + 1, mid + 1, ed, pos, val);
    seg[ind] = seg[ind * 2] + seg[ind * 2 + 1];
}




int query(int ind, int st, int ed, int l, int r, bool isrgt)
{
    if(l > r) return 0;
//    cout<<ind<<" "<<st<<" "<<ed<<" "<<l<<" "<<r<<" "<<isrgt<<" "<<seg[ind]<<endl;
    if(!seg[ind]) return 0;

    if(st == ed)
        return st;

    int mid = (st + ed)/2;
    if(r <= mid)
        return query(ind * 2, st, mid, l, r, isrgt);
    else if(l > mid)
        return query(ind * 2 + 1, mid + 1, ed, l, r, isrgt);
    else
    {
        if(isrgt)
        {
            int a = query(ind * 2, st, mid, l, mid, isrgt);
            if(!a)
                a = query(ind * 2 + 1, mid + 1, ed, mid + 1, r, isrgt);
            return a;
        }
        else
        {
            int a = query(ind * 2 + 1, mid + 1, ed, mid + 1, r, isrgt);
            if(!a)
                a = query(ind * 2, st, mid, l, mid, isrgt);
            return a;
        }
    }
}


int main()
{
//    READ;
//    WRITE;
//    use_cin;

    int i, j, k;
    int cases = 1, T, S, q;
    int n, m;
    string str;
    cin>>n>>m;
    cin>>str;
    int cnt = 0;
    for(i = 1; i < n; i++)
    {
        if(str[i] == str[i - 1] && str[i] == '.')
            cnt++;
    }

    for(i = 0; i < n; i++)
    {
        if(str[i] != '.')
            insert(1, 1, n + 1, i + 1, 1);
    }
    insert(1, 1, n + 1, n + 1, 1);


    int pos;
    char ch;
    int ans = cnt;
//    cout<<ans<<endl;
    while(m--)
    {
        cin>>pos>>ch;
        if(ch != '.')
        {
            int get = query(1, 1, n + 1, pos, pos, 1);
            if(get)
            {
                cout<<ans<<endl;
                continue;
            }

            int lft = query(1, 1, n + 1, 1, pos - 1, 0);
            int rgt = query(1, 1, n + 1, pos + 1, n + 1, 1);

//            cout<<lft<<" "<<rgt<<endl;

            int have = rgt - lft - 2;
            if(have < 0) have = 0;
            int rh = (rgt - pos - 2);
            if(rh < 0) rh = 0;

            int lh = (pos - lft - 2);
            if(lh < 0) lh = 0;
            ans = ans - have + lh + rh;
            cout<<ans<<endl;
            insert(1, 1, n + 1, pos, 1);
        }
        else
        {
            int get = query(1, 1, n + 1, pos, pos, 0);
            if(!get)
            {
                cout<<ans<<endl;
                continue;
            }

            int lft = query(1, 1, n + 1, 1, pos - 1, 0);
            int rgt = query(1, 1, n + 1, pos + 1, n + 1, 1);

//            cout<<lft<<" "<<rgt<<endl;
            int have = rgt - lft - 2;
            if(have < 0) have = 0;
            int rh = (rgt - pos - 2);
            if(rh < 0) rh = 0;

            int lh = (pos - lft - 2);
            if(lh < 0) lh = 0;

            ans = ans + have - lh - rh;

            cout<<ans<<endl;

            insert(1, 1, n + 1, pos, 0);

        }
    }











    return 0;
}
/*

2 7
ab
1 w
2 w
1 c
2 .
2 .
1 .
2 b



*/
