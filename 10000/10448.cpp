#include <cstdio>
#include <vector>

#define INF 987654321
#define MAXSIZE 10000
using namespace std;

bool result;
vector<int> gause;

void get(const int n, int toPick, int numOfPicked){
    if(result == true || numOfPicked > 3 || n < 0){
        return;
    }
    if(n == 0 && numOfPicked == 3){
        result = true;
        return;
    }

    for(int next = toPick; next <= 45; next++){
        get(n - gause[next], next, numOfPicked + 1);
    }

}

int main() {
    gause.push_back(0);
    for(int i = 1; i <= 45; i++) {
        gause.push_back(i * (i + 1) / 2);
    }

    int testcase;
    scanf("%d", &testcase);

    while(testcase--){
        result = false;
        int n;
        scanf("%d", &n);

        get(n, 1, 0);
        printf("%d\n", result);
    }
	return 0;
}

