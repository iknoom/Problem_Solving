from sys import stdin, setrecursionlimit
input = stdin.readline
setrecursionlimit(500001)

class SegmentTree():
    def __init__(self, n, func, init):
        self.n = 2 ** (n - 1).bit_length()
        self.init = init
        self.data = [init] * (2 * self.n)
        self.func = func

    def set(self,k, v):
        self.data[k + self.n - 1] = v

    def get(self, k):
        k += self.n - 1
        ret = self.data[k]
        while k > 0:
            k = (k - 1) // 2
            ret = self.func(ret, self.data[k])
        return ret

    def update(self, l, r, k):
        L = l + self.n
        R = r + self.n
        while L < R:
            if R & 1:
                R -= 1
                self.data[R - 1] = self.func(self.data[R - 1], k)
            if L & 1:
                self.data[L - 1] = self.func(self.data[L - 1], k)
                L += 1
            L >>= 1
            R >>= 1

def dfs(u):
    global idx
    idx += 1
    l[u] = idx
    for v in adj[u]:
        dfs(v)
    r[u] = idx

if __name__ == "__main__":
    # input
    N, M = map(int, input().split())
    pay = [0] * N
    adj = [[] for _ in range(N)]
    pay[0] = int(input())
    for u in range(1, N):
        p_i, v = map(int, input().split())
        pay[u] = p_i
        adj[v - 1].append(u)

    # set l, r, segmentTree
    l = [-1] * N
    r = [-1] * N
    idx = -1
    dfs(0)
    segmentTree = SegmentTree(N, int.__add__, 0)
    for u in range(N):
        segmentTree.set(l[u], pay[u])

    # query
    for _ in range(M):
        query = input().split()
        if query[0] == 'p':
            a, x = map(int, query[1:])
            if l[a - 1] == r[a - 1]:
                continue
            segmentTree.update(l[a - 1] + 1, r[a - 1] + 1, x)
        else:
            a = int(query[1])
            print(segmentTree.get(l[a - 1]))