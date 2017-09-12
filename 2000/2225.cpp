#include <cstdio>
#include <vector>
#include <algorithm>

#define INF 987654321
using namespace std;

vector<vector<int> > nCr;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

   nCr.resize(n + k);

    for(int i = 1; i < n + k; i++){
        nCr[i].resize(k);
        nCr[i][0] = 1;
        nCr[i][1] = i;

        for(int j = 2; j < k && j <= i; j++){
            if(i != 1){
                nCr[i][j] = (nCr[i - 1][j - 1] + nCr[i - 1][j]) % 1000000000;
            }
            else {
                nCr[i][j] = 1;
            }
        }
    }



    printf("%d\n", nCr[n + k - 1][k - 1]);

    return 0;
}
