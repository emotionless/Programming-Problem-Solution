#include<bits/stdc++.h>

#define LL long long
#define MAX 100009
#define PB push_back

using namespace std;

vector<int>store[12];
int arr[23];
int main()
{
    int i, j;
    int t;
    int n, m;
    scanf("%d", &t);
    while(t--)
    {
        LL num;
        int a, b, x;
        int s = 0;
        int sum = 0;
        for(i = 0; i < 22; i++)
        {
            scanf("%d", &arr[i]);
            sum += arr[i];
        }
        for(i = 0; i < 12; i++)
            store[i].clear();
        int mid = sum/2;
        for(i = 0; i < (1<<11); i++)
        {
            int bit = __builtin_popcount(i);
            s = 0;
            for(j = 0; j < 11; j++)
                if(i & (1<<j))
                {
                    s += arr[j + 11];
                }
            if(s > mid) continue;
//        cout<<"sdfsad"<<endl;
            store[bit].push_back(s);

        }
        int mx = 0;
        for(i = 0; i < 12; i++)
            sort(store[i].begin(), store[i].end());
//    for(i = 0; i < store[5].size(); i++)
//        cout<<store[5][i]<<" ";

        for(i = 0; i < 1<<11; i++)
        {
            int bit = __builtin_popcount(i);
            s = 0;
            for(j = 0; j < 11; j++)
                if(i & (1<<j))
                {
                    s += arr[j];
                }
            if(s > mid) continue;
            int get = upper_bound(store[11-bit].begin(), store[11-bit].end(), mid - s) - store[11-bit].begin();
            get = min(get-1, (int)store[11-bit].size() - 1);
            if(get < 0) continue;
//        if(s + store[11-bit][get] > mx)
//        {
//            cout<<s<<" "<<store[11-bit][get]<<" "<<i<<endl;
//        }
            mx = max(mx, s + store[11-bit][get]);
//        cout<<i<<" "<<mx<<" "<<get<<endl;
//        cout<<"sdf"<<endl;
        }
        printf("%d\n", sum - 2*mx);
    }






    return 0;
}

/*



1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1



*/
