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



LL arr[100009];
string str[509], inp;

bool vis[509][509];

int t, n;
int cases = 1;
int num, m;
int sx, sy, ex, ey;

int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

void BFS()
{

    clr(vis, false);

    queue<pii>Q;
    Q.push(mp(sx, sy));
    bool f = 0;
    while(!Q.empty())
    {
        pii top = Q.front();
        Q.pop();

        int cx = top.xx;
        int cy = top.yy;
        if(str[cx][cy] == 'X' && f == 1) continue;
        if(vis[cx][cy]) continue;
        f = 1;
        vis[cx][cy] = 1;
        for(int i = 0; i < 4; i++)
        {
            int adx = cx + dr[i];
            int ady = cy + dc[i];
            if( adx <= 0 || adx > n || ady <= 0 || ady > m) continue;
            Q.push(mp(adx, ady));
        }
    }
}


int main()
{
    int i, j, k;
    cin>>n>>m;
    for(i = 1; i <= n; i++)
    {
        cin>>str[i];
        str[i] = " "+ str[i];
    }



    cin>>sx>>sy;
    cin>>ex>>ey;




    BFS();

    if(str[ex][ey] == '.')
    {

        int cnt = 0;
        bool ok = false;
        for(i = 0; i < 4; i++)
        {
            if(str[ex + dr[i]] [ey + dc[i]] == '.')
            {

                cnt++;
                if(vis [ex + dr[i]] [ey + dc[i]])
                    ok = 1;
            }
        }


        if(cnt >= 2 && ok)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    else
    {
        int cnt = 0;
        bool ok = false;
        for(i = 0; i < 4; i++)
        {
            if(str[ex + dr[i]] [ey + dc[i]] == '.')
            {
                cnt++;
                if(vis [ex + dr[i]] [ey + dc[i]])
                    ok = 1;
            }
        }

        if(cnt >= 1 && ok)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

    return 0;
}

/*

4 7
..X.XX.
.XX..XX
X...X..
X......
2 2
2 6
*/
