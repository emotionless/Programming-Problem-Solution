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
#define pb push_back
#define pii pair<int, int>
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

#define use_cin  ios_base::sync_with_stdio(0); cin.tie(0);


#define s1(a) scanf("%d", &a)
#define s2(a, b) scanf("%d %d", &a, &b)
#define s3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define p1(a) printf("%d", a)
#define p2(a, b) printf("%d %d", a, b)
#define p3(a, b, c) printf("%d %d %d", a, b, c)
#define eps 1e-9


#define MOD 1000000007
#define MAX 1000009



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

//int dr[] = {-1, 0, 1, 0}; int dc[] = {0, 1, 0, -1}; /// 4 sides
//int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1}; dc[] = {0, 1, 1, 1, 0, -1, -1, -1}; /// 8 sides


///***** Template ends here *****///
///********************* Code starts here ****************************
const int mx = 26;
struct node
{
    int nxt[mx];
    node()
    {
        memset(nxt, -1, sizeof nxt);
    }
};

node T[10*MAX];
int fl[MAX];
int ind[1009];
int nw;
int val[10*MAX];

//int ST[MAX];
int stock[10*MAX];
int top;

void init()
{
    nw = 0;
    top = 0;
    memset(T, 0, sizeof T);
    memset(fl, 0, sizeof fl);
    memset(ind, 0, sizeof ind);
    memset(val, 0, sizeof val);
    memset(stock, 0, sizeof stock);
    T[0] = node();
}

void Aho(char S[], int pos)
{
    int len = strlen(S);
    int p = 0;
    for(int i = 0; i < len; i++)
    {
        int id = S[i] - 'A';
        if(T[p].nxt[id] == -1)
        {
            T[p].nxt[id] = (++nw);

            T[nw] = node();
        }
        p = T[p].nxt[id];
    }
    ind[pos] = p;
    stock[p] = pos;
//    cout<<pos<<" "<<p<<endl;
}


void Failure()
{
//    cout<<"Failure is here\n";
    queue<int>Q;
    for(int i = 0; i < mx; i++)
    {
        if(T[0].nxt[i] != -1)
            Q.push(T[0].nxt[i]);
        else
            T[0].nxt[i] = 0;
    }
    fl[1] = 0;
    top = 0;
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
//        ST[top++] = u;

        for(int i = 0; i < mx; i++)
        {
            int v = T[u].nxt[i];
            if(T[u].nxt[i] == -1)
            {
                T[u].nxt[i] = T[fl[u]].nxt[i];
                continue;
            }
            fl[v] = T[fl[u]].nxt[i];
            Q.push(v);
        }
    }
}

char str[1009][1009];

int x[1009];
int y[1009];
char chr[1009];

void Search(string tar, char ch, int r, int c)
{
    int p = 0;
    int len = tar.length();
    for(int i = 0; i < len; i++)
    {
        int id = tar[i] - 'A';
        p = T[p].nxt[id];
        val[p]++;
        if(stock[p])
        {
            int pos = stock[p];
            int mnus = i - strlen(str[pos - 1]) + 1;
            if(ch == 'G')
            {
                x[pos] = r;
                y[pos] = tar.length() - mnus - 1;
                chr[pos] = 'G';
//                cout<<r<<" "<<tar.length() - mnus - 1<<" G"<<endl;
            }
            else if(ch == 'A')
            {
                x[pos] = r - mnus;
                y[pos] = c;
                chr[pos] = 'A';
//                cout<<r - mnus<<" "<<c<<" A"<<endl;
            }
            else if(ch == 'B')
            {

                x[pos] = r - mnus;
                y[pos] = c + mnus;
                chr[pos] = 'B';
//                cout<<r - mnus << " "<<c + mnus<<" B"<<endl;
            }
            else if(ch == 'C')
            {
                x[pos] = r;
                y[pos] = mnus;
                chr[pos] = 'C';

//                cout<<r<<" "<<mnus<<" C"<<endl;
            }
            else if(ch == 'D')
            {
                x[pos] = r + mnus;
                y[pos] = c + mnus;
                chr[pos] = 'D';
//                cout<<r + mnus<<" "<<c + mnus<<" D"<<endl;
            }
            else if(ch == 'E')
            {
                x[pos] = mnus;
                y[pos] = c;
                chr[pos] = 'E';
//                cout<<mnus<<" "<<c<<" E"<<endl;
            }
            else if(ch == 'F')
            {
                x[pos] = r + mnus;
                y[pos] = c + mnus;
                chr[pos] = 'F';
//                cout<<r + mnus <<" "<<c + mnus<<" F"<<endl;
            }
            else if(ch == 'H')
            {
                x[pos] = r - mnus;
                y[pos] = c - mnus;
                chr[pos] = 'H';
//                cout<<r - mnus<<" "<<c - mnus<<" H"<<endl;
            }
        }
//        cout<<p<<endl;
    }
//    for(int i = top - 1; i >= 0; i--)
//    {
//        int id = ST[i];
//        val[fl[id]] += val[id];
//    }

    return;
}


