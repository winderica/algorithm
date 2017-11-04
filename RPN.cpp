#include <iostream>
#include <stack>
using namespace std;

bool isNum(char c) {
    string chars = "1234567890";
    for (int i = 0; i < chars.length(); i++) {
        if (c == chars[i]) {
            return true;
        }
    }
    return false;
}

bool hasPriority(char i, stack<char> cha) {
    return i == '(' || (i == '*' || i == '/') && (cha.top() == '+' || cha.top() == '-');
}

string transform(string input, stack<char> cha) {
    string output;
    for (int i = 0; i < input.length(); i++) {
        char j = input[i];
        if (isNum(j)) {
            output += j;
        } else {
            if (cha.empty()) {
                cha.push(j);
            } else {
                if (j == ')') {
                    while (cha.top() != '(') {
                        output += cha.top();
                        cha.pop();
                    }
                    cha.pop();
                } else {
                    while (!hasPriority(j, cha)) {
                        if (!cha.empty() && cha.top() != '(') {
                            output += cha.top();
                            cha.pop();
                        } else {
                            break;
                        }
                    }
                    cha.push(j);
                }
            }
        }
    }
    while (!cha.empty()) {
        output += cha.top();
        cha.pop();
    }
    return output;
}

int main() {
    stack <char>cha;
    string input = "(1+2)*3+(4*5+6)*7";
    string output = transform(input, cha);
    cout << output<<endl;
    return 0;
}
