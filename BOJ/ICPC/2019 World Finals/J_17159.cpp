#include <bits/stdc++.h>
using namespace std;
long long p, h;
long long score[501][51];
using pi = pair<long long, long long>;
vector<pi> interval[501];

int sweep(int i){
    int ret = 0;
    int cur = 0;
    sort(interval[i].begin(), interval[i].end());
    for(auto p : interval[i]){
        cur += p.second;
        ret = max(ret, cur);
    }
    return ret;
}

void get_interval(){
    for(int a = 0; a < p - 1; a++) for(int b = a + 1; b < p; b++){
        bool a_beat, b_beat;
        int a_i, b_i;
        long long prv_x, prv_dy, sum_a, sum_b;
        a_beat = false; b_beat = false;
        prv_dy = 0;
        prv_x = 1;
        a_i = 0; b_i = 0;
        sum_a = 0; sum_b = 0;
        set<long long> S;
        for(int i = 0; i < h; i++){
            S.insert(score[a][i]);
            S.insert(score[b][i]);
        }
        for(long long x : S){
            while(a_i < h && score[a][a_i] < x) sum_a += score[a][a_i++];
            while(b_i < h && score[b][b_i] < x) sum_b += score[b][b_i++];
            long long score_a = sum_a + (h - a_i) * x;
            long long score_b = sum_b + (h - b_i) * x;
            long long next_dy = abs(score_a - score_b);
            long long dx = x - prv_x;

            if(score_a < score_b){
                if(b_beat){
                    a_beat = true;
                    b_beat = false;
                    long long diff = dx * prv_dy / (prv_dy + next_dy);
                    interval[a].emplace_back(prv_x + diff + 1, 1);
                    interval[b].emplace_back(prv_x + diff + ((prv_dy + next_dy) * diff != dx * prv_dy), -1);
                }
                else if(!a_beat){
                    a_beat = true;
                    interval[a].emplace_back(prv_x + 1, 1);
                }
            }
            else if(score_a > score_b){
                if(a_beat){
                    a_beat = false;
                    b_beat = true;
                    long long diff = dx * prv_dy / (prv_dy + next_dy);
                    interval[a].emplace_back(prv_x + diff + ((prv_dy + next_dy) * diff != dx * prv_dy), -1);
                    interval[b].emplace_back(prv_x + diff + 1, 1);
                }
                else if(!b_beat){
                    b_beat = true;
                    interval[b].emplace_back(prv_x + 1, 1);
                }
            }
            else if(score_a == score_b && a_beat){
                a_beat = false;
                interval[a].emplace_back(x + 1, -1);
            }
            else if(score_a == score_b && b_beat){
                b_beat = false;
                interval[b].emplace_back(x + 1, -1);
            }
            prv_dy = next_dy;
            prv_x = x;
        }
    }
}

int main() {
    cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false);
    cin >> p >> h;
    for(int i = 0; i < p; i++){
        for(int j = 0; j < h; j++){
            cin >> score[i][j];
        }
        sort(score[i], score[i] + h);
    }
    get_interval();

    for(int i = 0; i < p; i++){
        cout << p - sweep(i) << '\n';
    }
}