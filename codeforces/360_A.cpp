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
#define ll long long
#define pb push_back
#define pii pair<int, int>
#define vll vector<long long>
///***** bit *****///
#define check_bit(a, b) (a&(1<<b))
#define set_bit(a, b) (a|(1<<b))
#define total_bit(a) __builtin_popcount(a)

#define WRITE freopen("A_large.txt","w",stdout)
#define use_cin  ios_base::sync_with_stdio(0); cin.tie(0);
#define READ  freopen("a2.in","r",stdin)

///***** Input / Output *****///
#define s1(a) scanf("%d", &a)
#define s2(a, b) scanf("%d %d", &a, &b)
#define s3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define s4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define p1(a) printf("%d", a)
#define p2(a, b) printf("%d %d", a, b)
#define p3(a, b, c) printf("%d %d %d", a, b, c)
#define eps 1e-9
#define deb cout<<"I am here"<<endl
#define MOD 1000000007
#define MAX (lim+7)
#define INF 100000000
#define PI acos(-1.0)

using namespace std;

///****** fast scan ends here ***********///

//int dr[] = {-1, 0, 1, 0};
//int dc[] = {0, 1, 0, -1}; /// 4 sides
//int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1}; dc[] = {0, 1, 1, 1, 0, -1, -1, -1}; /// 8 sides

#define LEN(a) strlen(a)

#define MX 1000000000000000000ll
#define lim 100000      /// 10^5

///***** Template ends here *****///
///********************* Code starts here ****************************

char str[MAX];

int main()
{
//    READ;
//    WRITE;
//    use_cin;
    int i, j, k, K, q;
    int n, m;
    scanf(" %s", str);
    bool ok = 0, done = 0, ck = 0;
    int len = strlen(str);
    string res = "";
    for(i = 0; i < len; i++)
    {
        if(done)
        {
           res += str[i];
            continue;
        }
        if(ok && str[i] == 'a')
        {
            res += str[i];
            ok = 0;
            done = 1;
        }
        else if(ok == 0 && str[i] != 'a')
        {
            res += (char)((str[i] - 'a' - 1 + 26)%26 + 'a');
            ok = 1;
            ck = 1;
        }
        else if(ok == 1 && str[i] != 'a')
        {
            res += (char)((str[i] - 'a' - 1 + 26)%26 + 'a');
            ok = 1;
            ck = 1;
        }
        else
        {
            res += str[i];
        }
    }
    if(!ck)
    {
        len--;
        res[len] = (char)((res[len] - 'a' - 1 + 26)%26 + 'a');
    }
    cout<<res<<endl;


    return 0;
}


/*

249999999999999999
250000000000000001
a

*/
