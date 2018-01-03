#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int result = 0;
    if ( n < 100)
        result = n;
    else
        result = 99;

    for (int i = 100; i <= n; i++) {
        string s = to_string(i);

        int d = s[0] - s[1];
        if (d == s[1] - s[2])
            result++;
    }

    cout << result << endl;

    return 0;
}
