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
int val[26];

int sum[1501];


int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j;
    int K;
    string str,value;
    cin>>str>>value;
    cin>>K;

    for(i=0; i<26; i++)
        val[i+1]=1-(value[i]-'0');
    int len=str.length();
    for(i=0; i<len; i++)
    {
        sum[i]=sum[i-1]+val[str[i]-'a'+1];
    }
    int cnt=0;
    map<string, bool>M;
    for(i=0; i<len; i++)
    {
        string S="";
        for(j=i; j<len; j++)
        {
            S+=str[j];
            if(!M[S])
            {
                M[S]=true;
                int have=sum[j]-sum[i-1];
              //  cout<<i<<" "<<j<<" "<<have;
                if(have<=K)
                {
                   // cout<<" yes"<<endl;
                    cnt++;
                }
            }
        }
    }
    cout<<cnt<<endl;
    M.clear();
    return 0;
}

/*

abcdefghijklmnopqrstuvwxyzkjheabcdefghijklmnopqrstuvwxyzkjheabcdefghijklmnopqrstuvwxyzkjhelkjhgfdsaqabcdefghijklmnopqrstuvwxyzkjheabcdefghijklmnopqrstuvwxyzkjheabcdefghijklmnopqrstuvwxyzkjhelkjhgfdsaqabcdefghijklmnopqrstuvwxyzkjheabcdefghijklmnopqrstuvwxyzkjheabcdefghijklmnopqrstuvwxyzkjhelkjhgfdsaqabcdefghijklmnopqrstuvwxyzkjheabcdefghijklmnopqrstuvwxyzkjheabcdefghijklmnopqrstuvwxyzkjhelkjhgfdsaqabcdefghijklmnopqrstuvwxyzkjheabcdefghijklmnopqrstuvwxyzkjheabcdefghijklmnopqrstuvwxyzkjhelkjhgfdsaqabcdefghijklmnopqrstuvwxyzkjheabcdefghijklmnopqrstuvwxyzkjheabcdefghijklmnopqrstuvwxyzkjhelkjhgfdsaqabcdefghijklmnopqrstuvwxyzkjheabcdefghijklmnopqrstuvwxyzkjheabcdefghijklmnopqrstuvwxyzkjhelkjhgfdsaqabcdefghijklmnopqrstuvwxyzkjheabcdefghijklmnopqrstuvwxyzkjheabcdefghijklmnopqrstuvwxyzkjhelkjhgfdsaqabcdefghijklmnopqrstuvwxyzkjheabcdefghijklmnopqrstuvwxyzkjheabcdefghijklmnopqrstuvwxyzkjhelkjhgfdsaqabcdefghijklmnopqrstuvwxyzkjheabcdefghijklmnopqrstuvwxyzkjheabcdefghijklmnopqrstuvwxyzkjhelkjhgfdsaqabcdefghijklmnopqrstuvwxyzkjheabcdefghijklmnopqrstuvwxyzkjheabcdefghijklmnopqrstuvwxyzkjhelkjhgfdsaqabcdefghijklmnopqrstuvwxyzkjheabcdefghijklmnopqrstuvwxyzkjheabcdefghijklmnopqrstuvwxyzkjhelkjhgfdsaqabcdefghijklmnopqrstuvwxyzkjheabcdefghijklmnopqrstuvwxyzkjheabcdefghijklmnopqrstuvwxyzkjhelkjhgfdsaqabcdefghijklmnopqrstuvwxyzkjheabcdefghijklmnopqrstuvwxyzkjheabcdefghijklmnopqrstuvwxyzkjhelkjhgfdsaqabcdefghijklmnopqrstuvwxyzkjheabcdefghijklmnopqrstuvwxyzkjheabcdefghijklmnopqrstuvwxyzkjhelkjhgfdsaq
00000000000000000000000000
1
*/
