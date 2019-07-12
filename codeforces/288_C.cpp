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
#define s1(a) scanf("%d", &a)
#define s2(a, b) scanf("%d %d", &a, &b)
#define s3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define p1(a) printf("%d", a)
#define p2(a, b) printf("%d %d", a, b)
#define p3(a, b, c) printf("%d %d %d", a, b, c)

#define MOD 1000000007
#define MAX 1000


//template <class T>
//void pop_front(IgushArray<T>& v)
//{
//  if (!v.empty())
//    v.erase(v.begin());
//}


using namespace std;

int val[MAX];

int main()
{
    int tc,cs=1,i,j,k;
    int n,m,r;
    string str;
    int t;

    cin>>m>>t>>r;
    for(i = 0; i < m; i++)
    {
        cin>>val[i];
        val[i] += 301;
    }
    vector<int>V;
    if(r > t)
    {
        cout<<-1<<endl;
        return 0;
    }
    bool vis[MAX];
    memset(vis,false, sizeof vis);
    int ans = 0;
    for(i = 0; i < m; i++)
    {
        if(V.size())
        while(V.size() && V[0] < val[i])
        {
            V.erase(V.begin());
        }
        int sz = V.size();
        if(sz >= r) continue;

        for(j = val[i]; (j - val[i]) < t; j--)
        {
            if(vis[j + t-1]) continue;
            vis[j + t-1]= true;
            sz++;
            ans++;
//            cout<<j<<" ";
            V.push_back(j+t-1);
            if(sz==r)
                break;
        }
        sort(V.begin(), V.end());
    }
    cout<<ans<<endl;









    return 0;
}

/*

5 5 5
1 2 3 4 5

*/
