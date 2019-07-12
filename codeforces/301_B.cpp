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


///***** Template ends here *****///
///********************* Code starts here ****************************



LL arr[100009];

int main()
{
    int i, j, k;
    string str, inp;
    int t, n;
    int cases = 1;
    int num, m;
    int p, x, y;
    cin>>n>>k>>p>>x>>y;
    int sum = 0;
    for(i = 0; i < k; i++){
        cin>>arr[i];
        sum += arr[i];
    }
        arr[i] = y;
    sum += y;

    int fst = 0, snd = 0, thrd = 0;
    for(j = 0; j < i; j++)
    {
        if(arr[j] < y)
            fst ++;
        else if(arr[j] > y)
            snd++;
        else
            thrd++;
    }
    if(fst > (n/2))
    {
        cout<<-1<<endl;
        return 0;
    }
    snd += thrd;

    int mid = n / 2;
    if(snd > mid)
    {
        fst += (snd - mid - 1);
        snd = mid + 1;
    }
    sum += (mid - fst);
    sum += (n - mid - snd - 1)*y;
    if(sum > x)
    {
        cout<<-1<<endl;
        return 0;
    }

    for(i = 0; i < mid - fst; i++)
        cout<<1<<" ";
    for(i = 0; i <= (n - mid - snd - 1); i++)
        cout<<y<<" ";














    return 0;
}

/*

5 0 5 14 5



*/
