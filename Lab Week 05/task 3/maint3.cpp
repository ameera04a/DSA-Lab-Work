#include "Stack.h"

// Function to define precedence
int precedence(char ch) {
    if (ch == '+' || ch == '-') return 1;
    if (ch == '*' || ch == '/') return 2;
    if (ch == '^') return 3;
    return 0;
}

// Function to check if character is operator
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}


string reverseString(string str) {
    Stack s(str.length());

    // Push all characters onto the stack
    for (int i = 0; i < str.length(); i++) {
        s.push(str[i]);
    }

    // Pop all characters to get reversed string
    string reversed = "";
    while (!s.isEmpty()) {
        reversed += s.pop();
    }

    return reversed;
}

string infixToPrefix(string infix) {
    infix = reverseString(infix);

    // Swap brackets
    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }

    Stack stack(infix.length());
    string result = "";

    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        if (isalnum(ch)) {
            result += ch;
        }
        else if (ch == '(') {
            stack.push(ch);
        }
        else if (ch == ')') {
            while (!stack.isEmpty() && stack.peek() != '(') {
                result += stack.pop();
            }
            if (!stack.isEmpty()) {
                stack.pop(); // remove '('
            }
        }
        else if (isOperator(ch)) {
            while (!stack.isEmpty() && precedence(stack.peek()) > precedence(ch)) {
                result += stack.pop();
            }
            stack.push(ch);
        }
    }

    while (!stack.isEmpty()) {
        result += stack.pop();
    }

    result = reverseString(result); // use stack based reverse again
    return result;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    getline(cin, infix);

    string prefix = infixToPrefix(infix);
    cout << "Prefix expression: " << prefix << endl;

	system("pause");
}