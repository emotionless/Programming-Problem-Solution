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
#define MAX 19371495



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

int k;
bool is[MAX + 7];
int prime[MAX + 7];
int cnt[MAX + 7];
int till[MAX + 7];

void sieve()
{
    int i, j;
    for(i = 4; i < MAX; i+= 2)
        is[i] = 1;
    int sq = sqrt(MAX);
    for(i = 3; i <= sq; i += 2)
    {
        if(!is[i])
        {
            for(j = i + i; j < MAX; j+=i)
                is[j] = 1;
        }
    }
    k = 0;
    for(i = 2; i < MAX; i++)
    {
        if(!is[i])
            prime[k++] = i;
        till[i] = k;
    }
}

int take[12];

int tot;

int main()
{
//    READ;
//    WRITE;
//    use_cin;

    int i, j;
    int cases = 1, T, S;
    sieve();
    tot = 0;
    for(i = 1; i < MAX; i++)
    {
        int tmp = i;
        int c = 0;
        while(tmp)
        {
            take[c++] = tmp%10;
            tmp = tmp / 10;
        }
        c--;
        for(j = 0; j <= c; j++)
        {
            if(take[j] != take[c--])
                break;
        }

        if(j > c)
        {
            cnt[i] = (++tot);
//            cout<<i<<endl;
        }
        else
            cnt[i] = tot;
    }
    int ans = -1;
    LL p, q;
//    cout<<till[1566]<<" "<<cnt[1566]<<endl;
    cin>>p>>q;
    for(i = 1; i < MAX; i++)
    {
        if((LL)q*(LL)till[i] <= p*(LL)cnt[i])
            ans = i;
    }
    if(ans == -1 || ans == MAX - 1)
        cout<<"Palindromic tree is better than splay tree"<<endl;
    else
        cout<<ans<<endl;







    return 0;
}
/*

5000 1660 2
20
1 100 18 102 300 81 19 25 44 88 1337 4999 1054 1203 91 16 164 914 1419 1487

5 1 3
5
1 2 3 4 5


*/
