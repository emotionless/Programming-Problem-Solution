/// *********** Sufffix Array ****************///
/**
LCP = Longest Common Prefix
It takes two index as a perimeter and output
the longest match start from x and y.
**/

struct Z
{
    int a, b, p;
} L[MAX];

string str, tmp[MAX];
int stp = 0, cnt, P[100][MAX];
int comp(Z A, Z B)
{
    return A.a == B.a?(A.b < B.b?1:0):(A.a < B.a?1:0);
}

int lcp(int x, int y)
{
    int ret = 0;
    for(int i = stp - 1; i >= 0; i--)
    {
        if(P[i][x] == P[i][y])
            ret += (1<<i), x += (1<<i), y += (1<<i);
    }
return ret;
}

int main()
{
    int tc,cs=1,i,j,k;
    cin>>str;
    int N = SZ(str);

    for(i = 0; i < N; i++)
        P[0][i] = str[i] - 'a';

    for(stp = 1, cnt = 1; cnt < N; stp++, cnt = cnt * 2)
    {
        for(i = 0; i < N; i++)
        {
            L[i].a = P[stp - 1][i];
            L[i].b = i + cnt < N ? P[stp - 1][i + cnt] : -1;
            L[i].p = i;
        }
        sort(L, L + N, comp);

        for(i = 0; i < N; i++)
            P[stp][L[i].p] = i > 0 && L[i].a == L[i - 1].a && L[i].b == L[i - 1].b ? P[stp][L[i-1].p] : i;
    }
    for(i = 0; i < N; i++)
        tmp[P[stp - 1][i]] = str.substr(i);
    for(i = 0; i < N; i++)
        cout<<i<<" "<<tmp[i]<<endl;
    cout<<lcp(0, 5)<<endl;
    return 0;
}
