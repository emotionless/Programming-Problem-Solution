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

///***** Template ends here *****///
///********************* Code starts here ****************************

int val[150];
LL arr[MAX];
int main()
{
    int i, j, k;
    int n, num;
    string str;
    int t;
    cin>>n;
    for(i = 0; i < n; i++)
        cin>>arr[i];
    sort(arr, arr + n);
    reverse(arr, arr + n);

    LL res = 0ll;
    j = 0;
    for(i = 0; i < n; i++)
    {
        LL fst = 0ll, snd = 0ll;
        for(j = max(i + 1, j); j < n; j++)
        {
            if(llabs(arr[j] - arr[j - 1]) <= 1)
            {
                fst = arr[j];
                j++;

//                st = j + 1;
                j++;
                break;
            }
        }
        if(fst == 0) continue;

        for(; j < n; j++)
        {
            if(llabs(arr[j] - arr[j - 1]) <= 1)
            {
                snd = arr[j];
                j++;
//                st = j;

                break;
            }
        }
        res += fst*snd;
        i = j - 1;
        j++;
    }
    cout<<res<<endl;














    return 0;
}

/*








*/
