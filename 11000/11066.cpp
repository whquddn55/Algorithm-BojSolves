#include <cstdio>
#include <vector>
#include <algorithm>

#define INF 987654321
using namespace std;

vector<int> novel;
vector<vector<int> > dp;
int result = 0;

int get(int from, int to){
    if(from == to - 1){
        return 0;
    }
    if(dp[from][to - 1] != INF){
        return dp[from][to - 1];
    }

    int m = INF;
    int sum = novel[from];
    for(int i = from + 1; i < to; i++){
        m = min (m, get(from, i) + get(i, to));
        sum += novel[i];
    }

    return dp[from][to - 1] = m + sum;
}

int main() {
    int testcase;
    scanf("%d", &testcase);
    while(testcase--){
        int k;
        scanf("%d", &k);

        novel.clear();
        novel.resize(k);
        dp.clear();
        dp.resize(k);

        for(int i = 0; i < k; i++){
            scanf("%d", &novel[i]);
            dp[i].resize(k, INF);
        }


        printf("%d\n", get(0, k));
    }

    return 0;
}
