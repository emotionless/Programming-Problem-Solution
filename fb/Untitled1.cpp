#include <iostream>
#include<cstdio>
#include <algorithm>
#include<cstring>
#include<cmath>
#include <cstdlib>
#include <vector>
#define MAX 1000900		//1 koti
#define exp12 1000000000000
#define pb(x) push_back(x)
using namespace std;

char is_prime[MAX];
int prime_series[100000], limit;
vector < long long int > al_prime;

void sieve()
{
    register int k, i=2, j, x;
    memset(is_prime, 1 , MAX);
    x=sqrt(MAX);

    ///for even number
    for(j=i*i ; j<=MAX; j+=i)
        is_prime[j]=0;

    for(i=3; i<=x; )
    {
        for(j=i*i; j<=MAX; j+=(i*2))
            is_prime[j]=0;

        i++;
        while(is_prime[i]!=1)
            i++;
    }

    ///saving the prime number
    for(i=2, k=0; i<=MAX ; i++)
    {
        if(is_prime[i]==1)
        {
            prime_series[k++]=i;
        }
    }
    limit=k;
}

int main()
{
    sieve();
    int i, j, k;
    long long int  ul, ll,  mul, result;
    int cnt=0;

    for(i=0, cnt=0 ; prime_series[i]<=1000000; i++)
    {
        mul=prime_series[i];
        mul*=mul;
        while(mul<=exp12)
        {
            al_prime.pb(mul);
            mul=mul*prime_series[i];
            //cnt++;
        }
    }
//	cout<<cnt<<" ";
    int sz;
    sz= al_prime.size();
    sort(al_prime.begin(), al_prime.end());
    int test_case;


    scanf("%d", &test_case);
    while(test_case--)
    {
        scanf("%lld %lld", &ll, &ul);
        for(i=0, result=0; i<sz; i++)
        {
            if(al_prime[i]>=ll)
            {
                if(al_prime[i]>ul)
                    break;
                result++;
            }
        }
        printf("%lld\n", result);
    }
}
