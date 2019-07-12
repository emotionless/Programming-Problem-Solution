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
bool vis[100001];
int arr[100001];
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

    sort(arr, arr+n);
    int cnt=0;
    vector<int>res;
    res.clear();
    if(n)
        res.PB(arr[0]);
    vis[0]=true;
    for(i=1; i<n; i++)
    {
        if(arr[i]>arr[i-1])
        {
            res.PB(arr[i]);
            vis[i]=true;
        }
    }
    vector<int>V, res1;
    V.clear();
    res1.clear();
    for(i=0; i<n; i++)
    {
        if(vis[i]) continue;
        V.PB(arr[i]);
    }
    int sz=V.size();
    if(sz && V[0]<res[res.size()-1])
        res1.PB(V[0]);
    for(i=1; i<sz; i++)
    {
        if(V[i]>V[i-1] && V[i]<res[res.size()-1])
            res1.PB(V[i]);
    }

    int s=res.size();
    int s1=res1.size();
    cout<<s+s1<<endl;
    for(i=0; i<s; i++)
        cout<<res[i]<<" ";

    reverse(res1.begin(), res1.end());
    for(i=0; i<s1; i++)
        cout<<res1[i]<<" ";

    res.clear();
    res1.clear();
    V.clear();
    return 0;
}

/*

4544545454

*/
