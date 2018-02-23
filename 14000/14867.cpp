#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)

int a, b, toX, toY;
vector<bool> visited[4];

bool decide(int i, int j) {
	if (!i) return visited[0][j];
	if (i == a) return visited[1][j];
	if (!j) return visited[2][i];
	if (j == b) return visited[3][i];
	return false;
}

void checkVisit(int i, int j) {
	if (!i) visited[0][j] = true;
	else if (i == a) visited[1][j] = true;
	else if (!j) visited[2][i] = true;
	else if (j == b) visited[3][i] = true;
}

int bfs() {
	queue<pair<pii, int>> q; // first.first : x, first.second : y, second :cost;
	q.emplace(make_pair(0, 0) , 0);
	
	
	while (!q.empty()) {
		int hereX = q.front().first.first;
		int hereY = q.front().first.second;
		int cost = q.front().second;
		q.pop();

		if (decide(hereX, hereY))
			continue;

		checkVisit(hereX, hereY);
		
		if (hereX == toX && hereY == toY)
			return cost;

		q.emplace(make_pair(a, hereY), cost + 1);
		q.emplace(make_pair(0, hereY), cost + 1);
		q.emplace(make_pair(hereX, b), cost + 1);
		q.emplace(make_pair(hereX, 0), cost + 1);
		
		if (a - hereX >= hereY)
			q.emplace(make_pair(hereX + hereY, 0), cost + 1);
		else
			q.emplace(make_pair(a, hereY - (a - hereX)), cost + 1);
		if (b - hereY >= hereX)
			q.emplace(make_pair(0, hereY + hereX), cost + 1);
		else
			q.emplace(make_pair(hereX - (b - hereY), b), cost + 1);
		
	}
	return -1;
}

int main() {
	scanf("%d %d %d %d", &a, &b, &toX, &toY);

	for (int i = 0; i < 4; i++)
		visited[i].resize(100001);

	printf("%d\n", bfs());
	return 0;

}