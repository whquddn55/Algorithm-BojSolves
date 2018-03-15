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
using std::fill;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)

vector<pair<pii, int> > line;
vector<bool> result;

bool comp(const pair<pii, int>& p1, const pair<pii, int> & p2) {
	return (p1.first.first == p2.first.first) ? (p1.first.second > p2.first.second) : p1.first.first < p2.first.first;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	int minValue = 0;
	for (int i = 0; i < m; i++) {
		int from, to;
		scanf("%d %d", &from, &to);

		if (from < to) {
			line.emplace_back(make_pair(from, to), i + 1);
		}
		else {
			minValue = max(minValue, to);
			line.emplace_back(make_pair(from, to + n), i + 1);
		}
	}

	sort(line.begin(), line.end(), comp);

	result.resize(m + 1, true);
	int maxValue = -1;
	for (int i = 0; i < line.size(); i++) {
		if (line[i].first.second <= maxValue || line[i].first.second <= minValue)
			result[line[i].second] = false;
		else
			maxValue = max(maxValue, line[i].first.second);
	}

	for (int i = 1; i <= m; i++)
		if (result[i])
			printf("%d ", i);

	return 0;
}
