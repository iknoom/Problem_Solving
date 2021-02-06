import sys

input = sys.stdin.readline


def solution():
    n, k = map(int, input().split())
    h = list(map(int, input().split()))
    if n == 2:
        if abs(h[0] - h[-1]) >= k:
            print("NO")
            return

    sweep = []
    for i in range(1, n - 1):
        sweep.append((h[i], i))
    sweep.sort(reverse=True)
    H = [-1] * n
    H[0] = h[0]
    H[-1] = h[-1]
    for h_i, i in sweep:
        cur = h_i
        if H[i - 1] != -1:
            cur = max(cur, H[i - 1] + 1 - k)
        if H[i + 1] != -1:
            cur = max(cur, H[i + 1] + 1 - k)
        if cur - h_i >= k:
            print("NO")
            return
        H[i] = cur
    for i in range(n - 1):
        if abs(H[i] - H[i + 1]) >= k:
            print("NO")
            return
    print("YES")





if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        solution()