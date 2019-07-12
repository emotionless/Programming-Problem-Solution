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

LL po[30];

int main()
{
//    READ;
//    WRITE;
    int i, j, k;
    int cases = 1, t;
    int n;
    LL m, w;
    cin>>w>>m;
    LL p = 1ll;
    map<LL, bool>M;
    int ind = 0;
    if(w == 2)
    {
        cout<<"YES"<<endl;
        return 0;
    }
    po[0] = 1ll;
    for(i = 1; i < 20; i++)
    {
        p = p * w;
        po[i] = p;
        if(p > 10000000000) break;
        ind = i;
    }
    for(i = 0; i <= (1<<ind); i++)
    {
        LL tot = 0ll;
        for(j = 0; j <= ind; j++)
        {
            if(check_bit(i, j))
                tot += po[j];
        }
        M[tot] = 1;
    }

    for(i = 0; i <= (1<<ind); i++)
    {
        LL tot = 0ll;
        for(j = 0; j <= ind; j++)
        {
            if(check_bit(i, j))
                tot += po[j];
        }
        if(M.find(m + tot) != M.end())
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;





















    return 0;
}

/*


1000000
0 100000
2 1
0 100000
2 2




*/
