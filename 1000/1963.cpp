#include <bits/stdc++.h>
using namespace std;

struct Data {
	int here;
	int cost;
	Data(int here, int cost)
		: here(here), cost(cost) { }
};

int from, to;
vector<bool> isPrime(10000, true);
vector<bool> visited(10000, false);

int bfs() {
	queue<Data> q;
	q.push(Data(from, 0));

	while (!q.empty()) {
		int here = q.front().here;
		int cost = q.front().cost;
		q.pop();

		if (visited[here])
			continue;

		visited[here] = true;

		if (here == to)
			return cost;

		char sNum[5];
		sprintf(sNum, "%d", here);
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j <= 9; j++) {
				if (i == 0 && j == 0)
					continue;

				int next = 0;
				for (int k = 0; k < 4; k++) {
					if (k == i)
						next = next * 10 + j;
					else
						next = next * 10 + (sNum[k] - '0');
				}

				if (visited[next] || !isPrime[next])
					continue;

				q.push(Data(next, cost + 1));
			}
		}
	}

	return -1;
}

int main() {
	for (int i = 1000; i < 10000; i++) 
		for (int j = 2; j < 100; j++) 
			if (i % j == 0) {
				isPrime[i] = false;
				break;
			}


	int tc;
	cin >> tc;
	while (tc--) {
		cin >> from >> to;
		fill(visited.begin(), visited.end(), false);
		cout << bfs() << endl;
	}

	return 0;
}