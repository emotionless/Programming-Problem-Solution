#include <cstring>
#include <cassert>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <climits>
#define scan(a) scanf("%d",&a);
#define s2(a,b) scanf("%d %d",&a,&b)
#define PI 2acos(-1.0)
#define s1(a) scanf("%d",&a);
#define INF 2<<15
#define PB(A) push_back(A)
#define clr(a,b) memset(a,b,sizeof(a))
#define LL long long
#define ULL unsigned long long
#define rep(i,a,b) for(i=a;i<=b;i++)

using namespace std;

int LIS1();
int LDS();


int n;
int arr[2001];

int main()
{
    int i,j,k,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        cout<<max(LIS1(),LDS())<<endl;
    }
}
int LIS1()
{
    int i,j,k,cnt=0,l[2001];
    int mx=0;
    int low,high,mid;
    for(i=0; i<n; i++)
    {
        int num=arr[i];
        if(num>mx)
        {
            l[++cnt]=num;
            mx=num;
        }
        else
        {
            low=1;
            high=cnt;
            while(low<=high)
            {
                mid=(low+high)>>1;
                if(l[mid]==num) break;
                if(num<l[mid])
                    high=mid-1;
                else
                    low=mid+1;
            }
            if(l[mid]<num)
                l[mid+1]=num;
            else if(l[mid]>num)
                l[mid]=num;
        }
    }
    return cnt;
}

int LDS()
{

    int i,j,k,cnt=0,l[2001],rev[2001];
    for(i=0; i<n; i++)
    {
        rev[i]=arr[n-1-i];
    }

    int mx=0;
    int low,high,mid;
    for(i=0; i<n; i++)
    {
        int num=rev[i];
        if(num>mx)
        {
            l[++cnt]=num;
            mx=num;
        }
        else
        {
            low=1;
            high=cnt;
            while(low<=high)
            {
                mid=(low+high)>>1;
                if(l[mid]==num) break;
                if(num<l[mid])
                    high=mid-1;
                else
                    low=mid+1;
            }
            if(l[mid]<num)
                l[mid+1]=num;
            else if(l[mid]>num)
                l[mid]=num;
        }
    }
    return cnt;
}
