#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    ios::sync_with_stdio(0);

    string month[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    map<string, int> m;

    for(int i = 0;i < 12;++i)
        m[ month[i] ] = i;

    int T;
    string s;
    char c;
    int d,y1,y2;

    cin >> T;

    for(int tc = 1;tc <= T;++tc){
        cin >> s >> d >> c >> y1;

        if(m[s] > 1) ++y1;

        cin >> s >> d >> c >> y2;

        if(m[s] < 1 || (m[s] == 1 && d < 29)) --y2;

        int ans = y2 / 4 - (y1 - 1) / 4;
        ans -= y2 / 100 - (y1 - 1) / 100;
        ans += y2 / 400 - (y1 - 1) / 400;

        cout << "Case " << tc << ": " << ans << '\n';
    }

    return 0;
}
