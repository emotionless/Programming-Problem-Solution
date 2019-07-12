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


int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    int a,b;
    int t;
    cin>>t;
    string str1, str2;
    while(t--)
    {
        cin>>str1;
        cin>>str2;
        int cnt1[150], cnt2[150];
        memset(cnt1, 0, sizeof cnt1);
        memset(cnt2, 0, sizeof cnt2);
        int len1=str1.length();
        int len2=str2.length();

        for(i=0; i<len1; i++)
            cnt1[str1[i]]++;

        for(i=0; i<len2; i++)
            cnt2[str2[i]]++;
        int res=0;
        for(i=0; i<150; i++)
            res+=min(cnt1[i], cnt2[i]);
        cout<<res<<endl;


    }



    return 0;
}

/*

4544545454

*/
