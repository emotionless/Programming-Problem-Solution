#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
/**Define file I/O **/
#define f_input freopen("input.txt","r",stdin)
#define f_output freopen("output.txt","w",stdout)
/**Define memory set function**/
#define mem(x,y) memset(x,y,sizeof(x))
#define CLEAR(x) memset(x,0,sizeof(x))
/**Define function and object**/
#define pb(t) push_back(t)

#define ll long long

using namespace std;


/******************************End******************************/

vector<int> vec2[300007];
int vec[300007][200];
int length[300007];



void fnc(int p, int q)
{
    if(p < 0 || p >= 300007 || q < 0 || q >= 300007) assert(0);
//    cout<<p<<" "<<q<<endl;
    int m=length[p];
    int n=length[q];
    while(m>0&&n>0)
    {
        if(length[p] <= 0 || length[q] <= 0) assert(0);
        if(vec[p][ length[p]-1 ]>vec[q][ length[q]-1 ])
        {
            int a=vec[p][ length[p]-1 ];
//            vec[p].pop_back();
            length[p]--;
            m--;
            for(ll i=0; vec[q][i]<a&&i<n; i++)
                vec2[vec[q][i]].pb(a);
        }
        else if(vec[p][ length[p]-1 ]<=vec[q][ length[q]-1 ])
        {
            int a=vec[q][ length[q]-1 ];
            /*if(a==vec[p].back())
            {
                vec[p].pop_back();
                m--;
            }*/
//            vec[q].pop_back();
            length[q]--;
            n--;
            for(ll i=0; vec[p][i]<a&&i<m; i++)
            {
                vec2[vec[p][i]].pb(a);
                //printf("%lld\n",a);
            }
        }
    }
    return;
}


int main()
{
    int  n;
//    scanf("%lld",&n);
    cin>>n;
    for(int i=2; i<n; i++)
    {
        for(int j=i; j<n; j+=i)
        {
            vec[j][ length[j]++ ]=(i);
            if(length[j] > 200) assert(0);
            //printf(".");
        }
    }
    int p=n/2;

    if(n%2==0)
        p--;
    for(ll i=2; i<=p; i++)
    {
        fnc(i,n-i);
    }
    int kase = 0;
    ll cnt=n-2;
    if(n%2==0)
    {
        ll sz=length[n/2];
        for(ll i=0; i<sz; i++)
        {
            kase++;
            for(ll j=i+1; j<sz; j++)
            {
                vec2[vec[n/2][i]].pb(vec[n/2][j]);
//                if(vis[ vec[n/2][j] ] != (kase)) cnt++;
//                vis[ vec[n/2][j] ] = kase;
            }
        }
        p++;
    }
//    cout<<p<<endl;
    for(int i=2; i<=p; i++)
    {
        sort(vec2[i].begin(),vec2[i].end());
        vec2[i].erase(unique(vec2[i].begin(),vec2[i].end()),vec2[i].end());
        cnt+=vec2[i].size();
        //printf("%lld %lld\n",cnt, vec2[i].size());

    }
    printf("%lld\n",cnt);
}

/*
156
1104
270228
13820036
*/
