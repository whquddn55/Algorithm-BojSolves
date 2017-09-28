#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 987654321
#define MAXSIZE 100000
using namespace std;

vector<vector<int> > wall;
vector<vector<int> > roomNumber;
vector<int> roomSize;
int n, m;

int bfs(int sy, int sx, int number) {
    queue<pair<int, int> >q;
	q.push(make_pair(sy, sx));

	int cnt = 0;
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        if (roomNumber[y][x]) {
            continue;
        }

		cnt++;
        roomNumber[y][x] = number;
		

        int dy[] = {0, -1, 0, 1};
        int dx[] = {-1, 0, 1, 0};
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
			
			if ((wall[y][x] & (1 << i)) == (1 << i)) {
				continue;
			}
            if (roomNumber[ny][nx]) {
                continue;
            }

            q.push(make_pair(ny, nx));
        }

    }
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	
	cin >> m >> n;
	wall.resize(n);
	roomNumber.resize(n);
	roomSize.push_back(0);
	for (int i = 0; i < n; i++) {
		wall[i].resize(m);
		roomNumber[i].resize(m, 0);
		for (int j = 0; j < m; j++)	{
			cin >> wall[i][j];
		}
	}
	
	int maxRoom = -INF;
	int numOfRoom = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (roomNumber[i][j]) {
				continue;
			}
			
			numOfRoom++;
			int temp = bfs(i, j, numOfRoom);
			roomSize.push_back(temp);
			maxRoom = max(temp, maxRoom);
		}
	}
	
	cout << numOfRoom << endl;
	cout << maxRoom << endl;
	
	int maxTwoRoom = -INF;
	int dy[] = {0, -1, 0, 1};
	int dx[] = {-1, 0, 1, 0};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 4; k++) {
				int ny = i + dy[k];
				int nx = j + dx[k];
				
				if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
					continue;
				}
				
				if (roomNumber[i][j] == roomNumber[ny][nx]) {
					continue;
				}
				
				if ((wall[i][j] & (1 << k)) == (1 << k)) {
					maxTwoRoom = max(roomSize[roomNumber[i][j]] + roomSize[roomNumber[ny][nx]], maxTwoRoom);
				}
			}
		}
	}
	
	cout << maxTwoRoom << endl;
    
    return 0;
}
