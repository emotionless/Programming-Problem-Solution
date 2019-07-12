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


int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j,k,K;
    int n, q,m;
    string str;
    int t;
    cin>>K;
    int val[12];
    memset(val, 0, sizeof val);
    for(i=0; i<4; i++)
    {
        cin>>str;
        for(j=0; j<4; j++)
        {
            if(str[j]>='1' && str[j]<='9')
            {
                int a=str[j]-'1'+1;
                val[a]++;
            }
        }
    }

    for(i=0; i<10; i++)
    {
        if((val[i]/2+(val[i]%2))>K)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;




    return 0;
}

/*



*/
