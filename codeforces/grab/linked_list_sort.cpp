#include <bits/stdc++.h>

using namespace std;

struct node
{
    int x;
    node *nxt;
};
node *root;

void Insert(int v)
{
    node *cur = root;
    node *tmp, *pre;
    pre = root;
    tmp->x = v;
    tmp->nxt = new node;


    while(cur->nxt != NULL && cur->x <= v)
    {
        pre = cur;
        cur = cur->nxt;
    }
    if(cur->nxt == NULL)
    {
        cout<<"In if"<<endl;
        if(pre == root)
            root = tmp;
        else{
            pre->nxt = tmp;
            cout<<"in: "<<pre->x<<endl;
        }
    }
    else
    {
        cout<<pre->x<<" "<<v<<endl;
        tmp->nxt = pre->nxt;
        pre->nxt = tmp;
    }

    return;
}


void Query()
{
    node *cur = root;
    int cnt = 0;
    while(cur -> nxt != NULL)
    {
        cout<<cur->x<<endl;
        cur = cur -> nxt;
    }
    return;
}

void Delete(int v)
{
    node *tmp, *cur = root;

    while(cur ->nxt != NULL)
    {
        if(cur->x == v)
            break;
        tmp = cur;
        cur= cur->nxt;
    }
    tmp->nxt = cur->nxt;
    return;
}


int main()
{
    int i, j, k;
    int v, op;

    root = new node;
    while(1)
    {
        cin>>v;
        if(v == 0) break;
        Insert(v);
    }
    Query();





    return 0;
}
