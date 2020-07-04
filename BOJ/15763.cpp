#include <iostream>
#include <string>
#include <set>
using namespace std;

string board[3];
set<set<char>> one_cow, two_cow;

void count(set<char> L) {
	if (L.size() == 1) one_cow.insert(L);
	if (L.size() == 2) two_cow.insert(L);
}

int main()
{
	for (int i = 0; i < 3; i++)
		cin >> board[i];
	for (int i = 0; i < 3; i++) {
		set<char> R; set<char> C;
		for (int j = 0; j < 3; j++) {
			R.insert(board[i][j]);
			C.insert(board[j][i]);
		}
		count(R); count(C);
	}

	set<char> D1; set<char> D2;
	for (int i = 0; i < 3; i++) {
		D1.insert(board[i][i]);
		D2.insert(board[i][2-i]);
	}
	count(D1); count(D2);

	cout << one_cow.size() << endl;
	cout << two_cow.size() << endl;
}