#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i, j, k;
    int n, m, num, a, tm;
    int t, cs = 1;

    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d %d", &n, &a, &tm);
        printf("Case %d: ", cs++);

        if(a >= tm || n==1)
        {
            printf("-1\n");
            continue;
        }
        int st = 1, ed = tm, ans = -1, mid;
        int dif = tm - a;

        while(st <= ed)
        {
            mid = (st + ed)/2;
            int now = dif/mid;
            if(n-now > 1)
            {
                ans = mid;
                ed = mid - 1;
            }
            else
                st = mid + 1;
        }
        printf("%d\n", ans);
    }

return 0;
}
