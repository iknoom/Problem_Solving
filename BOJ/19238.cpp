#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

struct person {
    int sx, sy, ex, ey;
    bool is_end;
} people[400];

int N, M, T, board[20][20], cx, cy, dist[20][20];

void update_dist() {
    // init
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dist[i][j] = -1;
        }
    }
    // bfs
    queue<pair<int, int>> q;
    q.push({cx, cy});
    dist[cy][cx] = 0;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || N <= nx) continue;
            if (ny < 0 || N <= ny) continue;
            if (board[ny][nx]) continue;
            if (dist[ny][nx] >= 0) continue;
            dist[ny][nx] = dist[y][x] + 1;
            q.push({nx, ny});
        }
    }
}

int get_min_dist_person_idx() {
    // sort
    vector<tuple<int, int, int, int>> tmp;
    for (int i = 0; i < M; i++) {
        if (people[i].is_end) continue;
        int x = people[i].sx, y = people[i].sy;
        if (dist[y][x] < 0) continue;
        tmp.push_back({dist[y][x], y, x, i});
    }
    if (tmp.empty()) {
        return -1;
    }
    sort(tmp.begin(), tmp.end());
    return get<3>(tmp.front());
}

bool solve() {
    for (int i = 0; i < M; i++) {
        // move 1
        update_dist();
        int idx = get_min_dist_person_idx();
        if (idx < 0) {
            return false;
        }
        if (T < dist[people[idx].sy][people[idx].sx]) {
            return false;
        }
        T -= dist[people[idx].sy][people[idx].sx];
        cx = people[idx].sx;
        cy = people[idx].sy;

        // move 2
        update_dist();
        if (dist[people[idx].ey][people[idx].ex] < 0) {
            return false;
        }
        if (T < dist[people[idx].ey][people[idx].ex]) {
            return false;
        }
        T += dist[people[idx].ey][people[idx].ex];
        cx = people[idx].ex;
        cy = people[idx].ey;
        people[idx].is_end = true;
    }
    return true;
}

int main() {
    cin >> N >> M >> T;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    cin >> cy >> cx;
    cx--; cy--;
    for (int i = 0; i < M; i++) {
        cin >> people[i].sy >> people[i].sx >> people[i].ey >> people[i].ex;
        people[i].sx--; people[i].sy--;
        people[i].ex--; people[i].ey--;
    }

    if (solve()) {
        cout << T << '\n';
    } else {
        cout << -1 << '\n';
    }
}