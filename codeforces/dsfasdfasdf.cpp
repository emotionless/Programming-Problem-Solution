#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    string s;
    while(cin>>s)
    {
        ll l=s.length();
        stack<ll> stk;
        for(ll i=0; i<l; i++)
        {
            if(s[i]=='('||s[i]=='[')
            {
                stk.push(s[i]);
                printf("%c",s[i]);
            }
            else
            {
                if(s[i]==']')
                {
                    while(!stk.empty()&&stk.top()!='[')
                    {
                        printf(")");
                        stk.pop();
                    }
                    if(!stk.empty()&&stk.top()=='[')
                    {
                        printf("]");
                        stk.pop();
                    }
                    else
                        printf("[]");
                }
                else
                {
                    while(!stk.empty()&&stk.top()!='(')
                    {
                        printf("]");
                        stk.pop();
                    }
                    if(!stk.empty()&&stk.top()=='(')
                    {
                        printf(")");
                        stk.pop();
                    }
                    else
                        printf("()");
                }
            }
        }
        while(!stk.empty())
        {
            if(stk.top()=='(')
            {
                printf(")");
                stk.pop();
            }
            else
            {
                printf("]");
                stk.pop();
            }
        }
        printf("\n");
    }
    return 0;
}
