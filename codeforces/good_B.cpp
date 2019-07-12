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
#define check_bit(a,b) (a & (1<<b))
#define PB push_back


using namespace std;
LL arr[3*100001];

map<LL, LL>M;
inline LL rec(LL n)
{
    if(!M[n]) return n;

    return rec(M[n]+1);
}

int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j;
    int a,b;
    int n;

    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    for(i=0; i<n; i++)
    {
        LL cn=arr[i];
        if(!M[cn])
        {
            M[arr[i]]=cn;
            arr[i]=cn;
        }
        else
        {
            LL num=M[arr[i]];
            for(j=num; j<num+(3*100000); j++)
            {
                if(!M[j])
                break;
            }
            M[arr[i]]=j;
            M[j]=j;
            arr[i]=j;
        }
    }
    for(i=0; i<n; i++)
        cout<<arr[i]<<" ";
    M.clear();

    return 0;
}

/*

4544545454

*/
