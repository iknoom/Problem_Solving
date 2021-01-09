#include <bits/stdc++.h>

using namespace std;
const int MAX = 400005;
const int INF = 1000000000;

// A[i], B[i]: 그룹의 i번 정점과 매칭된 상대편 그룹 정점 번호
int N, M, A[MAX], B[MAX], dist[MAX]; // dist[i]: (A그룹의) i번 정점의 레벨
bool used[MAX]; // used: (A그룹의) 이 정점이 매칭에 속해 있는가?
vector<int> adj[MAX];

// 호프크로프트 카프 전용 bfs 함수: A그룹의 각 정점에 레벨을 매김
void bfs() {
    queue<int> Q;
    // 매칭에 안 속한 A그룹의 정점만 레벨 0인 채로 시작
    for (int i = 0; i < N; i++) {
        if (!used[i]) {
            dist[i] = 0;
            Q.push(i);
        } else dist[i] = INF;
    }

    // BFS를 통해 A그룹 정점에 0, 1, 2, 3, ... 의 레벨을 매김
    while (!Q.empty()) {
        int a = Q.front();
        Q.pop();
        for (int b: adj[a]) {
            if (B[b] != -1 && dist[B[b]] == INF) {
                dist[B[b]] = dist[a] + 1;
                Q.push(B[b]);
            }
        }
    }
}

// 호프크로프트 카프 전용 dfs 함수: 새 매칭을 찾으면 true
bool dfs(int a) {
    for (int b: adj[a]) {
        // 이분 매칭 코드와 상당히 유사하나, dist 배열에 대한 조건이 추가로 붙음
        if (B[b] == -1 || (dist[B[b]] == dist[a] + 1 && dfs(B[b]))) {
            // used 배열 값도 true가 됨
            used[a] = true;
            A[a] = b;
            B[b] = a;
            return true;
        }
    }
    return false;
}

int hopcroft_karp() {
    int match = 0;
    fill(A, A + MAX, -1);
    fill(B, B + MAX, -1);
    while (1) {
        // 각 정점에 레벨을 매기고 시작
        bfs();

        // 이분 매칭과 비슷하게 A그룹 정점을 순회하며 매칭 증가량 찾음
        int flow = 0;
        for (int i = 0; i < N; i++)
            if (!used[i] && dfs(i)) flow++;

        // 더 이상 증가 경로를 못 찾으면 알고리즘 종료
        if (flow == 0) break;

        // 찾았을 경우 반복
        match += flow;
    }
    return match;
}
int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> N;
    M = N * 2;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        adj[i].push_back(a - 1);
        adj[i].push_back(b - 1);
    }
    cout << hopcroft_karp() << '\n';
}