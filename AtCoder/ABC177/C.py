from sys import stdin
input = stdin.readline
MOD = 10**9 + 7

if __name__ == "__main__":
    N = int(input())
    A = list(map(int, input().split()))
    S = A[0]
    ans = 0
    for i in range(1, N):
        ans += S * A[i]
        ans %= MOD
        S += A[i]
        S %= MOD
    print(ans)