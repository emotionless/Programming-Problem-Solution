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
#define nl printf("\n")
#define sp printf(" ")
#define pii pair<int, int>
#define vll vector<long long>
///***** bit *****///
#define check_bit(a, b) (a&(1<<b))
#define set_bit(a, b) (a|(1<<b))
#define total_bit(a) __builtin_popcount(a)

#define WRITE freopen("output.txt","w",stdout)
#define use_cin  ios_base::sync_with_stdio(0); cin.tie(0);
#define READ  freopen("D-small-attempt0.in","r",stdin)

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

//int dr[] = {-1, 0, 1, 0};
//int dc[] = {0, 1, 0, -1}; /// 4 sides
//int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1}; dc[] = {0, 1, 1, 1, 0, -1, -1, -1}; /// 8 sides

#define LEN(a) strlen(a)

#define MX 10000000000000000ll
#define lim 100000      /// 10^5

///***** Template ends here *****///
///********************* Code starts here ****************************



#define BD_MAXXXX  4


struct State
{
    char bd[BD_MAXXXX][BD_MAXXXX];
    State()
    {
        memset(bd, '-', sizeof(bd));
    }
    bool operator<(const State &rhs) const
    {
        return memcmp(bd, rhs.bd, sizeof(bd)) < 0;
    }
};

enum
{
    WIN = 1,
    CONT,
    STOP
};

int move(bool white, char piv, int i, int j, State &s, queue<State> &q)
{
    if (s.bd[i][j] == '-')
    {
        s.bd[i][j] = piv;
        q.push(s);
        s.bd[i][j] = '-';
        return CONT;
    }
    char op;
    if (white && !isupper(s.bd[i][j]))
    {
        if (s.bd[i][j] == 'q')
            return WIN;
        op = s.bd[i][j];
        s.bd[i][j] = piv;
        q.push(s);
        s.bd[i][j] = op;
    }
    else if (!white && isupper(s.bd[i][j]))
    {
        if (s.bd[i][j] == 'Q')
            return WIN;
        op = s.bd[i][j];
        s.bd[i][j] = piv;
        q.push(s);
        s.bd[i][j] = op;
    }
    return STOP;
}

bool pawn(bool white, int r, int c, State &s, queue<State> &q)
{
    if (white && !isupper(s.bd[r][c])) return false;
    if (!white && isupper(s.bd[r][c])) return false;

    static char offset[2] = { -1, 1 };
    static char promo[4] = { 'B', 'K', 'R', 'N' };

    bool ans = false;
    char piv = s.bd[r][c];
    s.bd[r][c] = '-';
    int i = r + ((white)? 1: -1);
    char op;
    for (int k = 0; k < 2; ++k)
    {
        int j = c + offset[k];
        if (0 <= j && j < BD_MAXXXX)
        {
            if ((white && !isupper(s.bd[i][j])) || (!white && isupper(s.bd[i][j])))
            {
                if (tolower(s.bd[i][j]) == 'q')
                {
                    ans = true;
                }
                else
                {
                    op = s.bd[i][j];
                    if ((white && i + 1 == BD_MAXXXX) || (!white && i == 0))
                    {
                        for (int k = 0; k < 4; ++k)
                        {
                            s.bd[i][j] = (white)? promo[k]: tolower(promo[k]);
                            q.push(s);
                        }
                    }
                    else
                    {
                        s.bd[i][j] = piv;
                        q.push(s);
                    }
                    s.bd[i][j] = op;
                }
            }
        }
    }
    if (!ans)
    {
        if (s.bd[i][c] == '-')
        {
            op = s.bd[i][c];
            if ((white && i + 1 == BD_MAXXXX) || (!white && i == 0))
            {
                for (int k = 0; k < 4; ++k)
                {
                    s.bd[i][c] = (white)? promo[k]: tolower(promo[k]);
                    q.push(s);
                }
            }
            else
            {
                s.bd[i][c] = piv;
                q.push(s);
            }
            s.bd[i][c] = op;
        }
    }
    s.bd[r][c] = piv;
    return ans;
}

bool knight(bool white, int r, int c, State &s, queue<State> &q)
{
    if (white && !isupper(s.bd[r][c])) return false;
    if (!white && isupper(s.bd[r][c])) return false;

    static char offset[8][2] =
    {
        { -1, 2 }, { 1, 2 },
        { 2, 1 }, { 2, -1 },
        { 1, -2 }, { -1, -2 },
        { -2, -1 }, { -2, 1 },
    };

    bool ans = false;
    char piv = s.bd[r][c];
    s.bd[r][c] = '-';
    for (int k = 0; k < 8; ++k)
    {
        int i = r + offset[k][1];
        int j = c + offset[k][0];
        if (i < 0 || i >= BD_MAXXXX) continue;
        if (j < 0 || j >= BD_MAXXXX) continue;
        if (move(white, piv, i, j, s, q) == WIN)
        {
            ans = true;
            break;
        }
    }
    s.bd[r][c] = piv;
    return ans;
}

