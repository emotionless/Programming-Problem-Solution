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
#define MAX 100000001
#define MOD 1000000007
#define N 1000007
#define PB push_back
#define set_mask(a,b) (a|(1<<b))


using namespace std;



int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j,k;
    LL num;
    string str, inp;
    int t;
    scanf("%d", &t);
    while(t--)
    {
        cin>>str;
        cin>>inp;
        for(i = 0; i < str.length(); i++)
        {
            if(str[i] == inp[i]) continue;
            if(str[i] == '?' || inp[i] == '?') continue;
            break;
        }
        if(i == str.length())
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }




    return 0;
}

/*

5 4
2 1 2
2 2 3
2 3 4
1 5

*/
