#include<iostream>
#include<string>
#include<cstring>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<cctype>
#include <climits>

#define MX 500009

#define PI 3.14159265358979323846264338328

using namespace std;

struct Z
{
    int u, v;
    int w, used, del;
    Z() {}
    Z(int _, int __, int ___)
    {
        u = _;
        v = __;
        w = ___;
        used = false;
        del = false;
    }
} arr[MX];

bool comp(Z A, Z B)
{
    return A.w < B.w;
}

int n, m;
int par[509];
int ranking[509];

int find(int x)
{
    if(par[x] == x) return x;
    return par[x] = find(par[x]);
}

void Union(int x, int y)
{
    if(ranking[x] > ranking[y])
        par[y] = x;
    else
    {
        par[x] = y;
        if(ranking[x] == ranking[y])
            ranking[y]++;
    }
}

bool ok;

int mst()
{


    for(int i = 1; i <= n; i++)
        par[i] = i, ranking[i] = 0;
    int res = 0;
    int con = 0;
    for(int i = 0; i < m; i++)
    {
        Z top = arr[i];
        if(arr[i].del) continue;
        int x = top.u;
        int y = top.v;
        int w = top.w;

        int px = find(x);
        int py = find(y);
        if(px != py)
        {
            Union(px, py);
            res += w;
            if(!ok)
                arr[i].used = true;
            con++;
        }
        if(con >= n - 1) break;
    }
    if(con < n - 1) return -1;
    return res;
}


int main()
{
    int i, j, k;
    int w;
    scanf("%d %d", &n, &m);
    int need, u, v;
    for(i = 0; i < m; i++)
    {
        scanf("%d %d %d,", &u, &v, &need);
        arr[i] = Z(u, v, need);
        arr[i].used = arr[i].del = false;
    }
    sort(arr, arr + m, comp);
    ok = false;

    int mn1 = mst();
    if(mn1 == -1)
    {
        printf("Cost: ");
        printf("-1\n");

        printf("Cost: ");
        printf("-1\n");
        return 0;

    }

    if(m == n - 1)
    {
        printf("Cost: ");
        printf("%d\n", mn1);

        printf("Cost: ");
        printf("-1\n");
        return 0;

    }

    ok = true;
    int mn = INT_MAX;

    for(i = 0; i < m; i++)
    {
        if(arr[i].used)
        {
            arr[i].del= true;
            int w = mst();
            if(w < mn && w != -1)
                mn = w;
            arr[i].del = false;
        }
    }
    printf("Cost: ");
    printf("%d\n", mn1);

    printf("Cost: ");
    if(mn == INT_MAX)
    {
        printf("-1\n");
    }
    else
        printf("%d\n", mn);
    return 0;
}

/*



3 2
1 2 0
1 3 0

*/

