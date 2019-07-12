#include<bits/stdc++.h>


#define mp make_pair
#define vi vector<int>
#define xx first
#define yy second
#define all(a) a.begin(), a.end()
#define vsort(v) sort(all(v))
#define LB(a, b) (lower_bound(a.begin(), a.end(), b) - a.begin())
#define UB(a, b) (upper_bound(a.begin(), a.end(), b) - a.begin())
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


int arr[10];
int main()
{
//    READ;
//    WRITE;
//    use_cin;

    int i, j, k;
    int n, m;
    fr(i, 6)
    cin>>arr[i];
//    if(arr[0] != arr[2] || arr[4] != arr[2] || arr[4] != arr[0])
//    {
//        cout<<0<<endl;
//        return 0;
//    }
//    if(arr[1] != arr[3] || arr[5] != arr[3] || arr[5] != arr[1])
//    {
//        cout<<0<<endl;
//        return 0;
//    }
    int f = arr[0];
    int s = f - 1;
    int res = (f * (f + 1))/2 + (s * (s + 1))/2;

//    cout<<res<<endl;

    f = arr[1];
    s = f - 1;
    int t = (f * (f + 1))/2 + (s * (s + 1))/2;
    res += t;
    if(arr[0] != arr[1])
        res -= 2;
//    cout<<t<<endl;
    cout<<res<<endl;









    return 0;
}

/*



4 4
3 4
6 7
10 10
13 13
4 4 3 8


*/
