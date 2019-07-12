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

double one(int num)
{
    double cost1=0.0;
    cost1=10;
    num=num-4;
    if(num<=0) return cost1;

    return cost1+(num*2.0);
}

double two(int num)
{
    double cost=0;
    return (double)num*2.4;
}

void print(double num)
{
    long long n=(LL)num;
    if(n==num)
    cout<<n<<endl;
    else
    printf("%.1lf\n", num);
}

int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j,k;
    int n, q,m;
    while(cin>>n && n)
    {
        int cnt=n/8;
        if(cnt==0)
        {
            double get=one(n);
            print(get);
            continue;
        }
        int md=n%8;
        if(md==0)
        {
            print(cnt*18.0);
            continue;
        }
        double res=cnt*18.0;

        double cost1=one(md);
        double cost2=two(md);

        res+=min(cost1, cost2);

        print(res);
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
