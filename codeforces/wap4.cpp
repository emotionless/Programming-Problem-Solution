#include <bits/stdc++.h>

using namespace std;

struct node
{
    node *next[2];  // maximum two leaves
    node()
    {
        for(int i=0; i<2; i++)
            next[i]=NULL;   // initially all nodes are null
    }
}*root;


long long nums[100002];      // store input data
long long total;


void trieInsert(long long value)
{
    int len = 42;   // maximum bit is 40
    node *cur=root;

    for(int i=len; i>=0; i--)
    {
        bool id = (((1ll<<i)&value)?1:0) ;
        if(cur->next[id]==NULL) cur->next[id]=new node();
        cur=cur->next[id];
    }

    return;
}


long long Query(long long csxor)
{
    int len = 42;       // highest number of bit
    node *cur = root;
    long long ret = 0;
    //cout<<csxor<<endl;
    for(int i = len; i >= 0; i--)
    {
        bool idOfcsxor = (((1ll<<i)&csxor)?1:0);    // get current bit of csxor
        bool idOfTotal = (((1ll<<i)&total)?1:0);    // get current bit of Total
        bool id = (idOfcsxor^idOfTotal)^1;          // get the opposite bit (0,1)
        if(cur->next[id] != NULL)                   // check if match with opposite bit
        {
            cur = cur -> next[id];
            ret = (ret|(1ll<<i));
        }
        else
            cur = cur -> next[id^1];
        //cout<<idOfcsxor<<" "<<idOfTotal<<" "<<id<<" "<<ret<<endl;
    }

    return ret;
}

void del(node *cur)
{
    for(int i = 0; i < 2; i++)
        if(cur->next[i] != NULL)
            del(cur->next[i]);
    delete(cur);

    return;
}


int main()
{
    int i, j, k;
    int n, t;
    cin>>n;
    total = 0;
    for(i = 0; i < n; i++)
    {
        cin>>nums[i];
        total = total ^ nums[i];
    }


    long long xorsum = 0, ans = total, currentGetMax;
    //cout<<xorsum<<endl;
    root=new node();
    trieInsert(0);
    for(i = 0; i < n; i++)
    {
        xorsum = xorsum ^ nums[i];
        // get maximum value from this position
        currentGetMax = Query(xorsum);
//            cout<<i<<" "<<currentGetMax<<endl;
        ans = max(ans, currentGetMax);
        trieInsert(xorsum);

    }
    cout<<ans<<endl;

    // delete this trie
    del(root);

    return 0;
}

/*

3
1 3 2
out: 3

3
5 9 1
out: 13


7
1 2 7 8 6 4 0
out: 15


*/
