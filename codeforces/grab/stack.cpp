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
    node *tmp = new node;
    tmp->x = v;
    tmp->nxt = root;
    root = tmp;
    return;
}


void Query()
{
    node *cur = root;
    if(cur->nxt == NULL)
    {
        cout<<"Empty"<<endl;
        return;
    }
    cout<<cur->x<<endl;
    root = root->nxt;

    return;
}


int main()
{
    int i, j, k;
    int v, op;

    root = new node;
//    root ->nxt = new node;
    while(1)
    {
        cin>>op>>v;
        if(v == 0) break;
        if(op == 1)Insert(v);
        else Query();
    }





    return 0;
}
