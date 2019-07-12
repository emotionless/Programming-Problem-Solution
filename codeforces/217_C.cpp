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

int rgt[MX];
int lft[MX];


int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j,k;
    int n, q,m;
    int t,a,b,c,d;

    cin>>n>>m;

    for(i=0; i<n; i++)
    {
        cin>>lft[i];
        rgt[i]=lft[i];

    }

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(i==j) continue;


            if(lft[i]!=rgt[j] && lft[j]!=rgt[i])
            {
                swap(rgt[i], rgt[j]);
                break;
            }

            if(rgt[i]!=lft[j] && lft[i]!=rgt[j])
            {
                swap(lft[i], lft[j]);
                break;
            }
        }

    }
    int cnt=0;
    for(i=0; i<n ; i++)
    {
        if(lft[i]!=rgt[i])
            cnt++;
    }
    cout<<cnt<<endl;
    for(i=0; i<n; i++)
    {
        cout<<lft[i]<<" "<<rgt[i]<<endl;
    }





    return 0;
}

/*

5 3
1000 1002 1003 1004 1005
S 0 2
G 0 3
S 0 2

*/
