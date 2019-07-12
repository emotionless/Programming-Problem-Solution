#include<bits/stdc++.h>

#define LL long long
#define MAX 10000001

#define xx first
#define yy second
#define all(a) a.begin(), a.end()
#define vsort(v) sort(all(v))
#define UNIQUE(a)  sort(all(a)); a.erase(unique(all(a)), a.end())
using namespace std;

struct node
{
    int mn, mx;
    bool is;
    node *next[26];
    node()
    {
        mn = 10000;
        mx = -1;
        for(int i = 0; i < 26; i++)
            next[i] = NULL;
    }
}*root;


vector<string> str;

void insert(string S, int pos)
{
    int len = S.length();
    node *cur = root;
    for(int i = 0; i < len; i++)
    {
        int id = S[i] - 'a';
        if(cur->next[id] == NULL) cur->next[id] = new node();
        cur = cur->next[id];
        cur->mn = min(cur->mn, pos);
        cur->mx = max(cur->mx, pos);
    }
    cur->is = true;
}

int mnn, mxx;
void search(string S)
{
    int len = S.length();
    node *cur = root;
    for(int i = 0; i < len; i++)
    {
        int id = S[i] - 'a';
        if(cur->next[id] == NULL)
        {
            mnn = 10000;
            mxx = 0;
            return;
        }
        cur = cur->next[id];
        mnn = cur->mn;
        mxx = cur->mx;
    }
}



int main()
{
//    ios_base::sync_with_stdio(0); cin.tie(0);

    int i;
    int t, cases = 1;
    cin>>t;
    int n;
    while(t--)
    {
        scanf("%d", &n);
        root = new node();
        string tmp;
        str.clear();
        for(i = 0; i < n; i++)
        {
            cin>>tmp;
            str.push_back(tmp);
        }
        UNIQUE(str);
        n = str.size();
        for(i = 0; i < n; i++)
            insert(str[i], i);
        int q;
        string name;
        scanf("%d", &q);
        printf("Case %d:\n", cases++);
        while(q--)
        {
            cin>>name;
            mnn = 10000;
            mxx = 0;
            search(name);
            if(mnn > mxx)
                cout<<"No Match"<<endl;
            else
            {
                for(i = mnn; i <= mxx; i++)
                    cout<<str[i]<<endl;
            }

        }
    }





    return 0;
}
/*

1
8
aaaaa
aaaaa
aaaaa
aaabc
aaa
aaa
aaa
aaaa
10
a
aa
aaa
aaaa
aaaaa
aaaaaa
aaaaaaa
*/
