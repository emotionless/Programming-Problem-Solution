#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;
bool prime[5000010],k,a[100000];

long divide(long n);
void pr()
{
    long n=5000000,i,j;
    memset(prime,true,sizeof prime);
    a[0]=2;
    k=1;
    for(i=3; i<=sqrt(n); i+=2)
    {
        if(prime[i])
        {
            a[k]=i;
            k++;
            cout<<k<<endl;
            for(j=i+i; j<=sqrt(n); j+=i)
                prime[j]=false;
        }
    }
}
int main()
{
    long i,j,k,a,b;
    pr();
    //cout<<k<<endl;
    scanf("%ld %ld",&a,&b);
    long r=divide(a);
    cout<<r;
}
long divide(long n)
{
    int v[10000],i;
    memset(v,0,sizeof v);
    for(i=0; i<=k; i++)
    {
        while(n%a[i]==0)
        {
            v[i]++;
            n=n/a[i];
        }
        if(n==1) break;
        if(a[i]*a[i]>n) break;
    }
    long mul=1;
    if(n>1)

        mul=2;
    for(int k=i; k>=0; k--)
    {
        mul=mul*v[i];
    }
    return mul;
}
