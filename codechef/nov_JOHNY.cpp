#include<bits/stdc++.h>

#define LL long long

using namespace std;

int main()
{
    int i, j,k;
    int n,t;
    LL arr[105];
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        scanf("%d", &k);
        LL num=arr[k-1];
        sort(arr, arr+n);

        for(i=0; i<n; i++)
        {
            if(arr[i]==num)
            {
                printf("%d\n", i+1);
                break;
            }
        }
    }
    return 0;
}
