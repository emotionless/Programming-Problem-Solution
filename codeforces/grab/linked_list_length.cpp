#include <bits/stdc++.h>

using namespace std;

struct node
{
    int x;
    node *nxt;
};

node *root;

void Insert(int val, node **head)
{
    node *tmp = new node;
    tmp->x = val;
    tmp->nxt = new node;
    tmp->nxt = *head;
    *head = tmp;
    return;
}

int Count()
{
    node *cur = root;
    int cnt = 0;
    while(cur-> nxt != NULL)
    {
        cur = cur->nxt;
        cnt++;
    }
return cnt;
}

void Delete(node **cur)
{
    if((*cur)->nxt != NULL)
    {
        node *tmp = *cur;
        *cur=(*cur)->nxt;
        free(tmp);
    }
}



//int CountRecursive(node *cur)
//{
//    if(cur->nxt == NULL) return 0;
//    return 1 + Count(cur->nxt);
//}


int main()
{
    int i, j, k, v;

    root = new node();
    while(1)
    {
        cin>>v;
        if(v == 0) break;
        Insert(v, &root);

        if(v == 2)
            Delete(&root);
    }
    cout<<Count()<<endl;




return 0;
}
