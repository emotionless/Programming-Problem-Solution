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
#define MAX 1562501
#define MOD 1000000007
#define N 1000007
#define PB push_back
#define set_mask(a,b) (a|(1<<b))


using namespace std;

struct Z
{
    LL t, cost;
    bool operator <(const Z& A )const
    {
        return cost < A.cost;

    }
};



int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int t,j,i,k;
    LL n, m, p;
    scanf("%lld %lld %lld", &n, &m, &p);
    Z tmp;
    vector<Z>V;
    V.clear();
    for(int i = 0; i < p; i++)
    {
        scanf("%lld %lld", &tmp.t, &tmp.cost);
        V.PB(tmp);
    }

    sort(V.begin(), V.end());
    LL tot = n * m;
    LL res = 0LL;
    for(LL i = 0; i < p; i++)
    {
        //cout<<V[i].cost<<endl;
        if(tot - V[i].t < 0)
        {
            res += (tot) * V[i].cost;
            tot = 0;
        }
        else
        {
            res += (V[i].cost * V[i].t);
            tot -= V[i].t;
        }
    }
    if(tot ==0)
        printf("%lld\n", res);
    else
        printf("Impossible\n");
    return 0;
}

/*

1
10 4 2
7 8
9 10
1 3
4 6
9 3
4 8


2 2 3
1 2
1 1
1 2

*/
