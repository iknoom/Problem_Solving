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

    def get(self, k):
        k += self.n - 1
        ret = self.data[k]
        while k > 0:
            k = (k - 1) // 2
            ret += self.data[k]
        return ret

    def query(self, l, r, v):
        L = l + self.n
        R = r + self.n
        while L < R:
            if R & 1:
                R -= 1
                self.data[R - 1] = self.func(self.data[R - 1], v)
            if L & 1:
                self.data[L - 1] = self.func(self.data[L - 1], v)
                L += 1
            L >>= 1
            R >>= 1

def solution():
    N = int(input())
    A = list(map(int, input().split()))
    tree = SegmentTree(N, int.__add__, 0)
    B = [(A[i], i) for i in range(N)]
    B.sort()

    final = sorted(A)
    answer = [0] * N
    for i in range(N - 1, -1, -1):
        left = tree.get(i)
        j = B[i][1]
        answer[i] = (left + (i - j + left)) % 2
        tree.query(j - left, i, 1)
    t = "YES"
    for i in range(N):
        if answer[i] == 0:
            continue

        if i == N - 1:
            t = "NO"
        else:
            if final[i] == final[i + 1] and answer[i + 1] == 1:
                answer[i] ^= 1
                answer[i + 1] ^= 1
            else:
                t = "NO"
                break
    print(t)

if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        solution()