#include<bits/stdc++.h>

#define LL long long
#define check_mask(aa, bb) (aa & (1<<bb))
#define set_mask(aa, bb) (aa | (1<<bb))

using namespace std;

LL num[21];
int dp[(1<<20)+3];
int n;

int check(LL x, LL y)
{
   for ( ; x>0 && y>0; x/=10,y/=10)
      if (x%10+y%10>=10) return 0;
   return 1;
}

int solve(LL mask, LL sum)
{
    if(mask == ((1<<n) - 1)) return 0;
    int &ret = dp[mask];
    if(ret != -1) return ret;
    ret = 0;

    for(int i = 0; i < n; i++)
    {
        if(!check_mask(mask, i))
        {
            bool is = check(sum, num[i]);
            if(is)
            ret = max(ret, 1 + solve(set_mask(mask, i), sum + num[i]));
        }
    }
return ret;
}


int main()
{
    int i, j, k;
    cin>>n;
    LL sum = 0;
    memset(num, 0, sizeof num);
    for(i = 0; i < n; i++)
    {
        cin>>num[i];
    }
    memset(dp, -1, sizeof dp);
    int res = solve(0, 0);
    printf("%d\n", res);
    return 0;
}
