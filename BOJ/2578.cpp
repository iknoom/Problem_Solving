#include <bits/stdc++.h>

using namespace std;
int board[5][5];
int order[25];
unordered_set<int> dict;

bool check(){
    int ret = 0;
    for (int i = 0; i < 5; i++){
        bool flag = true;
        for (int j = 0; j < 5; j++){
            if (dict.find(board[i][j]) == dict.end()){
                flag = false;
            }
        }
        if (flag) ret++;

        flag = true;
        for (int j = 0; j < 5; j++){
            if (dict.find(board[j][i]) == dict.end()){
                flag = false;
            }
        }
        if (flag) ret++;
    }
    bool flag = true;
    for (int j = 0; j < 5; j++){
        if (dict.find(board[j][j]) == dict.end()){
            flag = false;
        }
    }
    if (flag) ret++;

    flag = true;
    for (int j = 0; j < 5; j++){
        if (dict.find(board[j][4 - j]) == dict.end()){
            flag = false;
        }
    }
    if (flag) ret++;

    if (ret >= 3) return true;
    else return false;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < 25; i++){
        cin >> order[i];
    }
    for (int i = 0; i < 25; i++){
        dict.insert(order[i]);
        if(check()){
            cout << i + 1 << '\n';
            break;
        }
    }
}