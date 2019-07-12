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
#define MAX 200009


using namespace std;

vector<int>V[309];

bool vis[309];
int arr[309];

int tmp[309];

int DFS(int num)
{
    if(tmp[num]) return INT_MAX;
    tmp[num] = 1;
    int mn = INT_MAX;
    int sz = V[num].size();
    if(!vis[arr[num]])
        mn = arr[num];
    for(int i = 0; i < sz; i++)
    {
        mn = min(mn, DFS(V[num][i]));
    }
return mn;
}


int main()
{
    int tc,cs=1,i,j,k;
    int n, m;

    FILE *fp;
    fp = fopen("t.txt", "w", stdout);
    for(i = 1; i <= 300; i++)
    printf("%d ", i);
    printf("\n");
    for(i = 0; i<300; i++)
    {
        for(j = 0; j < 300; j++)
        {
            if(i == j) printf("0");
            else
                printf("1");
        }
        printf("\n");
    }


    cin>>n;
    for(i = 1; i <= n; i++)
    {
        cin>>arr[i];
    }
    string str;
    for(i = 1; i <= n; i++)
    {
        cin>>str;
        for(j = 0; j < n; j++)
        {
            if(str[j] == '1')
                V[i].pb(j + 1);
        }
    }

    for(i = 1; i <= n; i++)
    {
        clr(tmp, 0);
        int num = DFS(i);
        vis[num] = true;
        cout<<num<<" ";
    }










    return 0;
}

/*





*/
