#include <cstdio>
#include <vector>

#define INF 987654321
#define MAXSIZE 10000
using namespace std;

vector<vector<char> > graph;
int h, w;
int result = INF;

void get(const int y, const int x){
    char value = graph[y][x];
    int ret = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            int dy = i + y;
            int dx = j + x;

            if(graph[dy][dx] == value){
                if((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1)){
                    continue;
                }
                ret++;
            }
            else {
                if((i % 2 == 1 && j % 2 == 0) || (i % 2 == 0 && j % 2 == 1)){
                    continue;
                }
                ret++;
            }
        }
    }

    ret = ret >= 32 ? 64 - ret: ret;
    result = result > ret ? ret : result;
}

int main() {
    scanf("%d %d", &h, &w);
    getchar();
    graph.resize(h);

    for(int i = 0; i < h; i++){
        graph[i].resize(w);
        for(int j = 0; j < w; j++){
            scanf("%c", &graph[i][j]);
        }
        getchar();
    }

    for(int i = 0; i <= h - 8; i++){
        for(int j = 0; j <= w - 8; j++){
            get(i, j);
        }
    }
    printf("%d\n", result);

	return 0;
}

