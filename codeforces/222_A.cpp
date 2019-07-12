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
#define check_bit(a,b) (a & (1<<b))
#define PB push_back


using namespace std;


int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j,k;
    int a,b;
    cin>>a>>b;
    int resa=0, resb=0, d=0;
    for(i=1; i<=6; i++)
    {
        int ta=abs(i-a);
        int tb=abs(i-b);
        if(ta==tb)
        d++;
        else if(ta<tb)
        resa++;
        else
        resb++;
    }
    cout<<resa<<" "<<d<<" "<<resb<<endl;



    return 0;
}

/*

4544545454

*/
