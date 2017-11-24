#include <iostream>
#include <vector>

using namespace std;

vector<int> numbers;
vector<int> results;

int main() {
    int n;
    cin >> n;

    numbers.resize(n);
    results.resize(n, 0);
    for (int i = 0; i < n; i++)
        cin >> numbers[i];

    results[0] = numbers[0];
    int idx = 0;
    for (int i = 1; i < n; i++) {
        int next = (idx + numbers[i - 1]) % n;
        while (results[next] != 0)
            next = (next + 1) % n;
        results[next] = numbers[i];
        idx = next;
    }

    cout << n << endl;
    for (int i = 0; i < n; i++)
        cout << results[i] << ' ';
    cout << endl;

    return 0;
}

