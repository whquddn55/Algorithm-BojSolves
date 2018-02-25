#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)

int n, m;
vector<pii> arr;
int a, b;
vector<vector<int>> canGo;
vector<vector<int>> floorGo;
vector<int> previous;

pii bfs() {
	queue<pair<pii, pii>> q; // first.first : here, first.second : prev, second.first : cost, second.second : type
	// type 0 : 엘리베이터, type 1 : 층
	vector<int> visited1(m, false);
	vector<int> visited2(n, false);
	for (int i = 0; i < floorGo[a].size(); i++) {
		q.emplace(make_pair(floorGo[a][i], floorGo[a][i]), make_pair(1, 0));
		visited1[floorGo[a][i]] = true;
		previous[floorGo[a][i]] = floorGo[a][i];
	}
	
	while (!q.empty()) {
		int here = q.front().first.first;
		int prev = q.front().first.second;
		int cost = q.front().second.first;
		int type = q.front().second.second;
		q.pop();

		if (type == 0) {

			for (int i = 0; i < canGo[here].size(); i++) {
				if (visited2[canGo[here][i]])
					continue;
				
				visited2[canGo[here][i]] = true;
				q.emplace(make_pair(canGo[here][i], here), make_pair(cost, 1));
			}
		}
		else {
			if (here == b)
				return { prev, cost };

			for (int i = 0; i < floorGo[here].size(); i++) {
				if (visited1[floorGo[here][i]])
					continue;

				visited1[floorGo[here][i]] = true;
				previous[floorGo[here][i]] = prev;
				q.emplace(make_pair(floorGo[here][i], prev), make_pair(cost + 1, 0));
			}
		}
	}
	return { -1, -1 };
}

void print(int here) {
	if (previous[here] != here)
		print(previous[here]);
	printf("%d\n", here + 1);
}

int main() {
	scanf("%d %d", &n, &m);
	arr.resize(m);
	canGo.resize(m);
	previous.resize(m);
	for (int i = 0; i < m; i++)
		scanf("%d %d", &arr[i].first, &arr[i].second);
	scanf("%d %d", &a, &b);

	for (int i = 0; i < m; i++)
		for (int j = arr[i].first; j <= n; j += arr[i].second)
			canGo[i].push_back(j);

	floorGo.resize(n + 1);
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < m; j++)
			if ((i - arr[j].first) % arr[j].second == 0)
				floorGo[i].push_back(j);

	pii result = bfs();
	printf("%d\n", result.second);
	if (result.second != -1) {
		print(result.first);
	}


	return 0;

}
