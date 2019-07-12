#include<bits/stdc++.h>
#define LL long long

using namespace std;

string good(string str)
{
    int len=str.length();
    int cnt=0;

    for(int i=0; i<len; i++)
    {
        if(str[i]==' ' && cnt==0)
            str[i]='.';
        else if(str[i]==34)
        {
            if(cnt==0)
                cnt++;
            else
                cnt--;
        }
    }
    int i=0;
    string first="", second="";
    bool f=false;
    str[len]='.';

    for(i=0; i<len; i++)
    {
        if(str[i]!='.')
        {
            if(f==false)
            {
                while(str[i]!='.')
                {
                    first+=tolower(str[i]);
                    i++;
                }
                f=true;
            }
            else
            {
                while(str[i]!='.')
                {
                    second+=tolower(str[i]);
                    i++;
                }
            }
        }
    }

    return "*"+first+"*"+second+"*";
}


int main()
{
    int i,j,k, cases=1;

    string inp;
    int qur,rep;

    while(cin>>qur && qur)
    {
        cin>>rep;
        getchar();
        getline(cin, inp);

        string str=good(inp);
        int len=str.length();
        string first="", second="";
        int cnt=0;
        for(i=0; i<len; i++)
        {
            if(str[i]==34) continue;
            if(str[i]=='*')
                cnt++;
            else if(cnt==1)
                first+=str[i];
            else
                second+=str[i];
        }

        LL md=qur%rep;
        LL res=qur/rep;
        if(md!=0)
            res+=1;
        printf("%d. ", cases++);
        if(res%2==0)
            cout<<second<<endl;
        else
            cout<<first<<endl;
    }
    return 0;
}
