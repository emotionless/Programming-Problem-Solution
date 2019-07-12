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
#define SZ(a) a.size()
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

struct Z
{
    int a, b, p;
} L[MAX];

int P[100][MAX];
string str;
int stp = 0, cnt;
int comp(Z A, Z B)
{
    return A.a == B.a?(A.b < B.b?1:0):(A.a < B.a?1:0);
}


int lcp(int x, int y)
{
    int ret = 0;
    for(int i = stp - 1; i >= 0; i--)
    {
        if(P[i][x] == P[i][y])
        {
            ret += (1<<i);
            x += (1<<i);
            y += (1<<i);
        }
    }
return ret;
}

int main()
{
    int tc,cs=1,i,j,k;
    int n,m;
    cin>>str;
    int N = SZ(str);

    for(i = 0; i < N; i++)
        P[0][i] = str[i] - 'a';

    for(stp = 1, cnt = 1; cnt < N; stp++, cnt = cnt * 2)
    {
        for(i = 0; i < N; i++)
        {
            L[i].a = P[stp - 1][i];
            L[i].b = i + cnt < N ? P[stp - 1][i + cnt] : -1;
            L[i].p = i;
        }
        sort(L, L + N, comp);

        for(i = 0; i < N; i++)
            P[stp][L[i].p] = i > 0 && L[i].a == L[i - 1].a && L[i].b == L[i - 1].b ? P[stp][L[i-1].p] : i;
    }
    string tmp[MAX];
    for(i = 0; i < N; i++)
    {
        tmp[P[stp - 1][i]] = str.substr(i);
    }
    for(i = 0; i < N; i++)
    {
        cout<<i<<" "<<tmp[i]<<endl;
    }
    cout<<lcp(0, 5)<<endl;
//    cout<<(char)('z' + 1)<<endl;


    return 0;
}

/*

aaaa{aa


*/
