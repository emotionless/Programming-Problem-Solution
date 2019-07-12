#include <bits/stdc++.h>

#define LL long long
#define MX 100009
#define clr(aa, bb) memset(aa, bb, sizeof aa)
#define MD 1000000007
#define N 1000007
#define check_bit(a,b) (a & (1<<b))
#define set_bit(a,b) (a | (1<<b))
#define PB push_back
#define FOR(aa,nn) for(aa=0; aa<nn; aa++)
#define vi vector<int>
#define vll vector<long long>


using namespace std;

int val1[300];
int val2[300];

int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i, j;
    int a, b, h, m, n;
    string str;
    string tar;
    cin>>str;
    cin>>tar;
    int len = str.length();
    for(i = 0; i < len; i++)
    {
        val1[str[i] - 'a']++;
    }
    int l = tar.length();

    for(i = 0; i < l; i++)
    {
        val2[tar[i] - 'a']++;
    }
    for(i = 0; i < 300; i++)
    {
        if(val2[i] > val1[i])
        {
            cout<<"need tree"<<endl;
            return 0;
        }
    }

    int cnt = 0;
    j = 0;
    for(i = 0; i < l; i++)
    {
        for(; j < len; j++)
        {
            if(str[j] == tar[i])
            {
                cnt++;
                j++;
                break;
            }
        }
    }
    if(cnt == l && len != l)
    {
        cout<<"automaton"<<endl;
        return 0;
    }

    if(len == l)
        cout<<"array"<<endl;
    else
        cout<<"both"<<endl;



    return 0;
}

/*

7 3
5 5 5 5 5 5
1 3 4
4 5 2
6 3 1



*/
