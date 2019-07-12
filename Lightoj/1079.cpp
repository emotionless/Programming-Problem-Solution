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
#define Z pair<double, int>

using namespace std;
int n;
double P;
double arr[101];
int MLN[101];

map<Z, int>M;


int solve(int ind, double prob)
{
    if(ind==n)
    {
        if(prob<P)
            return 0;
        return -21472136;
    }
    Z tmp = make_pair(prob, ind);
    if(M[tmp])
        return M[tmp];
    M[tmp] = max((solve(ind + 1, arr[ind] + (1.0 - arr[ind]) * prob) + MLN[ind]), solve(ind + 1, prob));
    return M[tmp];
}



int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j,k;
    int t;
    int cases = 1;
    int a,b,c;
    cin>>t;
    while(t--)
    {
        cin>>P>>n;
        rep(i,n)
        {
            cin>>MLN[i]>>arr[i];
        }
        M.clear();
        int res = solve(0, 0.0);
        printf("Case %d: %d\n", cases++, res);
        M.clear();
    }
    return 0;
}

/*

1
0.25 6
30 0.07
78 0.04
56 0.08
48 0.12
57 0.02
27 0.09

*/
