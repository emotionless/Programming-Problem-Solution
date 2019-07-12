/**********************************************************************
 *                                                                    *
 *             ==>> BG_PeaceMind(BISHAL)                       @NEPAL *
 **********************************************************************/
#include<bits/stdc++.h>

#define MX 31625
using namespace std;


bool vis[MX+5];
int pr[MX+5];
int pl;
map<int,bool>mp;

void seive()
{
    int i,j,k,sq=sqrt(MX);
    vis[0]=vis[1]=true;
    pl=0;
    pr[pl++]=2;
    for(i=3 ; i<=MX ; i+=2)
    {
        if(!vis[i])
        {
            pr[pl++]=(i);
            if(i<=sq)
            {
                for(j= i*i ; j<=MX ; j+= 2*i)
                    vis[j]=true;
            }
        }
        vis[i+1]=true;
    }
}

void precal()
{
   // cout<<" Prime Size: "<<pl<<endl;

    for(int i=0;i<pl;i++)
    {
        int cnt=1;
        mp[ pr[i] ]=1;
        long long num=(long long)pr[i];
        while(num<=1000000000LL)
        {
            num*=num;
            cnt++;
            if(!vis[cnt])mp[(int)num]=1;
        }
    }
}

//bool ok_dis_fac( int n)
//{
//    if(n<=MX) return (!vis[n]);
//    int sq=sqrt(n)
//    int sq=sqrt(n),i,j,ret=1,cntt=0;
//    for(i=0;i<pl && pr[i]<=sq ;i++)
//    {
//        if( n%pr[i] == 0)
//        {
//            cntt++;
//            if(cntt>=2) return false;
//            int cnt=1;
//            while( n%pr[i]==0 )n/=pr[i],cnt++;
//            ret*=cnt;
//        }
//        if(n==1)break;
//        sq=sqrt(n);
//    }
//    if(n>1)
//    {
//        cntt++;
//        if(cntt>=2) return false;
//        ret=(ret<<1);
//    }
//    return (!vis[ret]);
//}

int main()
{
    int a,b,i,j,n,tc,q;
    seive();
    precal();
    //return 0;
    S(tc);
    while(tc--)
    {
        S2(a,b);
        int cnt=0;
        for(i=a;i<=b;i++)
        {
           // cout<<dis_fac(i)<<endl;
           // if( ok_dis_fac(i) )cnt++;
            if( mp[i] )cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
