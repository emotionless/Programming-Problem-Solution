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
int main()
{
    int i,j,k;
    int n;
    cin>>n;
    double arr[10][100],num;
    int high[10];
    for(i=0; i<10; i++)
        high[i]=0;
    for(i=0; i<n; i++)
    {
        cin>>num;
        int m=num*10;
        arr[m][high[m]++]=num;
    }
    for(i=0; i<10; i++)
    {
        for(j=0; j<high[i]; j++)
        {
            double nn=arr[i][j];
            int k=j-1;
            while(arr[i][k]>nn && k>=0)
            {
                arr[i][k+1]=arr[i][k];
                k--;
            }
            arr[i][k+1]=nn;
        }
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<high[i]; j++)
            printf("%.3lf ",arr[i][j]);
    }
    return 0;
}

/*

9
.12
.1
.145
.45
.67
.78
.90
.64
.44

*/
