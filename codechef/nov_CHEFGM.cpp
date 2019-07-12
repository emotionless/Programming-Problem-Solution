#include<bits/stdc++.h>

#define LL long long

using namespace std;

int main()
{
    int i,j,k;
    int t,n;

    int amount[101];
    LL arr[101][101];

    scanf("%d", &t);

    while(t--)
    {
        scanf("%d", &n);
        for(i=0; i<n; i++)
        {
            scanf("%d",&amount[i]);

            for(j=0; j<amount[i]; j++)
            {
                scanf("%lld", &arr[i][j]);
            }
            sort(arr[i], arr[i]+amount[i]);
        }

        int even=0, odd=0;

        bool p=false;
        int bar=1;

XX:
        {
            for(i=0; i<n; i++)
            {
                LL cn=arr[i][0];

                if(amount[i]>0 && cn!=2147483648)
                {
                    p=true;
                    if(cn%2==0)
                    {
                        j=0;
                        int cnt=0;
                        while(arr[i][j]%2==0 && j<amount[i] && arr[i][j]!=2147483648)
                        {
                            if(arr[i][j]!=arr[i][j+1])
                                cnt++;

                            arr[i][j]=2147483648;

                            j++;
                        }
                        even+=cnt;
                    }
                    else
                    {
                        j=0;
                        int cnt=0;
                        while(arr[i][j]%2 && j<amount[i] && arr[i][j]!=2147483648)
                        {

                            if(arr[i][j]!=arr[i][j+1])
                                cnt++;

                            arr[i][j]=2147483648;

                            j++;
                        }
                        odd+=cnt;
                    }
                }
                sort(arr[i], arr[i]+amount[i]);
                //   cout<<"here\n";

            }
        }
       // cout<<bar++<<" "<<even<<" "<<odd<<endl;

        if(even>odd)
            printf("EVEN\n");
        else if(odd>even)
            printf("ODD\n");
        else
        {
            if(p)
            {
                p=false;
                even=0;
                odd=0;
                goto XX;

            }
            else
                printf("DON'T PLAY\n");
        }
    }

    return 0;
}


/*

1
2
5 2 2 3 2 2
3 3 3 3

2
3 4 2 2
4 1 4 3 3

1
2
2 0 1
2 2 1

*/
