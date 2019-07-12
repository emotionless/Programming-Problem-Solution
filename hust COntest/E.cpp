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
#include <cstring>
#include <cassert>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <climits>

#define LL long long
#define MX 2000000
#define MOD 1000000000+7
#define N 1000007
#define PB push_back
#define FOR(ii,aa,bb) for(ii=aa; ii<=bb; ii++)
#define loop(aa) for(int ii=0; ii<aa; ii++)
#define rep(i,bb) for(i=0; i<bb; i++)
#define clr(aa, bb) memset(aa, bb, sizeof aa)

using namespace std;


bool is_prime[MX];
int prime[MX];

int sieve()
{
    long i,j;
    prime[0]=2;
    int k=1;
    int sq=(sqrt(MX));
    for(i=3; i<=sq; i+=2)
    {
        if(!is_prime[i])
        {
            for(j=i*i; j<=MX; j+=(2*i))
                is_prime[j]=1;
        }
    }
    for(j=3; j<=MX; j+=2)
    {
        if(!is_prime[j])
        {
            prime[k++]=j;
        }
    }
return k;
}
int sz;


int factorization(int n)
{
    int sq = sqrt(n);

    int cnt = 0;

    for(int i = 0; i < sz && prime[i] <= sq; i++)
    {
        if(n % prime[i] == 0)
        {
            while(n % prime[i] == 0 && n)
            {
                cnt++;
                n = n / prime[i];
            }
        }
        sq = sqrt(n);
    }
    if(n > 1) cnt++;
return cnt;
}

pair<int, int>P[MX];

int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i, j, k;
    int t;
    int cases = 1;
    int n, m;
    sz = sieve();
    vector< pair<int, int> >V;
    V.clear();
    for(i = 1; i <= MX; i++)
    {
        P[i - 1] = make_pair(factorization(i), i);

    }
    sort(P, P + MX);

    while(cin>>t && t)
    {
        printf("Case %d: ", cases++);
        cout<<P[t - 1].second<<endl;
    }








    return 0;
}

/*

1
This can't be solved by brute force.

*/
