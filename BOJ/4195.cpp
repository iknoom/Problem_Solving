#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <map>
using namespace std;
typedef pair<int, int> tt;
map<string, string> p;
map<string, int> s;

string find(string name) {
	if (p.find(name) == p.end()) {
		p[name] = name;
		s[name] = 1;
	}
	if (p[name] == name) return name;
	return p[name] = find(p[name]);
}

int merge(string name1, string name2) {
	name1 = find(name1);
	name2 = find(name2);
	if (name1 == name2) return s[name1];
	if (s[name1] < s[name2]) {
		s[name2] += s[name1];
		p[name1] = name2;
		return s[name2];
	}
	else {
		s[name1] += s[name2];
		p[name2] = name1;
		return s[name1];
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T, N;
	string A, B;
	cin >> T;
	while (T--) {
		p.clear();
		s.clear();
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> A >> B;
			cout << merge(A, B) << '\n';
		}
	}
}