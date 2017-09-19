#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

#define INF 987654321
using namespace std;

vector<int> num;

int getNext(int n, int p){
    int result = 0;
    while (n != 0) {
        int temp = 1;
        for (int i = 0; i < p; i++) {
            temp *= n % 10;
        }
        result += temp;
        n /= 10;
    }

    return result;
}

int main() {
    int a, p;
    scanf("%d %d", &a, &p);

    num.push_back(a);
    int index = 0;
    while (true) {
        int next = getNext(num[index], p);
        num.push_back(next);

        int result = -1;
        for (int i = 0; i < index; i++) {
            if (num[i] == next) {
                result = i;
                break;
            }
        }

        if (result != -1) {
            printf("%d\n", result);
            break;
        }

        index++;
    }

    return 0;
}


