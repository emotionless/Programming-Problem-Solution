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
    int a,b;

    int n;
    cin>>n;

    for(i=0; i<n; i++)
        cin>>arr[i];
    int s=0, f=0;
    i=0;
    int k=n-1;
    for(j=0; j<n; j++)
    {
        if(j%2==0)
        {
            if(arr[i]>arr[k])
            {
                s+=arr[i];
                i++;
            }
            else
            {
                s+=arr[k];
                k--;
            }
        }
        else
        {
            if(arr[i]>arr[k])
            {
                f+=arr[i];
                i++;
            }
            else
            {
                f+=arr[k];
                k--;
            }
        }
    }
    cout<<s<<" "<<f<<endl;


    return 0;
}

/*

4544545454

*/
