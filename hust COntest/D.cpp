#include<bits/stdc++.h>
#define LL long long

using namespace std;

string solve(string str)
{
    int len=str.length();
    int i,j,k;
    string age="",third="",first="",second="";
    int f=0, s=0,t=0;
    bool p=1;
    for(i=0; i<len; i++)
    {
        if(str[i]>='A' && str[i]<='Z')
            str[i]=str[i]-'A'+'a';
        char cc=str[i];
        if(cc==' ' && f==0 && s==0 && t==0) continue;
        if(cc=='(')
            f++;
        else if(cc==')')
            f--;
        else if(cc=='{')
            s++;
        else if(cc=='}')
            s--;
        else if(cc=='[')
            t++;
        else if(cc==']')
            t--;
        else if(f)
            first+=str[i];
        else if(s)
            second+=str[i];
        else if(t)
            third+=str[i];
        else
            age+=str[i];
    }
    if(age=="")
        return second+" "+first+" "+third;
    return age+" "+second+" "+first+" "+third;
}



int main()
{
    int i,j,k;
    string sen;
    while(getline(cin,sen))
    {
        sen+=',';
        int len=sen.length();

        string str="";
        bool p=true;
        int f=0, s=0, t=0;
        for(i=0; i<len; i++)
        {
            // this

            char cc=sen[i];
            if(cc==' ' && f==0 && s==0 && t==0) continue;
            if(cc=='(')
                f++;
            else if(cc==')')
                f--;
            else if(cc=='{')
                s++;
            else if(cc=='}')
                s--;
            else if(cc=='[')
                t++;
            else if(cc==']')
                t--;

            //


            if(sen[i]==',' && f==0 && s==0 && t==0)
            {
                string got=solve(str);
                if(p==true)
                    got[0]=toupper(got[0]);
                p=0;
                cout<<got;
                if(i!=len-1)
                    cout<<", ";
                else
                    cout<<endl;
                str="";
            }
            else
                str+=sen[i];
        }
    }

    return 0;
}

/*

asas [asad] {kkf} (jhf) asa

*/
