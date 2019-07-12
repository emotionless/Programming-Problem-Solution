#include <cstdio>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int n;
int a[128];
int m;
char t[32];
int who[32];

int u[22][1 << 20];
int dp[22][1 << 20];

void read() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		cin>>t[i]>>who[i];
	}
}

int go(int x, int mask) {
	if (x == m) {
		return 0;
	}

	if (u[x][mask]) return dp[x][mask];
	u[x][mask] = 1;
	int &ans = dp[x][mask];

	if (who[x] == 2) {
		ans = 1 << 30;
	} else {
		ans = -(1 << 30);
	}

	if (t[x] == 'b') {
		for (int i = 0; i < m; i++) {
			if (!(mask & (1 << i))) {
				int cur = go(x + 1, mask | (1 << i));

				if (who[x] == 2) {
					ans = min(ans, cur);
				} else {
					ans = max(ans, cur);
				}
			}
		}
	} else {
		for (int i = 0; i < m; i++) {
			if (!(mask & (1 << i))) {
				int cur = go(x + 1, mask | (1 << i));

				if (who[x] == 2) {
					ans = min(ans, cur - a[i]);
				} else {
					ans = max(ans, cur + a[i]);
				}
			}
		}
	}
	cout<<x<<" "<<mask<<" "<<ans<<endl;

	return ans;
}

void solve() {
	sort(a, a + n);
	reverse(a, a + n);
	printf ("%d\n", go(0, 0));
}

int main() {
	read();
	solve();

	return 0;
}
