/*
******************************************
***** Bismillahir Rahmanir Rahim *********
***** Full Name: Faruk Hossain Milon *****
***** University: IIT-JU, BD ****************

***** Codechef username: emotionless *****
***** Topcoder handle: emotionless *******
***** UVA username: emotionless **********
***** Hust username: emotionless *********
***** Codeforces handle: milon ***********
******************************************
***** Sorry for bad written code **********
*/


#include <bits/stdc++.h>

#define LL long long
#define MX 5000+7
#define MOD 1000000000+7
#define N 1000007
#define PB push_back
#define FOR(ii,aa,bb) for(ii=aa; ii<=bb; ii++)
#define loop(aa) for(int ii=0; ii<aa; ii++)
#define rep(i,bb) for(i=0; i<bb; i++)
#define clr(aa, bb) memset(aa, bb, sizeof aa)

using namespace std;

map < pair <int, int > , int > M;
int n;
int arr[21];
int solve(int ind, int sum)
{
    if(ind == n) return sum;

    pair < int, int> mp = make_pair(ind, sum);
    if(sum - arr[ind]<0)
        return M[mp] = sum;

    if(M.find(mp) != M.end()) return M[mp];
    int ret = solve(ind + 1, sum);
    ret = min(ret, solve(ind + 1, sum - arr[ind]));
    return M[mp] = ret;
}



int main()
{
    int i,j,k;
    int t, cases = 1;

    scanf("%d",&n);
    int sum = 0;
    for(i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
        sum += arr[i];
    }
    sort(arr, arr + n);
    int res = solve(0, sum / 2);
    int rest = sum/2 - res;
    int baki = sum - rest;
    printf("%d\n",baki - rest);
    //cout<<res<<" "<<sum<<endl;

    return 0;
}

/*


(((xyz+a)))(a+b+c+a((xyz+c)))

*/
