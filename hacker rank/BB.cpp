#include<bits/stdc++.h>

#define xx first
#define yy second
#define vsort(v) sort(v.begin(),v.end())
#define clr(a,k) memset(a,k,sizeof a)
#define bclr(b) memset(b,false,sizeof b)
#define LL long long
#define PB push_back
#define MP make_pair
#define MOD 1000000007
#define MAX 20001
#define mp make_pair
#define use_cin  ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long
#define check(AA,BB) (AA&(1<<BB))
#define set_bit(AA,BB) (AA|(1<<BB))

using namespace std;


vector< pair<int , char> >V[MAX];

struct Z
{
    int v, pre, len;
    string str;
    Z() {}
    Z(int _, string __, int ___, int ____)
    {
        v = _;
        str = __;
        pre = ___;
        len = ____;
    }
    bool operator < (const Z& A) const
    {
        if(str == A.str) return v<A.v;
        return str < A.str;
    }
};

bool vis[MAX];

int BFS(int st)
{
    priority_queue< Z >Q;
    memset(vis, false, sizeof vis);

    Q.push(Z(st, "", -1, 0));

    Z tmp;
    string mx = "";
    int ans = 0;
    while(!Q.empty())
    {
        tmp = Q.top();
        Q.pop();

        int cn = tmp.v;
        string cc = tmp.str;
        int pre = tmp.pre;
        int len = tmp.len;
//        cout<<cn<< " "<<cc<<" "<<pre<<" "<<len<<endl;
        if(vis[cn]) continue;
        if(V[cn].size() == 1 && cn != st)
        {
            if(cc > mx)
            {
                ans = cn;
                mx = cc;
            }
            else if(cc == mx)
            {
                ans = max(ans, cn);
            }
        }
        vis[cn] = 1;
        int sz = V[cn].size();
        char ch = '0';
        for(int i = 0; i < sz; i++)
        {
            if(V[cn][i].xx != pre)
                ch = max(ch, V[cn][i].yy);
        }

        for(int i = 0; i < sz; i++)
        {
            if(V[cn][i].yy == ch)
                Q.push(Z(V[cn][i].xx, cc + ch, cn, len + 1));
        }
    }
    return ans;
}


string cost[MAX];
int ans[MAX];


void chalao(int st)
{
    priority_queue< Z >Q;
    memset(vis, false, sizeof vis);

    Q.push(Z(st, "", -1, 0));


    Z tmp;
//    cout<<"For: "<<st<<endl;
    while(!Q.empty())
    {
        tmp = Q.top();
        Q.pop();

        int cn = tmp.v;
        string cc = tmp.str;
        int pre = tmp.pre;
        int len = tmp.len;
        if(vis[cn]) continue;
        vis[cn] = 1;
        string rv = cc;
//        reverse(rv.begin(), rv.end());
        if(rv > cost[cn])
        {
            cost[cn] = rv;
            ans[cn] = st;
        }
        else if(rv == cost[cn])
        {
            ans[cn] = max(ans[cn], st);
        }
//        cout<<cn<<endl;
        int sz = V[cn].size();


        for(int i = 0; i < sz; i++)
        {
            if(V[cn][i].xx != pre)
                Q.push(Z(V[cn][i].xx, V[cn][i].yy + cc, cn, len + 1));
        }
    }
return;
}




int main()
{
    int t, cases = 1;
    int n;
    use_cin;
    cin>>n;
    int u, v;
    int i, j, k;
    char c;

    if(n == 1)
    {
        return 0;
    }

    for(i = 1; i < n; i++)
    {
        cin>>u>>v>>c;
        V[u].push_back(mp(v, c));
        V[v].push_back(mp(u, c));
    }

    for(i = 1; i <= n; i++)
    {
        if(V[i].size() == 1)
        {
            chalao(i);
        }
    }
    for(i = 1; i <= n; i++)
    {
        cout<<ans[i];
        if(i < n)
            cout<<" ";
    }
    cout<<endl;


//    for(i = 1; i  <= n; i++)
//    {
////        cout<<"For: "<<i<<endl;
//        int get = BFS(i);
//        cout<<get;
//        if(i < n)
//            cout<<" ";
//    }
//    cout<<endl;









    return 0;
}

/*

5 5
1 2
2 3
3 4
2 4
2 5

*/
