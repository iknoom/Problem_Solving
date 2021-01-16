from sys import stdin

input = stdin.readline

if __name__ == "__main__":
    N, K = map(int, input().split())
    A = list(map(int, input().split()))
    count = [0] * (N + 1)
    for a in A:
        count[a] += 1
    ans = min(K, count[0])
    before = ans
    for i in range(1, N + 1):
        ans += min(count[i], before)
        before = min(count[i], before)
    print(ans)

