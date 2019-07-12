#include<bits/stdc++.h>

#define vsort(v) sort(v.begin(),v.end())
#define clr(a,k) memset(a,k,sizeof a)
#define bclr(b) memset(b,false,sizeof b)
#define LL long long
#define PB push_back
#define MP make_pair
#define MOD 1000000007
#define MX 100009
#define mp make_pair

using namespace std;

LL arr[100001];
LL lis[100001];
LL lds[100001];
int last1, last2;
int first[100001];
int second[100001];
void LIS(int ind)
{

    if(arr[ind] > lis[last1])
    {
        lis[++last1] = arr[ind];

        first[ind] = last1;
    }
    else
    {
        int st = 1, ed = last1, mid;
        while(st < ed)
        {
            int mid = (st + ed) >> 1;
            if(lis[mid] < arr[ind])
                st = mid + 1;
            else
                ed = mid;
        }

        for(int i = ed; i <= st; i++)
        {
            if(lis[i] >= arr[ind])
            {
                lis[ed] = arr[ind];
                first[ind] = ed;
                return;
            }
        }

    }
}



void LDS(int ind)
{
    if(arr[ind] > lds[last2])
    {
        lds[++last2] = arr[ind];
        second[ind] = last2;
    }
    else
    {
        int st = 1, ed = last2, mid;
        while(st < ed)
        {
            int mid = (st + ed) >> 1;
            if(lds[mid] < arr[ind])
                st = mid + 1;
            else
                ed = mid;
        }
        for(int i = ed; i <= st; i++)
        {
            if(lds[i] >= arr[ind])
            {
                lds[ed] = arr[ind];
                second[ind] = ed;
                return;
            }
        }
    }
}


int main()
{
    int i, j, k;
    int t, cases = 1;


    int n, m;
    scanf("%d", &t);
    while(t--)
    {

        scanf("%d", &n);

        last1 = last2 = 0;

        for(i = 0; i < n; i++)
            scanf("%lld", &arr[i]);
        lis[0] = -10000000000;
        lds[0] = -10000000000;
        for(i = 0, j = n - 1; i < n; i++, j--)
        {
            LIS(i);
            LDS(j);
        }
        int mx = 0;
        for(i = 0; i < n; i++)
        {
            int xxx = first[i] - 1;
            int yyy = second[i] - 1;
            int ans = min(xxx, yyy);
            mx = max(mx, ans);
        }
        printf("Case %d: %d\n", cases++, mx*2 + 1);
    }

    return 0;
}

/*

7
10
1 2 3 4 5 4 3 2 1 10
14
1 2 3 2 1 2 3 4 3 2 1 5 4 1
5
1 2 3 4 5
7
10 16 19 -9 19 15 -6
11
54 -73 -83 -85 -78 100 -83 100 -8 -80 -21
11
-5 -4 11 15 2 -11 15 7 -1 -13 4
15
77 -6 78 1 -6 72 -97 -91 72 -29 21 94 -34 47 87


*/
