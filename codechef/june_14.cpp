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




int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int t,j,i,k;
    LL n, m;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lld", &n);

        LL sum = n * (n-1) * (n-1);
        sum += sum;
        sum += n * (n-1) * (n-2);
        sum += n * (n-1) * (n-2) * (n-2);
        sum += n * (n-1) * (n-2) * (n-2);
        printf("%lld\n", sum);
    }

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
