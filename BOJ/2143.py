from collections import Counter

if __name__ == "__main__":
    T = int(input())
    N = int(input())
    A = list(map(int, input().split()))
    M = int(input())
    B = list(map(int, input().split()))
    D = []
    for i in range(N):
        S = 0
        for j in range(i, N):
            S += A[j]
            D.append(S)
    C = Counter(D)
    ans = 0
    for i in range(M):
        S = 0
        for j in range(i, M):
            S += B[j]
            ans += C[T - S]
    print(ans)