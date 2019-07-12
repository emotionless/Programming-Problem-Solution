#include<bits/stdc++.h>

#define xx first
#define yy second
#define vsort(v) sort(v.begin(),v.end())
#define clr(a,k) memset(a,k,sizeof a)
#define bclr(b) memset(b,false,sizeof b)
#define fr(i, a) for(i = 0; i < a; i++)
#define frr(i,a) for(i = a - 1; i >= 0, i--)
#define all(a) (a.begin(), a.end())
#define LL long long
#define PB push_back
#define MP make_pair
#define MOD 1000000007
#define MX 5009
#define mp make_pair


using namespace std;

int arr[MX];


int main()
{

    int i, j, k;
    int t, cases = 1;
    int n, m;
    LL a, b;
    cin>>n;
    vector<int>fst, snd, thd;
    fr(i, n)
    {
        cin>>arr[i];
        if(arr[i] == 1)
            fst.PB(i + 1);

        if(arr[i] == 2)
            snd.PB(i + 1);
        if(arr[i] == 3)
            thd.PB(i + 1);
    }
    cout<<min(fst.size(), min(snd.size(), thd.size()))<<endl;
    for(i = 0; i < fst.size() && i < snd.size() && i < thd.size(); i++)
    {
        cout<<fst[i]<<" "<<snd[i]<<" "<<thd[i]<<endl;
    }





    return 0;
}

/*

5
9 2 3 4 6
5
10 7 3 2 1
*/
