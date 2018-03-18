#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

int n, cntOfK = 0;
vector<vector<pair<char, int>>> arr;
vector<int> seq;
vector<bool> c;
pii startPoint;

int dy[] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };

bool dicide(int minValue, int mid) {
	vector<vector<bool>> visited(n, vector<bool>(n, false));
	queue<pii> q;
	if ((arr[startPoint.first][startPoint.second].second < minValue) || 
		(arr[startPoint.first][startPoint.second].second > (minValue + mid)))
		return false;
	q.emplace(startPoint);
	visited[startPoint.first][startPoint.second] = true;

	int cnt = 0;
	while (!q.empty()) {
		int hereY = q.front().first;
		int hereX = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nextY = hereY + dy[i];
			int nextX = hereX + dx[i];

			if (nextY >= n || nextY < 0 || nextX >= n || nextX < 0)
				continue;
			if (visited[nextY][nextX])
				continue;
			
			if (arr[nextY][nextX].second < minValue || arr[nextY][nextX].second > (minValue + mid)) {
				if (arr[nextY][nextX].first == 'K')
					return false;
				continue;
			}

			q.emplace(nextY, nextX);
			visited[nextY][nextX] = true;
			if (arr[nextY][nextX].first == 'K')
				cnt++;
		}
	}
	return (cnt == cntOfK);
}

int binarySearch(int minValue, int maxValue) {
	int left = minValue, right = maxValue;

	while (left <= right) {
		int mid = (left + right) / 2; // diff
			
		bool ret = false;
		for (int i = 0; (i < seq.size()) && !ret; i++) // bfs의 최소값
			ret = dicide(seq[i], mid);

		if (ret)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return left;
}

bool cut(int n) {
	if (c[n])
		return true;
	return !(c[n] = true);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	c.resize(1000001, false);
	cin >> n;
	arr.resize(n, vector<pair<char, int>>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j].first;
			if (arr[i][j].first == 'P')
				startPoint = { i, j };
			if (arr[i][j].first == 'K')
				cntOfK++;
		}

	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j].second;
			seq.push_back(arr[i][j].second);
		}

	seq.erase(remove_if(seq.begin(), seq.end(), cut), seq.end());
	sort(seq.begin(), seq.end());

	int minValue = INF;
	int maxValue = 0;
	for (int i = 0; i < seq.size(); i++)
		for (int j = i + 1; j < seq.size(); j++) {
			minValue = min(minValue, abs(seq[i] - seq[j]));
			maxValue = max(maxValue, abs(seq[i] - seq[j]));
		}

	cout << binarySearch(0, maxValue - minValue);

	return 0;
}
