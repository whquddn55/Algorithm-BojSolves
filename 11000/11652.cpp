#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

bool op(pair<long long, int>& m1, pair<long long, int>& m2) {
    return m1.second > m2.second;
}

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    map<long long, int> m;
    for (int i = 0; i < n; i++) {
        long long t;
        cin >> t;

        m[t]++;
    }

    int result = 0;
    long long key = 0;
    for (map<long long, int>::iterator it = m.begin(); it != m.end(); ++it) {
        if (it->second > result) {
            result = it->second;
            key = it->first;
        }
    }

    cout << key << endl;
}
