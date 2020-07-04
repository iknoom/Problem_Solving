#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	cin.get();

	while (N--) {
		vector<char> stack;
		char input;
		string ans = "YES";
		while (1) {
			input = cin.get();
			if (isspace(input)) break;
			else if (input == '(') stack.push_back(input);
			else if (input == ')') {
				if (!stack.empty() && stack.back() == '(')
					stack.pop_back();
				else ans = "NO";
			}
		}
		if (!stack.empty()) ans = "NO";
		cout << ans << endl;
	}
}