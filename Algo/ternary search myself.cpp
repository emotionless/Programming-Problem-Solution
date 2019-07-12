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

int ternary_search(int left, int  right, int val);

int arr[100];

int main()
{
    int i,j,k;
    int n;
    cout<<"Enter n: ";
    cin>>n;
    for(i=0; i<n; i++)
        cin>>arr[i];
    int val;
    cout<<"Search value: ";
    cin>>val;
    int ind=ternary_search(0,n-1,val);
    if(ind==-1)
        cout<<"Not found...\n";
    else
        cout<<ind+1<<endl;
    return 0;
}

int ternary_search(int left, int  right, int val)
{
    while(left<=right)
    {
        int mid1=(left*2+right)/3;
        int mid2=(left+right*2)/3;

        if(arr[mid1]==val) return mid1;
        if(arr[mid2]==val) return mid2;

        if(val<arr[mid1])
            right=mid1-1;
        else if(val>arr[mid2])
            left=mid2+1;
        else if(val>arr[mid1] && val<arr[mid2])
        {
            left=mid1;
            right=mid2-1;
        }
    }
    return -1;
}
