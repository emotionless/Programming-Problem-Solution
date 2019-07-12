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
***** Sorry for bad writen code **********
*/


#include <bits/stdc++.h>

#define LL long long
#define MX 5000+7
#define MOD 1000000000+7
#define N 1000007
#define PB push_back


using namespace std;



int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j,k;
    int n, q,m;
    double fib[105];
    fib[0]=1;
    fib[1]=2;
    for(i=2; i<101; i++)
    {
        fib[i]=fib[i-1]+fib[i-2];
    }
    string fir, sec, res;
    cin>>fir>>sec;
    int len=fir.length();
    reverse(fir.begin(), fir.end());
    reverse(sec.begin(), sec.end());
    double sum=0;
    for(i=0; i<len; i++)
    {
        sum+=round((fir[i]-'0')*fib[i]);
    }

    return 0;
}

/*

5 3
1000 1002 1003 1004 1005
S 0 2
G 0 3
S 0 2
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111

*/
