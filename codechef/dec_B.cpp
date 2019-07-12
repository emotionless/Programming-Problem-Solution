/*
******************************************
***** Bismillahir Rahmanir Rahim *********
***** Full Name: Faruk Hossain Milon *****
***** University: IIT-JU, BD ****************

***** Codechef username: emotionless *****
***** Topcoder handle: emotionless *******
***** UVA username: emotionless **********
***** Hust username: emotionless *********
***** Codeforces handle: milon ***********
******************************************
***** Sorry for bad written code **********
*/


#include<bits/stdc++.h>


#define clr(a,k) memset(a,k,sizeof a)

#define xx first
#define yy second
#define all(a) a.begin(), a.end()
#define vsort(v) sort(all(v))
#define UNIQUE(a)  sort(all(a)); a.erase(unique(all(a)), a.end())


#define MAX 509

using namespace std;
bool vis[MAX];
int arr[200009];

bool mat[MAX][MAX];
bool can[MAX][MAX];

int N;
int  K, M;


vector<int>v[MAX];

void DFS(int cn, int u)
{
    if(vis[u]) return;
    vis[u] = true;
    mat[cn][u] = 1;
    v[cn].push_back(u);
    for(int i = 1; i <= M; i++)
    {
        if(!vis[i] && can[u][i])
            DFS(cn, i);
    }
    return;
}

int dp[200009][MAX];

int solve(int ind, int pre)
{
    if(ind >= N)
        return 0;
    int &ret = dp[ind][pre];
    if(ret != -1) return ret;
    ret = 10000000;
    for(int i = pre; i <= M; i++)
    {
        if(mat[arr[ind]][i])
        {
            ret = min(ret, (arr[ind]!=i) + solve(ind + 1, i));
            if(arr[ind] < i) break;
        }
    }
    return ret;
}


int BS(vector<int>vec, int num)
{
    int st = 0, ed = vec.size() - 1, mid;
    int ans = 100000;
    while(st <= ed)
    {
        mid = (st + ed)/2;
        if(vec[mid] >= num)
        {
            ans = min(ans, vec[mid]);
            ed = mid - 1;
        }
        else
            st = mid + 1;
    }

    return ans;
}



int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");
    int i,j;
    int t;
    int a, b;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d %d", &M, &K, &N);

        for(i = 0; i < K; i++)
        {
            scanf("%d %d", &a, &b);
            can[a][b] = can[b][a] = 1;
        }

        for(i = 1; i <= M; i++)
        {
            clr(vis, false);
            DFS(i, i);
            UNIQUE(v[i]);
        }

        for(i = 0; i <= N + 1; i++)
            for(j = 0; j <= M + 1; j++)
                dp[i][j] = 10000000;
        for(i = 0; i <=M; i++)
            dp[N][i] = 0;


        for(i = 0; i < N; i++)
            scanf("%d", &arr[i]);;

        for(i = N - 1; i >= 0; i--)
        {
            for(j = M; j >= 1; j--)
            {
                if(mat[arr[i]][j])
                    dp[i][j] = dp[i + 1][j] + (j != arr[i]);
                dp[i][j] = min(dp[i][j], dp[i][j + 1]);
            }
        }
        int res = INT_MAX;
        for(i = 1; i <= M; i++)
            res = min(res, dp[0][i]);
        if(res >= 10000000)
            printf("-1\n");
        else
            printf("%d\n", res);

        clr(mat, false);
        clr(can, false);
        for(i = 0; i <= 200; i++)
            v[i].clear();



    }
    return 0;
}

/*
1
3 0 3
1 2 1

2
3 3 3
1 2
2 3
3 1
3 2 1
3 1 2
2 3
2 1

*/
