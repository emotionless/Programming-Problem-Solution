#include <stdio.h>
#include <string.h>
#define INF 0x3f3f3f3f
const int MAXN = 25;
int min(int a, int b)
{
    return a < b ? a : b;
}
int N;
int n, m, i, j, k, line[MAXN][MAXN], dp[1<<20];
struct Point
{
    int x, y;
} p[MAXN];

int DP(int ss)
{
    if (dp[ss] != -1)
        return dp[ss];
    int &ans = dp[ss];
    int count = 0;
    for (int ii = 0; ii < n; ii ++)
    {
        if ((1 << ii) & ss) count ++;
    }
    if (count <= (n - m)) return ans = 0;
    if (count == 1) return ans = 1;
    ans = INF;
    for (int i = 0; i < n; i ++)
    {
        if (ss & (1 << i))
            for (int j = i + 1; j < n; j ++)
            {
                if (ss & (1 << j))
                {
                    ans = min(ans, DP(ss&(~line[i][j])) + 1);
                }
            }
    }
    return ans;
}

int main()
{
    int T = 0;
    scanf("%d", &N);
    while (N --)
    {
        memset(line, 0, sizeof(line));
        memset(dp, -1, sizeof(dp));
        scanf("%d%d", &n, &m);
        for (i = 0; i < n; i ++)
        {
            scanf("%d%d", &p[i].x, &p[i].y);
        }
        for (i = 0; i < n; i ++)
        {
            for (j = i + 1; j < n; j ++)
            {
                int s = 0;
                for (k = n - 1; k >= 0; k --)
                {
                    if ((p[i].x - p[k].x) * (p[j].y - p[k].y) == (p[j].x - p[k].x) * (p[i].y - p[k].y))
                    {
                        s = s * 2 + 1;
                    }
                    else
                    {
                        s *= 2;
                    }
                }
                line[i][j] = line[j][i] = s;
            }
        }
        printf("Case #%d:\n", ++ T);
        printf("%d\n", DP((1<<n) - 1));
        if (N) printf("\n");
    }
    return 0;
}
