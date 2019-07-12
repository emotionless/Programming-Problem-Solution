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
#define loop(n) for(int o=1;o<=n;o++)

using namespace std;


long SEARCH(long find);


long arr[50001],val[50001],con[50001];
int taken[100001];
long n,a,q;
int main()
{
    long i,j,k;
    int t,cases=0;
    scanf("%d",&t);
    while(t--)
    {
        map<long, long>M;
        scanf("%ld %ld %ld",&n,&a,&q);
        for(i=0; i<a; i++)
        {
            scanf("%ld",&arr[i]);
            M[i]=arr[i];
         //   cout<<i<<ends<<M[i]<<endl;
        }
        sort(arr,arr+a);
        arr[a]=n+1;

        con[0]=taken[0]=arr[0]-1;
        val[0]=0;
        for(i=0; i<a; i++)
        {
            con[i+1]=arr[i+1]-arr[i]-1;
            taken[i+1]=taken[i]+con[i+1];
            val[i+1]=arr[i];
        }
        long search;
        printf("Case %d:\n",++cases);
        rep(i,0,q-1)
        {
            scanf("%ld",&search);
            if(M[search-1]>0)
                printf("%d\n",M[search-1]);
            else
            {
                int baki=search-a,total=0;
                long ind=SEARCH(baki);
                int temp=taken[ind]-baki;
                long res=con[ind]-temp+val[ind];
                printf("%ld\n",res);
            }
        }
        M.clear();
    }
    return 0;
}

long SEARCH(long find)
{
    long low=0,high=a,mid=(low+high)/2,i=0;
    while(low<high)
    {
        mid=(low+high)/2;
        assert(mid<high);
        if (taken[mid] < find)
            low = mid + 1;
        else
            high = mid;
    }
    if(find==taken[mid])
        return mid;
    else if(find>taken[mid])
        return mid+1;
    else
        return mid;

}
/*


10 4 4
3 5 8 10

10 6 10
4 5 6 3 2 7
7


*/
