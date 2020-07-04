import sys
sys.setrecursionlimit(9**9)
input = sys.stdin.readline

def sol(u):
    global ans
    sig2 = []
    sig1 = []
    M = []
    W = []

    for v, w in g[u]:
        if not vst[v]:
            vst[v] = True
            s1, s2, m = sol(v)
            W.append(w)
            sig2.append(s1)
            sig1.append(s2)
            M.append(m)
    sig_W = sum(W)

    if len(M) == 0:
        return 0, 0, 1

    elif len(M) == 1:
        ans += sig2[0] + 2 * sig1[0] * sig_W + sig_W * sig_W * M[0]
        return sig2[0] + 2 * sig1[0] * sig_W + sig_W * sig_W * M[0], sig1[0] + sig_W * M[0], M[0]

    elif len(M) == 2:
        ans += sig2[0] * M[1] + sig2[1] * M[0]
        ans += sig_W * sig_W * M[0] * M[1]
        ans += 2 * sig1[0] * sig1[1]
        ans += 2 * sig_W * M[1] * sig1[0]
        ans += 2 * sig_W * M[0] * sig1[1]
        ret1 = sig2[0] + (2 * sig1[0] * W[0]) + (W[0] * W[0] * M[0])
        ret2 = sig2[1] + (2 * sig1[1] * W[1]) + (W[1] * W[1] * M[1])
        return ret1 + ret2, sum(sig1) + W[0] * M[0] + W[1] * M[1], sum(M)


if __name__ == "__main__":
    N = int(input())
    g = [[] for _ in range(N)]
    for _ in range(N - 1):
        u, v, w = map(int, input().split())
        g[u - 1].append((v - 1, w))
        g[v - 1].append((u - 1, w))
    s = -1
    for i in range(N):
        if len(g[i]) == 1: s = i; break
    ans = 0
    vst = [False] * N
    vst[s] = True
    sol(s)
    print(ans)