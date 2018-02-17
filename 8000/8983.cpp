#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)

int m, n, l;
vector<int> points;
map<int, int> compress; // first : 실제 x 좌표, second : array에 들어갈 index
vector<vector<int> > animals;

int main() {
	scanf("%d %d %d", &m, &n, &l);
	points.resize(m);
	for (int i = 0; i < m; i++)
		scanf("%d", &points[i]);
	sort(points.begin(), points.end());
	
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		if (compress[x]) 
			animals[compress[x]].push_back(y);
		else {
			compress[x] = animals.size();
			animals.emplace_back(vector<int>(1, y));
		}
	}
	
	for (int i = 0; i < animals.size(); i++)
		sort(animals[i].begin(), animals[i].end());
	
	int result = 0;
	for (const auto& here : compress) {
		int realX = here.first;
		int comX = here.second;
		int idx = lower_bound(points.begin(), points.end(), realX) - points.begin();

		int minDist;
		if (idx == 0)
			minDist = abs(realX - points[idx]);
		else
			minDist = min(abs(realX - points[idx - 1]), abs(realX - points[idx]));

		result += upper_bound(animals[comX].begin(), animals[comX].end(), l - minDist) - animals[comX].begin();
	}
	printf("%d\n", result);

	return 0;
}