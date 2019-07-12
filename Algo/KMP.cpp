///******** KMP (N + M) ***************///
/**
Given a text string and a pattern string.
Output how many times the pattern string
occurs in the given string.
**/
#include <bits/stdc++.h>
#define MAX 1000

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
    cin>>t;
    while(t--)
    {
        scanf("%s %s", txt, pat);
        printf("Case %d: %d\n", cases++, KMP());
    }
return 0;
}

/**
1
abcdabcd
bc

Output:
2
**/
