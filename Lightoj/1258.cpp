#include<bits/stdc++.h>

#define xx first
#define yy second
#define vsort(v) sort(v.begin(),v.end())
#define clr(a,k) memset(a,k,sizeof a)
#define bclr(b) memset(b,false,sizeof b)
#define LL long long
#define PB push_back
#define MP make_pair
#define mp make_pair
#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d %d", &a, &b)
#define MOD 1000000007
#define MAX 1000009
#define SZ(a) a.size()

using namespace std;

string txt, pat;
int F[MAX];

void FailureFunction()
{
    int i = 1, j = 0;
    F[0] = 0;
    int m = SZ(pat);
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
int KMP()
{
    int i = 0, j = 0;
    FailureFunction();
    int n = SZ(txt);
    int m = SZ(pat);
    while(i < n)
    {
        if(txt[i] == pat[j])
        {


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
    return j;
}

int main()
{

    int i, j, k;
    int t, cases = 1;
    sc(t);
    while(t--)
    {
        cin>>txt;
        int len = SZ(txt);
        pat = txt;
        reverse(pat.begin(), pat.end());
        printf("Case %d: %d\n", cases++, 2*len - KMP());
    }

    return 0;
}

/*

5 5
1 2
2 3
3 4
2 4
2 5

*/
