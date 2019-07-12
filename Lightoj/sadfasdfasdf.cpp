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

#define WRITE freopen("semipal.out","w",stdout)
#define use_cin  ios_base::sync_with_stdio(0); cin.tie(0);
#define READ  freopen("semipal.in","r",stdin)

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
#define INF 10000000000000
#define PI acos(-1.0)
#define piii pair<int, pii>

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

/**
return (a * b) % m;
where a, b, m <= 10^18
**/
template <class T> inline T multimod(T a, T b, T m)
{
    T ans = 0ll;
    a%=m, b%=m;
    while(b)
    {
        if(b&1ll) ans = m - ans > a?(ans + a): (ans + a - m);
        b >>= 1ll;
        a = (m - a)>a?a+a:a+a-m;
    }
    return (T)ans;
}


///****** fast scan ends here ***********///

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1}; /// 4 sides
//int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1}; dc[] = {0, 1, 1, 1, 0, -1, -1, -1}; /// 8 sides

#define LEN(a) strlen(a)
#define ull unsigned long long
#define INF 1000000000

#define MX 10000000000000000ll
#define lim 40      /// 10^5

///***** Template ends here *****///
///********************* Code starts here ****************************

char str[50][50];

struct Z
{
    int firstX, firstY, secondX, secondY, cst;
    Z() {}
    Z(int _, int __, int ___, int ____, int _____)
    {
        firstX = _;
        firstY = __;
        secondX = ___;
        secondY = ____;
        cst = _____;
    }
    bool operator<(const Z&A) const
    {
        return cst > A.cst;
    }
};

int ex, ey;
int n,m;
bool vis[MAX][MAX][MAX][MAX];

int BFS(int fx, int fy, int sx, int sy)
{
    clr(vis, false);

    priority_queue<Z>Q;
    Q.push(Z(fx, fy, sx, sy, 0));

    while(!Q.empty())
    {
        Z top = Q.top();
        Q.pop();

        int fstX = top.firstX;
        int fstY = top.firstY;
        int sndX = top.secondX;
        int sndY = top.secondY;
        int cc = top.cst;


        if(vis[fstX][fstY][sndX][sndY]) continue;
        vis[fstX][fstY][sndX][sndY] = true;
        if(fstX == sndX && fstY == sndY && fstX == ex && fstY == ey) return cc;

        for(int i = 0; i  < 4; i++)
        {
            // for the first
            int adx1 = fstX + dr[i];
            int ady1 = fstY + dc[i];

            // for the second
            int adx2 = sndX + dr[i];
            int ady2 = sndY + dc[i];
            int adjc = cc + 1;

            if(i == 1)
            {
                adx2 = sndX + dr[i+2];
                ady2 = sndY + dc[i+2];
            }
            else if(i == 3)
            {
                adx2 = sndX + dr[i-2];
                ady2 = sndY + dc[i-2];
            }

            if(adx1 >= 0 && adx1 < n && ady1 >= 0 && ady1 < m && str[adx1][ady1] == '.')
            {
                if(adx2 >= 0 && adx2 < n && ady2 >= 0 && ady2 < m && str[adx2][ady2] == '.')
                    Q.push(Z(adx1, ady1, adx2, ady2, adjc));
                else
                    Q.push(Z(adx1, ady1, sndX, sndY, adjc));
            }
            else if(adx2 >= 0 && adx2 < n && ady2 >= 0 && ady2 < m && str[adx2][ady2] == '.')
            {
                if(adx1 >= 0 && adx1 < n && ady1 >= 0 && ady1 < m && str[adx1][ady1] == '.')
                    Q.push(Z(adx1, ady1, adx2, ady2, adjc));
                else
                    Q.push(Z(fstX, fstY, adx2, ady2, adjc));
            }
        }
    }
    return INF;
}


int main()
{
//    use_cin;
//    WRITE;
//    READ;

    int i, j, k;
    int t, cases = 1,  fx, fy, sx, sy;
    while(s2(n,m) == 2)
    {
        s2(ex, ey);
        s2(fx, fy);
        s2(sx, sy);
        ex--;
        ey--;
        fx--;
        fy--;
        sx--;
        sy--;
        for(i = 0; i <n; i++)
            scanf("%s", str[i]);

        int res = BFS(fx, fy, sx, sy);
        if(res == INF)
            printf("NO LOVE\n");
        else
            printf("%d\n", res);
    }





    return 0;
}

/*

10 15
1 8 10 9 10 7
...............
.###.###.###.##
##.#.#.###.#.#.
.......#.......
.#####.#.#####.
.......#.......
##.#.#.#.#.#.##
.......#.......
.#############.
.......#.......
3 3
1 2 3 2 3 2
...
.#.
...
3 3
1 2 3 2 3 2
...
###
...
3 3
3 2 3 2 3 2
...
###
...





3 3
1 2 3 1 3 3
#..
.##
...

*/
