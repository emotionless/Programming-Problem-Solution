#include<bits/stdc++.h>

#define xx first
#define yy second
#define all(a) a.begin(), a.end()
#define vsort(v) sort(all(v))
#define UNIQUE(a)  sort(all(a)); a.erase(unique(all(a)), a.end())
#define clr(a,k) memset(a,k,sizeof a)
#define bclr(b) memset(b,false,sizeof b)
#define fr(i, a) for(i = 0; i < a; i++)
#define frr(i,a) for(i = a - 1; i >= 0, i--)
#define LL long long
#define pb push_back
#define mp make_pair
///***** bit *****///
#define check_bit(a, b) (a&(1<<b))
#define set_bit(a, b) (a|(1<<b))
#define total_bit(a) __builtin_popcount(a)
///***** Input / Output *****///
#define s1(a) scanf("%d", &a)
#define s2(a, b) scanf("%d %d", &a, &b)
#define s3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define p1(a) printf("%d", a)
#define p2(a, b) printf("%d %d", a, b)
#define p3(a, b, c) printf("%d %d %d", a, b, c)

#define MOD 1000000007
#define MAX 10000009


using namespace std;

struct node
{
    bool ismark;
    node *next[26];
    node()
    {
        ismark=false;
        for(int i=0; i<26; i++)
            next[i]=NULL;
    }
}*root;

string insert(string str)
{
    int len=str.length();
    node *cur=root;
    string ret = "";
    bool ok = false;
    for(int i=0; i<len; i++)
    {
        int id=str[i]-'a';
        if(!ok)
            ret += str[i];
        if(cur->next[id]==NULL) ok = true, cur->next[id]=new node();
        cur=cur->next[id];
    }
    cur->ismark=true;
    return ret;
}


void del(node *curr)
{
    for(int i=0; i<25; i++) if(curr->next[i]) del(curr->next[i]);
    delete(curr);
}



int main()
{
    string str;
    ofstream myfile;
    myfile.open ("outputforB.txt");

    int t,cs=1,i,j,k;
    int n, m;
    cin>>t;
    while(t--)
    {
        cin>>n;
        root=new node();
        int res = 0;
        for(i = 0; i < n; i++)
        {
            cin>>str;
            res += insert(str).length();
        }

        myfile<<"Case #"<<cs<<": "<<res<<"\n";
        cs++;
        del(root);
    }
    return 0;
}

/*

3 2
-4 -60 -30
1 2
2 3



*/
