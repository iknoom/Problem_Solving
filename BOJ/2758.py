import sys
input = sys.stdin.readline

def solution():
    n, m = map(int, input().split())
    ans = [0] + [1] * m
    for _ in range(n - 1):
        nxt = [0] * (m + 1)
        for i in range(1, m + 1):
            t = i // 2
            for j in range(1, t + 1):
                nxt[i] += ans[j]
        ans = nxt
    print(sum(ans))

if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        solution()