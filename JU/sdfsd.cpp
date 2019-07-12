#include<bits/stdc++.h>

#define MAX 1000009

using namespace std;

map<double, bool>M;

int x[12];
int y[12];
int arr[12];

double dull(int i, int j)
{
    return (double)(y[j] - y[i])/(double)(x[j] - x[i]);
}


int main()
{

    int i, j, k;
    int n,  q, cases = 1;
    int t, u, v, tg, ks= 1, dr;
    string str, tmp;
    scanf("%d", &t);
    while(t--)
    {
        long long m;
        scanf("%d %lld", &n, &m);

        for(i = 1 ; i <= n; i++)
        {
            scanf("%d %d", &x[i], &y[i]);
            arr[i] = i;
        }
        long long cnt = 0;
        map< pair< int, pair<int,int> >, bool > M;

        for(i = 1; i <= n; i++)
        {
            for(j = i + 1; j <= n; j++)
            {
                long long a = (y[j] - y[i]);
                long long b = (x[j] - x[i]);
                bool c = (a * b < 0)?1:0;
                if(a < 0) a = a * -1;
                if(b < 0) b = b * -1;
                long long gcd = __gcd(a, b);
                a = a/ gcd;
                b = b/gcd;
                if(M.find(make_pair(a, make_pair(b, c))) == M.end())
                {
                    M[make_pair(a, make_pair(b, c))] = 1;
                    cnt++;
                }
            }
        }

        printf("Case %d: %lld\n", ks++, cnt*m);

    }




    return 0;
}
/*






1
4 1
-2 0
1 1
-1 1
0 0


*/
