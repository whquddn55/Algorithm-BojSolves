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

int n;
vector<pii> arr;
int l, p;

int main() {
	scanf("%d", &n);
	arr.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &arr[i].first, &arr[i].second);

	sort(arr.begin(), arr.end());
	scanf("%d %d", &l, &p);
	arr.emplace_back(l, 0);
	n++;

	int cnt = 0;
	while (true) {
		int idx = upper_bound(arr.begin(), arr.end(), make_pair(p, INF)) - arr.begin();
		if (idx == n)
			break;

		int maxValue = -INF;
		int maxIdx;
		for (int i = 0; i < idx; i++)
			if ((arr[i].second != -1) && (maxValue < arr[i].second)) {
				maxValue = arr[i].second;
				maxIdx = i;
			}

		if (maxValue == -INF) {
			cnt = -1;
			break;
		}

		p += maxValue;
		arr[maxIdx].second = -1;
		cnt++;
	}

	printf("%d\n", cnt);
}