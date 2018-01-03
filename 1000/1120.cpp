#include <bits/stdc++.h>
using namespace std;

int result = INT_MAX;
string s;

int main() {
    ios_base::sync_with_stdio(false);

    string s1, s2;
    cin >> s1 >> s2;

    int result = INT_MAX;
    for (int i = 0; i <= s2.size() - s1.size(); i++) {
        int cnt = 0;
        for (int j = 0; j < s1.size(); j++)
            if (s1[j] != s2[j + i])
                cnt++;
        result = min(cnt, result);
    }

    cout << (result == INT_MAX ? 0 : result) << endl;

    return 0;
}
