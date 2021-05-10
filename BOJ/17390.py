from sys import stdin
input = stdin.readline

def query(L, R):
    return

if __name__ == '__main__':
    N, Q = map(int, input().split())
    A = list(map(int, input().split()))
    B = [0] + sorted(A)
    for i in range(N):
        B[i + 1] += B[i]

    # do query
    for _ in range(Q):
        L, R = map(int, input().split())
        print(B[R] - B[L - 1])