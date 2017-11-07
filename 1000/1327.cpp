#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int pow(int a, int r) {
	int result = 1;
	while (r--)
		result *= a;

	return result;
}

int reverse(int here, int i, int n, int k) {
	int mod = pow(10, n - 1);

	vector<int> num(n);
	for (int j = 0; j < n; j++) {
		num[j] = here / mod;
		here -= num[j] * mod;
		mod /= 10;
	}

	for (int j = 0; j < k / 2; j++) {
		int temp = num[i + j];
		num[i + j] = num[i + k - 1 - j];
		num[i + k - 1 - j] = temp;
	}

	int result = 0;
	for (int j = 0; j < n; j++) {
		result = result * 10 + num[j];
	}

	return result;
}

vector<bool> visited;

int main() {
	int n, k;
	cin >> n >> k;

	int last = 0;
	int first = 0;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		first = first * 10 + temp;

		last = last * 10 + (i + 1);
	}

	visited.resize((n + 1)*pow(10, n - 1), false);
	queue<pair<int, int> > q;
	visited[first] = true;
	q.push(make_pair(first, 0));


	while (!q.empty()) {
		int here = q.front().first;
		int cost = q.front().second;
		q.pop();
		if (here == last) {
			cout << cost << endl;
			return 0;
		}

		for (int i = 0; i < n - k + 1; i++) {
			int next = reverse(here, i, n, k);
			if (visited[next])
				continue;

			visited[next] = true;
			q.push(make_pair(next, cost + 1));
		}
	}

	cout << -1 << endl;
	return 0;
}
