from sys import stdin
input = stdin.readline

def solution():
    n, k1, k2 = map(int, input().split())
    a1, a2 = n - k1, n - k2
    w, b = map(int, input().split())
    white = min(k1, k2)
    black = min(a1, a2)
    white += (max(k1, k2) - min(k1, k2)) // 2
    black += (max(a1, a2) - min(a1, a2)) // 2
    if w <= white and b <= black:
        print("YES")
    else:
        print("NO")

if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        solution()
