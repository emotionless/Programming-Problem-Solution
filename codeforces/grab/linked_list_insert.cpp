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
    while(cur -> nxt != NULL){
        cout<<cur->x<<endl;
        cur = cur->nxt;
    }
    cur->nxt = new node;
//    cur = cur->nxt;
    cur -> x = v;

    return;
}


void Query(int v)
{
    node *cur = root;
    int cnt = 0;
    while(cur -> nxt != NULL)
    {
        cnt++;
        if(cur-> x == v)
        {
            cout<<"Got in "<<cnt<<" depth"<<endl;
            return;
        }
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
        cin>>op>>v;
        if(op == 1) /// insert
            Insert( v);
        else if(op == 2)    /// delete
            Delete(v);
        else
            Query(v);
    }





    return 0;
}
