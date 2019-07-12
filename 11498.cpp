#include <cstdio>
using namespace std;

int main() {
	for (int queries; scanf("%d", &queries) != EOF && queries;) {
		int x, y; scanf("%d%d", &x, &y);
		for (int i = 0; i < queries; ++i) {
			int nx, ny; scanf("%d%d", &nx, &ny);
			if (nx == x || ny == y) puts("divisa");
			else if (nx > x && ny > y) puts("NE");
			else if (nx < x && ny > y) puts("NO");
			else if (nx < x && ny < y) puts("SO");
			else if (nx > x && ny < y) puts("SE");
		}
	}
	return 0;
}
