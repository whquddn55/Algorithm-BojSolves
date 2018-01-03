#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int result = 0;
    for (int i = 1; i < n; i++) {
        string s = to_string(i);
        int sum = i;
        for (char c : s)
            sum += (c - '0');

        if (sum == n) {
            result = i;
            break;
        }
    }

    cout << result << endl;

    return 0;
}
