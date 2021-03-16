from sys import stdin
input = stdin.readline

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
    # input
    N = int(input())
    A = list(map(int, input().split()))
    Q = int(input())
    queries = []
    for i in range(Q):
        l, r = map(int, input().split())
        queries.append((l - 1, r - 1, i))

    # solution
    queries.sort(key=lambda x: x[1])
    answer = [0] * Q

    segment_tree = SegmentTree(N, int.__add__, 0)
    last = {}
    i = 0
    for l, r, idx in queries:
        while i <= r:
            if A[i] in last:
                segment_tree.update(last[A[i]], -1)
            segment_tree.update(i, 1)
            last[A[i]] = i
            i += 1
        answer[idx] = segment_tree.query(l, r + 1)
    print(*answer, sep='\n')