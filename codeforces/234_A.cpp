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
#define FOR(aa,nn) for(aa=0; aa<nn; aa++)


using namespace std;


int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    int a,b;
    int n,g;
    int t;
    string str;
    cin>>t;
    while(t--)
    {
        cin>>str;
        str=" "+str;
        vector<int>V;
        V.clear();

        // for 1
        for(i=1; i<=12; i++)
        {
            if(str[i]=='X')
            {
                V.PB(1);
                V.PB(12);
                break;
            }
        }

        for(i=1; i<=6; i++)
        {
            if(str[i]=='X' && str[i+6]=='X')
            {
                V.PB(2);
                V.PB(6);
                break;
            }
        }

        for(i=1; i<=4; i++)
        {
            if(str[i]=='X' && str[i+4]=='X' && str[i+8]=='X')
            {
                V.PB(3);
                V.PB(4);
                break;
            }
        }

        for(i=1; i<=3; i++)
        {
            if(str[i]=='X' && str[i+3]=='X' && str[i+6]=='X' && str[i+9]=='X')
            {
                V.PB(4);
                V.PB(3);

                break;
            }
        }

        for(i=1; i<=2; i++)
        {
            if(str[i]=='X' && str[i+2]=='X' && str[i+4]=='X' && str[i+6]=='X' && str[i+8]=='X' && str[i+10]=='X')
            {
                V.PB(6);
                V.PB(2);

                break;
            }
        }

        for(i=1; i<=12; i++)
        {
            if(str[i]!='X')
            {
                break;
            }
        }
        if(i==13)
        {
            V.PB(12);
            V.PB(1);
        }
        int sz=V.size();
        cout<<sz/2;

        for(i=0; i<sz; i+=2)
            cout<<" "<<V[i]<<"x"<<V[i+1];
        cout<<endl;



    }





    return 0;
}

/*

4544545454

*/
