#include <bits/stdc++.h>
using namespace std;

struct Data {
	int end;
	int weight;
	Data (int end, int weight)
		: end(end), weight(weight) { }
};

int n, m;
int from, to;
vector<vector<Data> > bridges; 
vector<bool> visited;

// mid 무게로 from에서 to로 지날 수 있는가?
bool decision(int mid) {
	queue<int> q;
	q.push(from);

	while (!q.empty()) {
		int here = q.front();
		q.pop();

		if (visited[here])
			continue;

		visited[here] = true;
		if (here == to) 
			return true;

		for (int i = 0; i < bridges[here].size(); i++) {
			int there = bridges[here][i].end;
			int weight = bridges[here][i].weight;

			if (weight < mid)
				continue;
			if (visited[there])
				continue;

			q.push(there);
		}
	}
	return false;
}

int binarySearch(int maxValue) {
	int left = 1, right = maxValue;

	while (left <= right) {
		int mid = (right + left) / 2;
		for (int i = 1; i <= n; i++)
			visited[i] = false;

		if (decision(mid)) 
			left = mid + 1;
		else
			right = mid - 1;
	}

	return right;
}

int main() {
	cin >> n >> m;

	bridges.resize(n + 1);
	visited.resize(n + 1, false);

	int maxValue = 0;
	for (int i = 0; i < m; i++) {
		int start, end, weight;
		cin >> start >> end >> weight;

		bridges[start].push_back(Data(end, weight));
		bridges[end].push_back(Data(start, weight));
		maxValue = max(maxValue, weight);
	}

	cin >> from >> to;

	cout << binarySearch(maxValue) << endl;

	return 0;
}