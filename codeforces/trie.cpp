#include<bits/stdc++.h>

using namespace std;

struct node
{
    bool endmark;
    node *nxt[26];
    node()
    {
        endmark=false;
        for(int i=0; i<26; i++) nxt[i]=NULL;
    }
}*root;

void insert(string str)
{
    int l=str.length();
    node *curr=root;
    for(int i=0; i<l; i++)
    {
        int id=str[i]-'a';
        if(curr->nxt[id]==NULL) curr->nxt[id]=new node();
        curr=curr->nxt[id];
    }
    curr->endmark=true;
}

bool srch(string str)
{
    int l=str.length();
    node *curr=root;
    for(int i=0; i<l; i++)
    {
        int id=str[i]-'a';
        if(curr->nxt[id]==NULL) return false;
        curr=curr->nxt[id];
    }
    return curr->endmark;
}

void del(node *curr)
{
    for(int i=0; i<26; i++) if(curr->nxt[i]) del(curr->nxt[i]);
    delete(curr);
}

int main()
{
    int n;
    root=new node();
    cin>>n;
    for(int i=0; i<n; i++)
    {
        string str;
        cin>>str;
        insert(str);
    }
    int q;
    cin>>q;
    for(int i=0; i<q; i++)
    {
        string str;
        cin>>str;
        if(srch(str)) cout<<"got it"<<endl;
        else cout<<"not in the list"<<endl;
    }
    del(root);
    return 0;
}
