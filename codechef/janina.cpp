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
#define MX 100009
#define MOD 1000000007
#define PB push_back
#define set_mask(a,b) (a|(1<<b))
#define FOR(i, b) for(i = 0; i < b; i++)

using namespace std;

LL arr[MX + 5];
int cs[MX + 5];

int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int t,j,i,k;
    int n, P, K;
    scanf("%d %d %d", &n, &K, &P);
    set<LL>S;
    //V.clear();
    //memset(seg, 0, sizeof seg);
    for(i = 1; i <= n; i++)
    {
        scanf("%lld", &arr[i]);
        S.insert(arr[i]);
    }
    vector<LL>V(S.begin(), S.end());
    map<LL, int>MP;
    MP[V[0]] = 0;
    int sz = V.size();
    for(i = 1; i < sz; i++)
    {
        MP[V[i]] = i;
        if(V[i] - V[i - 1] <= K)
            cs[i] = cs[i - 1] + 1;
        else
            cs[i] = cs[i - 1];
    }
    int q, A, B;
    while(P--)
    {
        scanf("%d %d", &A, &B);
        int a = MP[arr[A]];
        int b = MP[arr[B]];
        if(a > b) swap(a, b);
        if( (cs[b] - cs[a]) == (b - a))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}

/*


1
7
1 2 3 4 5 6 7
30


*/
