import sys
input = sys.stdin.readline

def solution(N, M):
    A = [list(map(int, input().split())) for _ in range(N)]
    ret = 0
    for i in range(N):
        for j in range(M):
            if 0 < i and 0 < j and A[i][j] == 1:
                A[i][j] += min(A[i][j - 1], A[i - 1][j], A[i - 1][j - 1])
            ret = max(ret, A[i][j])
    print(ret)

if __name__ == "__main__":
    while True:
        N, M = map(int, input().split())
        if N + M == 0: break
        solution(N, M)