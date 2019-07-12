#include <bits/stdc++.h>

#define ll long long

using namespace std;

int arr[100009];

map<int, int>M;

int main()
{
    int i, j, k;
    int n, m, q, u, v;
    scanf("%d %d %d", &n, &m, &q);
    for(i = 1; i <= n; i++)
        scanf("%d", &arr[i]);
    while(q--)
    {
        scanf("%d %d", &u, &v);
        int ans = 0;
        M.clear();
        for(i = u; i <= v; i++)
        {
            if(!M[arr[i]])
                M[arr[i]] = i;
            else
                ans = max(ans, i - M[arr[i]]);
        }
        printf("%d\n", ans);
    }







    return 0;
}

/*

5 10000000
1 2 3 4 5

*/
