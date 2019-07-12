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


string str[109];
bool is[109];

int main()
{
    int tc,cs=1,i,j,k;
    int n, m;

    cin>>n>>m;

    for(i = 0; i < n;  i++)
        cin>>str[i];

    clr(is, false);

    vector<int>V;

    int cnt = 0;

    for(k = 0; k < m; k++)
    {
        V.clear();
        for(i = 1; i < n; i++)
        {
            if(is[i]) continue;
            if(str[i][k] > str[i - 1][k])
                V.push_back(i);
            else if(str[i][k] < str[i - 1][k])
            {
                cnt++;
                break;
            }
        }

        if(i != n)
        {
            continue;
        }

        for(i = 0; i < V.size(); i++)
        {
            is[V[i]] = true;
        }
    }
    cout<<cnt<<endl;













    return 0;
}

/*





*/
