#include <cstdio>
#include <algorithm>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

#define MAXN 65536
#define MAXLG 17

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


int main()
{
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
        cout<<i<<" "<<P[stp - 1][i]<<endl;
//        cout<<i<<" "<<A.substr(P[stp-1][i])<<endl;
    }


    cout<<find_LCP(0,3);


    return 0;
}
//    bcacbadab
//    ababa
