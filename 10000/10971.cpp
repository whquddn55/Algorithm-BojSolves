#include <cstdio>
#include <vector>

#define INF 987654321
using namespace std;

vector<vector<int> > adj;
int n;
int result = INF;

void get(vector<bool> isVisited,const int here, const int cost, const int remainCity){
    if(cost > result){
        return;
    }
    if(remainCity == 0){
        result = cost;
        return;
    }

    for(int next = 0; next < n; next++){
        if(!adj[here][next] || (isVisited[next] && !(next == 0 && remainCity == 1))){
            continue;
        }
        
        isVisited[next] = true;
        get(isVisited, next, cost + adj[here][next], remainCity - 1);
        isVisited[next] = false;
    }
}

int main() {
    scanf("%d", &n);

    adj.resize(n);
    for(int i = 0; i < n; i++){
        adj[i].resize(n);
        for(int j = 0; j < n; j++){
            scanf("%d", &adj[i][j]);
        }
    }

    vector<bool>isVisited(n);
    isVisited[0] = true;
    get(isVisited, 0, 0, n);
    printf("%d\n",result);

	return 0;
}

