#include <cstring>
#include <cassert>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <climits>
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
#define PI 3.1416



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

int dp[85][85];
string str1, str2;
int n, m;
vector<string>V;
map<string, bool>M;
void print(int i, int j, string str)
{
    if(i == 0 || j == 0)
    {
        reverse(str.begin(), str.end());
        if(!M[str])
        {
            M[str] = 1;
            V.pb(str);
        }
        return;
    }

    if(str1[i] == str2[j])
    {
        print(i - 1, j - 1, str + str1[i]);
    }
    if(dp[i][j] == (dp[i - 1][j]))
        print(i - 1, j, str);
    if(dp[i][j] == (dp[i][j - 1]))
        print(i, j - 1, str);
    return;
}


int main()
{
    use_cin;
    int i, j, k;
    int cases = 1;
    int a, b, c, K, t;
    cin>>t;
    while(t--)
    {
        cin>>str1>>str2;
        memset(dp, 0, sizeof dp);
        V.clear();
        M.clear();
        n = str1.length();
        m = str2.length();

        str1 = " " + str1;
        str2 = " " + str2;

        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= m; j++)
            {
                if(str1[i] == str2[j])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        print(n, m, "");
        vsort(V);
        for(i= 0; i < V.size(); i++)
            cout<<V[i]<<endl;
    }
    return 0;
}

/*

3 3 3
0 2 0
0 2 1
1 2 2



*/
