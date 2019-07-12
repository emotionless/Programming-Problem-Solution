#include <bits/stdc++.h>

#define LL long long
#define MX 100001
#define MD 1000000007
#define check_bit(a,b) (a & (1<<b))
#define PB push_back
#define FOR(aa,nn) for(aa=0; aa<nn; aa++)
#define vi vector<int>
#define vll vector<long long>
#define MXLOG log(MX)


using namespace std;
char str[MX + 2];
int high_limit, low_limit;


struct Z
{
    int nr[2];
    int p;
} L[MX];

int P[25][MX];
int stp, sz, cnt;

int cmp(struct Z a, struct Z b)
{
    return a.nr[0]==b.nr[0] ?(a.nr[1]<b.nr[1] ?1: 0): (a.nr[0]<b.nr[0] ?1: 0);
}

void suffix_Lay()
{
    int i, j, k;

    for(i=0; i < sz; i++)
        P[0][i]=str[i] - 'A';

    for(stp = 1, cnt = 1; cnt < sz; cnt = cnt * 2, stp++)
    {
        for(i = 0; i < sz; i++)
        {
            L[i].nr[0] = P[stp - 1][i];
            L[i].nr[1] = i + cnt < sz ? P[stp - 1][i + cnt] : -1;
            L[i].p=i;
        }
        sort(L, L + sz, cmp);
        for(i = 0; i < sz; i++)
            P[stp][L[i].p] = i > 0 && L[i].nr[0] == L[i-1].nr[0] && L[i].nr[1] == L[i-1].nr[1] ? P[stp][L[i-1].p] : i;
    }
}

int find_low(int cur)
{
    char ch = str[cur];
    int low = low_limit, high = high_limit, mid, ret;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(L[mid].p + cur < sz && str[L[mid].p + cur] > ch)
            high = mid - 1;
        else if(L[mid].p + cur < sz && str[L[mid].p + cur] < ch)
            low = mid + 1;
        else if(L[mid].p + cur < sz && str[L[mid].p + cur] == ch)
            high = mid - 1, ret = mid;
        else
            low = mid + 1;
    }
    return ret;
}


int find_high(int cur)
{
    char ch = str[cur];
    int low = low_limit, high = high_limit, mid, ret;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(L[mid].p + cur < sz && str[L[mid].p + cur] > ch)
            high = mid - 1;
        else if(L[mid].p + cur < sz && str[L[mid].p + cur] < ch)
            low = mid + 1;
        else if(L[mid].p + cur < sz && str[L[mid].p + cur] == ch)
            low = mid + 1, ret = mid;
        else
            low = mid + 1;
    }
    return ret;
}


int lcp(int id1, int id2)
{
    int j, ret = 0;
    for(j = log2(strlen(str)) + 1; j >= 0; j--)
        if(P[j][id1] == P[j][id2] && id2 < (strlen(str)))
        {
            ret += (1 << j);
            id1 += (1 << j);
            id2 += (1 << j);
        }
    return ret;
}


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int i, j, k;
    gets(str);

    int l=0, r=strlen(str)-1;
    sz = r + 1;
    suffix_Lay();

    low_limit = 0;
    high_limit = r;

    vector< pair<int, int> >res;
    int len=1;
    while(l < sz)
    {
        int low = find_low(l);
        int high = find_high(l);
        if(lcp(0, r) == len)
            res.PB(make_pair(len, high - low + 1));
        low_limit = low;
        high_limit = high;
        r--;
        l++;
        len++;
    }
    int tot=res.size();
    cout<< tot <<endl;

    for(i = 0; i < tot; i++)
        cout<<res[i].first  <<" "<<res[i].second<<endl;
return 0;
}
