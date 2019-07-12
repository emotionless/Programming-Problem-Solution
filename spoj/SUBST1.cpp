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
#define MAXN 50009
#define MAXLG 100


using namespace std;

struct entry
{
    int nr[2], p;
} L[MAXN];
int P[MAXLG][MAXN], N, i, stp, cnt;

int cmp(struct entry a, struct entry b)
{
    return a.nr[0] == b.nr[0] ? (a.nr[1] < b.nr[1] ? 1 : 0) : (a.nr[0] < b.nr[0] ? 1 : 0);
}

int val[MAXN];

int lcp(int x, int y)
{
    int ret = 0;
    for(int i = stp - 1; i >= 0; i--)
    {
        if(P[i][x] == P[i][y] && P[i][x])
        {
//            cout<<P[i][x]<<" "<<P[i][y]<<" "<<ret<<endl;
            ret += (1<<i);
            x += (1<<i);
            y += (1<<i);
        }
    }
    return ret;
}

char A[MAXN];
int main()
{
    int tc,cs=1,i,j,k;
    int n,m;
    scanf("%d", &tc);
    while(tc--)
    {
        scanf("%s", A);
        int N = strlen(A);
//        cout<<A<<endl;

        for (N = strlen(A), i = 0; i < N; i ++)
            P[0][i] = A[i] - 'A';
        for (stp = 1, cnt = 1; cnt >> 1 < N; stp ++, cnt <<= 1)
        {
            for (i = 0; i < N; i ++)
            {
                L[i].nr[0] = P[stp - 1][i];
                L[i].nr[1] = i + cnt < N ? P[stp - 1][i + cnt] : -1;
                L[i].p = i;
            }
            sort(L, L + N, cmp);
            for (i = 0; i < N; i ++)
                P[stp][L[i].p] = i > 0 && L[i].nr[0] == L[i - 1].nr[0] && L[i].nr[1] == L[i - 1].nr[1] ?
                                 P[stp][L[i - 1].p] : i;
        }
//        cout<<lcp(0, 1)<<endl;
//        continue;
        for(i = 0; i < N; i++)
        {
            val[P[stp - 1][i]] = i;
//        tmp[P[stp - 1][i]] = str.substr(i);
        }
        int ans = N - val[0];
        for(i = 1; i < N; i++)
        {
            ans += (N - val[i]) - lcp(val[i - 1], val[i]);
//            cout<<i<<" "<<val[i]<<" "<<val[i - 1]<<" "<<" "<<N - val[i]<<" "<< lcp(val[i - 1], val[i])<<endl;
        }
        printf("%d\n", ans);
    }
    return 0;
}

/*

5 3 1103


*/
