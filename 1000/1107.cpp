#include <bits/stdc++.h>
using namespace std;

int n;
vector<bool> buttons(10, true);
int result;

int checkBrokenButton(int i) {
    int cnt = 0;
    while (true) {
        int digit = i % 10;
        i /= 10;
        cnt++;

        if (!buttons[digit])
            return -1;

        if (i == 0)
            break;
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n;

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int broken;
        cin >> broken;
        buttons[broken] = false;
    }

    result = abs(n - 100);

    for (int i = 0; i < 1000000; i++) {
        int cnt = checkBrokenButton(i);
        if (cnt == -1)
            continue;

        int pressed = abs(n - i) + cnt;
        result = result > pressed ? pressed : result;
    }

    cout << result << endl;

    return 0;
}
