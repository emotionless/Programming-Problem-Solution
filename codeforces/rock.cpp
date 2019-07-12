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


#include <cstdio>
#include <iostream>

#define LL long long
#define MX 5000+7
#define MOD 1000000000+7
#define N 1000007
#define check_bit(a,b) (a & (1<<b))
#define PB push_back


using namespace std;

LL x1[1001];
LL x2[1001];
LL y2[1001];
LL y1[1001];
LL len1[1001];
LL len2[1001];


int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    LL a,b;
    LL n,g;
    LL m;
    cin>>n>>m;

    for(i=0; i<n; i++)
    {
        cin>>x1[i]>>y1[i]>>len1[i];
    }
    for(i=0; i<m; i++)
    {
        cin>>x2[i]>>y2[i]>>len2[i];
    }
    LL res=0;
    for(i=0; i<n; i++)
    {
        LL xx1=x1[i];
        LL yy1=y1[i];
        LL yy2=y1[i]+len1[i];
        LL mx=0;
        for(j=0; j<m; j++)
        {
            LL tmp=0;
            if(yy1<=y2[j] && yy2>=y2[j] && x2[j]<=xx1 && xx1<=x2[j]+len2[j])
            {
                LL x=xx1;
                LL y=y2[j];

                LL dif1=(y-yy1);
                if(dif1<0) dif1*=(-1);

                LL dif2=(x-x2[j]);
                if(dif2<0) dif2=dif2*(-1);

                LL dif3=(y-yy2);
                if(dif3<0) dif3=dif3*(-1);

                LL dif4=(x-(x2[j]+len2[j]));
                if(dif4<0) dif4=dif4*(-1);
                //cout<<i<<" "<<j<<" "<<x<<" "<<y<<" "<<dif1<<" "<<dif2<<" "<<dif3<<" "<<dif4<<endl;
                tmp=min(min(dif1, dif2), min(dif3, dif4));
            }
            mx=max(mx, tmp);
        }
        res=max(res, mx);

    }
    cout<<res<<endl;





    return 0;
}

/*

4544545454

*/
