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
int val[5001];

int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    int a,b;
    string str;

    cin>>str;
    int len=str.length();
    memset(val, 0, sizeof val);

    for(i=0; i<len-3; i++)
    {
        string tmp="";
        tmp+=str[i];
        tmp+=str[i+1];
        tmp+=str[i+2];
        tmp+=str[i+3];
        if(tmp=="bear")
        {
            val[i+3]=1;
        }
    }
    LL save=0;
    LL res=0;
    for(i=len-1; i>=0; i--)
    {
        if(val[i])
        {
            val[i]=save;
            val[i-1]=save;
            val[i-2]=save;
            res+=save*3;
            save=len-i;
            i=i-2;
        }
        else
            res+=save;
    }
    cout<<res<<endl;



    return 0;
}

/*

4544545454

*/
