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

using namespace std;
bool check(int N,int pos);
int Set(int N,int pos);
int N =100,prime[100];
int status[100/32];
void sieve()
{
    int i, j, sqrtN;
    sqrtN = int( sqrt( N ) );
    for( i = 3; i <= sqrtN; i += 2 )
    {
      //  cout<<endl<<i<<" for ";
        if( check(status[i/32],i%32)==0)
        {
            for( j = i*i; j <= N; j += 2*i )
            {
                status[j/32]=Set(status[j/32],j % 32);
              //  cout<<j<<ends<<status[j/32]<<ends;
            }
        }
    }
     puts("2");
     for(i=3; i<=N; i+=2)
         if( check(status[i/32],i%32)==0)
             printf("%d\n",i);

}
bool check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}
int Set(int N,int pos)
{
    return N=N | (1<<pos);
}
int main()
{
    int i,j,k;
    int n;
    sieve();
}
