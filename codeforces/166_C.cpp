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
#define MX 100000+7
#define MOD 1000000000+7
#define N 1000007
#define PB push_back


using namespace std;

int arr[MX];


int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j,k;
    int n, q,m;
    int t;
    cin>>n>>k;
    if(n<k*3)
    {
        cout<<-1<<endl;
        return 0;
    }
    int p=1;
    for(i=1; i<=k; i++)
    {
        cout<<p<<" "<<p<<" ";
        p++;
    }
    j=1;
    for(i=k*2+1; i<=n; i++)
    {
        cout<<j<<" ";
        j++;
        j=j%(k+1);
        if(j==0) j++;
    }

    return 0;
}

/*



*/
