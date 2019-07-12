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
#define MAX 200009



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

struct Z
{
    LL tot, f, s;
    Z() {}
    Z(LL _, LL __, LL ___)
    {
        tot = _;
        f = __;
        s = ___;
    }
    bool operator < (const Z& A) const
    {
        if(tot == A.tot)
            return f < A.f;

        return tot < A.tot;
    }
};

struct Z1
{
    LL tot, f, s;
    Z1() {}
    Z1(LL _, LL __, LL ___)
    {
        tot = _;
        f = __;
        s = ___;
    }
    bool operator < (const Z1& A) const
    {
        if(tot == A.tot)
            f > A.f;
        return tot > A.tot;
    }
};

vector<Z> ans;
vector<Z1> ans1;



LL arr[MAX];
LL arr1[MAX];

LL  is[10009];
LL  is1[10009];


int main()
{
//    READ;
//    WRITE;
//    use_cin;

    LL i, j, k;
    LL cases = 1, T, S, q;
    LL  m;
    LL t, f, s, n;

    cin>>n>>s;
    char ch;
    LL p, d;
    vector<int>vec;
    vector< pair<LL, LL> > fst, snd;
    fr(i, n)
    {
        cin>>ch>>p>>d;
        vec.pb(ch);
        vec.pb(p);
        vec.pb(d);
        if(ch == 'B')
            fst.pb(mp(p, d));
        else
            snd.pb(mp(p, d));

    }
    sort(fst.begin(), fst.end());
    sort(snd.begin(), snd.end());
    int sz = fst.size();
    for(i = 0; i < sz;)
    {
        for(j = i + 1; j < sz; j++)
        {
            if(fst[i].xx == fst[j].xx)
                fst[i].yy += fst[j].yy;
            else
                break;
        }
        ans.pb(Z(fst[i].xx * fst[i].yy, fst[i].xx, fst[i].yy));
        i = j;
    }
    sort(ans.begin(), ans.end());
    int sz1 = snd.size();
    for(i = 0; i < sz1;)
    {
        for(j = i + 1; j < sz1; j++)
        {
            if(snd[i].xx == snd[j].xx)
                snd[i].yy += snd[j].yy;
            else
                break;
        }
        ans1.pb(Z1(snd[i].xx * snd[i].yy, snd[i].xx, snd[i].yy));
        i = j;
    }

    sort(ans1.begin(), ans1.end());
    sz1 = ans1.size();
    k = 0;

    vector< pair<int, int> > take, take1;

    for(i = 0; i < sz1 && k < s; i++, k++)
    {
//        cout<<'S'<<" "<<ans1[i].f<<" "<<ans1[i].s<<endl;
//        is1[ans1[i].f] = ans1[i].s;
        take.pb(mp(ans1[i].f, ans1[i].s));
    }

    k = 0;

    sz = ans.size();
    for(i = sz - 1; i >= 0 && k < s; i--, k++)
    {
//        cout<<'B'<<" "<<ans[i].f<<" "<<ans[i].s<<endl;
//        is[ans[i].f] = ans[i].s;
        take1.pb(mp(ans[i].f, ans[i].s));
    }

    sort(take.begin(), take.end());
    sort(take1.begin(), take1.end());

    for(i = take.size() - 1; i >= 0; i --)
    cout<<"S "<<take[i].xx<<" "<<take[i].yy<<endl;

    for(i = take1.size() - 1; i >= 0; i --)
    cout<<"B "<<take1[i].xx<<" "<<take1[i].yy<<endl;


























    return 0;
}
/*

1
8
2 3 4 3 1 6 1 4


*/
