import sys
input = sys.stdin.readline

def solution(N, M, A):
    lower = [[0] * M for _ in range(N)]
    upper = [[0] * M for _ in range(N)]
    for y in range(N):
        for x in range(M):
            if not A[y][x]: continue
            if y and A[y - 1][x]:
                lower[y][x] = lower[y - 1][x] + 1
            else:
                lower[y][x] = 1
    for y in range(N):
        for x in range(M):
            if not A[-y-1][-x-1]: continue
            if y and A[-y][-x-1]:
                upper[-y-1][-x-1] = upper[-y][-x-1] + 1
            else:
                upper[-y-1][-x-1] = 1

    ret = 0
    hrz = [[0] * M for _ in range(N)]
    for y in range(N):
        for x in range(M):
            if not A[y][x]: continue
            if x and A[y][x - 1]:
                hrz[y][x] = hrz[y][x - 1] + 1
            else:
                hrz[y][x] = 1
            # solution
            L = 1
            while True:
                L += 1
                H = L // 2
                if hrz[y][x] < L: break
                # left
                # 2 L cases
                if y - L * 2 + 1 >= 0 and lower[y][x - L + 1] >= L * 2:
                    ret += 1
                if y + L * 2 - 1 < N and upper[y][x - L + 1] >= L * 2:
                    ret += 1
                if L % 2 == 0 and H > 1 and y - H + 1 >= 0 and lower[y][x - L + 1] >= H:
                    ret += 1
                if L % 2 == 0 and H > 1 and y + H - 1 < N and upper[y][x - L + 1] >= H:
                    ret += 1
                # right
                # 2 L cases
                if y - L * 2 + 1 >= 0 and lower[y][x] >= L * 2:
                    ret += 1
                if y + L * 2 - 1 < N and upper[y][x] >= L * 2:
                    ret += 1
                # 2 H cases
                if L % 2 == 0 and H > 1 and y - H + 1 >= 0 and lower[y][x] >= H:
                    ret += 1
                if L % 2 == 0 and H > 1 and y + H - 1 < N and upper[y][x] >= H:
                    ret += 1
    return ret


if __name__ == '__main__':
    T = int(input())
    for case in range(1, T + 1):
        R, C = map(int, input().split())
        A = [list(map(int, input().split())) for _ in range(R)]
        answer = solution(R, C, A)
        print("Case #" + str(case) + ":", answer)