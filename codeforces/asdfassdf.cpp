#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = a, _b = b; i <= _b; ++i)
#define FORD(i, a, b) for (int i = a, _b = b; i >= _b; --i)
#define REP(i, a) for (int i = 0, _a = a; i < _a; ++i)
#define llint long long
#define sz(x) (x.size())
#define mp make_pair
#define LL(x) (x * 2)
#define RR(x) (x * 2 + 1)
#define fi first
#define se second
#define db(x) cout << #x << " = " << x << endl;

void openFile() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifdef Tr___
	freopen("sorting.inp", "r", stdin);
	freopen("sorting.out", "w", stdout);
	#endif
}

const int maxN = 5e5 + 5;
const int maxM = 1e6 + 5;
const llint INF = 1e9 + 7;

int N;
int a[maxN];
int pos[maxN];
int root[maxN];
int nNode = 0;
struct node {
	int sum, l, r;
} it[maxN * 100];

void enter() {
	scanf("%d", &N);
	FOR(i, 1, N) {
		scanf("%d", &a[i]);
		pos[a[i]] = i;
	}
}

void update(int &x, int l, int r, int pos) {
	it[++nNode] = it[x]; x = nNode;

	if (l == r) {
		it[x] = (node) {1, 0, 0};
		return;
	}
	int m = (l + r) >> 1;
	if (pos <= m) {
		update(it[x].l, l, m, pos);
	}
	else {
		update(it[x].r, m + 1, r, pos);
	}
	it[x].sum = it[it[x].l].sum + it[it[x].r].sum;
}

int query(int u, int v, int l, int r, int k) {
    cout<<u<<" "<<v<<" "<<l<<" "<<r<<" "<<k<<endl;
	if (l == r) {
		return l;
	}

	int m = (l + r) >> 1;
	int sl = it[it[v].l].sum - it[it[u].l].sum;
	if (k <= sl) return query(it[u].l, it[v].l, l, m, k);
	else return query(it[u].r, it[v].r, m + 1, r, k - sl);
}

llint sorting(int l, int r) {
	if (l >= r) return 0;
	int mid = a[query(root[l - 1], root[r], 1, N, (r - l + 2) / 2)];
	//cout << l << " " << r << " = " << mid << endl;
	return sorting(l, mid - 1) + sorting(mid + 1, r) + r - l + 1;
}

void solve() {
	FOR(i, 1, N) {
		root[i] = root[i - 1];
		update(root[i], 1, N, pos[i]);
	}

	//cout << a[query(root[1], root[3], 1, N, 2)] << endl;
	//return;
	printf("%lld\n", sorting(1, N));
}

int main() {
	openFile();
	enter();
	solve();
	return 0;
}
