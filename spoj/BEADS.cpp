#include<bits/stdc++.h>

#define xx first
#define yy second
#define all(a) a.begin(), a.end()
#define vsort(v) sort(all(v))
#define UNIQUE(a)  sort(all(a)); a.erase(unique(all(a)), a.end())
#define clr(a,k) memset(a,k,sizeof a)
#define bclr(b) memset(b,false,sizeof b)
#define fr(i, a) for(i = 0; i < a; i++)
#define frr(i,a) for(i = a - 1; i >= 0, i--)
#define LL long long
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define vi vector<int>
#define vll vector<long long>
#define SZ(a) a.size()
///***** bit *****///
#define check_bit(a, b) (a&(1<<b))
#define set_bit(a, b) (a|(1<<b))
#define total_bit(a) __builtin_popcount(a)
///***** Input / Output *****///
#define s1(a) scanf("%d", &a)
#define s2(a, b) scanf("%d %d", &a, &b)
#define s3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define p1(a) printf("%d", a)
#define p2(a, b) printf("%d %d", a, b)
#define p3(a, b, c) printf("%d %d %d", a, b, c)

#define MOD 1000000007
#define MAX 200009


using namespace std;

int mid;
//int dp[23][11000009];
int arr[23];
map < pair<pii, int>, int>M;
int solve(int ind, int taken, int sum)
{
    if(ind == 22)
    {
        if(taken == 11) return sum;
        return 0;
    }
    pair< pii, int> P = mp(mp(ind, taken), sum);
    if(M.find(P) != M.end()) return M[P];
    int ret = 0;
    ret = solve(ind + 1, taken, sum);
    if(sum + arr[ind] <= mid && taken < 11)
        ret = max(ret, solve(ind + 1, taken + 1, sum + arr[ind]));
    M[P] = ret;
    return M[P];
}

int main()
{
    int tc,cs=1,i,j,k;
    int n,m;
    scanf("%d", &tc);
    while(tc--)
    {
        int sum = 0;
        for(i = 0; i < 22; i++)
        {
            scanf("%d", &arr[i]);
            sum += arr[i];
        }
//        memset(dp, -1, sizeof dp);
        mid = sum/2;
        int res = solve(0,0, 0);
        printf("%d\n", sum - res - res);
        M.clear();

    }
    return 0;
}

//
//int main()
//{
//    int i, j, k;
//    int t;
//    scanf("%d", &t);
//    while(t--)
//    {
//        int sum = 0;
//        for(i = 0; i < 22; i++)
//            scanf("%d", &arr[i]), sum += arr[i];
//        int mid = sum/2;
//        int mx = 0;
//        for(i = 1; i <(1<<22); i++)
//        {
//            int s = 0;
//            if(__builtin_popcount(i) == 11)
//            {
//                for(j = 0; j < 22; j++)
//                {
//                    if(i & (1<<j))
//                        s+=arr[j];
//                }
//            }
//            else continue;
//            if(s <= mid)
//            mx = max(mx, s);
//        }
//        printf("%d\n", sum - mx - mx);
//
//
//    }
//}


/*

3
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1


*/
