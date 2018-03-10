#include <bits/stdc++.h>
using std::pair;
using std::vector;
using std::queue;
using std::stack;
using std::priority_queue;
using std::set;
using std::map;
using std::deque;
using std::greater;
using std::max;
using std::min;
using std::sort;
using std::binary_search;
using std::lower_bound;
using std::upper_bound;
using std::reverse;
using std::make_pair;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)

int tc;
int n, m;
vector<int> arr[100001];
vector<int> existPosX;
vector<pii> result;

int main() {
	scanf("%d", &tc);
	while (tc--) {
		existPosX.clear();
		result.clear();
		for (int i = 0; i <= 100000; i++)
			arr[i].clear();

		scanf("%d", &n);
		
		for (int i = 0; i < n; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			arr[x].push_back(y);
		}

		for (int i = 0; i <= 100000; i++)
			if (arr[i].size()) {
				existPosX.push_back(i);
				sort(arr[i].begin(), arr[i].end());
			}

		int hereY = 0;
		for (int i = 0; i < existPosX.size(); i++) {
			int hereX = existPosX[i];

			if (hereY == arr[hereX][0]) {
				for (int i = 0; i < arr[hereX].size(); i++)
					result.emplace_back(hereX, arr[hereX][i]);

				hereY =  arr[hereX][arr[hereX].size() - 1];
			}
			else {
				for (int i = arr[hereX].size() - 1; i >= 0; i--)
					result.emplace_back(hereX, arr[hereX][i]);

				hereY = arr[hereX][0];
			}
		}

		scanf("%d", &m);
		while (m--) {
			int k;
			scanf("%d", &k);
			printf("%d %d\n", result[k - 1].first, result[k - 1].second);
		}
	}
}