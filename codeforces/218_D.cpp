/*
******************************************
***** Bismillahir Rahmanir Rahim *********
***** Full Name: Faruk Hossain Milon *****
***** University: IIT-JU, BD ****************

***** Codechef username: emotionless *****
***** Topcoder handle: emotionless *******
***** UVA username: emotionless **********
***** Hust username: emotionless *********
***** Codeforces handle: milon ***********
******************************************
***** Sorry for bad writen code **********
*/


#include <bits/stdc++.h>

#define LL long long
#define MX 2*100009
#define MOD 1000000000+7
#define N 1000007
#define PB push_back


using namespace std;

LL par[MX];
LL cap[MX];
LL have[MX];

int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    LL i,j,k;
    LL n, q,m;
    LL t;
    cin>>n;

    for(i=1; i<=n; i++)
    {
        cin>>cap[i];
        par[i]=i+1;
    }

    cin>>q;
    int op;
    LL x,p;

    while(q--)
    {
        cin>>op;
        if(op==1)
        {
            cin>>p>>x;
            i=p;
            vector<int>V;
            LL mx=0;
            while(i<=n && x>0)
            {
                if(cap[i]>=0)
                {
                    LL mn=min(cap[i], x);
                    x-=mn;
                    cap[i]-=mn;
                    have[i]+=mn;
                    V.PB(i);
                    if(x>0)
                        i=par[i];
                    mx=max(mx,i);
                }
            }
            int sz=V.size();
            for(j=0; j<sz-1; j++)
                par[V[j]]=mx;
            V.clear();
        }
        else
        {
            cin>>x;
            cout<<have[x]<<endl;
        }
    }






    return 0;
}

/*

3
5 10 8
9
1 1 12
2 2
1 1 6
1 3 2
2 2
2 3

*/
