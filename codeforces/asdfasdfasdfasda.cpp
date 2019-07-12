#include <bits/stdc++.h>




void sc(int &a)
{
    scanf("%d", &a);
}


void sc(int &a, int &b)
{
    scanf("%d %d", &a, &b);
}


void sc(int &a, int &b, int &c)
{
    scanf("%d %d %d", &a, &b, &c);
}


using namespace std;


int arr[5009];
int dp[5009][5009];
int n;

int solve(int ind, int k)
{
    if(ind >= n) return 0;

    int &ret = dp[ind][k];
    if(ret != -1) return ret;

    ret = 0;
    ret = arr[ind] + solve(ind+1, k);
    if(k > 0) ret = max(ret, solve(ind+1, k-1));
    ret = max(0, ret);
    return ret;
}


int main()
{
    int i, j, k;
    int t, cases = 1;
    sc(t);
    while(t--)
    {
        sc(n, k);

        int ans = INT_MIN;
        for(i = 0; i < n; i++)
        {
            sc(arr[i]);
            ans = max(ans, arr[i]);
        }

        if(k == 0)
        {
            int sum = 0;
            for(i = 0; i < n; i++)
            {
                sum += arr[i];
                ans = max(ans, sum);
                if(sum < 0)
                    sum = 0;
            }
            printf("Case %d: %d\n", cases++, ans);
            continue;

        }


        memset(dp, -1, sizeof dp);
        int res = INT_MIN;

        for(i = 0; i < n; i++)
        {
            res = max(res, solve(i, k));
//        cout<<i<<" "<<solve(i, k)<<endl;
        }
        printf("Case %d: %d\n", cases++, res);


    }



    return 0;
}

