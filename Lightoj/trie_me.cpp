#include<bits/stdc++.h>

using namespace std;
struct node
{
    bool ismark;
    node *next[26];
    node()
    {
        ismark=false;
        for(int i=0; i<26; i++)
        next[i]=NULL;
    }
}*root;

void insert(string str)
{
    int len=str.length();
    node *cur=root;

    for(int i=0; i<len; i++)
    {
        int id=str[i]-'a';
        if(cur->next[id]==NULL) cur->next[id]=new node();
        cur=cur->next[id];
    }
    cur->ismark=true;
}

bool check(string str)
{
    int len=str.length();
    node *cur=root;
    for(int i=0; i<len; i++)
    {
        int id=str[i]-'a';
        if(cur->next[id]==NULL) return false;
        cur=cur->next[id];
    }
    return cur->ismark;
}

int main()
{
    int i,j,k,n,q;
    string str;
    root=new node();
    cin>>n;
    while(n--)
    {
        cin>>str;
        insert(str);
    }
    cin>>q;
    while(q--)
    {
        cin>>str;
        if(check(str)) cout<<"Yes"<<endl;
        else
        cout<<"No"<<endl;
    }
return 0;
}
