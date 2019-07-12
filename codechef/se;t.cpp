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
***** Sorry for bad written code **********
*/


#include<bits/stdc++.h>

#define LL long long
#define MX 100009        // 10^5 + 9
#define MOD 1000000007   // 10^9 + 7
#define PB push_back
#define set_mask(a,b) (a|(1<<b))
#define check_mask(a,b) (a&(1<<b))
#define FOR(i, b) for(i = 0; i < b; i++)

using namespace std;



int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int t,j,i,k;
    int n;
    string str;
    cin>>str;
    str = " "+str;
    int len = str.length();
    LL res = 0;
    for(i = 1; i < len; i++)
    {
        if(i%2)
        {
            res = (res * 2) % MD;
            if(str[i] == 'r')
                res = (res + 2) % MD;
        }
        else
        {
            res = (res * 2) % MD;
            if(str[i] == 'r') res = (res - 1) % MD;
            else
                res = (res + 1) % MD;
        }
    }
    cout<<res<<endl;



    return 0;
}

/*



*/
