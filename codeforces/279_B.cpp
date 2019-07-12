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
#define MX 1000009
#define mp make_pair


using namespace std;



int main()
{

    int i, j, k;
    int t, cases = 1;
    int n, m;
    LL a, b;
    cin>>n;
    vector<int>save;
    map<int, int>M, R;
    for(i = 0; i < n; i++)
    {
        cin>>a>>b;
        save.PB(a);
        save.PB(b);
        M[a] = b;
        R[b] = a;
    }
    int cn = 0;
    i = 1;
    while(R.find(cn) != R.end() && (i || cn))
    {
        i = 0;
        cn = R[cn];
    }

    // cout<<cn<<endl;

    int fst = cn, snd;
    for(i = 0; i < save.size(); i++)
    {
        cn = save[i];
        // cout<<"FFOR: "<<cn<<endl;
        while(R.find(cn) != R.end() && cn)
        {
            cn = R[cn];
            // cout<<cn<<endl;
        }
        if(cn != fst)
        {
            snd = cn;
            break;
        }
    }
    int f= fst, s = snd;
    int cnt  = 0;
    while(cnt < n)
    {
        if(f == 0)
        {
            if(snd)
            {
                cout<<snd<<" ";
                cnt++;
            }
            fst = M[fst];
            if(fst)
            {
                cout<<fst<<" ";
                cnt++;
            }
            snd = M[snd];
        }
        else
        {
            if(fst)
            {
                cout<<fst<<" ";
                cnt++;
            }
            snd = M[snd];
            if(snd)
            {
                cout<<snd<<" ";
                cnt++;
            }
            fst = M[fst];
        }
    }





    return 0;
}

/*


5
92 31
0 7
31 5
7 141
141 0

*/
