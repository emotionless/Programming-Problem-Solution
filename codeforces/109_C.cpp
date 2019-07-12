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
#define s1(a) scanf("%d", &a)
#define s2(a, b) scanf("%d %d", &a, &b)
#define s3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define p1(a) printf("%d", a)
#define p2(a, b) printf("%d %d", a, b)
#define p3(a, b, c) printf("%d %d %d", a, b, c)


#define MOD 1000000007
#define MAX 100009


using namespace std;
string str, tmp;
int val[30];
int n;
int dp[MAX][30];

int solve(int ind, int last)
{
    if(ind == n)
        return 0;
    int &ret = dp[ind][last];
    if(ret != -1) return ret;
    ret = 0;
    int v = str[ind] - 'a' + 1;
    if(last == val[v])
        return ret = 1 + solve(ind + 1, last);  // obiously take
    ret =   solve(ind + 1, v);    // don't take
    ret = min(ret, 1 + solve(ind + 1, last));     // take
//    cout<<ind<<" "<<last<<" "<<ret<<endl;
    return ret;
}


int main()
{
    int i, j, k;
    int num;
    cin>>str;
    n = str.length();
    cin>>k;
    while(k--)
    {
        cin>>tmp;
        val[tmp[0] - 'a' + 1] = tmp[1] - 'a' + 1;
        val[tmp[1] - 'a' + 1] = tmp[0] - 'a' + 1;
    }
    clr(dp, -1);
    cout<<solve(0, 29)<<endl;








    return 0;
}

/*

aludfbjtwnkgnfl
1
oy


*/
