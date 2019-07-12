#include <bits/stdc++.h>

#define LL long long
#define MX 100009
#define clr(aa, bb) memset(aa, bb, sizeof aa)
#define MD 1000000007
#define check_bit(a,b) (a & (1<<b))
#define set_bit(a,b) (a | (1<<b))
#define PB push_back
#define FOR(aa,nn) for(aa=0; aa<nn; aa++)
#define vi vector<int>
#define vll vector<long long>
#define mp make_pair
#define pi pair<int, int>


using namespace std;

int main()
{

    int i, j, k;
    int n, x, y;
    int p;
    string str;
    cin>>n>>p;
    cin>>str;
    string save = str;
    reverse(str.begin(), str.end());
    int st = -1;
    for(i = 0; i < n; i++)
    {
        char cc = str[i];
        //cout<<endl<<"FOR "<<cc<<endl<<endl;
        for(j = cc + 1; j <= 'a' + p - 1 && j <= 'z'; j++)
        {
            if((j == str[i + 1]) || (j == str[i + 2]))continue;
        st = j;
            break;
        }
        if(st != -1) break;
    }
   // cin>>x;
    //cout<<(char)st<<endl;
    if(st == -1)
    {
        cout<<"NO"<<endl;
        return 0;
    }

    str[i] = st;
    j = i - 1;
    for(i = j; i >= 0; i--)
    {
        int pre1 = str[i + 1];
        int pre2 = str[i + 2];
       // cout<<i<<" "<<pre1<<" "<<pre2<<endl;
        for(k = 'a'; k <= 'a' + p - 1; k++)
        {
            if(k == pre1 || k == pre2) continue;
            str[i] = (char)k;
            break;
        }
        if(k > 'z')
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    reverse(str.begin(), str.end());
    cout<<str<<endl;







    return 0;
}

/*


4 4
4 4 4 4



*/
