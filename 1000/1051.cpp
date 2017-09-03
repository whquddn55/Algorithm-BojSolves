#include <cstdio>
#include <vector>

#define INF 987654321
#define MAXSIZE 10000
using namespace std;

vector<vector<int> > graph;
int h, w;
int result;

void get(const int y, const int x){
    int len = 0;
    while(true){
        int dx[] = { x + len, x, x + len };
        int dy[] = { y, y + len, y + len };

        bool check = true;
        int value = graph[y][x];
        for(int i = 0; i < 3; i++){
            if(dx[i] >= w || dy[i] >= h){
                return;
            }

            if(graph[dy[i]][dx[i]] != value){
                check = false;
                break;
            }
        }
        len++;
        if(check){
            result = (result < len * len) ? (len * len) : result;
        }
    }
}

int main() {
    scanf("%d %d", &h, &w);
    getchar();
    graph.resize(h);

    for(int i = 0; i < h; i++){
        graph[i].resize(w);
        for(int j = 0; j < w; j++){
            char ch;
            scanf("%c", &ch);
            graph[i][j] = ch - '0';
        }
        getchar();
    }

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            get(i, j);
        }
    }
    printf("%d\n", result);

	return 0;
}

