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
#define MAX 500009



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


int go[MAX][3];
LL arr[MAX];
pair<LL, int>  V[MAX];

int main()
{
    int i, j, k;
    string str;
    int t, n;
    int cases = 1;
    int num, m;
    cin>>n;

    memset(go, -1, sizeof go);

    for(i = 0; i < n; i++)
    {
        cin>>arr[i];
        V[i] = (mp(arr[i], i));
    }
    sort(V + 1, V + (n - 1));
    LL res = 0ll;

//    for(i = 0; i < n; i++)
//        cout<<i<<" "<<V[i].first<<endl;

    for(i = 1; i < n - 1; i++)
    {
        pair<LL, int> P = V[i];
        LL val = P.xx;
        int  pos = P.yy;
        int j = pos;
        for(j = pos - 1; j >= 0; j--)
        {
            if(go[j][0] != -1)
                j = go[j][0] + 1;
            else
                break;
        }

        for(k = pos + 1; k < n; k++)
        {
            if(go[k][1] != -1)
                k = go[k][1] - 1;
            else
                break;
        }
        go[pos][0] = j;
        go[pos][1] = k;
        if(j >= 0  && k < n)
            res += min(arr[j], arr[k]);
//        cout<<pos<<" "<<res<<endl;
    }

    memset(go, -1, sizeof go);
    LL res1 = 0ll;
    for(i = n - 2; i > 0; i--)
    {
        pair<LL, int> P = V[i];
        LL val = P.xx;
        int  pos = P.yy;
        int j = pos;
        for(j = pos - 1; j >= 0; j--)
        {
            if(go[j][0] != -1)
                j = go[j][0] + 1;
            else
                break;
        }

        for(k = pos + 1; k < n; k++)
        {
            if(go[k][1] != -1)
                k = go[k][1] - 1;
            else
                break;
        }
        go[pos][0] = j;
        go[pos][1] = k;
        if(j >= 0  && k < n)
            res1 += min(arr[j], arr[k]);
//        cout<<pos<<" "<<res<<endl;
    }


    cout<<max(res1, res)<<endl;


    return 0;
}

/*

10 5
4 4 5 8 8


*/
