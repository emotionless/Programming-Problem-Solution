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


LL sum1[100009];
LL sum[100009];


int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int t,j,i,k;
    int n, m, op;
    cin>>n;
    LL c;
    vector<LL>odd, even;
    odd.clear();
    even.clear();
    for(i = 0; i < n; i++)
    {
        scanf("%d %lld", &op, &c);
        if(op==1)
            odd.PB(c);
        else
            even.PB(c);
    }
    sort(odd.begin(), odd.end());
    int sz = odd.size();
    j = 1;
    for(i = sz - 1; i >= 0; i--)
    {
        sum[j++] += sum[j-1] + odd[i];
        j++;
      //  cout<<sum[j]<<endl;
    }



    sort(even.begin(), even.end());
    int sz1 = even.size();
    j = 1;
    for(i = sz1 - 1; i >= 0; i--)
    {
        sum1[j] += sum1[j-1] + even[i];
        j++;
    }

    LL tot = sz + sz1*2;
    for(i = 1; i <= tot; i++)
    {
        int cn = i;

        LL res = 0;

        if(sz1)
        {
            int need = (cn)/2;
            int mn = min(need, sz1);
            cn -= (mn * 2);

            res += sum1[mn];
        }

        res += sum[cn];
        printf("%lld", res);
        if(i<tot)
            printf(" ");
    }
    printf("\n");





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


*/
