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
#define FOR(i,a,b) for(i=a;i<=b;i++)

using namespace std;


int GCD(int a, int b);

int main()
{
    int n;
    int i,j,k;
    int arr[100001];
    cin>>n;
    FOR(i,0,n-1)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int gcd=arr[0];
    FOR(i,1,n-1)
    {
        gcd=GCD(gcd,arr[i]);
    }
    int p=1;
    FOR(i,0,n-1)
    {
        if(gcd==arr[i])
        {
            cout<<gcd<<endl;
            p=0;
            break;
        }
        else if(arr[i]>gcd)
            break;
    }
    if(p)
        cout<<-1<<endl;
    return 0;
}

int GCD(int a, int b)
{
    while(1)
    {
        a=a%b;
        if(a==0) return b;
        b=b%a;
        if(b==0) return a;
    }
}
