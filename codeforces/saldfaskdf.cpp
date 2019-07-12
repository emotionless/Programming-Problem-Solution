#include <iostream>
#include <cstdio>
#include <string>

using namespace std;
const int maxN = 1e5;
typedef int TRes[3];
string s;

void Enter()
{
    getline(cin, s);
}

inline bool Minimize(int& Target, int Value)
{
    bool res = Value < Target;
    if (res) Target = Value;
    return res;
}

string Cal(string s, int Require)
{
    int n, cnt[3], r[3];
    n = s.length();
    fill(begin(cnt), end(cnt), 0);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cnt[(s[i] - '0') % 3]++;
        sum += s[i] - '0';
    }
    int Total = maxN + 1;
    for (int i = 0; i <= min(2, cnt[1]); i++)
        for (int j = 0; j <= min(2, cnt[2]); j++)
            if ((sum - Require - i - j * 2) % 3 == 0 && Minimize(Total, i + j))
            {
                r[1] = i;
                r[2] = j;
            }
    if (Total == maxN + 1)
        return "#";
    string sres = "";
    for (int i = 0; i < n; i++)
    {
        int d = (s[i] - '0') % 3;
        if (d > 0 && r[d] > 0)
            r[d]--;
        else
            sres.push_back(s[i]);
    }
    return sres;
}

void RemoveLZ(string& s)
{
    int i = 0;
    while (i < s.length() - 1 && s[i] == '0') i++;
    s.erase(0, i);
}

void Solve()
{
    string res1 = Cal(s.substr(1, s.length()), -(s[0] - '0'));
    if (res1 != "#") res1 = s[0] + res1;
    else res1 = "";
    string res2 = Cal(s, 0);
    RemoveLZ(res1);
    RemoveLZ(res2);
    string res = res1.length() > res2.length() ? res1 : res2;
    if (res.length() == 0) cout << -1;
    else cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);

    Enter();
    Solve();
    cout<<endl;
    main();
}
/*

1230001
1230002
999
1112
2111
1211
1121
1
11
121
9
90




*/
