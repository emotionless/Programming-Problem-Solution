#include <bits/stdc++.h>

#define LL long long
#define MX 5000+7
#define MOD 1000000007
#define N 1000007
#define check_bit(a,b) (a & (1<<b))
#define PB push_back
#define FOR(aa,nn) for(aa=0; aa<nn; aa++)


using namespace std;


int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    int a,b;

    int n;
    set<char[]>S;
    scanf("%d", &n);
    string str;
    char str1[10];
    for(i = 0; i < n; i++)
    {
        scanf("%s", str1);
        str = str1;
        S.insert(str1);
    }
    int sz = S.size();
    printf("%d\n", sz);

    while(!S.empty())
    {
        cout<< (*S.begin())<<endl;
        S.erase(S.begin());
    }

    return 0;
}

/*

4544545454

*/
