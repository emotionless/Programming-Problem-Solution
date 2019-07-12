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

LL arr[100001];
LL tmp[100001];

int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i, j;
    int a, b, h, m, n;
    cin>>n;
    map<LL, int>M;
    for(i = 0; i < n; i++)
    {
        cin>>arr[i];
        M[arr[i]] = i;
        tmp[i] = arr[i];
    }
    sort(tmp, tmp + n);
    bool ok = 0;
    int st = 0, ed = 0;
    for(i = 0; i < n; i++)
    {
        if(arr[i] == tmp[i])
        {

        }
        else
        {
            if(ok) continue;
            int ind = M[tmp[i]];
            //cout<<ind<<endl;
            int k = ind;
            st = i;
            ed = k;
            for(j = i; j < k; j++, k--)
            {
                swap(arr[j], arr[k]);
            }
            ok = 1;
        }
    }
    if(st > ed)
        swap(st, ed);
    for(i = 0; i < n; i++)
    {
        if(arr[i] != tmp[i])
        {
            cout<<"no"<<endl;
            return 0;
        }
    }
    cout<<"yes"<<endl;
    cout<<st+1<<" "<<ed+1<<endl;




    return 0;
}

/*

7 3
5 5 5 5 5 5
1 3 4
4 5 2
6 3 1



*/
