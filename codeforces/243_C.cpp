#include <bits/stdc++.h>

#define LL long long
#define MX 5000+7
#define MD 1000000007
#define N 1000007
#define check_bit(a,b) (a & (1<<b))
#define PB push_back
#define FOR(aa,nn) for(aa=0; aa<nn; aa++)
#define vi vector<int>
#define vll vector<long long>


using namespace std;

int arr[201];

int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j, k;
    int a,b;

    int n, m;
    cin>>n>>m;

    for(i=0; i<n; i++)
        cin>>arr[i];
    vector<int>tmp, B;
    int res=arr[0];
    for(i=0; i<n; i++)
    {
        for(j=i; j<n; j++)
        {
            tmp.clear();
            B.clear();
            for(k=i; k<=j; k++)
            {
                tmp.PB(arr[k]);
            }
            for(k=0; k<i; k++)
                B.PB(arr[k]);

            for(k=j+1; k<n; k++)
                B.PB(arr[k]);
            sort(tmp.begin(), tmp.end());
            sort(B.begin(), B.end());
            reverse(B.begin(), B.end());
            int sz=tmp.size();
            for(k=0; k<sz && k<m && k<B.size(); k++)
            {
                if(B[k]<=tmp[k])
                    break;
                else
                    swap(B[k], tmp[k]);
            }
            int sum=0;
            for(k=0; k<sz; k++)
                sum+=tmp[k];
           // cout<<i<<" "<<j<<" "<<sum<<endl;
            res=max(sum, res);
        }
    }
    cout<<res<<endl;
    return 0;
}

/*

4544545454

*/