bool rook(bool white, int r, int c, State &s, queue<State> &q)
{
    if (white && !isupper(s.bd[r][c])) return false;
    if (!white && isupper(s.bd[r][c])) return false;

    bool ans = false;
    int ret = 0;
    char piv = s.bd[r][c];
    s.bd[r][c] = '-';
    if (!ans)
    {
        for (int j = c - 1; j >= 0; --j)
            if (CONT != (ret = move(white, piv, r, j, s, q)))
                break;
        ans = (ret == WIN);
    }
    if (!ans)
    {
        for (int j = c + 1; j < BD_MAXXXX; ++j)
            if (CONT != (ret = move(white, piv, r, j, s, q)))
                break;
        ans = (ret == WIN);
    }
    if (!ans)
    {
        for (int i = r - 1; i >= 0; --i)
            if (CONT != (ret = move(white, piv, i, c, s, q)))
                break;
        ans = (ret == WIN);
    }
    if (!ans)
    {
        for (int i = r + 1; i < BD_MAXXXX; ++i)
            if (CONT != (ret = move(white, piv, i, c, s, q)))
                break;
        ans = (ret == WIN);
    }
    s.bd[r][c] = piv;
    return ans;
}

bool bishop(bool white, int r, int c, State &s, queue<State> &q)
{
    if (white && !isupper(s.bd[r][c])) return false;
    if (!white && isupper(s.bd[r][c])) return false;

    bool ans = false;
    int ret = 0;
    char piv = s.bd[r][c];
    s.bd[r][c] = '-';
    if (!ans)
    {
        for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; --i, --j)
            if (CONT != (ret = move(white, piv, i, j, s, q)))
                break;
        ans = (ret == WIN);
    }
    if (!ans)
    {
        for (int i = r - 1, j = c + 1; i >= 0 && j < BD_MAXXXX; --i, ++j)
            if (CONT != (ret = move(white, piv, i, j, s, q)))
                break;
        ans = (ret == WIN);
    }
    if (!ans)
    {
        for (int i = r + 1, j = c - 1; i < BD_MAXXXX && j >= 0; ++i, --j)
            if (CONT != (ret = move(white, piv, i, j, s, q)))
                break;
        ans = (ret == WIN);
    }
    if (!ans)
    {
        for (int i = r + 1, j = c + 1; i < BD_MAXXXX && j < BD_MAXXXX; ++i, ++j)
            if (CONT != (ret = move(white, piv, i, j, s, q)))
                break;
        ans = (ret == WIN);
    }
    s.bd[r][c] = piv;
    return ans;
}

bool queen(bool white, int r, int c, State &s, queue<State> &q)
{
    return rook(white, r, c, s, q) || bishop(white, r, c, s, q);
}

int winable(bool white, int m, State &s, vector<map<State,int> > &dp)
{
    if (m == 0)
        return 0;

    int &ans = dp[m][s];
    if (ans) return ans;

    queue<State> q;
    for (int i = 0; i < BD_MAXXXX; ++i)
    {
        for (int j = 0; j < BD_MAXXXX; ++j)
        {
            bool win = false;
            switch(s.bd[i][j])
            {
            case 'Q':
            case 'q':
                win = queen(white, i, j, s, q);
                break;
            case 'N':
            case 'n':
                win = knight(white, i, j, s, q);
                break;
            case 'B':
            case 'b':
                win = bishop(white, i, j, s, q);
                break;
            case 'R':
            case 'r':
                win = rook(white, i, j, s, q);
                break;
            case 'P':
            case 'p':
                win = pawn(white, i, j, s, q);
                break;
            }
            if (win)
            {
                return ans = 1;
            }
        }
    }

    ans = -1;
    while (!q.empty())
    {
        State next = q.front();
        q.pop();
        int lose = winable(!white, m - 1, next, dp);
        if (lose < 0)
            return ans = 1;
        if (lose == 0)
            ans = 0;
    }
    return ans;
}

int main(void)
{
    cout.sync_with_stdio(false);
    int nTests;
    cin >> nTests;
    while (nTests--)
    {
        State s;
        int w, b, m;
        char t, c, r;
        cin >> w >> b >> m;

        for (int i = 0; i < w; ++i)
        {
            cin >> t >> c >> r;
            s.bd[r-'1'][c-'A'] = t;
        }
        for (int i = 0; i < b; ++i)
        {
            cin >> t >> c >> r;
            s.bd[r-'1'][c-'A'] = tolower(t);
        }

        vector<map<State,int> > dp(m+1);
        cout << ((winable(true, m, s, dp) > 0)? "YES": "NO") << endl;
    }
    return 0;
}
