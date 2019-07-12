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
string mat[10];

int bit[10];

void pre()
{
    bit[0]=1;
    for(int i=1; i<8; i++)
    {
        bit[i]=bit[i-1]*2;
    }
}

void equal(string left, string right)
{
    cout<<"........||........"<<endl;
    cout<<".../\\...||.../\\..."<<endl;
    cout<<"../..\\..||../..\\.."<<endl;
    cout<<"./....\\.||./....\\."<<endl;
    cout<<"/"<<left;
    for(int i=0; i<6-left.size(); i++)
        cout<<".";
    cout<<"\\||/";
    cout<<right;
    for(int i=0; i<6-right.size(); i++)
        cout<<".";
    cout<<"\\"<<endl;
    cout<<"\\______/||\\______/"<<endl;
    cout<<"........||........"<<endl;

}

void up(string left, string right)
{
    cout<<".../\\...||........"<<endl;
    cout<<"../..\\..||........"<<endl;
    cout<<"./....\\.||.../\\..."<<endl;
    cout<<"/";
    cout<<left;

    for(int i=0; i<6-left.size(); i++)
        cout<<".";

    cout<<"\\||../..\\.."<<endl;
    cout<<"\\______/||./....\\."<<endl;
    cout<<"........||/";

    cout<<right;

    for(int i=0; i<6-right.size(); i++)
        cout<<".";
    cout<<"\\"<<endl;
    cout<<"........||\\______/"<<endl;
}

void down(string left, string right)
{
    cout<<"........||.../\\..."<<endl;
    cout<<"........||../..\\.."<<endl;
    cout<<".../\\...||./....\\."<<endl;
    cout<<"../..\\..||/";
    cout<<right;

    for(int i=0; i<6-right.size(); i++)
        cout<<".";
    cout<<"\\"<<endl;
    cout<<"./....\\.||\\______/"<<endl;
    cout<<"/";
    cout<<left;
    for(int i=0; i<6-left.size(); i++)
        cout<<".";
    cout<<"\\||........"<<endl;
    cout<<"\\______/||........"<<endl;



}


int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j,k;
    int n, q,m, cases=1;
    int t;
    pre();
    cin>>t;
    while(t--)
    {
        for(i=0; i<7; i++)
        {
            cin>>mat[i];
        }
        string temp, left="", right="";
        int lpos, rpos;
        cin>>temp;

        printf("Case %d:\n", cases++);

        for(i=0; i<7; i++)
        {
            for(j=0; j<8; j++)
            {
                if(mat[i][j]>='A' && mat[i][j]<='Z')
                {
                    left+=mat[i][j];
                }
                if(mat[i][j]=='_')
                    lpos=i;
            }
        }
        for(i=0; i<7; i++)
        {
            for(j=10; j<18; j++)
            {
                if(mat[i][j]>='A' && mat[i][j]<='Z')
                {
                    right+=mat[i][j];
                }
                if(mat[i][j]=='_')
                    rpos=i;
            }
        }
        // cout<<left<<" "<<right<<endl;
        int l=0;
        for(i=0; i<left.length(); i++)
        {
            int num=left[i];
            for(j=0; j<7; j++)
            {
                int tm=num&bit[j];
                if(tm)
                {
                    l+=500;
                }
                else
                    l+=250;
            }
        }

        int r=0;
        for(i=0; i<right.length(); i++)
        {
            int num=right[i];
            for(j=0; j<7; j++)
            {
                int tm=num&bit[j];
                if(tm)
                {
                    r+=500;
                }
                else
                    r+=250;
            }
        }
        if(l==r)
        {
            if(lpos==rpos)
                cout<<"The figure is correct."<<endl;
            else
            {
                equal(left, right);
            }
        }

        else if(l<r)
        {
            if(lpos<rpos)
                cout<<"The figure is correct."<<endl;
            else
            {
                up(left, right);
            }
        }
        else if(l>r)
        {
            if(lpos>rpos)
                cout<<"The figure is correct."<<endl;
            else
            {
                down(left, right);
            }
        }
    }
    return 0;
}

/*

........||.../\...
........||../..\..
.../\...||./....\.
../..\..||/AAA...\
./....\.||\______/
/AA....\||........
\______/||........
------------------



.../\...||........
../..\..||........
./....\.||.../\...
/W.....\||../..\..
\______/||./....\.
........||/W.....\
........||\______/
------------------


........||.../\...
........||../..\..
.../\...||./....\.
../..\..||/......\
./....\.||\______/
/......\||........
\______/||........
------------------



........||........
.../\...||.../\...
../..\..||../..\..
./....\.||./....\.
/......\||/......\
\______/||\______/
........||........
------------------

*/
