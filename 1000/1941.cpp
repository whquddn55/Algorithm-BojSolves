#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<typename a, typename b>
ostream& operator<<(ostream& os, const pair<a, b>& pai) {
    os << pai.first << ' ' << pai.second;
    return os;
}
template<typename a, typename b>
istream& operator>>(istream& is, pair<a, b>& pai) {
    is >> pai.first >> pai.second;
    return is;
}

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif

#define INF (INT_MAX / 2)
#define MAX_N 300005
#define MOD 9901

char arr[5][5];

int dy[] = {0, -1, 0, 1};
int dx[] = {-1, 0, 1, 0};
vector<int> picked;
int ans = 0;
void pick(int toPick, int remain) {
	if (remain == 0) {
		queue<int> q;
		bool visited[5][5];
		memset(visited, 0, sizeof(visited));

		int cnt = 0;
		int cntOfS = 0;
		q.emplace(picked.front());
		visited[picked.front() / 5][picked.front() % 5] = true;
		++cnt;
		if (arr[picked.front() / 5][picked.front() % 5] == 'S')
			++cntOfS;
		while(q.size()) {
			int hereY = q.front() / 5;
			int hereX = q.front() % 5;
			q.pop();

			for (int i = 0; i < 4; ++i) {
				int nextY = hereY + dy[i];
				int nextX = hereX + dx[i];

				if (nextY >= 5 || nextY < 0 || nextX >= 5 || nextX < 0)
					continue;
				if (!binary_search(picked.begin(), picked.end(), nextY * 5 + nextX))
					continue;
				if (visited[nextY][nextX])
					continue;
				q.emplace(nextY * 5 + nextX);
				visited[nextY][nextX] = true;
				++cnt;
				if (arr[nextY][nextX] == 'S')
					++cntOfS;
			}
		}
		if (cnt == 7 && cntOfS >= 4)
			++ans;
		return;
	}
	if (toPick == 25)
		return;
	picked.emplace_back(toPick);
	pick(toPick + 1, remain - 1);
	picked.pop_back();
	pick(toPick + 1, remain);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j) 
			cin >> arr[i][j];
		
	pick(0, 7);
	cout << ans << endl;
    
    return 0;
}