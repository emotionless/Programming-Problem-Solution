#include <bits/stdc++.h>

#define LL long long
#define MX 2009
#define clr(aa, bb) memset(aa, bb, sizeof aa)
#define MD 1000000007
#define check_bit(a,b) (a & (1<<b))
#define set_bit(a,b) (a | (1<<b))
#define PB push_back
#define FOR(aa,nn) for(aa=0; aa<nn; aa++)
#define vi vector<int>
#define vll vector<long long>
#define mp make_pair
#define pi pair<int, int>
#define ll long long
#define MOD  1000000007ll
#define check(aa , bb) (aa & (1<<bb))

#define PI 3.14159265358979323846264338328

using namespace std;
int word_len, r;
string tolower_letter(string str)
{
    int len = str.length();
    word_len = len;
    r = 0;
    for(int i = 0; i < len; i++)
    {
        str[i] = tolower(str[i]);
        if(str[i] == 'r')
            r++;
    }
    return str;
}


vector<int>V[100001];
int len[100001];
int cost[100001];
int dp[100001];
bool vis[100001];
map<string, int>M;
int DFS(int src)
{
    if(vis[src]) return dp[src];
    vis[src] = true;
    dp[src] = src;
    int ret = src;
    int sz = V[src].size();
    for(int i = 0; i < sz; i++)
    {
        int tmp = DFS(V[src][i]);
        if(cost[tmp] < cost[ret])
            ret = tmp;
        else if(cost[tmp] == cost[ret])
        {
            if(len[tmp] < len[ret])
                ret = tmp;
        }
    }
    return dp[src] = ret;
}


int main()
{
    int i, j, k;
    int n, m;
    string str;
    cin>>n;
    getchar();
    getline(cin, str);
    stringstream ss;
    string tmp;

    cin>>m;
    string s, t;
    k = 0;
    while(m--)
    {
        cin>>s>>t;
        tmp = tolower_letter(s);
        if(!M[tmp]) M[tmp] = (++k);

        int u = M[tmp];
        cost[u] = r;
        len[u] = word_len;

        tmp = tolower_letter(t);
        if(!M[tmp]) M[tmp] = (++k);
        int v = M[tmp];
        cost[v] = r;
        len[v] = word_len;
        V[u].PB(v);
    }

    ss<<str;
    int ans = 0, res = 0;
    while(ss >> tmp)
    {
        string word = tolower_letter(tmp);
        if(!M[word])
        {
            ans += r;
            res += word_len;
        }
        else
        {
            int ind = DFS(M[word]);
            ans += cost[ind];
            res += len[ind];
        }
        //cout<<word<<" "<<ans<<" "<<res<<endl;

    }
    cout<<ans<<" "<<res<<endl;














    return 0;
}

/*


3
AbRb r Zz
7
xR abRb
abRb r
r abRb
r a
aA xr
zz Z
xr y


2
ara bbb
2
ara r
bbb aaa


10
r r r r r r r r r r
1
r aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa

*/
