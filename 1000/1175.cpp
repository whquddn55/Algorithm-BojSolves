#include<iostream>
#include<string>
#include<queue>
 
#define endl "\n"
#define MAX 50
using namespace std;
 
struct INFO
{
    int x;
    int y;
    int Cnt;
    int Dir;
    bool C_Visit;
    bool D_Visit;
};
 
int N, M, Answer;
char MAP[MAX][MAX];
bool Visit[MAX][MAX][5][2][2];
 
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
 
pair<int, int> Start;
 
void Input()
{
    int Idx = 0;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string Inp; cin >> Inp;
        for (int j = 0; j < Inp.length(); j++)
        {
            MAP[i][j] = Inp[j];
            if (MAP[i][j] == 'S')
            {
                Start.first = i;
                Start.second = j;
                MAP[i][j] = '.';
            }
            else if (MAP[i][j] == 'C')
            {
                Idx++;
                if (Idx == 2) MAP[i][j] = 'D';
            }
        }
    }
}
 
void Solution()
{
    
    queue<INFO> Q;
    Q.push({ Start.first, Start.second, 0, -1, 0, 0 });
    Visit[Start.first][Start.second][4][0][0] = true;
 
    while (Q.empty() == 0)
    {
        int x = Q.front().x;
        int y = Q.front().y;
        int Cnt = Q.front().Cnt;
        int Dir = Q.front().Dir;
        bool C_Visit = Q.front().C_Visit;
        bool D_Visit = Q.front().D_Visit;
        Q.pop();
 
        if (C_Visit == true && D_Visit == true)
        {
            Answer = Cnt;
            return;
        }
 
        for (int i = 0; i < 4; i++)
        {
            if (i == Dir) continue;
 
            int nx = x + dx[i];
            int ny = y + dy[i];
            bool nC_Visit = C_Visit;
            bool nD_Visit = D_Visit;
 
            if(nx >= 0 && ny >= 0 && nx < N && ny < M)
            { 
                if (Visit[nx][ny][i][C_Visit][D_Visit] == false && MAP[nx][ny] != '#')
                {
                    if (MAP[nx][ny] == 'C') nC_Visit = true;
                    if (MAP[nx][ny] == 'D') nD_Visit = true;
 
                    Visit[nx][ny][i][nC_Visit][nD_Visit] = true;
                    Q.push({ nx, ny, Cnt + 1, i, nC_Visit, nD_Visit });
                }
            }
        }
    }
}
 
void Solve()
{
    Input();
    Solution();
 
    if (Answer == 0) cout << -1 << endl;
    else cout << Answer << endl;
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    
    Solve();
 
    return 0;
}