char mat[1009][1009];

int main()
{
//    READ;
//    WRITE;
//    use_cin;

    int i, j, k;
    int cases = 1, S, q;
    int  m, n;
    int t;
    bool ck = 0;
    s1(t);

    while(t--)
    {
        scanf("%d %d %d", &n, &m, &q);

        for(i = 0; i < n; i++)
            scanf(" %s", mat[i]);
        for(i = 0; i < q; i++)
            scanf(" %s", str[i]);

        nw = 0;
        init();

        for(i = 0; i < q; i++)
            Aho(str[i], i + 1);
        Failure();
        string tar;

        for(i = 0; i < n; i++)
        {
            tar = "";
            for(j = 0; j < m; j++)
                tar += mat[i][j];
            Search(tar, 'C', i, 0);
            reverse(tar.begin(), tar.end());
            Search(tar, 'G', i, m - 1);
        }

        for(i = 0; i < m; i++)
        {
            tar = "";
            for(j = 0; j < n; j++)
                tar += mat[j][i];
            Search(tar, 'E', 0, i);
            reverse(tar.begin(), tar.end());
            Search(tar, 'A', n - 1, i);
        }
        for(i = 0; i < n; i++)
        {
            tar = "";
            for(j = 0; j < n && j < m && i + j < n; j++)
                tar += mat[i + j][j];
            Search(tar, 'D', i, 0);
            reverse(tar.begin(), tar.end());
            Search(tar, 'H', i + j - 1, j - 1);
        }

        for(i = 0; i < n && i < m; i++)
        {

            tar = "";
            k = 0;
            for(j = 1; j < m; j++)
                tar += mat[k++][i + j];
            Search(tar, 'D', 0, j + i - 1);
            cout<<tar<<endl;
            reverse(tar.begin(), tar.end());
            Search(tar, 'H', j - 1, j + i - 1);
            cout<<tar<<endl;
        }

        for(i = 0; i < n; i++)
        {
            tar = "";
            for(j = 0; j <= i && j < m; j++)
                tar += mat[i - j][j];
            Search(tar, 'B', i, 0);
            reverse(tar.begin(), tar.end());
            Search(tar, 'F', i - j - 1, j + 1);
        }
        for(i = 1; i < m; i++)
        {
            tar = "";
            k = i;
            for(j = n - 1; j >= 0 && k < m; j--)
                tar += mat[j][k++];
            Search(tar, 'B', n - 1, i);
            reverse(tar.begin(), tar.end());
            Search(tar, 'F', j + 1, k - 1);
        }
//        if(ck)
            printf("\n");
        ck = 1;
        for(i = 1; i <= q; i++)
            printf("%d %d %c\n", x[i], y[i], chr[i]);
    }


    return 0;
}
/*

20 20 10
QWSPILAATIRAGRAMYKEI
AGTRCLQAXLPOIJLFVBUQ
TQTKAZXVMRWALEMAPKCW
LIEACNKAZXKPOTPIZCEO
FGKLSTCBTROPICALBLBC
JEWHJEEWSMLPOEKORORA
LUPQWRNJOAAGJKMUSJAE
KRQEIOLOAOQPRTVILCBZ
QOPUCAJSPPOUTMTSLPSF
LPOUYTRFGMMLKIUISXSW
WAHCPOIYTGAKLMNAHBVA
EIAKHPLBGSMCLOGNGJML
LDTIKENVCSWQAZUAOEAL
HOPLPGEJKMNUTIIORMNC
LOIUFTGSQACAXMOPBEIO
QOASDHOPEPNBUYUYOBXB
IONIAELOJHSWASMOUTRK
HPOIYTJPLNAQWDRIBITG
LPOINUYMRTEMPTMLMNBO
PAFCOPLHAVAIANALBPFS
MARGARITA
ALEMA
BARBECUE
TROPICAL
SUPREMA
LOUISIANA
CHEESEHAM
EUROPA
HAVAIANA
CAMPONESA



2 10 3
ABCDEFGHIJ
ADSFASDFSF
CF
SG
IF


*/
