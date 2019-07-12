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
#define MX 5000+7
#define MOD 1000000000+7
#define N 1000007
#define PB push_back


using namespace std;

LL pb,b,s,c, ps, pc, nb,ns,nc;
LL r;

inline LL solve(LL n)
{
    LL tot=0;
    if(nb<n*b)
    {
        tot+=(n*b-nb)*pb;
    }

    if(ns<n*s)
    {
        tot+=(n*s-ns)*ps;
    }
    if(nc<n*c)
    {
        tot+=(n*c-nc)*pc;
    }
    return tot;
}

inline LL Binary_search()
{
    LL st=0, ed=1000000010001LL, mid;

    while(st<ed)
    {
        mid=(st+ed)/2;

        LL cal=solve(mid);
        if(cal>r)
            ed=mid;
        else
            st=mid+1;
    }
    LL again=solve(ed);
    if(again<=r)
        return ed;
    again=solve(st);
    if(again<=r)
        return st;
    return st-1;
}


int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");
    string str;
    int i;

    cin>>str;
    cin>>nb>>ns>>nc;
    cin>>pb>>ps>>pc;

    cin>>r;
    b=s=c=0;
    for(i=0; i<str.length(); i++)
    {
        if(str[i]=='S')
            s++;

        if(str[i]=='C')
            c++;

        if(str[i]=='B')
            b++;
    }
    LL res=Binary_search();
    cout<<res<<endl;


    return 0;
}

/*

BSC
1 1 0
1 1 3
0


C
100 100 100
1 1 1
1000000000000



*/
