#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_SIZE 21

struct Data {
	int a, b, c;
	bool operator<(const Data& other) {
		return c < other.c;
	}
};

int n;
int arr[MAX_SIZE][MAX_SIZE];
Data sorted[MAX_SIZE * MAX_SIZE / 2];
int dist[MAX_SIZE][MAX_SIZE];

bool floyd() {
	bool ret = false;
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					ret = true;
					dist[i][j] = dist[i][k] + dist[k][j];
				}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) 
			cin >> arr[i][j];
		
	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++) {
			sorted[cnt].a = i;
			sorted[cnt].b = j;
			sorted[cnt++].c = arr[i][j];
		}
		

	sort(sorted, sorted + n * (n - 1) / 2);

	fill(&dist[0][0], &dist[0][0] + MAX_SIZE * MAX_SIZE, INF);
	for (int i = 0; i < n; i++)
		dist[i][i] = 0;

	int ans = 0;
	for (int i = 0; i < n * (n - 1) / 2; i++) {
		int t = dist[sorted[i].b][sorted[i].a];
		if (t > sorted[i].c) {
			dist[sorted[i].a][sorted[i].b] = dist[sorted[i].b][sorted[i].a] = sorted[i].c;
			ans += sorted[i].c;
			floyd();
		}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (arr[i][j] != dist[i][j])
				ans = -1;

	cout << ans << endl;

	return 0;
}
