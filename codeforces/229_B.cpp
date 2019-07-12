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

LL a[100009];
LL b[100009];

int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    int n,g;
    cin>>n;

    for(i=0; i<n; i++)
        cin>>a[i];


    for(i=0; i<n; i++)
        cin>>b[i];
    LL res=0;
    for(i=0; i<n; i++)
    {
        LL cn=b[i];
        if(cn==1)
        {
            res--;
            continue;
        }


        LL mid=cn/2;

        if(mid*2==cn)
        {
            if(mid<=a[i])
                res+=(LL)(mid*mid);
            else
                res--;
        }
        else
        {
            LL f=mid+1;
            LL s=mid;
            if(f<=a[i])
                res+=(LL)(f*s);
            else
                res--;
        }
    }
    cout<<res<<endl;



    return 0;
}

/*

4544545454

*/
