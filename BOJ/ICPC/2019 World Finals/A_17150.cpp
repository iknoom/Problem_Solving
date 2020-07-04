#include <bits/stdc++.h>
using namespace std;
using tt = tuple<int, int, int>; // p, h, i
using pi = pair<int, int>; // h, i
const int MAX_SIZE = 1000000;
tt front[MAX_SIZE], back[MAX_SIZE];
int N, front_set[MAX_SIZE], back_set[MAX_SIZE];
int front_idx[MAX_SIZE], back_idx[MAX_SIZE];

int main() {
    cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false);

    cin >> N;
    for(int i = 0; i < N; i++) cin >> get<0>(back[i]);
    for(int i = 0; i < N; i++) cin >> get<1>(back[i]);
    for(int i = 0; i < N; i++) cin >> get<0>(front[i]);
    for(int i = 0; i < N; i++) cin >> get<1>(front[i]);
    for(int i = 0; i < N; i++){
        get<2>(back[i]) = i;
        get<2>(front[i]) = i;
    }
    sort(back, back + N);
    sort(front, front + N);

    vector<set<pi>> v;

    for(int i = 0; i < N; i++){
        if(i != 0 && get<0>(back[i]) == get<0>(back[i - 1])){
            back_set[i] = v.size() - 1;
            v.back().insert({get<1>(back[i]), get<2>(back[i])});
        }

        else if(i != N - 1 && get<0>(back[i]) == get<0>(back[i + 1])){
            set<pi> tmp;
            tmp.insert({get<1>(back[i]), get<2>(back[i])});
            v.push_back(tmp);
            back_set[i] = v.size() - 1;
        }
        else{
            back_set[i] = -1;
        }
    }

    for(int i = 0; i < N; i++){
        if(i != 0 && get<0>(front[i]) == get<0>(front[i - 1])){
            front_set[i] = v.size() - 1;
            v.back().insert({-get<1>(front[i]), get<2>(front[i])});
        }
        else if(i != N - 1 && get<0>(front[i]) == get<0>(front[i + 1])){
            set<pi> tmp;
            tmp.insert({-get<1>(front[i]), get<2>(front[i])});
            v.push_back(tmp);
            front_set[i] = v.size() - 1;
        }
        else{
            front_set[i] = -1;
        }
    }

    for(int i = 0; i < N; i++){
        if(front_set[i] == -1 && back_set[i] == -1){
            if(get<1>(front[i]) < get<1>(back[i])){
                front_idx[i] = get<2>(front[i]) + 1;
                back_idx[i] = get<2>(back[i]) + 1;
            }
            else {
                cout << "impossible" << endl;
                return 0;
            }
            continue;
        }

        if(front_set[i] != -1 && back_set[i] != -1){
            if(v[front_set[i]].size() < v[back_set[i]].size()){
                get<1>(front[i]) = -v[front_set[i]].begin()->first;
                get<2>(front[i]) = v[front_set[i]].begin()->second;
                v[front_set[i]].erase(v[front_set[i]].begin());
                front_set[i] = -1;
            }
            else{
                get<1>(back[i]) = v[back_set[i]].begin()->first;
                get<2>(back[i]) = v[back_set[i]].begin()->second;
                v[back_set[i]].erase(v[back_set[i]].begin());
                back_set[i] = -1;
            }
        }

        if(front_set[i] == -1){
            // back에서 front보다 첫번째 큰 값을 찾는다
            int set_i = back_set[i];
            auto upper = v[set_i].upper_bound(make_pair(get<1>(front[i]), MAX_SIZE));
            if(upper == v[set_i].end()){
                cout << "impossible" << endl;
                return 0;
            }
            int idx = upper->second;
            v[set_i].erase(upper);
            back_idx[i] = idx + 1;
            front_idx[i] = get<2>(front[i]) + 1;
        }
        if(back_set[i] == -1){
            // front에서 back보다 작은 마지막 값을 찾는다
            int set_i = front_set[i];
            auto upper = v[set_i].upper_bound(make_pair(-get<1>(back[i]), MAX_SIZE));
            if(upper == v[set_i].end()){
                cout << "impossible" << endl;
                return 0;
            }
            int idx = upper->second;
            v[set_i].erase(upper);
            back_idx[i] = get<2>(back[i]) + 1;
            front_idx[i] = idx + 1;
        }
    }
    for(int j = 0; j < N; j++) cout << back_idx[j] << " ";
    cout << endl;
    for(int j = 0; j < N; j++) cout << front_idx[j] << " ";
    cout << endl;
}