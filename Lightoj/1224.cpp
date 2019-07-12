#include<bits/stdc++.h>

using namespace std;

struct node
{
    bool endmark;
    int pos, tot;
    node *nxt[4];
    node(int num)
    {
        endmark=false;
        pos=num;
        tot=0;
        for(int i=0; i<4; i++) nxt[i]=NULL;
    }
}*root;
int val[200];
int res;
void insert(string str)
{
    int l=str.length();
    node *curr=root;
    for(int i=0; i<l; i++)
    {
        int id=val[str[i]];
        if(curr->nxt[id]==NULL) curr->nxt[id]=new node(curr->pos+1);
        //if(i)
        curr->tot++;
        res=max(res, curr->tot*curr->pos);
        curr=curr->nxt[id];
    }
    curr->tot++;
    curr->endmark=true;
    res=max(res, curr->tot*curr->pos);
}
//
//bool srch(string str)
//{
//    int l=str.length();
//    node *curr=root;
//    for(int i=0; i<l; i++)
//    {
//        int id=str[i]-'a';
//        if(curr->nxt[id]==NULL) return false;
//        curr=curr->nxt[id];
//    }
//    return curr->endmark;
//}

void del(node *curr)
{
    for(int i=0; i<4; i++) if(curr->nxt[i]) del(curr->nxt[i]);
    delete(curr);
}

int main()
{
    int n, cases=1;
    val['A']=0;
    val['C']=1;
    val['G']=2;
    val['T']=3;
    int t;
    cin>>t;
    while(t--)
    {
        res=0;
        root=new node(0);
        cin>>n;
        res=0;
        for(int i=0; i<n; i++)
        {
            string str;
            cin>>str;
            insert(str);
        }
        printf("Case %d: %d\n", cases++, res);
        del(root);
    }
    return 0;
}
