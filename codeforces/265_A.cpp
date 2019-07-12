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
    cin>>n;
    string str;
    cin>>str;
    bool is = false;
    int cnt = 0;
    for(i = 0; i < str.length(); i++)
    {
        if(!is)
        {
            cnt++;
            if(str[i] == '0') break;
        }
    }
    cout<<cnt<<endl;




    return 0;
}

/*


4 4
4 4 4 4



*/
