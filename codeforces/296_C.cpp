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
#define pii pair<LL , LL >
#define mp make_pair
#define vi vector<LL >
#define vll vector<long long>
///***** bit *****///
#define check_bit(a, b) (a&(1<<b))
#define set_bit(a, b) (a|(1<<b))
#define total_bit(a) __builtin_popcount(a)
///***** Input / Output *****///
#define s1(a) scanf("%d", &a)
#define s2(a, b) scanf("%d %d", &a, &b)
#define s3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define p1(a) prLL f("%d", a)
#define p2(a, b) prLL f("%d %d", a, b)
#define p3(a, b, c) prLL f("%d %d %d", a, b, c)


#define MOD 1000000007
#define MAX 200009


using namespace std;

struct Z
{
    LL l, r, val;
};

Z seg[8*MAX], seg2[8*MAX];



void init(LL  ind, LL  st, LL  ed)
{
    if(st == ed)
    {
        seg[ind].l = seg[ind].r = 0;
        seg[ind].val = 1;
        return;
    }

    LL  mid = (st + ed)/2;
    LL  lft = ind * 2;
    LL  rgt = lft + 1;
    init(lft, st, mid);
    init(rgt, mid + 1, ed);

    if(seg[lft].l)
        seg[ind].l = seg[lft].l;

    else if(seg[lft].r)
        seg[ind].l = seg[lft].r;
    else if(seg[rgt].l)
        seg[ind].l = seg[rgt].l;
    else if(seg[rgt].r)
        seg[ind].l = seg[rgt].r;


    if(seg[rgt].r)
        seg[ind].r = seg[rgt].r;

    else if(seg[rgt].l)
        seg[ind].r = seg[rgt].l;


    else if(seg[lft].r)
        seg[ind].r = seg[lft].r;

    else if(seg[lft].l)
        seg[ind].r = seg[lft].l;




    seg[ind].val = max(seg[lft].val, seg[rgt].val);
    seg[ind].val = max(seg[ind].val,  seg[rgt].l - seg[lft].r);
    if(seg[ind].l == 0 && seg[ind].r == 0)
        seg[ind].val = ed - st + 1;
    else if(seg[lft].l == 0 && seg[lft].r == 0)
    {
        LL  v = 0;
        if(seg[rgt].l)
            v = seg[rgt].l - st;
        else if(seg[rgt].r)
            v = seg[rgt].r - st;
        seg[ind].val = max(seg[ind].val, v);
    }
    else if(seg[rgt].l == 0 && seg[rgt].r == 0)
    {
        LL  v = 0;
        if(seg[lft].r)
            v = ed - seg[lft].r;
        else if(seg[lft].l)
            v = ed - seg[lft].l;
        seg[ind].val = max(seg[ind].val, v);
    }
}



void inserth(LL  ind, LL  st, LL  ed, LL  pos)
{
    if(st == pos && ed == pos)
    {
        seg[ind].l = seg[ind].r = pos;
        seg[ind].val = 1;
        return;
    }

    LL  mid = (st + ed)/2;
    LL  lft = ind * 2;
    LL  rgt = lft + 1;
    if(pos <= mid)
        inserth(lft, st, mid, pos);
    else
        inserth(rgt, mid + 1, ed, pos);

    if(seg[lft].l)
        seg[ind].l = seg[lft].l;
    else if(seg[lft].r)
        seg[ind].l = seg[lft].r;
    else if(seg[rgt].l)
        seg[ind].l = seg[rgt].l;
    else if(seg[rgt].r)
        seg[ind].l = seg[rgt].r;


    if(seg[rgt].r)
        seg[ind].r = seg[rgt].r;

    else if(seg[rgt].l)
        seg[ind].r = seg[rgt].l;


    else if(seg[lft].r)
        seg[ind].r = seg[lft].r;

    else if(seg[lft].l)
        seg[ind].r = seg[lft].l;




    seg[ind].val = max(seg[lft].val, seg[rgt].val);

    if(seg[rgt].l && seg[lft].r)
        seg[ind].val = max(seg[ind].val,  seg[rgt].l - seg[lft].r);

    if(seg[ind].l == 0 && seg[ind].r == 0)
        seg[ind].val = ed - st + 1;
    else if(seg[lft].l == 0 && seg[lft].r == 0)
    {
        LL  v = 0;
        if(seg[rgt].l)
            v = seg[rgt].l - st + 1;
        else if(seg[rgt].r)
            v = seg[rgt].r - st + 1;
        seg[ind].val = max(seg[ind].val, v);
    }
    else if(seg[rgt].l == 0 && seg[rgt].r == 0)
    {
        LL  v = 0;
        if(seg[lft].r)
            v = ed - seg[lft].r + 1;
        else if(seg[lft].l)
            v = ed - seg[lft].l + 1;
        seg[ind].val = max(seg[ind].val, v);
    }
}

