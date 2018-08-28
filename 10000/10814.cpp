#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int n;
vector<string> arr[201];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        string b;
        cin >> a >> b;
        arr[a].emplace_back(b);
    }
    for (int i = 0; i <= 200; i++) 
        for (auto& e : arr[i])
            cout << i << ' ' << e << endl;
}