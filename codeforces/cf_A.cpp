#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k, i, num;
    scanf("%d %d", &n, &k);
    int sum = 0;
    for(i = 0; i < n; i++)
    {
        scanf("%d", &num);
        sum += num;
    }
    for(i = 0; i < 1000000; i++)
    {
        int now = sum + i*k;

        int need = round((double)now/(double)(i+n));
//        cout<<i<<" "<<need<<endl;
        if(need >= k)
        {
            printf("%d\n", i);
            return 0;
        }
    }



    return 0;
}


/*

1 100
1
*/
