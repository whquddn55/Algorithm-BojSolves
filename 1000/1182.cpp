#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
int n, s;
int result;

void pick(int toPick, int sum) {
    if (toPick == n && sum == s) {
        result++;
    }
    if (toPick > n)
        return;

    pick(toPick + 1, sum);
    pick(toPick + 1, sum + arr[toPick]);
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> s;
    arr.resize(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    pick(0, 0);
    if (s == 0)
        result--;

    cout << result << endl;


    return 0;
}
