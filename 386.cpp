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
    int i,j,k,l;
    long a,b,c,d;
    for(i=6; i<201; i++)
    {
        a=i*i*i;
        for(j=2; j<i; j++)
        {
            b=j*j*j;
            for(k=j; k<i; k++)
            {
                c=k*k*k;
                for(l=k; l<i; l++)
                {
                    d=l*l*l;
                    if(a==(b+c+d))
                    {
                        printf("Cube = %d, Triple = (%d,%d,%d)\n",i,j,k,l);
                    }
                }
            }
        }
    }
    return 0;
}

