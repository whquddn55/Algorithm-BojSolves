#include <iostream>
#include <queue>
#include <vector>
#include <list>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int testcase;
    cin >> testcase;

    while (testcase--) {
        int n, m;
        cin >> n >> m;

        list<int> l;
        while (n--) {
            int t;
            cin >> t;
            l.push_back(t);
        }

        int result = 0;
        while(!l.empty()) {
            bool check = false;
            for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
                if (*it > l.front()) {
                    check = true;
                    break;
                }

            if (check) {
                l.push_back(l.front());
                l.pop_front();

                if (m == 0)
                    m = l.size();
                m--;
            }

            else {
                l.pop_front();
                result++;
                if (m == 0)
                    break;
                m--;
            }
        }
        cout << result << endl;
    }


    return 0;
}
