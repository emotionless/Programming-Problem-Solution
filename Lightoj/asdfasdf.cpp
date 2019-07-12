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



int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

string mat[101];


int main()
{
    int i, j, k;
    string str;
    int t, n;
    int K;
    cin>>n>>K;
    str = "";
    for(i = 0; i < n; i++)
        str += 'S';
    for(i = 0; i < n; i++)
        mat[i] = str;

    vector<string > ans;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            for(k = 0; k < 4; k++)
            {
                int a = i + dr[k];
                int b = j + dc[k];
                if(a < 0 || a > n || b < 0 || b > n) continue;
                if(mat[a][ b] == 'L') break;
            }
            if(k == 4)
            {
                if(K)
                {
                    mat[i][j] = 'L';
                    K--;
                }
                for(k = 0; k < 4; k++)
                {
                    int a = i + dr[k];
                    int b = j + dc[k];

                    if(a < 0 || a > n || b < 0 || b > n) continue;

                }
            }
        }
        ans.pb(mat[i]);
    }
    if(K)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;

    for(i = 0; i < n; i++)
        cout<<ans[i]<<endl;

    return 0;
}

/*

3
abaaa

*/
