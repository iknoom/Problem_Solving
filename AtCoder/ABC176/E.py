import sys
input = sys.stdin.readline

class SegmentTree():
    def __init__(self, n, init):
        self.n = 2 ** (n - 1).bit_length()
        self.init = init
        self.data = [init] * (2 * self.n)

    def inc(self, k):
        self.data[k + self.n - 1] += 1

    def build(self):
        for k in reversed(range(self.n - 1)):
            self.data[k] = max(self.data[k * 2 + 1], self.data[k * 2 + 2])

    def update(self, k, a):
        k += self.n - 1
        self.data[k] += a

        while k > 0:
            k = (k - 1) // 2
            self.data[k] = max(self.data[k * 2 + 1], self.data[k * 2 + 2])

    def query(self, l, r):
        L = l + self.n
        R = r + self.n
        ret = self.init
        while L < R:
            if R & 1:
                R -= 1
                ret = max(ret, self.data[R - 1])
            if L & 1:
                ret = max(ret, self.data[L - 1])
                L += 1
            L >>= 1
            R >>= 1
        return ret

if __name__ == "__main__":
    H, W, M = map(int, input().split())
    Seg = SegmentTree(W + 5, 0)
    Yaxis = dict()

    for _ in range(M):
        h, w = map(int, input().split())
        if h in Yaxis: Yaxis[h].append(w)
        else: Yaxis[h] = [w]
        Seg.inc(w)
    Seg.build()

    ans = 0
    for y in Yaxis:
        for x in Yaxis[y]: Seg.update(x, -1)
        ans = max(ans, len(Yaxis[y]) + Seg.query(0, W + 1))
        for x in Yaxis[y]: Seg.update(x, 1)

    print(ans)