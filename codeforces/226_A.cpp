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

int arr[1001];
int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    int a,b, n, c;

    cin>>n>>c;
    for(i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    int mx=0;
    for(i=0; i<n-1; i++)
    {
        mx=max(mx, arr[i]-c-arr[i+1]);
    }
    cout<<mx<<endl;

    return 0;
}

/*

4544545454

*/
