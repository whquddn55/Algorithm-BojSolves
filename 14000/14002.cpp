#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 1000

int dp[MAXSIZE]; // i에서 시작하는 lcs크기
int nexts[MAXSIZE];
vector<int> arr;
int n;

int lis(int start) {
    // base case
    if (start == n)
        return 0;

    int& ret = dp[start];
    if (ret != -1) return ret;

    ret = 1;
    for (int next = start + 1; next < n; next++)
        if (arr[start] < arr[next]) {
            int nextret = lis(next) + 1;
            if (ret < nextret) {
                ret = nextret;
                nexts[start] = next;
            }
        }


    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    memset(dp, -1, sizeof(dp));
    memset(nexts, -1, sizeof(nexts));

    int result = 0;
    int next = 0;
    for (int i = 0; i < n; i++) {
        if (result < lis(i)) {
            result = lis(i);
            next = i;
        }
    }

    cout << result << endl;
    while (next != -1) {
        cout << arr[next] << ' ';
        next = nexts[next];
    }
    cout << endl;

    return 0;
}
