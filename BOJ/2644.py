from collections import deque

def bfs(start, end):
    vst = [-1] * N
    queue = deque([])
    # 1. 시작하는 정점 s를 큐에 넣고 방문했다고 표시한다.
    queue.append(start)
    vst[start] = 0
    # 2.
    # while (큐가 비어있지 않은 동안) {
    # 	큐에서 정점 curr를 꺼낸다.
    # 	for (curr에 인접한 정점 next에 대해) {
    # 		이전에 방문하지 않았다면 큐에 넣고 방문했다고 표시한다.
    #      }
    while len(queue) > 0:
        curr = queue.popleft()
        for next in adj[curr]:
            if vst[next] == -1:
                queue.append(next)
                vst[next] = vst[curr] + 1
    return vst[end]


if __name__ == '__main__':
    # input
    N = int(input())
    S, E = map(int, input().split())
    adj = [[] for _ in range(N)]
    M = int(input())
    for _ in range(M):
        u, v = map(int, input().split())
        adj[u - 1].append(v - 1)
        adj[v - 1].append(u - 1)

    # bfs
    answer = bfs(S - 1, E - 1)
    print(answer)