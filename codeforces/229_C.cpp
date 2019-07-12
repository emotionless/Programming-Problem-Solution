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

int arr[100009];
int sum[100009];


int main()
{
  //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    int a,b;
    int n,g,K,w;
    string str;

    cin>>n>>K>>w;

    cin>>str;
    int len=str.length();
    for(i=1; i<=len; i++)
    {
        if(i)
        sum[i]=sum[i-1]+(str[i-1]=='1'?1:0);
        else
        sum[i]=(str[i]=='1'?1:0);
    }

    for(int k=1; k<=K; k++)
    {
        for(i=k; i<=len; i+=K)
        {
            if(i==k)
            arr[i]=str[i-1]=='1'?1:0;
            else
            arr[i]=arr[i-K]+(str[i-1]=='1'?1:0);
        }

    }

    for(i=0; i<w; i++)
    {
        cin>>a>>b;

        int have=arr[b]-arr[a+K-1]+(str[a+K-2]=='1'?1:0);
        int tot=sum[b]-sum[a-1];
        int xtra=tot-have;
        int need=(b-a+1)/K-have;
        cout<<need+xtra<<endl;
    }





    return 0;
}

/*
6 3 3
101010
1 3
1 6
2 5

*/
