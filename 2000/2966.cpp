#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    string input;
    cin >> input;

    int correct[] = {0, 0, 0};
    for (int i = 0; i < input.size(); i++) {
        if (i % 3 == 0 && input[i] == 'A')
            correct[0]++;
        else if (i % 3 == 1 && input[i] == 'B')
            correct[0]++;
        else if (i % 3 == 2 && input[i] == 'C')
            correct[0]++;

        if (i % 4 == 0 && input[i] == 'B')
            correct[1]++;
        else if (i % 4 == 1 && input[i] == 'A')
            correct[1]++;
        else if (i % 4 == 2 && input[i] == 'B')
            correct[1]++;
        else if (i % 4 == 3 && input[i] == 'C')
            correct[1]++;

        if (i % 6 == 0 && input[i] == 'C')
            correct[2]++;
        else if (i % 6 == 1 && input[i] == 'C')
            correct[2]++;
        else if (i % 6 == 2 && input[i] == 'A')
            correct[2]++;
        else if (i % 6 == 3 && input[i] == 'A')
            correct[2]++;
        else if (i % 6 == 4 && input[i] == 'B')
            correct[2]++;
        else if (i % 6 == 5 && input[i] == 'B')
            correct[2]++;
    }
    int result = 0;
    for (int i = 0; i < 3; i++)
        if (result < correct[i])
            result = correct[i];

    cout << result << endl;

    string names[3] = {"Adrian", "Bruno", "Goran"};
    for (int i = 0; i < 3; i++) {
        if (result == correct[i])
            cout << names[i] << endl;
    }

    return 0;
}
