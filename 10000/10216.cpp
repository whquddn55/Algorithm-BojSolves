#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<pair<pair<int, int>, int> > circles;
vector<vector<int> > adj;
vector<bool> visited;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    while (!q.empty()) {
        int here = q.front();
        q.pop();
        
        for (int i = 0; i < adj[here].size(); i++) {
            int next = adj[here][i];
            
            if (visited[next])
                continue;
                
            visited[next] = true;
            q.push(next);
        }
    }
}

void makeAdj() {
    int size = circles.size();
    
    for(int i = 1; i < size; i++) {
        for (int j = 0; j < i; j++) {
            int dist = (circles[i].first.first - circles[j].first.first) * (circles[i].first.first - circles[j].first.first) + 
                        (circles[i].first.second - circles[j].first.second) * (circles[i].first.second - circles[j].first.second);
            if (dist <= (circles[i].second + circles[j].second) * (circles[i].second + circles[j].second)) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
}

int main() {
    int testcase;
    cin >> testcase;
    
    while (testcase--) {
        adj.clear();
        circles.clear();
        visited.clear();
        
        int n;
        cin >> n;
        
        circles.resize(n);
        visited.resize(n,false);
        adj.resize(n);
        
        for (int i = 0; i < n; i++) {
            int x, y, r;
            cin >> x >> y >> r;
            circles[i] = make_pair(make_pair(x, y), r);
        }
        makeAdj();
        
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i])
                continue;
            bfs(i);
            cnt++;
        }
        
        cout << cnt << endl;
    }
    
}