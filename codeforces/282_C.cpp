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
#define mp make_pair
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
#define MX 200009


using namespace std;


bool vis[MX];

int main()
{
    int tc,cs=1,i,j,k;
    int n, m;
    string str;
    cin>>str;
    int len = str.length();
    int t = 0, f = 0;
    for(i = 0; i < len; i++)
    {
        if(str[i] == ')')
            t++;
    }
    for(i = 0; i < len; i++)
    {
        if(str[i] == '(')
            f++;
    }

    if(f == t)
    {
        cout<<-1<<endl;
        return 0;
    }

    if(t > f)
    {
        cout<<-1<<endl;
        return 0;
    }
    stack<int>ST;
    for(i = 0; i < len; i++)
    {
        if(str[i] == '#') continue;
        if(str[i] == '(')
            ST.push(i);
        else
        {
            if(!ST.empty())
            {
                int top = ST.top();
                ST.pop();
                vis[i] = vis[top] = true;
            }
        }
    }
    int cnt = 0;
    vector<int>ans;
    for(i = 0; i < len; i++)
    {
        if(vis[i]) continue;
        if(str[i] == '#')
        {
            ans.push_back(cnt);
            cnt = 0;
        }
        else if(str[i] == '(')
            cnt++;
    }
//
//    if(cnt)
//    {
//        cout<<-1<<endl;
//        return 0;
//    }
    for(i = 0; i < ans.size(); i++)
        cout<<ans[i]<<endl;









    return 0;
}

/*





*/