void init2(LL  ind, LL  st, LL  ed)
{
    if(st == ed)
    {
        seg2[ind].l = seg2[ind].r = 0;
        seg2[ind].val = 1;
        return;
    }

    LL  mid = (st + ed)/2;
    LL  lft = ind * 2;
    LL  rgt = lft + 1;
    init2(lft, st, mid);
    init2(rgt, mid + 1, ed);

    if(seg2[lft].l)
        seg2[ind].l = seg2[lft].l;

    else if(seg2[lft].r)
        seg2[ind].l = seg2[lft].r;
    else if(seg2[rgt].l)
        seg2[ind].l = seg2[rgt].l;
    else if(seg2[rgt].r)
        seg2[ind].l = seg2[rgt].r;


    if(seg2[rgt].r)
        seg2[ind].r = seg2[rgt].r;

    else if(seg2[rgt].l)
        seg2[ind].r = seg2[rgt].l;


    else if(seg2[lft].r)
        seg2[ind].r = seg2[lft].r;

    else if(seg2[lft].l)
        seg2[ind].r = seg2[lft].l;




    seg2[ind].val = max(seg2[lft].val, seg2[rgt].val);
    seg2[ind].val = max(seg2[ind].val,  seg2[rgt].l - seg2[lft].r);
    if(seg2[ind].l == 0 && seg2[ind].r == 0)
        seg2[ind].val = ed - st + 1;
    else if(seg2[lft].l == 0 && seg2[lft].r == 0)
    {
        LL  v = 0;
        if(seg2[rgt].l)
            v = seg2[rgt].l - st;
        else if(seg2[rgt].r)
            v = seg2[rgt].r - st;
        seg2[ind].val = max(seg2[ind].val, v);
    }
    else if(seg2[rgt].l == 0 && seg2[rgt].r == 0)
    {
        LL  v = 0;
        if(seg2[lft].r)
            v = ed - seg2[lft].r;
        else if(seg2[lft].l)
            v = ed - seg2[lft].l;
        seg2[ind].val = max(seg2[ind].val, v);
    }
}



void insertw(LL  ind, LL  st, LL  ed, LL  pos)
{
    if(st == pos && ed == pos)
    {
        seg2[ind].l = seg2[ind].r = pos;
        seg2[ind].val = 1;
        return;
    }

    LL  mid = (st + ed)/2;
    LL  lft = ind * 2;
    LL  rgt = lft + 1;
    if(pos <= mid)
        insertw(lft, st, mid, pos);
    else
        insertw(rgt, mid + 1, ed, pos);

    if(seg2[lft].l)
        seg2[ind].l = seg2[lft].l;
    else if(seg2[lft].r)
        seg2[ind].l = seg2[lft].r;
    else if(seg2[rgt].l)
        seg2[ind].l = seg2[rgt].l;
    else if(seg2[rgt].r)
        seg2[ind].l = seg2[rgt].r;


    if(seg2[rgt].r)
        seg2[ind].r = seg2[rgt].r;

    else if(seg2[rgt].l)
        seg2[ind].r = seg2[rgt].l;


    else if(seg2[lft].r)
        seg2[ind].r = seg2[lft].r;

    else if(seg2[lft].l)
        seg2[ind].r = seg2[lft].l;




    seg2[ind].val = max(seg2[lft].val, seg2[rgt].val);

    if(seg2[rgt].l && seg2[lft].r)
        seg2[ind].val = max(seg2[ind].val,  seg2[rgt].l - seg2[lft].r);

    if(seg2[ind].l == 0 && seg2[ind].r == 0)
        seg2[ind].val = ed - st + 1;
    else if(seg2[lft].l == 0 && seg2[lft].r == 0)
    {
        LL  v = 0;
        if(seg2[rgt].l)
            v = seg2[rgt].l - st + 1;
        else if(seg2[rgt].r)
            v = seg2[rgt].r - st + 1;
        seg2[ind].val = max(seg2[ind].val, v);
    }
    else if(seg2[rgt].l == 0 && seg2[rgt].r == 0)
    {
        LL  v = 0;
        if(seg2[lft].r)
            v = ed - seg2[lft].r + 1;
        else if(seg2[lft].l)
            v = ed - seg2[lft].l + 1;
        seg2[ind].val = max(seg2[ind].val, v);
    }
}




int  main()
{
    LL  i, j, k;
    LL  n, num;
    string str;
    LL  w, h, val;
    char op;
    cin>>w>>h>>n;
    init(1, 1, w);
    inserth(1, 1, w, w);
    insertw(1, 1, h, h);


    while(n--)
    {
        cin>>op>>val;
        if(op == 'V')
        {
            inserth(1, 1, w, val);
        }
        else{
            insertw(1, 1, h, val);
        }
        cout<<seg[1].val*seg2[1].val<<endl;
    }



    return 0;
}

/*

4 3 4
H 2
V 2


*/
