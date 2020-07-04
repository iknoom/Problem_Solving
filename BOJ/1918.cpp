#include <iostream>
#include <string>
#include <stack>
using namespace std;

int p(char a) { // priority
	if (a == '*' || a == '/') return 1;
	else if (a == '+' || a == '-') return 2;
	else if (a == ')') return 3;
	else if (a == '(') return 4;
	else return 0;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	stack<char> s;
	string input;
	cin >> input;
	input = '(' + input + ')';
	for (auto i : input) {
		if (i == '(') s.push(i);
		else if (p(i) > 0) {
			while (!s.empty() && p(s.top()) <= p(i)) {
				cout << s.top();
				s.pop();
			}
			if (i == ')') s.pop();
			else s.push(i);
		}
		else cout << i;
	}
}