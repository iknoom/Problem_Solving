#include <iostream>
#include <string>
using namespace std;

int L, n_op, n_prth;;

bool is_operand(char c) {
    if ('a' <= c && c <= 'z')
        return true;
    else
        return false;
}

bool is_operator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
        return true;
    else
        return false;
}

int main()
{
    string input, exp;
    getline(cin, input);

    bool is_error = false;
    bool is_proper = true;

    string stack = "";
    for (auto c : input) {
        if (isblank(c)) continue;
        if (c == '(') stack.push_back(c);
        else if (c == ')') {
            int cnt = 0;
            while (!stack.empty() && stack.back() != '(') {
                if (is_operator(stack.back())) cnt++;
                stack.pop_back();
            }
            if (!stack.empty())
                stack.pop_back();
            else
                is_error = true;
            if (cnt != 1) is_proper = false;
            n_prth++;
        }
        else if (is_operator(c)) {
            stack.push_back(c);
            n_op++;
        }
        exp.push_back(c);
    }
    while (!stack.empty() && is_operator(stack.back())) stack.pop_back();
    if (!stack.empty()) is_error = true;

    L = exp.size();
    for (int i = 0; i < L; i++) {
        if (is_operator(exp[i])) {
            if (i != L && exp[i + 1] == ')' || is_operator(exp[i + 1]))
                is_error = true;
            if (i != 0 && exp[i - 1] == '(')
                is_error = true;
        }

        if (is_operand(exp[i])) {
            if (i != L && exp[i + 1] == '(' || is_operand(exp[i + 1]))
                is_error = true;
            if (i != 0 && exp[i - 1] == ')')
                is_error = true;
        }

        if (exp[i] == '(') {
            if (i != L && exp[i + 1] == ')')
                is_error = true;
        }
    }

    if (is_operator(exp[0]) || is_operator(exp[L - 1])) {
        is_error = true;
    }

    if (is_error)
        cout << "error" << endl;
    else if (is_proper && n_op - n_prth == 1)
        cout << "proper" << endl;
    else if (is_proper && n_op == 0 && n_prth == 0)
        cout << "proper" << endl;
    else
        cout << "improper" << endl;
}
