#include<bits/stdc++.h>

#define xx first
#define yy second
#define all(a) a.begin(), a.end()
#define vsort(v) sort(all(v))
#define UNIQUE(a)  sort(all(a)); a.erase(unique(all(a)), a.end())
#define clr(a,k) memset(a,k,sizeof a)
#define bclr(b) memset(b,false,sizeof b)
#define fr(i, a) for(i = 0; i < a; i++)
#define frr(i,a) for(i = a - 1; i >= 0, i--)
#define LL long long
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define vi vector<int>
#define vll vector<long long>
///***** bit *****///
#define check_bit(a, b) (a&(1<<b))
#define set_bit(a, b) (a|(1<<b))
#define total_bit(a) __builtin_popcount(a)
///***** Input / Output *****///
#define s1(a) scanf("%d", &a)
#define s2(a, b) scanf("%d %d", &a, &b)
#define s3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define p1(a) printf("%d", a)
#define p2(a, b) printf("%d %d", a, b)
#define p3(a, b, c) printf("%d %d %d", a, b, c)

#define MOD 1000000007
#define MAX 200009


using namespace std;

int arr[330];
int tmp[330];

int main()
{
    int tc,cs=1,i,j,k;
    int n,m;
    string str;

    cin>>n;
    for(i = 0; i < n; i++){
        cin>>arr[i];
        tmp[i] = arr[i];
    }

    int pre = 0;

    for(i = 0; i < n; i++)
    {
        vi V;
        V.clear();
        while(arr[i]>0)
        {
            int mn = min(arr[i], 9);
            arr[i] -= mn;
            V.pb(mn);
        }

        int sz = V.size();
        if(tmp[i] > tmp[i - 1])
        {
            for(j = sz - 1; j >= 0; j--)
                cout<<V[j];
            cout<<endl;
            pre = sz;
            continue;
        }
        if(sz == 1)
        {
            int len = 1;
            cout<<1;
            for(j = 0; j < pre - sz; j++, len++)
            cout<<0;
            cout<<V[0] - 1<<endl;
            len++;
            pre = len;
            continue;
        }
        int len = 1;
        cout<<V[sz - 1];
        for(j = 0; j < pre + 1 - sz; j++)
        {
            cout<<0;
            len++;
        }
        for(j = 0; j < sz - 1; j++, len++)
            cout<<V[j];
        pre = len;
        cout<<endl;
    }








    return 0;
}

/*

2
3
2


*/
