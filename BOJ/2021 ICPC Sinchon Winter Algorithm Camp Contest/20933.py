from sys import stdin
input = stdin.readline
INF = float('inf')

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
        self.data[k] = a

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

if __name__ == "__main__":
    # construct
    N = int(input())
    sum_tree = SegmentTree(N + 1, int.__add__, 0)
    min_tree = SegmentTree(N + 1, min, INF)
    for i, v in enumerate(map(int, input().split())):
        min_tree.set(i, v)
    for i, v in enumerate(map(int, input().split())):
        sum_tree.set(i, v)
    sum_tree.build()
    min_tree.build()

    # query
    Q = int(input())
    for _ in range(Q):
        q, x, mt = input().split()
        x = int(x)
        mt = int(mt)
        x -= 1
        if q == "CALL":
            l = r = x
            if x > 0:
                _l, _r = 0, N
                while _l + 1 < _r:
                    mid = (_l + _r) // 2
                    if x - mid < 0:
                        _r = mid
                        continue
                    if sum_tree.query(x - mid, x) <= mt:
                        _l = mid
                    else:
                        _r = mid
                l = x - _l
            # right
            if x < N - 1:
                _l, _r = 0, N
                while _l + 1 < _r:
                    mid = (_l + _r) // 2
                    if x - 1 + mid >= N:
                        _r = mid
                        continue
                    if sum_tree.query(x, x + mid) <= mt:
                        _l = mid
                    else:
                        _r = mid
                r = x + _l
            print(min_tree.query(l, r + 1))
        else:
            sum_tree.update(x, mt)