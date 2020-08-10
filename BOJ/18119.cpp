#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    vector<int> words;
    for (int i = 0; i < N; i++) {
        string t;
        cin >> t;
        int bits_i = 0;
        for (auto k : t){
            int j = k - 'a';
            bits_i |= (1 << j);
        }
        words.push_back(bits_i);
    }

    int bits = 0;
    for(int i = 0; i < 26; i++) {
        bits |= (1 << i);
    }

    while (M--) {
        int t, k; char c;
        cin >> t >> c;
        k = c - 'a';

        if (t == 1) bits -= (1 << k);
        else bits += (1 << k);

        int ret = 0;
        for (auto word : words){
            if ((word & bits) == word) ret++;
        }
        cout << ret << '\n';
    }

}