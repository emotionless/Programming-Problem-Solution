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
#define MAX 1000009



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



int main()
{
    LL i, j, k;
    LL t, n;
    LL cases = 1;
    LL a, d, K;
    LL num;
//    s1(t);
    cin>>t;
    while(t--)
    {
//        scanf("%lld %lld %lld", &a, &d, &K);

        cin>>a>>d>>K;

        LL st = 0ll, ed = 1000000000ll, mid, ans = 0ll;
        if(a == 0)
            assert(0);
        if(d == 0ll)
        {
//            printf("%lld\n", K/a);
            cout<<K/a<<endl;
            continue;
        }
        while(st <= ed)
        {
            mid = (st + ed)/2ll;
            LL tot = ((mid * (mid - 1ll))/2ll) * d  + mid * a;
            if(tot <= K)
            {
                st = mid + 1ll;
                ans = max(ans, mid);
            }
            else
                ed = mid - 1;
        }
//        printf("%lld\n", ans);
        cout<<ans<<endl;

    }





    return 0;
}

/*

9
2 0 1
2 2 12

1
2 0 1

1
1 0 1000000000000

*/
