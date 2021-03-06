from sys import stdin
input = stdin.readline

if __name__ == '__main__':
    N = int(input())
    ans = 10 ** 18
    A = []
    B = []
    for i in range(N):
        a, b = map(int, input().split())
        A.append(a)
        B.append(b)
    for i in range(N):
        for j in range(N):
            if i == j:
                ans = min(ans, A[i] + B[i])
            else:
                ans = min(ans, max(A[i], B[j]))
    print(ans)