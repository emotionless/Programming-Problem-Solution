#include <bits/stdc++.h>

using namespace std;


char str[20009];
//
//int nxt[20009];
////bool can[20009];
int h, n;
//int dp[20009];
bool ok;
//int go(int ind)
//{
//    if(ind >= n)
//    {
//        if(ok) return 0;
//        return 10000000;
//    }
//    if(n-ind < h)
//    {
//        if(ok) return 1;
//        return 10000000;
//    }
//    int &ret = dp[ind];
//    if(ret != -1) return ret;
//    ret = 10000000;
////    if((str[ind]-'a') == pre) return ret = go(ind+1, pre);
//    ret = go(min(nxt[ind], ind+h))+1;
//    return ret;
//}


int main()
{
    int i, j;
    int  w;
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &h);
        scanf("%s", str);
        int res = 0;
        int ace = 0;

        ok = 0;

        for(i = 0; i < n; i++)
        {
            if(ace < h && (!i || str[i]==str[i-1]))
                ace++;
            else
                ace = 1, res++;
            if(ace == h) ok = 1;
        }
        if(ace) res++;

        if(!ok)
            printf("-1\n");
        else
            printf("%d\n", res);
    }

    return 0;
}

/*

100
14 3
aaaaaaaaaaaaaa

1
6 3
azbbzz

1
4 2
aaba


1
8 3
zzaaazzz

*/
