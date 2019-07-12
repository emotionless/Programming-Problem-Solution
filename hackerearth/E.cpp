#include <bits/stdc++.h>
#define MAX 1366663
using namespace std;
bool is_prime[MAX];
long long prime[MAX];
int sieve()
{
    long i,j,k=2,sq=(sqrt(MAX));;
    prime[1]=2;
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
return k;
}
int main()
{
    int i,k=sieve();
    cout<<prime[2];
    for(i=3; i<k; i+=2)
    {
        if(!is_prime[i])
        {
            cout<<" "<<prime[i];
        }
    }
    return 0;
}
