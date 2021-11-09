#include <bits/stdc++.h>

using namespace std;
using ll = long long;

enum result_t {
    ERROR = 3,
    IMPROPER = 2,
    PROPER = 1
};

bool is_operator(char c)
{
    return c == '+' || c == '-' || c == '/' || c == '*' || c == '%';
}

string s;
size_t i;

result_t result;

void update(result_t oth)
{
    
    result = max(result, oth);
}

void skip()
{
    while (s[i] == ' ')++i;
}

bool is_identifier(char c)
{
    return 'a' <= c && c <= 'z';
}

int parse()
{
    skip();

    if (s[i] == '\0' || s[i] == ')') {
        update(ERROR);
        return -1;
    }

    size_t count = 0;
    bool has_opexp = false;

    while (true) {
        if (s[i] == '(') {
            has_opexp = true;
            i += 1;
            skip();
            auto res = parse();
            if (res == 0)
                update(IMPROPER);
            skip();
            if (s[i] != ')') {
                update(ERROR);
                return -1;
            }

            i += 1;
        } else if (is_identifier(s[i])) {
            i += 1;
        }
        else {
            update(ERROR);
            return -1;
        }

        skip();

        if (!is_operator(s[i])) {
            if (count >= 2 || (count == 0 && has_opexp))
                update(IMPROPER);

            if (s[i] == '\0' || s[i] == ')')
                return count;

            update(ERROR);
            return -1;
        }
        else {
            i += 1;
            ++count;
            skip();
        }
    }
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    getline(cin, s);

    parse();

    skip();

    if (s[i] || result == ERROR)
        cout << "error";
    else if (result == IMPROPER)
        cout << "improper";
    else
        cout << "proper";
}
