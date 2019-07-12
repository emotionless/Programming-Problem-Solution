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

using namespace std;
char txt[MAX], pat[MAX];
int F[MAX];

void FailureFunction()
{
    int i = 1, j = 0;
    F[0] = 0;
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
int KMP()
{
    int i = 0, j = 0;
    int cnt = 0;
    FailureFunction();
    int n = strlen(txt);
    int m = strlen(pat);
    while(i < n)
    {
        if(txt[i] == pat[j])
        {
            if(j == m - 1)
            {
                cnt++;
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
    return cnt;
}

int main()
{

    int i, j, k;
    int t, cases = 1;
    sc(t);
    while(t--)
    {
        scanf("%s %s", txt, pat);
        printf("Case %d: %d\n", cases++, KMP());
    }
return 0;
}

/*


*/
