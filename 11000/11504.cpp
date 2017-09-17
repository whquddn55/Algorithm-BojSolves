#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

#define INF 987654321
using namespace std;

vector<int> arr;

int main() {
    int testcase;
    scanf("%d", &testcase);

    while (testcase--) {
        int n, m;
        scanf("%d %d", &n, &m);

        int ch;
        string str;
        for (int i = 0; i < m; i++) {
            scanf("%d", &ch);
            str.push_back(ch + '0');
        }
        int x = atoi(str.c_str());

        str.clear();
        for (int i = 0; i < m; i++) {
            scanf("%d", &ch);
            str.push_back(ch + '0');
        }
        int y = atoi(str.c_str());

        arr.resize(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            string str;
            for (int j = i; j < i + m; j++) {
                if (j >= n) {
                    str.push_back(arr[j - n] + '0');
                }
                else {
                    str.push_back(arr[j] + '0');
                }
            }

            int z = atoi(str.c_str());
            if (z >= x && z <= y) {
                result++;
            }
        }

        printf("%d\n", result);
    }


    return 0;
}