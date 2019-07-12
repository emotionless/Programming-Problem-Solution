#include <cstdio>
#include <algorithm>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

#define MAXN 100009
#define MAXLG 21

string A;

struct entry
{
    int nr[2];
    int p;
} L[MAXN];

int P[MAXLG][MAXN];
int N,i;
int stp, cnt;

int cmp(struct entry a, struct entry b)
{
    return a.nr[0]==b.nr[0] ?(a.nr[1]<b.nr[1] ?1: 0): (a.nr[0]<b.nr[0] ?1: 0);
}

int find_LCP(int x, int y)
{
    int k=0, ret=0;
    if(x==y) return N-x;

    for(k=stp-1; k>=0 && x<N && y<N; k--)
        if(P[k][x] == P[k][y])
            x += (1 << k), y += (1 << k), ret += (1 << k);
    return ret;
}

int original[100009];
int take[100009];

int main()
{
    int q, u, v;
    cin>>N>>q;
    cin>>A;

    for(N=(A.length()), i = 0; i < N; i++)
        P[0][i] = A[i] - 'a';

//     for(int i=0; i<N; i++)
//    {
//        cout<<P[0][i]<<ends;
//    }


    for(stp=1, cnt = 1; cnt < N; stp++, cnt *= 2)
    {
        for(i=0; i < N; i++)
        {
            L[i].nr[0]=P[stp- 1][i];
            L[i].nr[1]=i +cnt <N? P[stp -1][i+ cnt]:-1;
            L[i].p= i;
        }
        sort(L, L+N, cmp);
        for(i=0; i < N; i++)
            P[stp][L[i].p] = i> 0 && L[i].nr[0]==L[i-1].nr[0] && L[i].nr[1] == L[i- 1].nr[1] ? P[stp][L[i-1].p] : i;
    }

    for(i = 0; i < N; i++)
    {
        original[ P[stp-1] [i] ] = i;
    }
//    cout<<endl;
//    for(i = 0; i < N; i++)
//    {
//        cout<<original[i]<<endl;
////        cout<<i<<" "<<A.substr(P[stp-1][i])<<endl;
//    }


    while(q--)
    {
        cin>>u>>v;
        if(u > v) swap(u, v);
//        if(u > v) assert(0);
        int pre = -1;
        long long res = 0ll;
        int ind = 0;
        for(int i = 0; i < N; i++)
        {
//            cout<<original[i]<<endl;
            if(original[i] >= u && original[i] <= v)
            {
                take[ind++] = original[i];
            }
        }
        res = v - take[0]+1;
        for(i = 1; i < ind; i++)
        {
            res += (v-take[i]+1) - min(find_LCP(take[i], take[i-1]), v - max(take[i], take[i-1]) + 1);
            if(res <= 0) assert(0);
        }
        cout<<res<<endl;

    }









    return 0;
}
//    bcacbadab
//    ababa
