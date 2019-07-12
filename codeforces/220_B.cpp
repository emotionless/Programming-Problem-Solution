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

int arr[MX];

vector<LL>V;

int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j,k;
    int n, q,M;
    string str;
    cin>>str;

    int len=str.length();
    LL res=1;
    int cnt=0;
    for(i=1; i<len; i++)
    {
        if(str[i]+str[i-1]-2*('0')==9)
        {
            cnt++;
        }
        else
        {
            if(cnt!=0)
            V.push_back(cnt+1);
            cnt=0;
        }
    }
    if(cnt!=0)
    V.push_back(cnt+1);
    res=1;
    for(i=0; i<V.size(); i++)
    {
        if(V[i]%2)
        res=res*(V[i]/2+1);
    }
    cout<<res<<endl;

    return 0;
}

/*

4544545454

*/
