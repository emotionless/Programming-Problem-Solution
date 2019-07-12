#include <bits/stdc++.h>

using namespace std;


int arr[1009];
int ans[1009];
int main()
{
    int a, b, c, n, m, t, cs = 1, i, j;
    int num;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        memset(ans, 0, sizeof ans);
        for(i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        ans[0] = 1;
        int res = 1;
        for(i = 1; i < n; i++)
        {
            int now = 1;
            for(j = 0; j < i; j++)
            {
                if(arr[i] < arr[j])
                    now = max(now, ans[j]+1);
            }
            ans[i] = now;
            res = max(res, now);
        }
        printf("%d\n", res);
    }

return 0;
}
