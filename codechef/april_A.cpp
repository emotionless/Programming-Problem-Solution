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
#define MAX 1562501
#define MOD 1000000007
#define N 1000007
#define PB push_back
#define set_mask(a,b) (a|(1<<b))


using namespace std;


LL arr[100001];

int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int t,j,i,k;
    int n, m;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        sort(arr, arr+n);
        if(n==1)
        {
            cout<<arr[0]<<endl;
            continue;
        }
        if(n==2)
        {
            cout<<arr[0]<<" "<<arr[1]<<endl;
            continue;
        }
        if(n>2)
        {
            cout<<arr[0]<<" "<<arr[n-1]<<" ";
        }
        for(i=1, j=n-2; i<j; i++, j--)
        {
            cout<<" "<<arr[i]<<" "<<arr[j];
        }
        if(i==j)
            cout<<" "<<arr[i];
        cout<<endl;
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