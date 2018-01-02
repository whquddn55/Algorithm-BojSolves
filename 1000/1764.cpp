#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    map<string, int> ma;
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;

        ma[name]--;
    }
    for (int i = 0; i < m; i++) {
        string name;
        cin >> name;

        ma[name]--;
    }

    vector<string> result;
    for (map<string,int>::iterator it = ma.begin(); it != ma.end(); ++it) {
        if (it->second == -2)
            result.push_back(it->first);
    }

    cout << result.size() << endl;
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << endl;
}
