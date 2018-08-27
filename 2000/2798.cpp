#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    int arr[100];
    int ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                if (i != j && j != k && i != k && arr[i] + arr[j] + arr[k] <= m)
                    ans = max(ans, arr[i] + arr[j] + arr[k]);
    cout << ans << endl;
}