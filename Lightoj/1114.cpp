#include<bits/stdc++.h>

using namespace std;

struct node
{
    bool endmark;
    int tot;
    node *nxt[91];
    node()
    {
        endmark=false;
        tot=0;
        for(int i=0; i<91; i++) nxt[i]=NULL;
    }
}*root;
int val[150];

void insert(string str)
{
    if(str.length()==1)
        val[str[0]]++;
    string tmp="";
    tmp+=(char)str[0];
    tmp+=(char)str[str.length()-1];
    str=tmp;
    //cout<<str[0]<<" "<<str<<endl;
    int l=str.length();
    node *curr=root;
    for(int i=0; i<l; i++)
    {
        int id=str[i]-' ';
        if(curr->nxt[id]==NULL) curr->nxt[id]=new node();
        curr->tot++;
        curr=curr->nxt[id];
    }
    curr->tot++;
    curr->endmark=true;
}

int srch(string str)
{
    string tmp="";
    tmp+=(char)str[0];
    tmp+=(char)str[str.length()-1];
    str=tmp;

    int l=str.length();
    node *curr=root;
    for(int i=0; i<l; i++)
    {
        int id=str[i]-' ';
        if(curr->nxt[id]==NULL) return 0;
        curr=curr->nxt[id];
    }
    return curr->tot;
}

void del(node *curr)
{
    for(int i=0; i<91; i++) if(curr->nxt[i]) del(curr->nxt[i]);
    delete(curr);
}

int main()
{
    int n;
    string str;
    int t, cases=1;
    cin>>t;
    while(t--)
    {
        root=new node();
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>str;
            insert(str);
        }
        int m;
        cin>>m;
        getchar();
        printf("Case %d:\n", cases++);
        while(m--)
        {
            getline(cin, str);

            stringstream ss;
            ss<<str;
            string word;
            long long res=1;
            while(ss>>word)
            {
                if(word.length()==1)
                {
                    res=res*val[word[0]];
                    continue;
                }
                int get=(srch(word));
                res=res*get;
                //  cout<<word<<" "<<get<<endl;
            }
            cout<<res<<endl;
        }
        del(root);
        memset(val, 0, sizeof val);
    }
    return 0;
}
