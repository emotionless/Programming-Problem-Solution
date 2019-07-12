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
int func(int ind, int val);

int arr[21];
int mem[21][201];
int n;

int main()
{
    // int i,j,k;
    string str;
    int t;
    cin>>t;
    getchar();
    while(t--)
    {
        getline(cin,str);
        stringstream ss(str);
        int num;
        int sum=0;
        n=0;
        while(ss>>num)
        {
            arr[n++]=num;
            sum+=num;
        }
        if(sum%2==1)
            printf("NO\n");
        else
        {
            memset(mem,-1,sizeof mem);
            int res=func(0,sum/2);
            if(res==sum/2)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
}

int func(int ind, int val)
{
    if(ind>=n) return 0;
    if(mem[ind][val]!=-1) return mem[ind][val];
    int ret=0;
    if(arr[ind]<=val)
        ret=max(func(ind+1, val-arr[ind])+arr[ind] , func(ind+1,val));
    else
        ret=func(ind+1,val);
    return ret;
}
