from sys import stdin
input = stdin.readline
INF = float('inf')

class Solution:
    def __init__(self, N, H, tree):
        self.N = N
        self.H = H
        self.tree = tree
        self.arr = []

    def dfs(self, i, u, d, depth):
        if i >= self.N:
            return
        self.dfs(i * 2 + 1, u, d, depth + 1)
        if u <= depth <= d:
            self.arr.append(self.tree[i])
        self.dfs(i * 2 + 2, u, d, depth + 1)

    def getMaxSumArr(self):
        ret = -INF
        S = 0
        for e in self.arr:
            S = max(0, S) + e
            ret = max(ret, S)
        return ret

    def maxSumAllRectangle(self):
        ret = -INF
        for u in range(self.H):
            for d in range(u, self.H):
                self.arr = []
                self.dfs(0, u, d, 0)
                ret = max(ret, self.getMaxSumArr())
        return ret

if __name__ == '__main__':
    N = int(input())
    H = N.bit_length()
    tree = list(map(int, input().split()))
    solution = Solution(N, H, tree)
    answer = solution.maxSumAllRectangle()
    print(answer)