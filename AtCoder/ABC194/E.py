from sys import stdin
input = stdin.readline
INF = 10**9
class SegmentTree():
    def __init__(self, n, func, init):
        self.n = 2 ** (n - 1).bit_length()
        self.init = init
        self.data = [init] * (2 * self.n)
        self.func = func

    def set(self, k, v):
        self.data[k + self.n - 1] = v

    def build(self):
        for k in reversed(range(self.n - 1)):
            self.data[k] = self.func(self.data[k * 2 + 1], self.data[k * 2 + 2])

    def update(self, k, a):
        k += self.n - 1
        self.data[k] += a

        while k > 0:
            k = (k - 1) // 2
            self.data[k] = self.func(self.data[k * 2 + 1], self.data[k * 2 + 2])

    def query(self, l, r):
        L = l + self.n
        R = r + self.n
        ret = self.init
        while L < R:
            if R & 1:
                R -= 1
                ret = self.func(ret, self.data[R - 1])
            if L & 1:
                ret = self.func(ret, self.data[L - 1])
                L += 1
            L >>= 1
            R >>= 1
        return ret

if __name__ == '__main__':
    N, M = map(int, input().split())
    A = list(map(int, input().split()))
    segment_tree = SegmentTree(N + 5, min, INF)
    for i in range(N + 5):
        segment_tree.set(i, i)
    segment_tree.build()


    for i in range(M):
        segment_tree.update(A[i], INF)

    answer = segment_tree.query(0, N + 5)
    for i in range(M, N):
        segment_tree.update(A[i - M], -INF)
        segment_tree.update(A[i], INF)
        answer = min(answer, segment_tree.query(0, N + 5))
    print(answer)