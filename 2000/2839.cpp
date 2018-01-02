#include <iostream>
#include <climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int result = INT_MAX;
    int cnt = 0;
    while (n >= 0) {
        if (n % 3 == 0)
            result = result > (cnt + n / 3) ? (cnt + n / 3) : result;
        n -= 5;
        cnt++;
    }


    cout << ((result == INT_MAX) ? -1 : result) << endl;


    return 0;
}
