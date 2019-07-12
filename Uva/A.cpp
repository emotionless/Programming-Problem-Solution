#include<cstdio>
#include<map>
#include<cmath>
#include<iostream>
#include<vector>

using namespace std;

int prime[1000001];
unsigned long long ans[5000001];
bool flag[5000001];
void sieve()
{
    int i,j=0,k,l;
    flag[1]=true;
    prime[j++]=2;
    l=sqrt(5000000);
    for(i=3; i<=l; i+=2)
    {
        if(!flag[i])
        {
            prime[j++]=i;
            for(k=i*i; k<=5000000; k+=2*i)
                flag[k]=true;
        }
    }
    for(i=l+1; i<=5000000; i+=2)
    {
        if(!flag[i])
            prime[j++]=i;
    }
}
int main()
{
    sieve();
    int i,j,k,ll,ul,o,p,q,r,s,t,n;
    long long l,m;
    ans[0]=0;
    ans[1]=0;
    ans[2]=1;
    ans[3]=5;
    for(i=4; i<=5000000; i++)
    {
        if(!flag[i] && i%2==1)
        {
            m=i-1;
        }
        else
        {
            l=1.0;
            m=1;
            p=i;
            m=i;
            j=sqrt(i);
            for(k=0; prime[k]<=j; k++)
            {
                n=0;
                while(p%prime[k]==0 && p>1)
                {
                    if(n==0)
                    {
                        m=(m*(prime[k]-1))/prime[k];
                    }
                    p/=prime[k];
                    q=prime[k];
                    n++;
                }
                if(!flag[p] && p%2==1)
                    break;
            }
            if(p!=q && p>1)
            {
                m=(m*(p-1))/p;
            }
        }
        ans[i]=ans[i-1]+(m*m);
    }
    scanf("%d",&t);
    for(k=1; k<=t; k++)
    {
        scanf("%d %d",&ll,&ul);
        printf("Case %d: %llu\n",k,ans[ul]-ans[ll-1]);
    }
    return 0;
}
