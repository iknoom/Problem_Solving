def get_wolf_sheep(info, bitset):
    wolf_n = 0
    sheep_n = 0
    for i in range(len(info)):
        if bitset & (1 << i):
            if info[i] == 1:
                wolf_n += 1
            else:
                sheep_n += 1
    return wolf_n, sheep_n

def solution(info, edges):
    N = len(info)
    adj = [[] for _ in range(N)]
    for u, v in edges:
        adj[u].append(v)
        adj[v].append(u)
    vst = [[False] * (1 << N) for _ in range(N)]
    vst[0][1] = True
    queue = [(0, 1)]
    answer = 0
    for u, bitset in queue:
        _, u_sheep_n = get_wolf_sheep(info, bitset)
        answer = max(answer, u_sheep_n)
        for v in adj[u]:
            nxt_bitset = bitset | (1 << v)
            v_wolf_n, v_sheep_n = get_wolf_sheep(info, nxt_bitset)
            if v_wolf_n >= v_sheep_n:
                continue
            if vst[v][nxt_bitset]:
                continue
            vst[v][nxt_bitset] = True
            queue.append((v, nxt_bitset))
    return answer

if __name__ == '__main__':
    print(solution([0,0,1,1,1,0,1,0,1,0,1,1],	[[0,1],[1,2],[1,4],[0,8],[8,7],[9,10],[9,11],[4,3],[6,5],[4,6],[8,9]]))