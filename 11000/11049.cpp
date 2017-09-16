#include <cstdio>
#include <vector>
#include <algorithm>

#define INF 987654321
using namespace std;

vector<pair<int, int> > matrix;
vector<vector<int> > dp;

int get(int from, int to){
    int& ret = dp[from][to - 1];
    if (from == to - 1) {
        return ret;
    }
    if (from == to - 2) {
        return matrix[from].first * matrix[from].second * matrix[to - 1].second;
    }
    if (ret != 0) {
        return ret;
    }

    int m = INF;
    for(int i = from + 1; i < to; i++){
        m = min( m, get(from, i) + get(i, to) + matrix[from].first * matrix[i - 1].second * matrix[to - 1].second);
    };

    return ret = m;
}

int main() {
    int n;
    scanf("%d", &n);

    matrix.resize(n);
    dp.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &matrix[i].first, &matrix[i].second);
        dp[i].resize(n, 0);
    }

    printf("%d\n", get(0, n));

    return 0;
}
