#include<bits/stdc++.h>
#define LL long long
#define PB push_back


using namespace std;

int arr[100005];

int main()
{
    int i,j,k;
    int n;
    cin>>n>>k;

    for(i=0; i<n; i++)
        cin>>arr[i];
    LL mx=INT_MAX;
    int ind;
    for(i=0; i<k; i++)
    {
        LL sum=0;
        for(j=i; j<n; j+=k)
            sum+=arr[j];
        if(sum<mx)
        {
            mx=sum;
            ind=i;
        }
    }
    cout<<ind+1<<endl;


    return 0;
}

/*

10 2
1 3 5 7 9 9 4 1 8 5


*/
