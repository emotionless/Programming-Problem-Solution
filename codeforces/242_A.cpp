#include <bits/stdc++.h>

#define LL long long
#define MX 5000+7
#define MD 1000000007
#define N 1000007
#define check_bit(a,b) (a & (1<<b))
#define PB push_back
#define FOR(aa,nn) for(aa=0; aa<nn; aa++)


using namespace std;

int arr[200];

int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    int a,b;
    string str;
    cin>>a;
    cin>>str;
    int len=str.length();
    memset(arr, 0, sizeof arr);

    for(i=0; i<len ; i++)
        arr[str[i]]++;
    int ans=0;
    int mid=a/2;
    if(arr['X']>arr['x'])
    {
        int dif=arr['X']-mid;
        ans=dif;
        for(i=0; i<len && dif>0; i++)
        {
            if(str[i]=='X')
            {
                str[i]='x';
                dif--;
            }
        }
    }

    else
    {
        int dif=arr['x']-mid;
        ans=dif;
        for(i=0; i<len && dif>0; i++)
        {
            if(str[i]=='x')
            {
                str[i]='X';
                dif--;
            }
        }
    }
    cout<<ans<<endl;
    cout<<str<<endl;





    int n, m;






    return 0;
}

/*

4544545454

*/
