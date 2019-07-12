#include<bits/stdc++.h>

#define xx first
#define yy second
#define vsort(v) sort(v.begin(),v.end())
#define clr(a,k) memset(a,k,sizeof a)
#define bclr(b) memset(b,false,sizeof b)
#define LL long long
#define ll long long
#define PB push_back
#define MP make_pair
#define mp make_pair
#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d %d", &a, &b)
#define MOD 1000000007
#define MAX 50009

using namespace std;

struct Z
{
    int a, b, p;
} L[MAX];

int P[100][MAX];
string str;
int stp, cnt, NN;
int comp(Z A, Z B)
{
    return A.a == B.a?(A.b < B.b?1:0):(A.a < B.a?1:0);
}


int lcp(int x, int y)   /// actual position of x, y
{
    int ret = 0;
    for(int i = stp - 1; i >= 0 && x < NN && y < NN; i--)
    {
        if(P[i][x] == P[i][y])
        {
            ret += (1ll<<(ll)i);
            x += (1ll<<(ll)i);
            y += (1ll<<(ll)i);
        }
    }
    return ret;
}

void suffix_array(string str)
{
    int  i;
    int N = str.length();
    NN = N;
    stp = 0;

    for(i = 0; i < N; i++)
        P[0][i] = str[i] - 'a';

    for(stp = 1, cnt = 1; cnt < N; stp++, cnt = cnt * 2)
    {
        for(i = 0; i < N; i++)
        {
            L[i].a = P[stp - 1][i];
            L[i].b = i + cnt < N ? P[stp - 1][i + cnt] : -1;
            L[i].p = i;
        }
        sort(L, L + N, comp);

        for(i = 0; i < N; i++)
            P[stp][L[i].p] = i > 0 && L[i].a == L[i - 1].a && L[i].b == L[i - 1].b ? P[stp][L[i-1].p] : i;
    }
}


char txt[MAX], pat[MAX];
int F[MAX];




void FailureFunction()
{
    int i = 1, j = 0;
    F[0] = 0;
    memset(F, 0, sizeof F);
    int m = strlen(pat);
    while(i < m)
    {
        if(pat[i] == pat[j])
        {
            F[i] = j + 1;
            i++;
            j++;
        }
        else if(j > 0)
        {
            j = F[j - 1];
        }
        else
        {
            F[i] = 0;
            i++;
        }
    }
}

int last[MAX];
int nxt[MAX];

void KMP()
{
    int i = 0, j = 0;
    FailureFunction();
    int n = strlen(txt);
    int m = strlen(pat);
    memset(last, -1, sizeof last);

    while(i < n)
    {
        if(txt[i] == pat[j])
        {
            if(j == m - 1)
            {
                last[i] = i;
                i++;
                j = F[j];
            }
            else
            {
                i++;
                j++;
            }
        }
        else if(j > 0)
        {
            j = F[j - 1];
        }
        else
            i++;
    }
}

int pos[MAX];

int main()
{

    int i, j;
    int t, cases = 1;
    sc(t);
    while(t--)
    {
        scanf("%s %s", txt, pat);
        KMP();
        int len = strlen(txt);
        suffix_array(txt);
        int l = len;
        int len2 = strlen(pat);
        for(i = len - 1; i >= 0; i--)
        {
            if(last[i + len2 - 1] != -1)
                l = i;
            nxt[i] = l;
        }

        for(i = 0; i < len; i++)
            pos[ P[stp - 1][i] ] = i;

        int sum = min(len,  nxt[ pos[0] ] + len2 - 1) - pos[0];
        for(i = 1; i < len; i++)
        {
            int k = min(len,  nxt[ pos[i] ] + len2 - 1) - pos[i] - lcp( pos[i - 1], pos[i] );
            if(k > 0)
                sum += k;
        }
        printf("Case %d: %d\n", cases++, sum);

    }
    return 0;
}

/*

4
ababa
ba
ababa
a
abbabaaaba
aa
ababababa
babasdfasdf





1
bbbbabbbb
c

*/
