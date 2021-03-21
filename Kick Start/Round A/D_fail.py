import sys
input = sys.stdin.readline

def solution(N, A, B, R, C):
    ret = float('inf')
    M = N * N
    for k in range(1 << M):
        cur = 0
        check = [[0] * N for _ in range(N)]
        for y in range(N):
            for x in range(N):
                if A[y][x] != -1:
                    check[y][x] = 1
                if k & (1 << (y * N + x)):
                    check[y][x] = 1
                    cur += B[y][x]
        while True:
            flag = False
            for i in range(N):
                S = 0
                for j in range(N):
                    S += check[i][j]
                if S == N - 1:
                    flag = True
                    for j in range(N):
                        check[i][j] = 1
            for j in range(N):
                S = 0
                for i in range(N):
                    S += check[i][j]
                if S == N - 1:
                    flag = True
                    for i in range(N):
                        check[i][j] = 1
            if not flag:
                break
        if sum(sum(row) for row in check) == M:
            ret = min(ret, cur)
    return ret

if __name__ == '__main__':
    T = int(input())
    for case in range(1, T + 1):
        N = int(input())
        A = [list(map(int, input().split())) for _ in range(N)]
        B = [list(map(int, input().split())) for _ in range(N)]
        R = list(map(int, input().split()))
        C = list(map(int, input().split()))
        answer = solution(N, A, B, R, C)
        print("Case #" + str(case) + ":", answer)