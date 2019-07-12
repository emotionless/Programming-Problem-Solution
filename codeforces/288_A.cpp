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
#define MAX 200009


using namespace std;

bool mat[1001][1001];

int main()
{
    int tc,cs=1,i,j,k;
    int n,m, x, y;
    string str;
    cin>>n>>m>>k;
    for(i = 0; i < k; i++)
    {
        cin>>x>>y;
        mat[x][y] = 1;
        if(x + 1 <= n && y + 1 <= m && mat[x + 1][y] && mat[x][y + 1] && mat[x + 1][y  + 1])
        {
            cout<<i + 1<<endl;
            return 0;
        }
        if(x - 1 >= 1 && y + 1 <= m && mat[x - 1][y] && mat[x][y + 1] && mat[x - 1][y  + 1])
        {
            cout<<i + 1<<endl;
            return 0;
        }
        if(x + 1 <= n && y - 1 >= 1 && mat[x + 1][y] && mat[x][y - 1] && mat[x + 1][y  - 1])
        {
            cout<<i + 1<<endl;
            return 0;
        }
        if(x - 1 >= 1 && y - 1 >= 1 && mat[x - 1][y] && mat[x][y - 1] && mat[x - 1][y  - 1])
        {
            cout<<i + 1<<endl;
            return 0;
        }
    }
    cout<<0<<endl;




    return 0;
}

/*

5 3 1103


*/
