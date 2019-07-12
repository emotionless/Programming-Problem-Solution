/*
Username: emotionless
Full name: Faruk Hossain Milon
Email: milonju01@gmail.com, miloniitju@gmail.com

*/


#include <cstring>
#include <cassert>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <climits>

#define LL long long
#define MAX 2000009
#define MD 1000000007
#define N 1000007
#define check_bit(a,b) (a & (1<<b))
#define PB push_back
#define FOR(aa,nn) for(aa=0; aa<nn; aa++)
#define eps 1e-9


using namespace std;

char str[MAX];
char save[MAX];
int F[MAX];


int cycle(char txt[])
{
    int ln = strlen(txt);
    int i = 0, j = 1, k = 0;
    while(i < ln && j < ln)
    {
        if(txt[i + k] == txt[j + k]) k++;
        else if(txt[i + k] < txt[j + k])
        {
            j = j + k + 1;
            k = 0;
        }
        else
        {
            i = j;
            j = i + 1;
            k = 0;
        }
        if(k >= ln) break;
    }
    return min(i, j);
}




int f[MAX];
int Booth(char txt[])
{
    int n = strlen(txt);
    for(int i = 0; i < MAX; i++) f[i] = -1;
    int k = 0;
    for(int j = 1; j < n; j++)
    {
        int i = f[j - k - 1];
        while(i != -1 && txt[j] != txt[k + i + 1])
        {
            if(txt[j] < txt[k + i + 1])
                k = j - i - 1;
            i = f[i];
        }
        if(i == -1 && txt[j] != txt[k + i + 1])
        {
            if(txt[j] < txt[k + i + 1])
                k = j;
            f[j - k] = -1;
        }
        else
            f[j - k] = i + 1;
    }
return k;
}





void FailureFunction(char pat[])
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

//int ans;

int KMP(char txt[], char pat[])
{
    int i = 0, j = 0;
    int cnt = 0;
    memset(F, 0, sizeof F);
    FailureFunction(pat);
    int n = strlen(txt);
    int m = strlen(pat);
    while(i < n - 1)
    {
        if(txt[i] == pat[j])
        {
            if(j == m - 1)
            {
//                cout<<i<<endl;
//                if(ans == -1)
//                    ans = i - n/2 + 1;
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



char txt[MAX], pat[MAX];

char con[] = {'z', 'y', 'x', 'w', 'v', 'u', 't', 's', 'r', 'q', 'p', 'o', 'n', 'm', 'l', 'k', 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a'};

int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    int a,b;

    while(~scanf("%s", txt))
    {
        memset(pat, '\0', sizeof pat);
        int len = strlen(txt);
        strcpy(save, txt);
        int get = Booth(txt);
        for(i = 0; i < len; i++)
            txt[len + i] = txt[i];
        int k = 0;
        for(i = get; i < len; i++)
            pat[k++] = txt[i];
        for(i = 0; i < get; i++)
            pat[k++] = txt[i];

//        ans = -1;
        int fst = KMP(txt, pat);
//        get = ans;
//        ans = -1;
        for(i = 0; i < len; i++)
        {
            save[i] = con[ save[i] - 'a' ];
        }

        int get1 = Booth(save);
        k = 0;
        len = strlen(save);
        for(i = get1; i < len; i++)
            pat[k++] = save[i];
        for(i = 0; i < get1; i++)
            pat[k++] = save[i];
        for(i = 0; i < len; i++)
            save[len + i] = save[i];
//        ans = -1;
        int snd = KMP(save, pat);
//        get1 = ans;
        printf("%d %d %d %d\n", get + 1, fst, get1 + 1, snd);
    }
    return 0;
}

/*


abcdabcd



*/
