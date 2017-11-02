#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF 987654321

vector<vector<int> > graph;
vector<vector<bool> > visited;
vector<pair<int, int> > steps;
int r, c;

int bfs() {
    queue<pair<pair<int, int>, int> > q;
    for (int i = 0; i < c; i++) 
        if (graph[0][i]) 
            q.push(make_pair(make_pair(0, i), 0));
        
    
    while (!q.empty()) {
        int hereY = q.front().first.first;
        int hereX = q.front().first.second;
        int cost = q.front().second;
        q.pop();
        
        if (hereY == r - 1) 
            return cost;
        
        
        for (int i = 0; i < steps.size(); i++) {
            int nextY = hereY + steps[i].first;
            int nextX = hereX + steps[i].second;
            
            if (nextY < 0 || nextY >= r || nextX < 0 || nextX >= c)
                continue;
                
            if (!graph[nextY][nextX])
                continue;
            
            if (visited[nextY][nextX])
                continue;
                
            visited[nextY][nextX] = true;
            q.push(make_pair(make_pair(nextY, nextX), cost + 1));
        }
    }
    
    return -1;
}

int main() {
    cin >> r >> c;
    graph.resize(r);
    visited.resize(r);
    for (int i = 0; i < r; i++) {
        graph[i].resize(c, 0);
        visited[i].resize(c, false);
    }
    
        
    for (int i = 0; i < r; i++) 
        for (int j = 0; j < c; j++) 
            cin >> graph[i][j];
        
    int n;
    cin >> n;
    
    steps.resize(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        steps[i] = make_pair(x, y);
    }
            
    cout << bfs() << endl;

    return 0;
}