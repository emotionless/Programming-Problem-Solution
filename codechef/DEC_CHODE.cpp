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

struct Z
{
    char c;
    int val;
    Z() {}
    Z(char a, int b)
    {
        c=a;
        val=b;
    }

    bool operator<(const Z& A) const
    {
        if(A.val==val) return A.c>c;
        return A.val>val;
    }
};


int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j,k;
    int n, q,t,m;
    string str, inp;
    cin>>t;
    while(t--)
    {
        cin>>str;
        getchar();
        reverse(str.begin(), str.end());
        getline(cin,inp);

        int len=inp.length();
        string tmp=inp;
        int val[30];
        memset(val, 0, sizeof val);
        for(i=0; i<len; i++)
        {
            inp[i]=tolower(inp[i]);
            if(isalpha(inp[i]))
                val[inp[i]-'a']++;
        }
        vector<Z>V;
        for(i=0; i<30; i++)
        {
            if(val[i])
            {
                V.PB(Z('a'+i, val[i]));
            }
        }
        sort(V.begin(), V.end());

        reverse(V.begin(), V.end());
        inp=tmp;
        for(j=0; j<len; j++)
        {
            if(!isalpha(inp[j]))
            {
                cout<<inp[j];
                continue;
            }
            int cc=tolower(inp[j]);
            for(i=0; i<V.size(); i++)
            {
                if(cc==V[i].c)
                {
                    if(inp[j]>='A' && inp[j]<='Z')
                    {
                        char ccc=toupper(str[i]);
                        cout<<ccc;
                    }
                    else
                        cout<<str[i];
                    break;
                }
            }
        }
        cout<<endl;

    }
    return 0;
}

/*

qwrtyuipasdfgjkzxcvbnmheol
dummy!

*/
