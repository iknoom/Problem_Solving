#include <bits/stdc++.h>
using namespace std;

struct Trie {
    Trie* go[26];
    int count;
    bool out;

    Trie() : out(false), count(0) {
        fill(go, go + 26, nullptr);
    }
    ~Trie() {
        for (int i = 0; i < 26; i++)
            if (go[i]) delete go[i];
    }

    void insert(const char* key) {
        count++;
        if (*key == '\0') {
            out = true;
            return;
        }
        int next = *key - 'a';
        if (!go[next]) go[next] = new Trie;
        go[next]->insert(key + 1);
    }
};

int N;
const int MOD = 1000000007;
string full;

int main() {
    cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false);
    cin >> N;
    Trie* dict = new Trie;
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        dict->insert(word.c_str());
    }
    cin >> full;

    vector<long long> dp;
    dp.push_back(1L);
    for (int i = (int)full.size() - 1; i >= 0; i--){
        long long S = 0;
        int c = 0;
        Trie* p = dict;
        for (int j = i; j < (int)full.size(); j++){
            c++;
            int next = full[j] - 'a';
            if (!p->go[next]) break;
            p = p->go[next];
            S += dp[dp.size() - c] * p->count;
            S %= MOD;
        }
        dp.push_back(S);
    }
    cout << dp.back() << endl;
}