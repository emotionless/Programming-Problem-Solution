#include <bits/stdc++.h>

using namespace std;

struct node
{
    int x;
    node *nxt;
};


int main()
{
    int i, j, k;

    node *root = new node();
    root->x = 5;
    root -> nxt = 0;
    node *conductor = root;

    while(conductor->nxt != NULL)
    {
        conductor = conductor -> nxt;
    }
    conductor->nxt = new node;
    conductor = conductor->nxt;
    conductor->x = 10;
    conductor->nxt = new node;
    conductor = conductor->nxt;
    conductor->x = 20;
    conductor->nxt = new node;
    conductor = conductor->nxt;
    conductor->x = 30;

    conductor = root;
    while(conductor->nxt != NULL)
    {
        cout<<conductor->x<<endl;
        conductor = conductor -> nxt;
        if(conductor == NULL) break;
    }









return 0;
}
