#include <bits/stdc++.h>
using namespace std;

struct Data {
    string number;
    int strike, ball;
    Data(string number, int strike, int ball)
        : number(number), strike(strike), ball(ball) { }
};

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<Data> v;
    for (int i = 0; i < n; i++) {
        string t1;
        int t2, t3;
        cin >> t1 >> t2 >> t3;

        v.push_back(Data(t1, t2, t3));
    }

    int result = 0;
    for (int i = 111; i < 1000; i++) {
        string num = to_string(i);
        if (num[0] == '0' || num[1] == '0' || num[2] == '0' || num[0] == num[1] || num[1] == num[2] || num[2] == num[0])
            continue;

        bool check = true;
        for (int j = 0; j < n; j++) {
            int strike = 0, ball = 0;
            string number = v[j].number;

            for (int k = 0; k < 3; k++)
                if (num[k] == number[k])
                    strike++;

            if (num[0] == number[1] || num[0] == number[2])
                ball++;
            if (num[1] == number[0] || num[1] == number[2])
                ball++;
            if (num[2] == number[0] || num[2] == number[1])
                ball++;

            if (strike != v[j].strike || ball != v[j].ball) {
                check = false;
                break;
            }
        }

        if (check)
            result++;
    }

    cout << result << endl;

    return 0;
}
