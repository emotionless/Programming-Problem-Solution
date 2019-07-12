#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;
bool prime[5000010];
long k=0,a[100000];
int pr()
{
    long n=sqrt(50010),i,j;
    memset(prime,true,sizeof prime);
    a[0]=2;
    int p=0;
    for(i=3; i<=n; i+=2)
    {
        if(prime[i]==true)
        {
            p++;
            a[p]=i;
            for(j=i+i; j<=n; j+=i)
                prime[j]=false;
        }
    }
    return p;

}
long divide(long n, int k)
{
    int v[k+10],i;
    for(i=0; i<=k; i++)
    {
        v[i]=1;
        while(n%a[i]==0)
        {
            v[i]++;
            n=n/a[i];
        }
        //  if(n==1) break;
        //   if(a[i]*a[i]>n) break;
    }
    long mul=1;
    if(n>1)
        mul=2;
    for(int p=0; p<=k; p++)
    {
        mul=mul*v[p];
    }
    return mul;
}

int main()
{
    long i,j,k,a2,b;
    k=pr();
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%ld %ld",&a2,&b);
        long r=divide(a2,k);
        long r1=divide(b,k);
        if(r>r1)
            printf("%d\n",r-r1);
        else
            printf("%d\n",r1-r);
    }
    return 0;
}
