#include <cstdio>
#include <vector>
#include <algorithm>

#define INF 987654321
using namespace std;

vector<vector<int> > matrix1;
vector<vector<int> > matrix2;
vector<vector<int> > result;

int main() {
    int n, m, k;
    scanf("%d %d", &n, &m);
    matrix1.resize(n);
    for (int i = 0; i < n; i++) {
        matrix1[i].resize(m);
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    scanf("%d %d", &m, &k);
    matrix2.resize(m);

    for (int i = 0; i < m; i++) {
        matrix2[i].resize(k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    result.resize(n);
    for (int i = 0; i < n; i++) {
        result[i].resize(k, 0);
        for (int j = 0; j < k; j++) {
            for (int l = 0; l < m; l++) {
                result[i][j] += matrix1[i][l] * matrix2[l][j];
            }
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
