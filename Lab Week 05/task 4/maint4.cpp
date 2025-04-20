
#include "Stack.h"  // Your own Stack class (no <stack> allowed)


int evaluatePostfix(string expression) {
    Stack s(expression.length());  // Stack to hold numbers
    string num = "";  // to build the number

    for (int i = 0; i < expression.length(); i++) {
        char ch = expression[i];  // take one character at a time

        if (isdigit(ch)) {
            // if digit, keep adding to num
            num += ch;
        }
        else if (ch == ' ') {
            // if space, it means number ended
            if (num != "") {
                int number = stoi(num);  // convert the collected number string into int
                s.push(number);  // push into stack
                num = "";  // reset for next number
            }
        }
        else {
            // if operator (+, -, *, /)
            int val2 = s.pop();  // top value
            int val1 = s.pop();  // next value

            if (ch == '+') {
                s.push(val1 + val2);
            }
            else if (ch == '-') {
                s.push(val1 - val2);
            }
            else if (ch == '*') {
                s.push(val1 * val2);
            }
            else if (ch == '/') {
                s.push(val1 / val2);
            }
        }
    }

    // in case number is left without a space at end
    if (num != "") {
        int number = stoi(num);
        s.push(number);
    }

    return s.pop();  // result is final value
}

int main() {
    string expression;
    cout << "Enter postfix expression (example: 63 56 +): ";
    getline(cin, expression);

    int result = evaluatePostfix(expression);
    cout << "Result: " << result << endl;

    return 0;
}
