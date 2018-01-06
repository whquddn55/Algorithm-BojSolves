#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    string s1, s2;
    cin >> s1 >> s2;

    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    cout << max(atoi(s1.c_str()), atoi(s2.c_str())) << endl;

    return 0;
}
