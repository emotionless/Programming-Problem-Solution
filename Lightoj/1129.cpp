#include<bits/stdc++.h>

using namespace std;
bool ck;
struct node
{
    bool endmark;
    node *nxt[10];
    node()
    {
        endmark=false;
        for(int i=0; i<10; i++) nxt[i]=NULL;
    }
}*root;

void insert(string str)
{
    int l=str.length();
    node *curr=root;
    for(int i=0; i<l; i++)
    {
        int id=str[i]-'0';
        if(curr->endmark==true)
            ck=true;
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
        int id=str[i]-'0';
        if(curr->nxt[id]==NULL) return false;
        curr=curr->nxt[id];
    }
    return true;
}

void del(node *curr)
{
    for(int i=0; i<10; i++) if(curr->nxt[i]) del(curr->nxt[i]);
    delete (curr);
}

int main()
{
    int n;
    int t, cases=1;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ck=false;

        root=new node();
        for(int i=0; i<n; i++)
        {
            string str;
            cin>>str;
            if(!ck)
            {
                if(srch(str))
                    ck=true;
                else
                {
                    insert(str);
                }
            }
        }
        printf("Case %d: ", cases++);
        if(ck)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
        del(root);
    }
    return 0;
}
