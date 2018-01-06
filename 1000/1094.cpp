#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int x;
    cin >> x;

    vector<int> sticks;
    sticks.push_back(64);

    int cnt = 1;
    int sum = 64;
    int minimum = 64;
    while (sum > x) {
        minimum /= 2;
        if (sum - minimum >= x) {
            sum -= minimum;
            cnt--;
        }
        cnt++;
    }

    cout << cnt << endl;

    return 0;
}
