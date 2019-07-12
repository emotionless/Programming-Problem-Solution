#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cas=1,n,ar[205][205],i,j;
    while(cin>>n &&n)
    {
        n=100+n;

        memset(ar, 0, sizeof ar);

        for(i=100; i<n; i++)
        {
            for(j=100; j<n; j++)
                cin>>ar[i][j];
        }
        long long res=-LONG_MIN;
        for(i=100; i<n; i++)
        {
            for(j=100; j<n; j++)
            {
                long long tmp[50];
                memset(tmp, 0, sizeof tmp);

                tmp[0]=ar[i][j]+ar[i][j+1]+ar[i][j+2]+ar[i][j+3];
                tmp[1]=ar[i][j]+ar[i+1][j]+ar[i+2][j]+ar[i+3][j];
                tmp[2]=ar[i][j]+ar[i][j-1]+ar[i][j-2]+ar[i][j-3];
                tmp[3]=ar[i][j]+ar[i-1][j]+ar[i-2][j]+ar[i-3][j];


                tmp[4]=ar[i][j]+ar[i][j+1]+ar[i+1][j+1]+ar[i+1][j+2];
                tmp[5]=ar[i][j]+ar[i+1][j]+ar[i+1][j-1]+ar[i+2][j-1];
                tmp[6]=ar[i][j]+ar[i][j-1]+ar[i-1][j-1]+ar[i-1][j-2];
                tmp[7]=ar[i][j]+ar[i-1][j]+ar[i-1][j+1]+ar[i-2][j+1];

                tmp[8]=ar[i][j]+ar[i][j+1]+ar[i][j+2]+ar[i+1][j+2];
                tmp[9]=ar[i][j]+ar[i+1][j]+ar[i+2][j]+ar[i+2][j-1];
                tmp[10]=ar[i][j]+ar[i][j-1]+ar[i][j-2]+ar[i-1][j-2];
                tmp[11]=ar[i][j]+ar[i-1][j]+ar[i-2][j]+ar[i-2][j+1];


                tmp[12]=ar[i][j]+ar[i][j+1]+ar[i][j+2]+ar[i+1][j+1];
                tmp[13]=ar[i][j]+ar[i+1][j]+ar[i+2][j]+ar[i+1][j-1];
                tmp[14]=ar[i][j]+ar[i][j-1]+ar[i][j-2]+ar[i-1][j-1];
                tmp[15]=ar[i][j]+ar[i-1][j]+ar[i-2][j]+ar[i-1][j+1];


                tmp[16]=ar[i][j]+ar[i][j+1]+ar[i+1][j]+ar[i+1][j+1];
                tmp[17]=ar[i][j]+ar[i+1][j]+ar[i+1][j-1]+ar[i][j-1];
                tmp[18]=ar[i][j]+ar[i][j-1]+ar[i-1][j-1]+ar[i-1][j];
                tmp[19]=ar[i][j]+ar[i-1][j]+ar[i-1][j+1]+ar[i][j+1];

                for(int j=0; j<20; j++)
                    res=max(res, tmp[j]);
            }
        }
        printf("%d. %lld\n",cas, res);
        cas++;
    }
    return 0;
}
