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


using namespace std;

/*

LL gcd(LL a,LL b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}

LL bigmod(LL p,LL e,LL M)
{
    if(e==0)return 1;
    if(e%2==0)
    {
        LL t=bigmod(p,e/2,M);
        return (t*t)%M;
    }
    return (bigmod(p,e-1,M)*p)%M;
}

LL modinverse(LL a,LL M)
{
    return bigmod(a,M-2,M);
}




bool is_prime[MAX];
L prime[MAX];

bool sieve()
{
    long i,j;
    prime[0]=2;
    int k=1;
    int sq=(sqrt(MAX));
    for(i=3; i<=sq; i+=2)
    {
        if(!is_prime[i])
        {
            for(j=i*i; j<=MAX; j+=(2*i))
                is_prime[j]=1;
        }
    }
    for(j=3; j<=MAX; j+=2)
    {
        if(!is_prime[j])
        {
            prime[k++]=j;
        }
    }
}


long NOD(long n)
{
    int  i,j,k;
    long sq=sqrt(n);
    long res=1;
    for(i=0; prime[i]<=sq; i++)
    {
        int cnt=1;
        if(n%prime[i]==0)
        {
            while(n%prime[i]==0)
            {
                cnt++;
                n=n/prime[i];
                if(n==1) break;
            }
            res*=cnt;
            sq=sqrt(n);
        }
    }
    if(n>1) res*=2;
    return res;
}
*/

int lcs[100][100];
long long val[100][100];


int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j,k;
    int n;
    string fat,mot;
    int t,cases=1;
    cin>>t;
    getchar();
    while(t--)
    {
        getline(cin,fat);
        getline(cin,mot);


        int l1=fat.length();
        int l2=mot.length();

        fat=" "+fat;
        mot=" "+mot;

        for(i=0; i<100; i++)
        {
            lcs[0][i]=lcs[i][0]=i;
            val[0][i]=val[i][0]=1;
        }

        for(i=1; i<=l1; ++i)
        {
            for(j=1; j<=l2; ++j)
            {
                if(fat[i]==mot[j])
                {
                    lcs[i][j]=lcs[i-1][j-1]+1;
                    val[i][j]=val[i-1][j-1];
                }
                else
                {
                    lcs[i][j]=min(lcs[i-1][j],lcs[i][j-1])+1;
                    if(lcs[i-1][j]<lcs[i][j-1])
                        val[i][j]=val[i-1][j];
                    else if(lcs[i-1][j]>lcs[i][j-1])
                        val[i][j]=val[i][j-1];
                    else
                        val[i][j]=val[i-1][j]+val[i][j-1];
                }
            }
        }
        printf("Case %d: %d %lld\n",cases++,lcs[l1][l2],val[l1][l2]);
    }
    return 0;
}

/*

ABAAXGF
AABXFGA

*/
