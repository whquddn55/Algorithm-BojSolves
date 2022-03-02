#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <array>
#include <map>
#define MAX_SIZE 21
#define pii pair<int,int>
using namespace std;

typedef struct Shark {
    pii pos; // 상어의 위치
    int id; // 상어의 번호
    int direction; // 방향
    Shark(pii p, int i) {
        pos = p;
        id = i;
    }
};

int N, M, K; // N x N , M - 상어의 마리 수, K - 냄새 지속가능 시간
int ans; // 정답
int drow[4] = { 0,0,1,-1 };
int dcol[4] = { 1,-1,0,0 };
array<array<pii,MAX_SIZE>,MAX_SIZE> board; // 보드 (상어의 번호, 남은 시간)
array<array<array<int, 5>, 5>, MAX_SIZE * MAX_SIZE> priority;
map<int, pii> m = { {1,make_pair(-1,0)}, {2,make_pair(1,0)}, {3,make_pair(0,-1)}, {4,make_pair(0,1)} };
vector<Shark> shark;

bool cmp(Shark a, Shark b) {
    return a.id > b.id;
}

void input() {
    //ifstream in("test.txt");
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int k;
            cin >> k;
            board[i][j] = make_pair(k,0);
            if (board[i][j].first != 0) {
                shark.push_back(Shark(make_pair(i, j), board[i][j].first));                
            }
        }
    }
    sort(shark.begin(), shark.end(),cmp); // 상어번호 내림차순으로 정렬    

    for (int i = M-1; i >=0; i--) {
        cin >> shark[i].direction;
    }    
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= 4; j++) {
            for (int k = 1; k <= 4; k++) {
                cin >> priority[i][j][k];            
            }
        }
    }    
}

void solve() {          
    while (shark.size() > 1) { // 상어가 1마리가 될 때 까지 반복
        
        if (ans == 1000) { // 1000초가 되면 return 왜? -> 상어가 이동해서 1번만 남는다고해도 이미 1001초
            ans = -1;
            return;
        }
        // 모든 상어가 냄새 뿌리기
        for (int i = 0; i < shark.size(); i++) {
            board[shark[i].pos.first][shark[i].pos.second] = make_pair(shark[i].id, K);
        }

        vector<Shark> new_shark; // 이동한 상어들을 담을 벡터
        // 모든 상어에 대해서 이동
        for (int s = 0; s < shark.size(); s++) {
            Shark cur_shark = shark[s];

            bool is_empty = false; // 인접한 칸들중 비어있는 칸이 존재하는지
            for (int i = 0; i < 4; i++) { // 인접한 4방향중 넘어갈 수 있는 칸 탐색
                int nr = cur_shark.pos.first + drow[i];
                int nc = cur_shark.pos.second + dcol[i];
                if (nr >= 1 && nr <= N && nc >= 1 && nc <= N) { // 다음 칸이 범위 안에 존재하고                    
                    if (board[nr][nc].second == 0) { // 다음 칸에 아무 냄새도 없으면                       
                        is_empty = true;
                        break;
                    }
                }
            }
         
            array<int, 5> cur_priority = priority[cur_shark.id][cur_shark.direction];
            if (is_empty) { // 비어있는 칸이 존재하는 경우 우선순위에 따라 이동                
                for (int i = 1; i <= 4; i++) {
                    int dir_priority = cur_priority[i]; // 상어의 우선순위 순서에 따라 한가지방향씩 가져오고
                    int nr = cur_shark.pos.first + m[dir_priority].first; // 우선순위에 따른 다음 방향 row
                    int nc = cur_shark.pos.second + m[dir_priority].second; // 우선순위에 따른 다음 방향 col

                    if (nr >= 1 && nr <= N && nc >=1 && nc <= N &&
                        board[nr][nc].second == 0) { // 상어가 가려고 하는 방향이 비어있다면
                        board[nr][nc].first = cur_shark.id; // 자신의 영역을 표시
                        // -> 상어 번호가 큰 애들부터 이동했기 떄문에 그냥 덮어써도 됨.

                        new_shark.push_back(Shark(make_pair(nr, nc), cur_shark.id)); // 상어의 새로운 위치 push
                        new_shark.back().direction = dir_priority; // 바라보는 방향 = 우선순위 이동한 방향
                        break;
                    }                    
                }
            }
            else { // 비어있는 칸이 존재하지 않는경우, 자신의 냄새가 있는 곳으로 이동
                for (int i = 1; i <= 4; i++) {
                    int dir_priority = cur_priority[i]; // 상어의 우선순위 순서에 따라 한가지방향씩 가져오고
                    int nr = cur_shark.pos.first + m[dir_priority].first; // 우선순위에 따른 다음 방향 row
                    int nc = cur_shark.pos.second + m[dir_priority].second; // 우선순위에 따른 다음 방향 col

                    if (nr >= 1 && nr <= N && nc >= 1 && nc <= N
                        && board[nr][nc].first == cur_shark.id) { // 자신의 id값과 동일한 칸으로 이동
                        board[nr][nc].second = -1; // 새롭게 이동한 곳임을 표시
                        new_shark.push_back(Shark(make_pair(nr, nc), cur_shark.id)); // 상어의 새로운 위치 push
                        new_shark.back().direction = dir_priority; // 바라보는 방향 = 우선순위 이동한 방향                           
                        break;
                    }
                }

            }               
        }


        /*
        Next Shark 구하는 로직
        1. new_shark 후보들 중에서 실제로 그 id값과
           현재 board에 저장되어있는 (실제로 상어가 이동한 칸)이 동일하다면
           다른 상어에게 먹히지 않고 잘 이동한 것이므로 추가
           second 값이 0 이하여야 하는 이유는, 자신의 냄새를 찾아서 이동한 케이스에서
           구분하기 위함        
        */
        vector<Shark> next_shark;
        for (Shark s : new_shark) {
            bool is_dead = true;
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    if (s.id == board[i][j].first && board[i][j].second <= 0) { // id값이 동일, 새로이동한 곳이면
                        is_dead = false; // 살아있음
                    }
                }
            }
            if (!is_dead) { // 살아있으면 추가
                next_shark.push_back(s);
            }
        }

        shark = next_shark; // shark 벡터 업데이트
        sort(shark.begin(), shark.end(), cmp); // 큰 번호 상어부터 이동하기위해 정렬

        for (int i = 1; i <= N; i++) { // 냄새 감소시키기
            for (int j = 1; j <= N; j++) {
                if (board[i][j].second > 0) { 
                    board[i][j].second--;// 냄새 감소시키고

                    if (board[i][j].second == 0) { // 0이 되었으면 냄새 주인도 지워주기
                        board[i][j] = make_pair(0, 0); // 빈칸으로 만듦
                    }
                }                
            }
        }
        ans++;

    }
}
void print() {        
    cout << ans;    
}

int main() {    
    input();
    solve();
    print();
}
