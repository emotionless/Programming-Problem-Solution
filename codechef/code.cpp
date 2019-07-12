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
LL ans[100001];

int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int t,j,i,k;
    int n;
    scanf("%d %d", &n, &t);
    LL mx= (- 000000001);
    for(i=0; i<n; i++)
    {
        scanf("%lld", &arr[i]);
        mx=max(mx, arr[i]);
    }
    LL mx1=(- 000000001);
    if(t==0)
    {
        for(i=0; i<n; i++)
        {
            if(i)
                cout<<" ";
            cout<<arr[i];
        }

        cout<<endl;
        return 0;
    }
    for(i=0; i<n; i++)
    {
        arr[i]=mx-arr[i];
        ans[i]=arr[i];
        mx1=max(mx1, arr[i]);
    }

    for(i=0; i<n; i++)
    {
        arr[i]=mx1-arr[i];
    }
    if(t%2)
    {
        for(i=0; i<n; i++)
        {
            if(i)
                cout<<" ";
            cout<<ans[i];
        }

        cout<<endl;
    }
    else
    {
        for(i=0; i<n; i++)
        {
            if(i)
                cout<<" ";
            cout<<arr[i];
        }

        cout<<endl;
    }






    return 0;
}

/*

4 2
5 -1 7 0


*/
