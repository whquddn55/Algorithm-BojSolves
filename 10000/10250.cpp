#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int testcase;
    cin >> testcase;

    while (testcase--) {
        int h, w, n;
        cin >> h >> w >> n;

        int num = n / h + 1;
        if (n % h == 0)
            num--;

        int floor = n - (num - 1) * h;


        cout << floor;
        if (num < 10)
            cout << 0;
        cout << num << endl;
    }
}
